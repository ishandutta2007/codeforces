#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	a %= b;
	
	int k = -1;
	int i = 0;
	while(k != c && i <= b)
	{
		i++;
		a *= 10;
		k = a/b;
		a %= b;
	}
	
	if(i > b)
		i = -1;
	
	std::cout << i;
	
	return 0;
}