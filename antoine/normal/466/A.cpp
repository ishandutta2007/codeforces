
#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	int n, m, a, b;
	std::cin >> n >> m >> a >> b;
	std::cout << std::min(n*a, n/m*b + std::min(b, n%m*a));
	return 0;
}