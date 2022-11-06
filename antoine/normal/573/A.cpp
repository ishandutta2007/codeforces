

#include <iostream>

int trim(int &n) {
	while(n%3 == 0)
		n /= 3;
	while(n%2 == 0)
		n /= 2;
}

int main() {
	int n, a;
	std::cin >> n;
	int prev;
	std::cin >> prev;
	trim(prev);
	for(--n; n>=1; --n) {
		std::cin >> a;
		trim(a);
		if(a != prev) {
			std::cout << "No";
			break;
		}
	}
	if(n == 0)
		std::cout << "Yes";
}