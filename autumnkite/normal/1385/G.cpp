#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
		--b[i];
	}
	std::vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		E[a[i]].emplace_back(b[i], i);
		E[b[i]].emplace_back(a[i], i);
		++d[a[i]], --d[b[i]];
	}
	for (int i = 0; i < n; ++i) {
		if ((int)E[i].size() != 2) {
			std::cout << -1 << "\n";
			return;
		}
		d[i] /= 2;
	}
	
	std::vector<bool> vis(n);
	std::vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (!vis[i] && d[i]) {
			int lst = E[i][1].first;
			int now = 0;
			std::array<std::vector<int>, 2> id;
			for (int j = i; !vis[j]; j = E[j][0].first) {
				E[j].erase(std::find_if(E[j].begin(), E[j].end(), [&](std::pair<int, int> x) {
					return x.first == lst;
				}));
				vis[j] = true;
				lst = j;
				if (d[j]) {
					now ^= 1;
				}
				id[now].push_back(E[j][0].second);
			}
			if (now) {
				std::cout << -1 << "\n";
				return;
			}
			if (id[0].size() < id[1].size()) {
				ans.insert(ans.end(), id[0].begin(), id[0].end());
			} else {
				ans.insert(ans.end(), id[1].begin(), id[1].end());
			}
		}
	}
	std::cout << ans.size() << "\n";
	for (int x : ans) {
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