#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a(n);
	std::vector<int> val;
	int m = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		a[i].resize(k);
		for (int &v : a[i]) {
			std::cin >> v;
			val.push_back(v);
		}
		m += k;
	}
	std::sort(val.begin(), val.end());
	val.erase(std::unique(val.begin(), val.end()), val.end());
	for (int i = 0; i < n; ++i) {
		for (int &v : a[i]) {
			v = std::lower_bound(val.begin(), val.end(), v) - val.begin();
		}
		std::sort(a[i].begin(), a[i].end());
	}

	const int B = 50;
	std::vector<std::map<int, int>> mp(val.size());
	for (int k = 0; k < n; ++k) {
		if ((int)a[k].size() > B) {
			std::vector<bool> vis(val.size());
			for (int v : a[k]) {
				vis[v] = true;
			}
			for (int i = 0; i < n; ++i) {
				if (i != k) {
					int cnt = 0;
					for (int v : a[i]) {
						if (vis[v]) {
							++cnt;
						}
					}
					if (cnt >= 2) {
						std::cout << k + 1 << " " << i + 1 << "\n";
						return;
					}
				}
			}
		} else {
			for (int i = 0; i < (int)a[k].size(); ++i) {
				for (int j = i + 1; j < (int)a[k].size(); ++j) {
					if (mp[a[k][i]].count(a[k][j])) {
						std::cout << mp[a[k][i]][a[k][j]] + 1 << " " << k + 1 << "\n";
						return;
					} else {
						mp[a[k][i]][a[k][j]] = k;
					}
				}
			}
		}
	}
	std::cout << -1 << "\n";
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