#include <bits/stdc++.h>

int n, k;

void solve() {
	std::cin >> n >> k;
	if (n & 1) {
		int x = (k - 1) % (n - 1) + 1;
		if (x > n / 2) {
			++x;
		}
		int p = (k - 1) / (n - 1) % n;
		std::cout << (x + p - 1) % n + 1 << "\n";
	} else {
		std::cout << (k - 1) % n + 1 << "\n";
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