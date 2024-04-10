#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	
	while(t--)
	{
		long long n, a, b;
		std::cin >> n >> a >> b;

		long long c = a + b - n;
		a -= c;
		b -= c;
		std::cout << std::max(a, b) + 1 << std::endl;
	}
}