#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	int n, k;
	std::cin >> n >> k;

	if (n == k || k == 0)
		std::cout << "0 0";
	else
		std::cout << "1 " << std::min(n - k, 2*k);
	return 0;
}