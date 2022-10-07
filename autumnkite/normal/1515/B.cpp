#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	while (n % 4 == 0) {
		n /= 2;
	}
	if (n & 1) {
		std::cout << "NO\n";
	} else {
		n /= 2;
		int t = sqrt(n) + 0.5;
		if (t * t == n) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
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