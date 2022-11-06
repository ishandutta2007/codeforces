

#include <iostream>


int main() {
	int n;
	std::cin >> n;
	
	int a;
	std::cin >> a;
	a%=2;
	std::cout << (a + 1) << "\n";
	int s = (a + 1)%2;
	
	for(; n>=2; --n) {
		std::cin >> a;
		s = (s + a + 1)%2;
		std::cout << (s == 1 ? 1 : 2) << "\n";
	}
}