#include <bits/stdc++.h>

const int INF = 1e9;

template <class Flow>
class maxflow_network {
	const Flow INF = std::numeric_limits<Flow>::max();

	struct Edge {
		int u, v;
		Flow c;

		Edge() : u(0), v(0), c(0) {}
		Edge(int _u, int _v, Flow _c) : u(_u), v(_v), c(_c) {}
	};

	int n, S, T;
	std::vector<Edge> edge;
	std::vector<std::vector<int>> E;

	std::vector<int> dep;

	bool bfs() {
		std::fill(dep.begin(), dep.end(), -1);
		std::vector<int> Q;
		dep[S] = 0;
		Q.push_back(S);
		if (S == T) {
			return true;
		}
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			for (int id : E[u]) {
				int v = edge[id].v;
				Flow c = edge[id].c;
				if (c > 0 && dep[v] == -1) {
					dep[v] = dep[u] + 1;
					Q.push_back(v);
					if (v == T) {
						return true;
					}
				}
			}
		}
		return false;
	}

	std::vector<int> iter;

	Flow dfs(int u, Flow flow) {
		if (u == T || !flow) {
			return flow;
		}
		Flow res = 0;
		for (int &i = iter[u]; i < (int)E[u].size(); ++i) {
			int id = E[u][i];
			int v = edge[id].v;
			Flow c = edge[id].c;
			if (dep[v] == dep[u] + 1) {
				Flow tmp = dfs(v, std::min(flow, c));
				if (tmp) {
					edge[id].c -= tmp, edge[id ^ 1].c += tmp;
					res += tmp, flow -= tmp;
					if (!flow) {
						break;
					}
				}
			}
		}
		if (!res) {
			dep[u] = -1;
		}
		return res;
	}

public:
	maxflow_network(int _n) : n(_n), E(_n), dep(_n), iter(_n) {}

	void add_edge(int u, int v, Flow c) {
		E[u].push_back(edge.size()), edge.emplace_back(u, v, c);
		E[v].push_back(edge.size()), edge.emplace_back(v, u, 0);
	}

	int edge_size() {
		return edge.size() >> 1;
	}

	void slope(int _S, int _T, Flow &flow) {
		S = _S, T = _T;
		flow = 0;
		while (bfs()) {
			std::fill(iter.begin(), iter.end(), 0);
			flow += dfs(S, INF);
		}
	}

	Flow edge_flow(int id) {
		return edge[id << 1 | 1].c;
	}

	std::vector<int> min_cut() {
		std::vector<bool> vis(n);
		std::vector<int> Q;
		vis[S] = true;
		Q.push_back(S);
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			for (int id : E[u]) {
				int v = edge[id].v;
				Flow c = edge[id].c;
				if (c > 0 && !vis[v]) {
					vis[v] = true;
					Q.push_back(v);
				}
			}
		}
		std::vector<int> res;
		for (int u : Q) {
			for (int id : E[u]) {
				int v = edge[id].v;
				if (!(id & 1) && !vis[v]) {
					res.push_back(id >> 1);
				}
			}
		}
		return res;
	}
};


template <class Flow>
class limited_maxflow_network {
	const Flow INF_flow = std::numeric_limits<Flow>::max();

	struct Edge {
		int u, v;
		Flow lower, upper;

		Edge(int _u, int _v, Flow _lower, Flow _upper) : u(_u), v(_v), lower(_lower), upper(_upper) {}
	};

	int n, S, T;
	std::vector<Edge> edge;
	maxflow_network<Flow> G;

public:
	limited_maxflow_network(int _n) : n(_n), G(_n + 2) {}

	void add_edge(int u, int v, Flow lower, Flow upper) {
		edge.emplace_back(u, v, lower, upper);
	}

	bool slope(int _S, int _T, Flow &flow) {
		S = _S, T = _T;
		flow = 0;
		std::vector<Flow> d(n);
		for (auto e : edge) {
			if (e.upper < e.lower) {
				return false;
			}
			d[e.u] -= e.lower;
			d[e.v] += e.lower;
			G.add_edge(e.u, e.v, e.upper - e.lower);
		}
		G.add_edge(T, S, INF_flow);
		Flow full = 0;
		for (int i = 0; i < n; ++i) {
			if (d[i] > 0) {
				G.add_edge(n, i, d[i]);
				full += d[i];
			} else if (d[i] < 0) {
				G.add_edge(i, n + 1, -d[i]);
			}
		}
		Flow __flow;
		G.slope(n, n + 1, __flow);
		if (__flow < full) {
			return false;
		}
		G.slope(S, T, flow);
		return true;
	}

	int edge_flow(int id) {
		return edge[id].lower + G.edge_flow(id);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	--s, --t;
	std::vector<std::tuple<int, int, int>> edge;
	for (int i = 0; i < m; ++i) {
		int u, v, g;
		std::cin >> u >> v >> g;
		--u, --v;
		edge.emplace_back(u, v, g);
	}

	maxflow_network<int> G(n);
	for (auto [u, v, g] : edge) {
		if (g == 0) {
			G.add_edge(u, v, INF);
		} else {
			G.add_edge(u, v, 1);
		}
	}
	for (auto [u, v, g] : edge) {
		if (g) {
			G.add_edge(v, u, INF);
		}
	}
	int Gflow;
	G.slope(s, t, Gflow);

	limited_maxflow_network<int> H(n);
	std::vector<int> cut = G.min_cut();
	std::vector<bool> in_cut(m);
	for (int x : cut) {
		in_cut[x] = true;
	}
	for (int i = 0; i < m; ++i) {
		auto [u, v, g] = edge[i];
		if (in_cut[i]) {
			H.add_edge(u, v, 1, m);
		} else if (g) {
			H.add_edge(u, v, 1, INF);
		} else {
			H.add_edge(u, v, 0, 0);
		}
	}
	int Hflow;
	H.slope(s, t, Hflow);

	std::cout << cut.size() << "\n";
	for (int i = 0; i < m; ++i) {
		if (in_cut[i]) {
			std::cout << H.edge_flow(i) << " " << H.edge_flow(i) << "\n";
		} else {
			std::cout << H.edge_flow(i) << " " << INF << "\n";
		}
	}
}