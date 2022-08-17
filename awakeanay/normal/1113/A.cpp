#include <iostream>

int main()
{
	int n, v;
	std::cin >> n >> v;
	
	if(v >= n-1)
		std::cout << n-1;
	else
		std::cout << v + (n-v)*(n-v+1)/2 - 1;
	
	return 0;
}