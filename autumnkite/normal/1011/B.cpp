#include <bits/stdc++.h>

const int N = 105;

int n, m, mx, a[N], c[N];

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		std::cin >> a[i];
		++c[a[i]];
		mx = std::max(mx, a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		int s = 0;
		for (int j = 1; j <= mx; ++j) {
			s += c[j] / i;
		}
		if (s >= n) {
			ans = i;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T = 1;
//	std::cin >> T;
	while (T--) {
		solve();
	}
}