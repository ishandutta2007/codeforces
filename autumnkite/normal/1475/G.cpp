#include <bits/stdc++.h>

const int N = 200005;

int n, m;
int a[N];
int c[N];
int f[N];

void solve() {
	std::cin >> n;
	m = 0;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		c[i] = 0;
		f[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		++c[a[i]];
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (c[i]) {
			f[i] = std::max(f[i], c[i]);
			for (int j = i + i; j <= m; j += i) {
				if (c[j]) {
					f[j] = std::max(f[j], f[i] + c[j]);
				}
			}
			ans = std::max(ans, f[i]);
		}
	}
	std::cout << n - ans << "\n";
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