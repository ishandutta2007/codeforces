#include <bits/stdc++.h>

const int N = 200005;

int n, m, a[N], c[N], p[N << 1];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		++c[a[i]];
		m = std::max(m, a[i]);
	}
	int v = 0;
	for (int i = 1; i <= m; ++i) {
		if (!v || c[i] > c[v]) {
			v = i;
		}
	}

	int ans = 0;
	for (int x = 1; x <= m; ++x) {
		if (v != x) {
			for (int i = 0; i <= 2 * n; ++i) {
				p[i] = -1;
			}
			int now = n;
			p[now] = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == v) {
					++now;
				} else if (a[i] == x) {
					--now;
				}
				if (p[now] == -1) {
					p[now] = i;
				} else {
					ans = std::max(ans, i - p[now]);
				}
			}
		}
	}
	std::cout << ans << "\n";
}