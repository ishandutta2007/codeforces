#include <bits/stdc++.h>

class disjoint_set {
	std::vector<int> fa, sz;

public:
	disjoint_set(int n) : fa(n), sz(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
			sz[i] = 1;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	int size(int x) {
		return sz[find(x)];
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		sz[x] += sz[y];
		return true;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::tuple<int, int, int, int>> edge;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		edge.emplace_back(w, u, v, i);
	}
	std::sort(edge.begin(), edge.end());

	std::vector<long long> s(n - 1);
	disjoint_set D(n);
	std::vector<std::vector<std::pair<int, int>>> E(n);
	std::vector<int> sz(n);
	for (int i = 0, j = 0; i < n - 1; i = j) {
		j = i;
		std::vector<int> nd;
		while (j < n - 1 && std::get<0>(edge[j]) == std::get<0>(edge[i])) {
			auto [w, u, v, id] = edge[j];
			u = D.find(u), v = D.find(v);
			E[u].emplace_back(v, id);
			E[v].emplace_back(u, id);
			nd.push_back(u);
			nd.push_back(v);
			++j;
		}
		std::function<void(int, int)> dfs1 = [&](int u, int fa) {
			sz[u] = D.size(u);
			for (auto [v, id] : E[u]) {
				if (v != fa) {
					dfs1(v, u);
					sz[u] += sz[v];
				}
			}
		};
		std::function<void(int, int, int)> dfs2 = [&](int u, int fa, int Sz) {
			for (auto [v, id] : E[u]) {
				if (v != fa) {
					s[id] = 2ll * sz[v] * (Sz - sz[v]);
					dfs2(v, u, Sz);
				}
			}
		};
		std::vector<int> rt;
		for (int x : nd) {
			if (!sz[x]) {
				dfs1(x, -1);
				rt.emplace_back(x);
			}
		}
		for (int x : rt) {
			dfs2(x, -1, sz[x]);
		}
		for (int x : nd) {
			sz[x] = 0;
			E[x].clear();
		}
		for (int k = i; k < j; ++k) {
			auto [w, u, v, id] = edge[k];
			D.merge(u, v);
		}
	}

	long long mx = *std::max_element(s.begin(), s.end());
	std::vector<int> ans;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == mx) {
			ans.push_back(i);
		}
	}

	std::cout << mx << " " << ans.size() << "\n";
	for (int x : ans) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
}