#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	int v;
	std::cin >> v;
	for (int i = 1; i < n; ++i) {
		int x;
		std::cin >> x;
		v &= x;
	}
	std::cout << v << "\n";
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