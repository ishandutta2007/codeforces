#include <bits/stdc++.h>

int n, m, g;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	g = m;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		g = std::__gcd(g, x);
	}
	std::cout << m / g << "\n";
	for (int i = 0; i < m; i += g) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}