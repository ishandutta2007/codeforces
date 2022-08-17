#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int diff = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
			diff++;
		else
			diff--;
	}

	if(n % 2 || diff != 0)
	{
		std::cout << 1 << std::endl;
		std::cout << s << std::endl;
	}
	else
	{
		std::cout << 2 << std::endl;
		std::cout << s[0] << " ";
		for(int i = 1; i < n; i++)
			std::cout << s[i];
		std::cout << std::endl;
	}
}