#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n - 1), b(n - 1);
	std::vector<int> v;
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> a[i];
		v.push_back(a[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> b[i];
		v.push_back(b[i]);
	}
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());

	std::vector<std::vector<std::pair<int, int>>> E(v.size());
	for (int i = 0; i < n - 1; ++i) {
		a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		b[i] = std::lower_bound(v.begin(), v.end(), b[i]) - v.begin();
		if (a[i] > b[i]) {
			std::cout << -1 << "\n";
			return 0;
		}
		E[a[i]].emplace_back(b[i], i);
		E[b[i]].emplace_back(a[i], i);
	}
	int cnt = 0;
	int st = 0;
	for (int i = 0; i < (int)v.size(); ++i) {
		if (E[i].size() & 1) {
			++cnt;
			st = i;
		}
	}
	if (cnt > 2) {
		std::cout << -1 << "\n";
		return 0;
	}

	std::vector<bool> vis(n - 1);
	std::vector<int> cur(v.size());
	std::vector<int> ans;
	std::function<void(int)> dfs = [&](int u) {
		while (cur[u] < (int)E[u].size()) {
			auto [v, id] = E[u][cur[u]++];
			if (!vis[id]) {
				vis[id] = true;
				dfs(v);
			}
		}
		ans.push_back(u);
	};
	dfs(st);
	if ((int)ans.size() < n) {
		std::cout << -1 << "\n";
		return 0;
	}
	for (int x : ans) {
		std::cout << v[x] << " ";
	}
	std::cout << "\n";
}