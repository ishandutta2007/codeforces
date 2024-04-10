#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

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

int get_log2(int n) {
	int res = 1;
	while ((1 << res) < n) {
		++res;
	}
	return res;
}

class tree {
	const int n, LG;

	std::vector<std::vector<std::pair<int, long long>>> E;
	std::vector<int> dep;
	std::vector<std::vector<int>> fa;
	std::vector<std::vector<long long>> mx;

	void dfs(int u) {
		for (int i = 1; i < LG; ++i) {
			fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1];
			mx[u][i] = fa[u][i - 1] == -1 ? mx[u][i - 1] : std::max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
		}
		for (auto [v, w] : E[u]) {
			if (v != fa[u][0]) {
				dep[v] = dep[u] + 1;
				fa[v][0] = u;
				mx[v][0] = w;
				dfs(v);
			}
		}
	}

public:
	tree(int _n) : n(_n), LG(get_log2(n)), E(n), dep(n), fa(n, std::vector<int>(LG, -1)), mx(n, std::vector<long long>(LG, n)) {}

	void add_edge(int u, int v, long long w) {
		E[u].emplace_back(v, w);
		E[v].emplace_back(u, w);
	}

	void build() {
		dep[0] = 0;
		fa[0][0] = -1;
		mx[0][0] = 0;
		dfs(0);
	}

	long long query(int u, int v) {
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		long long ans = 0;
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[u][i] != -1 && dep[fa[u][i]] >= dep[v]) {
				ans = std::max(ans, mx[u][i]);
				u = fa[u][i];
			}
		}
		if (u == v) {
			return ans;
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[u][i] != fa[v][i]) {
				ans = std::max(ans, std::max(mx[u][i], mx[v][i]));
				u = fa[u][i], v = fa[v][i];
			}
		}
		ans = std::max(ans, std::max(mx[u][0], mx[v][0]));
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, k, q;
	std::cin >> n >> m >> k >> q;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		E[u].emplace_back(v, w);
		E[v].emplace_back(u, w);
	}

	std::vector<long long> dis(n, INF);
	std::vector<bool> vis(n, false);
	std::priority_queue<std::pair<long long, int>> Q;
	for (int i = 0; i < k; ++i) {
		dis[i] = 0;
		Q.emplace(0, i);
	}
	while (!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (auto [v, w] : E[u]) {
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				Q.emplace(-dis[v], v);
			}
		}
	}

	std::vector<std::tuple<long long, int, int>> edge;
	for (int u = 0; u < n; ++u) {
		for (auto [v, w] : E[u]) {
			if (u < v) {
				edge.emplace_back(dis[u] + dis[v] + w, u, v);
			}
		}
	}
	std::sort(edge.begin(), edge.end());
	tree T(n);
	DSU D(n);
	for (auto [w, u, v] : edge) {
		if (D.merge(u, v)) {
			T.add_edge(u, v, w);
		}
	}
	T.build();

	while (q--) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		std::cout << T.query(u, v) << "\n";
	}
}