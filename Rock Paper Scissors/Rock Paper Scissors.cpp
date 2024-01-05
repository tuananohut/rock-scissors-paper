#include <iostream>
#include <string>
#include <random>
#include <vector>

std::vector<std::string> moves = { "rock", "paper", "scissors" };

struct Player
{
	int moveIndex;
	std::string move;
};

Player player1 = Player();	
Player player2 = Player();

int generateRandomNumber(float min, float max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(min, max);
	return dis(gen);
}

bool win();

int main()
{
	// When you play rock-paper-scissors, you should one of them. These are the number definitions. If you want to choose rock, you have to enter 0.
	std::cout << "Rock: 0" << std::endl;
	std::cout << "Paper: 1" << std::endl;
	std::cout << "Scissors: 2" << std::endl;
	std::cout << "------------------------------" << std::endl;
	player1.moveIndex = -1;
	player2.moveIndex = -1;
	while (!win())
	{
		std::cout << "Player 1: ";
		std::cin >> player1.moveIndex;
		player1.move = moves[player1.moveIndex];
		player2.moveIndex = generateRandomNumber(0, 2); // Computer chooses random number.
		player2.move = moves[player2.moveIndex];
		std::cout << "Player 1 chose: " << player1.move << std::endl;
		std::cout << "Player 2 chose: " << player2.move << std::endl;
		std::cout << "------------------------------" << std::endl;
	}
	return 0;
}
bool win()
{
	// Winning strategy 
	if ((player1.moveIndex == 0 && player2.moveIndex == 2) ||   
		(player1.moveIndex == 1 && player2.moveIndex == 0) ||
		(player1.moveIndex == 2 && player2.moveIndex == 1))
	{
		std::cout << "Player 1 wins!" << std::endl;
		return true;
	}
	else if ((player2.moveIndex == 0 && player1.moveIndex == 2) ||
		(player2.moveIndex == 1 && player1.moveIndex == 0) ||
		(player2.moveIndex == 2 && player1.moveIndex == 1))
	{
		std::cout << "Player 2 wins!" << std::endl;
		return true;
	}
	return false;
}