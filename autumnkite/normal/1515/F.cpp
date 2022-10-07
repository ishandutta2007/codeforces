#include <bits/stdc++.h>

struct DSU {
	std::vector<int> fa;
	std::vector<long long> sum;
	std::vector<std::map<int, int>> E;

	DSU(std::vector<long long> a) : fa(a.size()), sum(a), E(a.size()) {
		for (int i = 0; i < (int)fa.size(); ++i) {
			fa[i] = i;
		}
	}

	void add(int x, int y, int id) {
		E[x].emplace(y, id);
		E[y].emplace(x, id);
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	int merge(int x, int y, long long w) {
		if (find(x) == find(y)) {
			E[find(x)].erase(y);
			E[find(y)].erase(x);
			return 1;
		}
		x = find(x), y = find(y);
		if (sum[x] + sum[y] < w) {
			return 0;
		}
		fa[y] = x;
		sum[x] += sum[y] - w;
		if (E[x].size() < E[y].size()) {
			E[x].swap(E[y]);
		}
		for (auto v : E[y]) {
			E[x].insert(v);
		}
		E[y].clear();
		return 2;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, x;
	std::cin >> n >> m >> x;
	std::vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	DSU D(a);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		D.add(u, v, i);
	}
	std::set<std::pair<long long, int>> Q;
	for (int i = 0; i < n; ++i) {
		Q.emplace(a[i], i);
	}
	std::vector<int> ans;
	while ((int)Q.size() > 1) {
		int u = (--Q.end())->second;
		Q.erase(--Q.end());
		if (D.E[u].empty()) {
			std::cout << "NO\n";
			return 0;
		}
		int v = D.E[u].begin()->first, id = D.E[u].begin()->second, tmp;
		Q.erase(std::make_pair(D.sum[D.find(v)], D.find(v)));
		if (!(tmp = D.merge(u, v, x))) {
			std::cout << "NO\n";
			return 0;
		}
		if (tmp == 2) {
			ans.push_back(id);
		}
		Q.emplace(D.sum[D.find(u)], D.find(u));
	}
	std::cout << "YES\n";
	for (int id : ans) {
		std::cout << id + 1 << "\n";
	}
}