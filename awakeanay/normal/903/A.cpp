#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	while(N--)
	{
		int pieces;
		std::cin >> pieces;
		
		if(pieces >= 12 || pieces == 3 || pieces == 6 || pieces == 7 || pieces == 9 || pieces == 10)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0;
}