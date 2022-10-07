#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int n, m;

void solve() {
	std::cin >> n >> m;
	int mn = INF, sum = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x;
			std::cin >> x;
			if (x < 0) {
				x = -x;
				++cnt;
			}
			mn = std::min(mn, x);
			sum += x;
		}
	}
	if (cnt & 1) {
		std::cout << sum - 2 * mn << "\n";
	} else {
		std::cout << sum << "\n";
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