#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	
	long long x, y;
	std::cin >> x >> y;
	
	if(((x - y + 1)%2 == 0 && x-y>0 && y > 1) || y == x + 1)
		std::cout << "Yes";
	else
		std::cout << "No";
	
	return 0;
}