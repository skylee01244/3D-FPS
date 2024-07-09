#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Headers/Global.h"
#include "Headers/Enemy.h"
#include "Headers/Player.h"
#include "Headers/ConvertSketch.h"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convert_sketch(Player& i_player, Enemy& i_enemy)
{
	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> output_map{};

	sf::Image map_sketch;
	map_sketch.loadFromFile("Resources/Images/MapSketch.png");

	for (unsigned char a = 0; a < MAP_WIDTH; a++)
	{
		for (unsigned char b = 0; b < MAP_HEIGHT; b++)
		{
			sf::Color pixel = map_sketch.getPixel(a, b);

			if (pixel == sf::Color(0, 0, 0))
			{
				output_map[a][b] = Cell::Wall;
			}
			else if (pixel == sf::Color(255, 0, 0))
			{
				i_player.set_position(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
			}
			else if (pixel == sf::Color(0, 0, 255))
			{
				i_enemy.set_position(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
			}
			else
			{
				output_map[a][b] = Cell::Empty;
			}
		}
	}

	return output_map;
}