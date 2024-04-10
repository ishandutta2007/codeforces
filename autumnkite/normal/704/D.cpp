#include <bits/stdc++.h>

template <class Flow>
class MaxFlow_Network {
	const Flow INF = std::numeric_limits<Flow>::max();

	struct Edge {
		int u, v;
		Flow c;
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

	void add_edge(int u, int v, Flow c) {
		E[u].push_back(edge.size()), edge.push_back({u, v, c});
		E[v].push_back(edge.size()), edge.push_back({v, u, 0});
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
};

template <class Flow>
class ST_LU_MaxFlow_Network {
	const Flow INF_flow = std::numeric_limits<Flow>::max();

	struct Edge {
		int u, v;
		Flow lower, upper;
	};

	int n, S, T;
	std::vector<Edge> edge;
	MaxFlow_Network<Flow> G;

public:
	ST_LU_MaxFlow_Network(int _n) : n(_n), G(_n + 2) {}

	void add_edge(int u, int v, Flow lower, Flow upper) {
		edge.push_back({u, v, lower, upper});
	}

	bool slope(int _S, int _T, Flow &flow) {
		S = _S, T = _T;
		std::vector<int> d(n);
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

const int N = 100005, M = 100005;

int n, m;
int r, b;
bool flipped;
int x[N], y[N];
int t[M], l[M], d[M];

int mx, vx[N + M], sx[N + M], Lx[N + M], Rx[N + M];
int my, vy[N + M], sy[N + M], Ly[N + M], Ry[N + M];

void update(int &L, int &R, int s, int d) {
	d = std::min(d, s);
	L = std::max(L, (s - d + 1) / 2);
	R = std::min(R, (s + d) / 2);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	std::cin >> r >> b;
	if (r > b) {
		std::swap(r, b);
		flipped = true;
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i];
		vx[mx++] = x[i];
		vy[my++] = y[i];
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> t[i] >> l[i] >> d[i];
		if (t[i] == 1) {
			vx[mx++] = l[i];
		} else {
			vy[my++] = l[i];
		}
	}
	std::sort(vx, vx + mx);
	mx = std::unique(vx, vx + mx) - vx;
	std::sort(vy, vy + my);
	my = std::unique(vy, vy + my) - vy;
	for (int i = 0; i < n; ++i) {
		x[i] = std::lower_bound(vx, vx + mx, x[i]) - vx;
		++sx[x[i]];
		y[i] = std::lower_bound(vy, vy + my, y[i]) - vy;
		++sy[y[i]];
	}
	for (int i = 0; i < mx; ++i) {
		Lx[i] = 0, Rx[i] = sx[i];
	}
	for (int i = 0; i < my; ++i) {
		Ly[i] = 0, Ry[i] = sy[i];
	}
	for (int i = 0; i < m; ++i) {
		if (t[i] == 1) {
			l[i] = std::lower_bound(vx, vx + mx, l[i]) - vx;
			update(Lx[l[i]], Rx[l[i]], sx[l[i]], d[i]);
		} else {
			l[i] = std::lower_bound(vy, vy + my, l[i]) - vy;
			update(Ly[l[i]], Ry[l[i]], sy[l[i]], d[i]);
		}
	}

	ST_LU_MaxFlow_Network<int> G(mx + my + 2);
	for (int i = 0; i < mx; ++i) {
		G.add_edge(mx + my, i, Lx[i], Rx[i]);
	}
	for (int i = 0; i < my; ++i) {
		G.add_edge(mx + i, mx + my + 1, Ly[i], Ry[i]);
	}
	for (int i = 0; i < n; ++i) {
		G.add_edge(x[i], mx + y[i], 0, 1);
	}
	int flow;
	if (!G.slope(mx + my, mx + my + 1, flow)) {
		std::cout << -1 << "\n";
		return 0;
	}
	std::cout << 1ll * b * n + 1ll * (r - b) * flow << "\n";
	int idx = mx + my;
	for (int i = 0; i < n; ++i) {
		if (G.edge_flow(idx) ^ flipped) {
			std::cout << "r";
		} else {
			std::cout << "b";
		}
		++idx;
	}
	std::cout << "\n";
}