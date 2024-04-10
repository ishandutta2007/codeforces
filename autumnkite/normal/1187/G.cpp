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

const int INF = 0x3f3f3f3f;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, k, c, d;
	std::cin >> n >> m >> k >> c >> d;
	MCMF_Network<int, int> G(n * (n + k + 1) + 1);
	int S = n * (n + k + 1);
	for (int i = 0; i < k; ++i) {
		int x;
		std::cin >> x;
		--x;
		G.add_edge(S, x, 1, 0);
	}
	std::vector<std::pair<int, int>> E;
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E.emplace_back(u, v);
		E.emplace_back(v, u);
	}
	for (int t = 0; t < n + k; ++t) {
		G.add_edge(t * n, (t + 1) * n, INF, 0);
		for (int i = 1; i < n; ++i) {
			G.add_edge(t * n + i, (t + 1) * n + i, INF, c);
		}
		for (auto [u, v] : E) {
			for (int i = 0; i < k; ++i) {
				G.add_edge(t * n + u, (t + 1) * n + v, 1, d * (i + 1) * (i + 1) - d * i * i + c);
			}
		}
	}
	int flow, cost;
	G.slope(S, (n + k) * n, flow, cost);
	std::cout << cost << "\n";
}