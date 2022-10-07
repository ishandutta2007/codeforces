#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n);
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
		--p[i];
		++c[(i + n - p[i]) % n];
	}
	std::vector<int> ans;
	for (int k = 0; k < n; ++k) {
		if (c[k] >= n - 2 * m) {
			int cnt = 0;
			std::vector<bool> vis(n);
			for (int i = 0; i < n; ++i) {
				if (!vis[i]) {
					++cnt;
					for (int j = i; !vis[j]; j = (p[j] + k) % n) {
						vis[j] = true;
					}
				}
			}
			if (cnt >= n - m) {
				ans.push_back(k);
			}
		}
	}
	std::cout << ans.size();
	for (int k : ans) {
		std::cout << " " << k;
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