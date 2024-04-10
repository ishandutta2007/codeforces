#include <iostream>

#define int long long

signed main() {
	int n, m;
	std::cin >> n;
	
	if(n < 6 && n != 4 && n != 5) {
		std::cout << "NO";
		return 0;
	}
	
	std::cout << "YES" << std::endl;
	if(n == 5) {
		std::cout << "5 - 3 = 2\n2 * 4 = 8\n1 + 2 = 3\n8 * 3 = 24\n";
		return 0;
	}
	std::cout << "2 * 3 = 6" << std::endl;
	std::cout << "6 * 4 = 24" << std::endl;
	
	if(n == 4) {
		std::cout << "24 * 1 = 24" << std::endl;
		return 0;
	}
	
	
	
	std::cout << "6 - 5 = 1" << std::endl;
	std::cout << "1 - 1 = 0" << std::endl;
	
	for(int i = 7; i <= n; i++) {
		std::cout << i << " * 0 = 0" << std::endl;
	}
	
	std::cout << "24 + 0 = 24" << std::endl;
	
	return 0;
}