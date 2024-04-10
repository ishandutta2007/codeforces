#include <bits/stdc++.h>

int n;
long long k, a[200005];

void solve() {
	std::cin >> n >> k;
	long long g = 0;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		g = std::__gcd(g, a[i] - a[i - 1]);
	}
	for (int i = 1; i <= n; ++i) {
		if ((a[i] - k) % g == 0) {
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