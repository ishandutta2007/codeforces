#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <map>


int gcd(int a, int b) {
	for (;;) {
		if (b == 0) return a;
		a %= b;
		if (a == 0) return b;
		b %= a;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, g, max;
	std::cin >> n >> g;
	max = g;
	for (int i = 1; i < n; ++i) {
		int a;
		std::cin >> a;
		g = gcd(g, a);
		max = std::max(max, a);
	}
	if ((max / g - n) & 1)
		std::cout << "Alice";
	else
		std::cout << "Bob";
	return 0;
}