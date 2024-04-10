#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string s;
	std::cin >> s;
	
	int ver = 0; int hor = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '1')
		{
			std::cout << (hor%4) + 1 << " " << 2 << std::endl;
			hor++;
		}
		else
		{
			ver++;
			if(ver%2)
				std::cout << 1 << " " << 1 << std::endl;
			else
				std::cout << 3 << " " << 1 << std::endl;
		}
	}
}