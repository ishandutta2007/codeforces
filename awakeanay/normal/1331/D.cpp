#include <iostream>

int main() {
	long long x;
	std::cin >> std::hex >> x;
	if(x%2)
		std::cout << 1;
	else
		std::cout << 0;
	std::cout << std::endl;
	return 0;
}