#include <bits/stdc++.h>

template <class Flow>
class MaxFlow_Network {
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
	MaxFlow_Network(int _n) : n(_n), E(_n), dep(_n), iter(_n) {}

	void add_edge(int u, int v, Flow c, Flow _c = 0) {
		E[u].push_back(edge.size()), edge.push_back(Edge(u, v, c));
		E[v].push_back(edge.size()), edge.push_back(Edge(v, u, _c));
	}

	int edge_size() {
		return edge.size() >> 1;
	}
	
	void slope(int _S, int _T, Flow &flow) {
		S = _S, T = _T;
		while (bfs()) {
			std::fill(iter.begin(), iter.end(), 0);
			flow += dfs(S, INF);
		}
	}

	void slope(int _S, int _T, Flow &flow, Flow lim) {
		S = _S, T = _T;
		while (flow < lim && bfs()) {
			std::fill(iter.begin(), iter.end(), 0);
			flow += dfs(S, lim - flow);
		}
	}

	Flow edge_flow(int id) {
		return edge[id << 1 | 1].c;
	}

	void erase_edge(int id, int S, int T, Flow &flow) {
		Flow F = edge[id << 1 | 1].c;
		flow -= F;
		edge[id << 1].c = edge[id << 1 | 1].c = 0;
		Flow tmp = 0;
		slope(edge[id << 1].u, S, tmp, F);
		slope(T, edge[id << 1].v, tmp, F);
	}
};

const int dx[] = {1, 0};
const int dy[] = {0, 1};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, m;
	std::cin >> n;
	m = n;
	const int INF = 4 * n * m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}

	std::vector<int> v;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] > 0) {
				v.push_back(a[i][j]);
			}
		}
	}
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());

	std::vector<std::vector<std::pair<int, int>>> p(v.size());

	MaxFlow_Network<int> G(n * m + 2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] > 0) {
				int t = std::lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
				p[t].emplace_back(i * m + j, G.edge_size());
				G.add_edge(n * m, i * m + j, INF);
			}
			if (a[i][j] != -1) {
				for (int k = 0; k < 2; ++k) {
					int x = i + dx[k], y = j + dy[k];
					if (x < n && y < m && a[x][y] != -1) {
						G.add_edge(i * m + j, x * m + y, 1, 1);
					}
				}
			}
		}
	}

	int flow = 0;
	long long ans = 0;
	for (int i = 0; i < (int)v.size() - 1; ++i) {
		for (auto t : p[i]) {
			int x = t.first, e = t.second;
			G.erase_edge(e, n * m, n * m + 1, flow);
			G.add_edge(x, n * m + 1, INF);
		}
		G.slope(n * m, n * m + 1, flow);
		ans += 1ll * (v[i + 1] - v[i]) * flow;
	}
	std::cout << ans << "\n";
}