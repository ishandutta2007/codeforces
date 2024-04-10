#include <bits/stdc++.h>

const int N = 200005;

int n, a[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	int p = std::max_element(a + 1, a + 1 + n) - a;
	for (int i = 1; i <= p - 1; ++i) {
		if (a[i] > a[i + 1]) {
			std::cout << "NO\n";
			return;
		}
	}
	for (int i = p + 1; i <= n; ++i) {
		if (a[i] > a[i - 1]) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
}