#include <iostream>
#include <string>

bool check(std::string s)
{
	int n = s.length();
	for(int i = 0; i < n/2; i++)
		if(s[i] != s[n-i-1])
			return false;
	return true;
}

int main()
{
	std::string s;
	std::cin >> s;
	
	int n = s.length();
	bool impos = true;
	for(int i = 1; i < n/2; i++)
	{
		if(s[i] != s[i-1])
			impos = false;
	}
	
	if(impos || n <= 3)
	{
		std::cout << "Impossible";
		return 0;
	}
	
	for(int i = 1; i < n; i++)
	{
		std::string a = s.substr(0, i);
		std::string b = s.substr(i, n-i);
		std::string c = b + a;
		if(check(c) && (c != s))
		{
			std::cout << 1;
			return 0;
		}
	}
	
	std::cout << 2;
	
	return 0;
}