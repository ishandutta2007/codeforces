#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	int max = 0;
	int day = 0;
	for(int i = 1; i <= n; i++)
	{
		int a;
		std::cin >> a;
		max = std::max(a, max);
		if(max <= i)
			day++;
	}
	
	std::cout << day;
	
	return 0;
}