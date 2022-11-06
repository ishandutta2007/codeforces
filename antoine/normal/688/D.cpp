#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <map>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
	return (long long)a * b / gcd(a, b);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	int l = 1;
	for (; n > 0; --n) {
		int c;
		std::cin >> c;
		c = gcd(c, k);
		l = lcm(l, c);
	}
	std::cout << (l == k ? "Yes" : "No");
	return 0;
}