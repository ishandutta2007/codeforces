#include <bits/stdc++.h>

using namespace std;

template <class T> struct BellmanFord {
	const T INF = std::numeric_limits<T>::max();
	int n; 
	std::vector<std::vector<int>> adj;
	std::vector<std::pair<std::pair<int, int>, T>> edges;
	std::vector<T> dist;

	void init(int n_) {
		n = n_;
		adj.assign(n, std::vector<int>());
		edges.clear();
		dist.assign(n, 0);
	}

	void ae(int u, int v, T w) {
		adj[u].push_back(v);
		edges.push_back({{u, v}, w});
	}   

	void gen_bad(int x) {
		if (dist[x] == -INF)
			return;
		dist[x] = -INF;
		for (auto& nxt : adj[x])
			gen_bad(nxt);
	}

	void gen(int src) {
		for (int i = 0; i < n; i++) 
			dist[i] = INF;
		dist[src] = 0;
		for (int i = 0; i < n; i++)
			for (auto& e : edges) 
				if (dist[e.first.first] < INF)
					dist[e.first.second] = std::min(dist[e.first.second], dist[e.first.first] + e.second);
		for (auto& e : edges) 
			if (dist[e.first.first] < INF && dist[e.first.second] > dist[e.first.first] + e.second)
			gen_bad(e.first.second);
	}
	
	std::vector<int> negative_cycle(int src = 0) {
		for (int i = 0; i < n; i++)
			dist[src] = INF;
		dist[src] = 0;
		std::vector<int> pre(n);
		for (auto& e : edges) 
			if (e.first.first == e.first.second && e.second < 0) 
				return {e.first.first};
		for (int i = 0; i < n; i++) 
			for (auto& e : edges) 
				if (dist[e.first.first] < INF)
					if (dist[e.first.second] > dist[e.first.first] + e.second) {
						dist[e.first.second] = dist[e.first.first] + e.second;
						pre[e.first.second] = e.first.first;
					}
		for (auto& e : edges) 
			if (dist[e.first.first] < INF)
				if (dist[e.first.second] > dist[e.first.first] + e.second) {
					int x = e.first.second;
					for (int i = 0; i < n; i++)
						x = pre[x];
					std::vector<int> cycle;
					for (int v = x; v != x || cycle.empty(); v = pre[v])
						cycle.push_back(v);
					reverse(cycle.begin(), cycle.end());
					return cycle;
				}
		return {};
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int INF = 1e9;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, INF));
	vector<vector<int>> adj(n);
	BellmanFord<int> bf;
	bf.init(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if (w) {
			bf.ae(u, v, -1);
			g[u][v] = 1;
			g[v][u] = -1;
		} else {
			bf.ae(u, v, 1);
			bf.ae(v, u, 1);
			g[u][v] = g[v][u] = 1;
		}
	}
	vector<bool> color(n);
	vector<bool> vis(n);
	bool bipartite = true;	
	function<void(int)> dfs = [&](int u) {
		vis[u] = true;
		for (int v : adj[u]) {
			if (vis[v]) {
				if (color[u] == color[v]) {
					bipartite = false;
				}
			} else {
				color[v] = !color[u];
				dfs(v);
			}
		}
	};
	dfs(0);
	if (!bipartite || !bf.negative_cycle().empty()) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		for (int i = 0; i < n; ++i) {
			g[i][i] = 0;
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		array<int, 2> diam = {0, 0};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[diam[0]][diam[1]] < g[i][j]) {
					diam = {i, j};
				}
			}
		}
		cout << g[diam[0]][diam[1]] << '\n';
		for (int i = 0; i < n; ++i) {
			cout << g[diam[0]][i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}