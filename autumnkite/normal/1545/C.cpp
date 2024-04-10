#include <bits/stdc++.h>

const int P = 998244353;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a(2 * n, std::vector<int>(n));
	for (auto &p : a) {
		for (int i = 0; i < n; ++i) {
			std::cin >> p[i];
			--p[i];
		}
	}
	std::vector<bool> vis(2 * n);
	std::vector<int> S(n);
	int ans = 1;
	for (int k = 0; k < n; ++k) {
		S[k] = -1;
		for (int i = 0; i < n && S[k] == -1; ++i) {
			std::vector<int> c(n), id(n);
			for (int j = 0; j < 2 * n; ++j) {
				if (!vis[j]) {
					++c[a[j][i]];
					id[a[j][i]] = j;
				}
			}
			for (int j = 0; j < n && S[k] == -1; ++j) {
				if (c[j] == 1) {
					S[k] = id[j];
				}
			}
		}
		if (S[k] == -1) {
			ans = 2ll * ans % P;
			for (int i = 0; i < 2 * n && S[k] == -1; ++i) {
				if (!vis[i]) {
					S[k] = i;
				}
			}
		}
		vis[S[k]] = true;
		for (int i = 0; i < 2 * n; ++i) {
			for (int j = 0; j < n && !vis[i]; ++j) {
				vis[i] = a[S[k]][j] == a[i][j];
			}
		}
	}
	std::cout << ans << "\n";
	for (int x : S) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
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