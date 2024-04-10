#include <bits/stdc++.h>

int n;

void solve() {
	std::cin >> n;
	for (int i = 0; i * 2020 <= n; ++i) {
		if ((n - i * 2020) % 2021 == 0) {
			std::cout << "YES\n";
			return;
		}
	}
	std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}