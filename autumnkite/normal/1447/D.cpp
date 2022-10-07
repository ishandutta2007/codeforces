#include <bits/stdc++.h>

const int N = 5005;

int n, m;
char a[N], b[N];
int f[N][N];

void solve() {
	std::cin >> n >> m;
	std::cin >> (a + 1);
	std::cin >> (b + 1);
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			f[i][j] = 0;
			if (i && j && a[i] == b[j]) {
				f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 2);
			}
			if (i) {
				f[i][j] = std::max(f[i][j], f[i - 1][j] - 1);
			}
			if (j) {
				f[i][j] = std::max(f[i][j], f[i][j - 1] - 1);
			}
			ans = std::max(ans, f[i][j]);
		}
	}
	std::cout << ans << "\n";
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