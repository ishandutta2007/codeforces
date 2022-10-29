#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int inf = (signed) (~0u >> 2);

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class Edge {
	public:
		int ed, nx, r, c;

		Edge() {	}
		Edge(int ed, int nx, int r, int c) : ed(ed), nx(nx), r(r), c(c) {	}
} Edge;

typedef class MapManager {
	public:
		int* h;
		vector<Edge> es;

		MapManager() {	}
		MapManager(int n)  {
			h = new int[(n + 1)];
			memset(h, -1, (n + 1) << 2);
		}

		void add_edge(int u, int v, int cap, int c) {
			es.emplace_back(v, h[u], cap, c);
			h[u] = (signed) es.size() - 1;
		}
		void add_arc(int u, int v, int cap, int c) {
			add_edge(u, v, cap, c);
			add_edge(v, u, 0, -c);
		}
		Edge& operator [] (int p) {
			return es[p];
		}
} MapManager;

typedef class Network {
	public:
		int S, T;
		MapManager g;

		Network() {	}
		Network(int S, int T) : S(S), T(T), g(T) {
			f = new int[(T + 1)];
			le = new int[(T + 1)];
			mf = new int[(T + 1)];
			dif = new int[(T + 1)];
			vis = new boolean[T + 1];
			pfill(dif, dif + T + 1, 0);
		}

		int *dif;
		boolean *vis;
		int *f, *le, *mf;

		void clear() {
			delete[] f;
			delete[] le;
			delete[] mf;
			delete[] vis;
			delete[] dif;
		}

		int spfa() {
			queue<int> Q;
			pfill(f, f + T + 1, inf);
			pfill(vis, vis + T + 1, false);
			Q.push(S);
			f[S] = 0, mf[S] = inf, le[S] = -1;
			while (!Q.empty()) {
				int e = Q.front();
				Q.pop();
				vis[e] = false;
				for (int i = g.h[e], eu, w; ~i; i = g[i].nx) {
					eu = g[i].ed;
					if (!g[i].r) continue;
					w = f[e] + g[i].c;
					if (w < f[eu]) {
						f[eu] = w, mf[eu] = min(mf[e], g[i].r), le[eu] = i;
						if (!vis[eu]) {
							Q.push(eu);
							vis[eu] = true;
						}
					}
				}
			}
			if (f[T] == inf)
				return inf;
			int flow = mf[T], rt = 0;
//			cerr << "path: ";
			for (int p = T, e; p ^ S; p = g[le[p] ^ 1].ed) {
//				cerr << p << " <- ";
				e = le[p];
				rt += g[e].c;
				g[e].r -= flow;
				g[e ^ 1].r += flow;
			}
//			cerr << S << '\n';
//			cerr << "flow: " << flow << ' ' << "cost :" << rt * flow << " " << '\n';
			return rt * flow;
		}
		
		int min_cost() {
			for (int i = 0; i < T; i++) {
				if (i ^ S) {
					if (dif[i] > 0) {
						add_edge(S, i, dif[i], 0);
					} else if (dif[i] < 0) {
						add_edge(i, T, -dif[i], 0);
					}
				}
			}
			int rt = 0, tmp;
			while ((tmp = spfa()) ^ inf) {
				rt += tmp;
			}
			return rt;
		}

		void add_edge(int u, int v, int cap, int w) {
//			cerr << u << "->" << v << " " << cap << " " << w << '\n';
			g.add_arc(u, v, cap, w);		
		}
} Network;

int n, K;
Network* network;
int *a, *c, *suf, *h;

int main() {
	scanf("%d%d", &n, &K);
	a = new int[(n + 1)];
	c = new int[(n + 1)];
	h = new int[(n + 1)];
	suf = new int[(n + 1)];
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}
	for (int i = 1; i <= n; i++) {
		h[i] = n + 1;
	}
	for (int i = n; i; i--) {
		suf[i] = h[a[i]];
		h[a[i]] = i;
	}
	int SS = 0, S = 3 * n + 1, T = 3 * n + 2, TT = 3 * n + 3;
	network = new Network(0, TT);
	network->add_edge(S, 2 * n + 1, K, 0);
	network->add_edge(3 * n, T, K, 0);
	network->add_edge(T, S, K, 0);
	for (int i = 1; i <= n; i++) {
		if (i < n) {
			network->add_edge(2 * n + i, 2 * n + i + 1, K, 0);
		}
		network->add_edge(2 * n + i, i, 1, c[a[i]]);
		network->add_edge(i, TT, 1, 0);
		network->add_edge(SS, n + i, 1, 0);
		if (i < n) {
			network->add_edge(n + i, 2 * n + i + 1, 1, 0);
		} else {
			network->add_edge(n + n, T, 1, 0);
		}
		if (suf[i] <= n) {
			network->add_edge(n + i, suf[i], 1, 0);
		}
	}
	int ans = network->min_cost();
	printf("%d\n", ans);
	return 0;
}