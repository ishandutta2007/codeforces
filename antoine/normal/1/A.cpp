#include <iostream>

typedef unsigned long long uint64;

uint64 cceil(uint64 n, uint64 a) {
	if (a == 1)
		return n;
	if (n % a == 0)
		return n / a;
	return n / a + 1;
}

int main() {
	uint64 n, m, a;
	std::cin >> n;
	std::cin >> m;
	std::cin >> a;
	if (a == 1)
		std::cout << m*n;
	else
		std::cout << cceil(n , a) * cceil(m , a);
}