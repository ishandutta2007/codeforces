#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		a[i] = std::min(a[i], n);
	}
	std::vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
		--b[i];
	}
	int q;
	std::cin >> q;
	std::vector<int> id(q);
	std::vector<bool> del(n);
	for (int i = 0; i < q; ++i) {
		std::cin >> id[i];
		--id[i];
		del[id[i]] = true;
	}

	std::vector<std::vector<int>> E(n + 1);
	for (int i = 0; i < n; ++i) {
		if (!del[i]) {
			E[a[i]].push_back(b[i]);
		}
	}
	std::vector<int> match(m, -1);
	std::vector<bool> vis(m);

	std::function<bool(int)> find = [&](int u) {
		for (int v : E[u]) {
			if (!vis[v]) {
				vis[v] = true;
				if (match[v] == -1 || find(match[v])) {
					match[v] = u;
					return true;
				}
			}
		}
		return false;
	};

	std::vector<int> ans(q);
	int t = 0;
	for (int i = q - 1; i >= 0; --i) {
		while (std::fill(vis.begin(), vis.end(), false), find(t)) {
			++t;
		}
		ans[i] = t;
		E[a[id[i]]].push_back(b[id[i]]);
	}
	for (int v : ans) {
		std::cout << v << "\n";
	}
}