#include <iostream>

int main() {
	int n;
	std::cin >> n;
	
	for(int i = 2; i <= n; i++) {
		while(n%i == 0) {
			std::cout << i;
			n /= i;
		}
	}
}