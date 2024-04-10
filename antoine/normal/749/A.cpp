

#include <iostream>

int main() {
	int n;
	std::cin >> n;
	if(n%2 == 0) {
		n /= 2;
		std::cout << n << "\n";
	} else {
		n -= 3;
		n /= 2;
		
		std::cout << (n+1) << "\n3 ";
	}
		for(; n>=1; --n) {
			std::cout << 2 << " ";
		}
}