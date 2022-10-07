#include <bits/stdc++.h>

int n;

void solve() {
	std::cin >> n;
	if (n & 1) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				std::cout << ((j - i) & 1 ? 1 : -1) << " ";
			}
		}
		std::cout << "\n";
	} else {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (j == i + 1 && i & 1) {
					std::cout << 0 << " ";
				} else {
					std::cout << ((j - i) & 1 ? 1 : -1) << " ";
				}
			}
		}
		std::cout << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}