#include <bits/stdc++.h>

const int N = 55;

int n, a[N], m, c[N];

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		++c[a[i]];
		m = std::max(m, a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		if (1 <= c[i] && c[i] <= n / 2) {
			std::cout << "Alice\n";
			return 0;
		}
		if (c[i] > n / 2) {
			std::cout << "Bob\n";
			return 0;
		}
	}
}