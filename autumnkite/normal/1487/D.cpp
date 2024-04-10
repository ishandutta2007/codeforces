#include <bits/stdc++.h>

int n;

void solve() {
	std::cin >> n;
	std::cout << ((int)(sqrt(2 * n - 1)) - 1) / 2 << "\n";
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