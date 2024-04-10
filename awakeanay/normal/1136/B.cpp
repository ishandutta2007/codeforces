#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;

	int walk = std::min(k-1, n-k);
	std::cout << walk + 3*n;
}