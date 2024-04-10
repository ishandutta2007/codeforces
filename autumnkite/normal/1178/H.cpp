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

const int N = 5000;

int n;
int a[N * 2], b[N * 2];
int id[N * 2];

bool check(int T) {
	for (int i = 0; i < n * 2; ++i) {
		id[i] = i;
	}
	std::sort(id, id + 2 * n, [&](int x, int y) {
		return b[x] < b[y] || (b[x] == b[y] && a[x] > a[y]);
	});
	long long mx = 0;
	std::vector<long long> have, need;
	for (int i = 0; i < 2 * n; ++i) {
		long long v = 1ll * a[id[i]] * T + b[id[i]];
		mx = std::max(mx, v);
		if (id[i] < n) {
			have.push_back(mx);
		} else {
			need.push_back(v);
		}
	}
	std::sort(need.begin(), need.end());
	for (int i = 0; i < n; ++i) {
		if (have[i] < need[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 0; i < n * 2; ++i) {
		std::cin >> a[i] >> b[i];
	}

	int l = 0, r = 1000000000, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (ans == -1) {
		std::cout << -1 << "\n";
		return 0;
	}

	MCMF_Network<int, int> G(6 * n + 2);
	for (int i = 0; i < 2 * n; ++i) {
		id[i] = i;
	}
	std::sort(id, id + n, [&](int x, int y) {
		return b[x] < b[y];// || (b[x] == b[y] && a[x] > a[y]);
	});
	std::sort(id + n, id + 2 * n, [&](int x, int y) {
		long long vx = 1ll * a[x] * ans + b[x];
		long long vy = 1ll * a[y] * ans + b[y];
		return vx < vy || (vx == vy && x > y);
	});
	for (int i = 0; i < n; ++i) {
		G.add_edge(6 * n, i, 1, 0);
		G.add_edge(i, 2 * n + i, n, 1);
		G.add_edge(i, 4 * n + i, n, 0);
		G.add_edge(n + i, 6 * n + 1, 1, 0);
		G.add_edge(2 * n + n + i, n + i, n, 1);
		G.add_edge(4 * n + n + i, n + i, n, 0);
	}
	for (int i = 1; i < n; ++i) {
		G.add_edge(2 * n + id[i], 2 * n + id[i - 1], n, 0);
		G.add_edge(2 * n + id[n + i], 2 * n + id[n + i - 1], n, 0);
	}
	for (int i = 0; i < 2 * n; ++i) {
		int p1 = std::lower_bound(id, id + n, i, [&](int x, int y) {
			return b[x] < b[y];
		}) - id;
		int p2 = std::upper_bound(id + n, id + 2 * n, i, [&](int x, int y) {
			return 1ll * a[x] * ans + b[x] < 1ll * a[y] * ans + b[y];
		}) - id - 1;
		if (p1 < n) {
			G.add_edge(2 * n + id[p1], 4 * n + i, n, 0);
		}
		if (p2 >= n) {
			G.add_edge(4 * n + i, 2 * n + id[p2], n, 0);
		}
	}
	int flow, cost;
	G.slope(6 * n, 6 * n + 1, flow, cost);
	std::cout << ans << " " << cost << "\n";

	std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
}