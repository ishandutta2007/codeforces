#include <iostream>
#include <algorithm>
#include <cstring>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int a, b;
	std::cin >> a >> b;
	int g = gcd(a, b);
	a /= g;
	b /= g;
	int steps = 0;
	for (int i : {2, 3, 5}) {
		while (a%i == 0) {
			a /= i;
			++steps;
		}
		while (b%i == 0) {
			b /= i;
			++steps;
		}
	}
	std::cout << (a == b ? steps : -1);
	return 0;
}