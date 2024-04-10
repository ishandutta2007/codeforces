#include <bits/stdc++.h>

int n;

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cout << 1 << " \n"[i == n];
	}
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