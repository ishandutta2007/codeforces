#include <iostream>
#include <vector>

int main()
{
	int h1, a1, c1;
	int h2, a2;
	
	std::cin >> h1 >> a1 >> c1 >> h2 >> a2;
	
	std::vector<bool> strategy;
	while(h2 > 0)
	{
		if(h1 > a2 || h2 <= a1)
		{
			strategy.push_back(true);
			h2 -= a1;
			h1 -= a2;
		}
		else
		{
			strategy.push_back(false);
			h1 += c1 - a2;
		}
	}
	
	std::cout << strategy.size() << std::endl;
	for(int i = 0; i < strategy.size(); i++)
	{
		if(strategy[i])
			std::cout << "STRIKE" << std::endl;
		else
			std::cout << "HEAL" << std::endl;
	}
	
	return 0;
}