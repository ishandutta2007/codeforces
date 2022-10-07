#include <bits/stdc++.h>

class tree {
	std::vector<std::vector<int>> E;
	std::vector<int> fa, dep, sz, son;
	std::vector<std::vector<int>> chain;

	void dfs(int u) {
		sz[u] = 1;
		son[u] = -1;
		for (int v : E[u]) {
			if (v != fa[u]) {
				fa[v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
				sz[u] += sz[v];
				if (son[u] == -1 || sz[v] > sz[son[u]]) {
					son[u] = v;
				}
			}
		}
	}

	void dfs(int u, int tp) {
		chain[tp].push_back(u);
		if (son[u] != -1) {
			dfs(son[u], tp);
		}
		for (int v : E[u]) {
			if (v != fa[u] && v != son[u]) {
				dfs(v, v);
			}
		}
	}

public:
	tree(int n) : E(n), fa(n), dep(n), sz(n), son(n), chain(n) {}

	void add_edge(int u, int v) {
		E[u].push_back(v);
		E[v].push_back(u);
	}

	template<typename _Dist, typename _Next>
	int work(_Dist dis, _Next nxt) {
		fa[0] = -1;
		dep[0] = 0;
		dfs(0);
		dfs(0, 0);
		int D = dis(0);
		int u = 0;
		while (D - dep[u] > 0) {
			int v = chain[u].back();
			int t = dis(v);
			int z = chain[u][(dep[v] + D - t) / 2 - dep[u]];
			if (dep[z] == D) {
				u = z;
				break;
			}
			u = nxt(z);
		}
		return u;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	tree T(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		T.add_edge(u, v);
	}
	int t = T.work([&](int x) {
		std::cout << "d " << x + 1 << std::endl;
		int res;
		std::cin >> res;
		return res;
	}, [&](int x) {
		std::cout << "s " << x + 1 << std::endl;
		int res;
		std::cin >> res;
		return res - 1;
	});
	std::cout << "! " << t + 1 << "\n";
}