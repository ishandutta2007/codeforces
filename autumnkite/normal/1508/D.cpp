#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> x(n), y(n), p(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i] >> p[i];
		--p[i];
	}

	std::vector<int> id;
	for (int i = 0; i < n; ++i) {
		if (p[i] != i) {
			id.push_back(i);
		}
	}
	if (id.empty()) {
		std::cout << 0 << "\n";
		return 0;
	}

	DSU D(n);
	std::vector<bool> vis(n);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			for (int j = i; !vis[j]; j = p[j]) {
				D.merge(j, i);
				vis[j] = true;
			}
		}
	}

	for (int i = 1; i < (int)id.size(); ++i) {
		if (y[id[i]] < y[id[0]]) {
			std::swap(id[i], id[0]);
		}
	}
	std::sort(id.begin() + 1, id.end(), [&](int i, int j) {
		return 1ll * (x[i] - x[id[0]]) * (y[j] - y[id[0]]) - 1ll * (y[i] - y[id[0]]) * (x[j] - x[id[0]]) > 0;
	});

	std::vector<std::pair<int, int>> ans;
	for (int i = 2; i < (int)id.size(); ++i) {
		if (D.merge(id[i - 1], id[i])) {
			ans.emplace_back(id[i - 1], id[i]);
			std::swap(p[id[i - 1]], p[id[i]]);
		}
	}
	for (int j = p[id[0]]; j != id[0]; j = p[j]) {
		ans.emplace_back(id[0], j);
	}
	std::cout << ans.size() << "\n";
	for (auto p : ans) {
		std::cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
}