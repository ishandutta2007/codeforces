#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		sum += v;
	}
	if (sum >= n) {
		std::cout << sum - n << "\n";
	} else {
		std::cout << 1 << "\n";
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