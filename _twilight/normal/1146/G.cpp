#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int inf = (signed) (~0u >> 1);

typedef class Edge {
	public:
		int ed, nx, r;

		Edge() {	}
		Edge(int ed, int nx, int r) : ed(ed), nx(nx), r(r) {	}
} Edge;

typedef class MapManager {
	public:
		int *h;
		vector<Edge> E;

		MapManager() {	}
		MapManager(int n) {
			h = new int[(n + 1)];
			memset(h, -1, sizeof(int) * (n + 1));
		}
		~MapManager() {
			delete[] h;
			E.clear();
		}

		void add_edge(int u, int v, int r) {
//			E.emplace_back(v, h[u], r);
			E.push_back(Edge(v, h[u], r));
			h[u] = (signed) E.size() - 1;
		}
		void add_arc(int u, int v, int r) {
			add_edge(u, v, r);
			add_edge(v, u, 0);
		}
		Edge& operator [] (int p) {
			return E[p];
		}
} MapManager;

typedef class Network {
	public:
		int S, T;
		MapManager g;

		int *d, *h;

		Network(int S, int T) : S(S), T(T), g(T) {
			d = new int[(T + 1)];
			h = new int[(T + 1)];
		}
		~Network() {
			delete[] d;
			delete[] h;
		}

		boolean bfs() {
			queue<int> Q;
			memset(d, -1, sizeof(int) * (T + 1));
			d[S] = 0;
			Q.push(S);
			while (!Q.empty()) {
				int e = Q.front();
				Q.pop();
				for (int i = g.h[e], eu; ~i; i = g[i].nx) {
					eu = g[i].ed;
					if (!g[i].r || ~d[eu])
						continue;
					d[eu] = d[e] + 1;
					Q.push(eu);
				}
			}
			return d[T] != -1;
		}
		
		int dfs(int p, int mf) {
			if (p == T || !mf)
				return mf;
			int flow = 0, f;
			for (int& i = h[p], j, e; ~i; (i != -1) && (i = g[i].nx)) {
				e = g[i].ed, j = i;
				if (g[i].r && d[e] == d[p] + 1 && (f = dfs(e, min(mf, g[i].r))) > 0) {
					g[j].r -= f;
					g[j ^ 1].r += f;
					flow += f;
					mf -= f;
					if (!mf)
						break;
				}
			}
			return flow;
		}

		int dinic() {
			int rt = 0;
			while (bfs()) {
				for (int i = 0; i <= T; i++)
					h[i] = g.h[i];
				rt += dfs(S, inf);
			}
			return rt;
		}

		void add_edge(int u, int v, int r) {
			g.add_arc(u, v, r);
		}
} Network;

const int N = 55;

int n, h, m, T;

int id(int x, int y) {
	return (x - 1) * h + y;
}

int main() {
	scanf("%d%d%d", &n, &h, &m);
	Network network (0, T = n * h + m + 1);
	int ans = h * h * n;
	for (int i = 1; i <= n; i++) {
		network.add_edge(0, id(i, 1), h * h);
		network.add_edge(id(i, 1), 0, inf);
		for (int j = 2; j <= h; j++) {
			network.add_edge(id(i, j - 1), id(i, j), h * h - (j - 1) * (j - 1));
			network.add_edge(id(i, j), id(i, j - 1), inf);
		}
	}
	int M = n * h;
	for (int i = 1, l, r, x, c; i <= m; i++) {
		scanf("%d%d%d%d", &l, &r, &x, &c);
		if (x == h) {
			continue;
		} 
		++x;
		for (int j = l; j <= r; j++) {
			network.add_edge(id(j, x), M + i, inf);
		}
		network.add_edge(M + i, T, c);
	}
	ans -= network.dinic();
	printf("%d\n", ans);
	return 0;
}