#include <bits/stdc++.h>

template<typename Flow, typename Cost>
class MC_Network {
	const Flow INF_flow = std::numeric_limits<Flow>::max();
	const Cost INF_cost = std::numeric_limits<Cost>::max();
	
	struct Edge {
		int u, v;
		Flow cap;
		Cost cost;
		
		Edge(int _u, int _v, Flow _cap, Cost _cost) : u(_u), v(_v), cap(_cap), cost(_cost) {}
	};
	
	int n, S, T;
	std::vector<Edge> edge;
	std::vector<std::vector<int>> E;
	
	std::vector<Cost> dis;
	
	bool SPFA() {
		dis = std::vector<Cost>(n, INF_cost);
		std::vector<bool> vis(n, false);
		std::vector<int> Q;
		dis[S] = 0;
		Q.push_back(S);
		vis[S] = true;
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			vis[u] = false;
			for (int id : E[u]) {
				int v = edge[id].v;
				Flow cap = edge[id].cap;
				Cost cost = edge[id].cost;
				if (cap && dis[v] > dis[u] + cost) {
					dis[v] = dis[u] + cost;
					if (!vis[v]) {
						Q.push_back(v);
						vis[v] = true;
					}
				}
			}
		}
		return dis[T] < 0;
	}

	std::vector<bool> vis;
	std::vector<int> hd;
	
	Flow dfs(int u, Flow flow) {
		if (u == T || !flow) {
			return flow;
		}
		vis[u] = true;
		Flow ans = 0;
		for (int &i = hd[u]; i < (int)E[u].size(); ++i) {
			int id = E[u][i];
			int v = edge[id].v;
			Flow cap = edge[id].cap, tmp;
			Cost cost = edge[id].cost;
			if (!vis[v] && dis[v] == dis[u] + cost && (tmp = dfs(v, std::min(flow, cap)))) {
				ans += tmp, flow -= tmp;
				edge[id].cap -= tmp, edge[id ^ 1].cap += tmp;
				if (!flow) {
					break;
				}
			}
		}
		vis[u] = false;
		if (!ans) {
			dis[u] = INF_cost;
		}
		return ans;
	}

public:
	MC_Network(int _n) : n(_n), E(n) {}

	void add_edge(int u, int v, Flow cap, Cost cost) {
		E[u].push_back(edge.size()), edge.emplace_back(u, v, cap, cost);
		E[v].push_back(edge.size()), edge.emplace_back(v, u, 0, -cost);
	}
	
	void slope(int _S, int _T, Flow &flow, Cost &cost) {
		S = _S, T = _T;
		flow = 0;
		cost = 0;
		while (SPFA()) {
			hd = std::vector<int>(n, 0);
			vis = std::vector<bool>(n, false);
			Flow tmp = dfs(S, INF_flow);
			flow += tmp;
			cost += tmp * dis[T];
		}
	}

	Flow edge_flow(int id) {
		return edge[id << 1 | 1].cap;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int d, n;
	std::cin >> d >> n;
	MC_Network<int, int> G(2 * (1 << d) + 1);
	const int INF = n * (d + 1) + 1;
	for (int S = 0; S < (1 << d); ++S) {
		for (int i = 0; i < d; ++i) {
			if (!(S >> i & 1)) {
				G.add_edge(S | (1 << d), S | (1 << i), INF, 1);
			}
		}
		G.add_edge(S | (1 << d), 1 << (d + 1), INF, 1);
	}
	for (int S = 0; S < (1 << d); ++S) {
		G.add_edge(S, S | (1 << d), INF, 0);
	}
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		int x = 0;
		for (int j = 0; j < d; ++j) {
			x |= (s[j] - '0') << j;
		}
		G.add_edge(x, x | (1 << d), 1, -INF);
	}

	int flow, cost;
	G.slope(0, 1 << (d + 1), flow, cost);

	std::vector<std::vector<int>> E(1 << d);
	int idx = 0;
	for (int S = 0; S < (1 << d); ++S) {
		for (int i = 0; i < d; ++i) {
			if (!(S >> i & 1)) {
				int t = G.edge_flow(idx++);
				while (t--) {
					E[S].push_back(S | (1 << i));
				}
			}
		}
		int t = G.edge_flow(idx++);
		while (t--) {
			E[S].push_back(0);
		}
	}

	std::vector<int> hd(1 << d);
	std::vector<int> ans;

	std::function<void(int)> dfs = [&](int u) {
		while (hd[u] < (int)E[u].size()) {
			int v = E[u][hd[u]++];
			dfs(v);
			if (v == 0) {
				ans.push_back(-1);
			} else {
				ans.push_back(__builtin_ctz(v ^ u));
			}
		}
	};
	dfs(0);
	std::reverse(ans.begin(), ans.end());
	ans.pop_back();
	std::cout << ans.size() << "\n";
	for (int x : ans) {
		if (x == -1) {
			std::cout << "R ";
		} else {
			std::cout << x << " ";
		}
	}
	std::cout << "\n";
}