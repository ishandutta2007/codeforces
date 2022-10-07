#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	a[n] = 1;
	for (int i = 0; i <= n; ++i) {
		if (a[i] == 1) {
			for (int j = 0; j < i; ++j) {
				std::cout << j + 1 << " ";
			}
			std::cout << n + 1 << " ";
			for (int j = i; j < n; ++j) {
				std::cout << j + 1 << " ";
			}
			std::cout << "\n";
			return;
		}
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