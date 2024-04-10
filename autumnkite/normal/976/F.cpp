#include <bits/stdc++.h>

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
		E[u].push_back(edge.size()), edge.push_back(Edge(u, v, c));
		E[v].push_back(edge.size()), edge.push_back(Edge(v, u, 0));
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

	void add_edge_cap(int id, Flow c) {
		++edge[id << 1].c;
	}

	Flow edge_flow(int id) {
		return edge[id << 1 | 1].c;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n1, n2, m;
	std::cin >> n1 >> n2 >> m;
	maxflow_network<int> G(n1 + n2 + 2);
	int S = n1 + n2, T = n1 + n2 + 1;
	std::vector<int> d1(n1), d2(n2);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		G.add_edge(u, v + n1, 1);
		++d1[u], ++d2[v];
	}
	int k = std::min(*std::min_element(d1.begin(), d1.end()), 
	                 *std::min_element(d2.begin(), d2.end()));
	for (int i = 0; i < n1; ++i) {
		G.add_edge(S, i, d1[i] - k);
	}
	for (int i = 0; i < n2; ++i) {
		G.add_edge(n1 + i, T, d2[i] - k);
	}
	int now = 0;
	std::vector<std::vector<int>> ans(k + 1);
	for (int t = k; t >= 0; --t) {
		int flow;
		G.slope(S, T, flow);
		now += flow;
		for (int i = 0; i < m; ++i) {
			if (!G.edge_flow(i)) {
				ans[t].push_back(i);
			}
		}
		for (int i = m; i < m + n1 + n2; ++i) {
			G.add_edge_cap(i, 1);
		}
	}
	for (int i = 0; i <= k; ++i) {
		std::cout << ans[i].size() << " ";
		for (int x : ans[i]) {
			std::cout << x + 1 << " ";
		}
		std::cout << "\n";
	}
}