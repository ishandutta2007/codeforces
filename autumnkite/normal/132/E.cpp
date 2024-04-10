#include <bits/stdc++.h>

template <class Flow, class Cost>
class MCMF_Network {
	const Flow INF_flow = std::numeric_limits<Flow>::max();
	const Cost INF_cost = std::numeric_limits<Cost>::max();

	struct Edge {
		int u, v;
		Flow flow;
		Cost cost;
	};

	int n, S, T;
	std::vector<Edge> edge;
	std::vector<std::vector<int>> E;

	std::vector<Cost> dis;

	bool SPFA() {
		std::fill(dis.begin(), dis.end(), INF_cost);
		std::vector<bool> vis(n);
		std::vector<int> Q;
		dis[S] = 0;
		vis[S] = true;
		Q.push_back(S);
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			vis[u] = false;
			for (int id : E[u]) {
				int v = edge[id].v;
				Flow flow = edge[id].flow;
				Cost cost = edge[id].cost;
				if (flow > 0 && dis[u] + cost < dis[v]) {
					dis[v] = dis[u] + cost;
					vis[v] = true;
					Q.push_back(v);
				}
			}
		}
		return dis[T] < INF_cost;
	}

	std::vector<int> iter;
	std::vector<bool> vis;

	Flow dfs(int u, Flow all) {
		if (u == T || !all) {
			return all;
		}
		vis[u] = true;
		Flow res = 0;
		for (int &i = iter[u]; i < (int)E[u].size(); ++i) {
			int id = E[u][i];
			int v = edge[id].v;
			Flow flow = edge[id].flow;
			Cost cost = edge[id].cost;
			if (!vis[v] && dis[v] == dis[u] + cost) {
				Flow tmp = dfs(v, std::min(all, flow));
				if (tmp) {
					edge[id].flow -= tmp, edge[id ^ 1].flow += tmp;
					res += tmp, all -= tmp;
					if (!all) {
						break;
					}
				}
			}
		}
		vis[u] = false;
		if (!res) {
			dis[u] = INF_cost;
		}
		return res;
	}

public:
	MCMF_Network(int _n) : n(_n), E(_n), dis(_n), iter(_n), vis(_n) {}

	void add_edge(int u, int v, Flow cap, Cost cost) {
		E[u].push_back(edge.size()), edge.push_back({u, v, cap, cost});
		E[v].push_back(edge.size()), edge.push_back({v, u, 0, -cost});
	}

	void slope(int _S, int _T, Flow &flow, Cost &cost) {
		std::fill(vis.begin(), vis.end(), false);
		S = _S, T = _T;
		flow = 0;
		cost = 0;
		while (SPFA()) {
			std::fill(iter.begin(), iter.end(), 0);
			Flow tmp = dfs(S, INF_flow);
			flow += tmp;
			cost += tmp * dis[T];
		}
	}

	Flow edge_flow(int id) {
		return edge[id << 1 | 1].flow;
	}
};

template <class Flow, class Cost>
class ST_LU_MCAF_Network {
	const Flow INF_flow = std::numeric_limits<Flow>::max();
	const Cost INF_cost = std::numeric_limits<Cost>::max();

	struct Edge {
		int u, v;
		Flow lower, upper;
		Cost cost;
	};

	int n, S, T;
	std::vector<Edge> edge;
	MCMF_Network<Flow, Cost> G;

public:
	ST_LU_MCAF_Network(int _n) : n(_n), G(_n + 2) {}

	void add_edge(int u, int v, Flow lower, Flow upper, Cost cost) {
		edge.push_back({u, v, lower, upper, cost});
	}

	bool slope(int _S, int _T, Flow &flow, Cost &cost) {
		S = _S, T = _T;
		std::vector<int> d(n);
		Cost tmp = 0;
		for (auto e : edge) {
			if (e.upper < e.lower) {
				return false;
			}
			d[e.u] -= e.lower;
			d[e.v] += e.lower;
			G.add_edge(e.u, e.v, e.upper - e.lower, e.cost);
			tmp += e.cost * e.lower;
		}
		G.add_edge(T, S, INF_flow, 0);
		Flow full = 0;
		for (int i = 0; i < n; ++i) {
			if (d[i] > 0) {
				G.add_edge(n, i, d[i], 0);
				full += d[i];
			} else if (d[i] < 0) {
				G.add_edge(i, n + 1, -d[i], 0);
			}
		}
		Flow __flow;
		Cost __cost;
		G.slope(n, n + 1, __flow, __cost);
		if (__flow < full) {
			return false;
		}
		flow = G.edge_flow(edge.size());
		cost = tmp + __cost;
		return true;
	}

	int edge_flow(int id) {
		return edge[id].lower + G.edge_flow(id);
	}
};

const int N = 255, M = 30;

int n, m;
int a[N];

int p[N];
int cnt, col[N];
int val[M];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	ST_LU_MCAF_Network<int, int> G(2 * (n + 2));
	for (int i = 0; i < n; ++i) {
		G.add_edge(i * 2, i * 2 + 1, 1, 1, 0);
	}
	G.add_edge(n * 2, n * 2 + 1, 0, m, 0);
	G.add_edge((n + 1) * 2, (n + 1) * 2 + 1, 0, m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			G.add_edge(i * 2 + 1, j * 2, 0, 1, a[i] == a[j] ? 0 : __builtin_popcount(a[j]));
		}
	}
	for (int i = 0; i < n; ++i) {
		G.add_edge(n * 2 + 1, i * 2, 0, 1, __builtin_popcount(a[i]));
		G.add_edge(i * 2 + 1, (n + 1) * 2, 0, 1, 0);
	}
	int flow, cost;
	assert(G.slope(n * 2, (n + 1) * 2 + 1, flow, cost));

	int idx = n + 2;
	for (int i = 0; i < n; ++i) {
		p[i] = -1;
		for (int j = i + 1; j < n; ++j) {
			if (G.edge_flow(idx)) {
				p[i] = j;
			}
			++idx;
		}
	}
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (G.edge_flow(idx)) {
			for (int x = i; x != -1; x = p[x]) {
				col[x] = cnt;
			}
			++cnt;
		}
		idx += 2;
	}
	std::vector<std::pair<int, int>> ops;
	for (int i = 0; i < n; ++i) {
		if (a[i] != val[col[i]]) {
			ops.emplace_back(col[i], a[i]);
			val[col[i]] = a[i];
		}
		ops.emplace_back(col[i], -1);
	}
	std::cout << ops.size() << " " << cost << "\n";
	for (auto v : ops) {
		if (v.second == -1) {
			std::cout << "print(" << char(v.first + 'a') << ")\n";
		} else {
			std::cout << char(v.first + 'a') << "=" << v.second << "\n";
		}
	}
}