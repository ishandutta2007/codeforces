#include <iostream>

int
main(void)
{
	long long retv = 0, n;
	std::cin >> n;
	for(long long x = 1; x <= n; x *= 10)
		retv += n - x + 1;
	std::cout << retv << std::endl;
}