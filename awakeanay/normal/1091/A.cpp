#include <iostream>

int main()
{
	long long y, b, r;
	std::cin >> y >> b >> r;
	b--; r-=2;
	
	std::cout << 3*std::min(y, std::min(b, r)) + 3;
	
	return 0;
}