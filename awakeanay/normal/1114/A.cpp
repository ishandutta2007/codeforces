#include <iostream>

int main()
{
	int x, y, z;
	int a, b, c;
	
	std::cin >> x >> y >> z;
	std::cin >> a >> b >> c;
	
	bool poss = true;
	if(a < x)
		poss = false;
	a -= x;
	
	if(a + b < y)
		poss = false;
	a -= y;
	
	if(a + b + c < z)
		poss = false;
	
	if(poss)
		std::cout << "YES";
	else
		std::cout << "NO";
	
	return 0;
}