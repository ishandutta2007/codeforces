#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const signed int inf = (signed) (~0u >> 1);

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class Edge {
	public:
		int ed, nx, r;

		Edge(int ed = 0, int nx = 0, int r = 0) : ed(ed), nx(nx), r(r) {	}
} Edge;

typedef class MapManager {
	public:
		int *h;
		vector<Edge> es;

		MapManager() {	}
		MapManager(int n) {
			h = new int[(n + 1)];
			pfill(h, h + n + 1, -1);
		}
		~MapManager() {
			delete[] h;
			es.clear();
		}

		void add_edge(int u, int v, int r) {
			es.push_back(Edge(v, h[u], r));
			h[u] = (signed) es.size() - 1;
		}

		void add_arc(int u, int v, int cap) {
			add_edge(u, v, cap);
			add_edge(v, u, 0);
		}

		Edge& operator [] (int p) {
			return es[p];
		}
		int size() {
			return es.size();
		}
} MapManager;

typedef class Network {
	public:
		int n, S, T;
		int *cur, *div;
		MapManager g;

		Network() {	}
		Network(int n, int S, int T) : n(n), S(S), T(T), g(n + 1) {
			cur = new int[(n + 1)];
			div = new int[(n + 1)];
		}
		~Network() {
			delete[] cur;
			delete[] div;
		}

		boolean bfs() {
			static queue<int> que;
			pfill(div, div + n + 1, -1);
			div[S] = 0;
			que.push(S);
			while (!que.empty()) {
				int e = que.front();
				que.pop();
				for (int i = g.h[e], eu; ~i; i = g[i].nx) {
//					cerr << i << '\n';
					if (!g[i].r)
						continue;
					eu = g[i].ed;
					if (!~div[eu]) {
						div[eu] = div[e] + 1;
						que.push(eu);
					}
				}
			}
			return ~div[T];
		} 

		int dfs(int p, int minf) {
			if (p == T || !minf)
				return minf;
			int flow = 0, f; 
			for (int& i = cur[p], e; (~i); i = cur[p], i = g[i].nx) {
				e = g[i].ed;
				if (div[e] == div[p] + 1 && (f = dfs(e, min(minf, g[i].r))) > 0) {
					flow += f;
					g[i].r -= f;
					g[i ^ 1].r += f;
					minf -= f;
					if (!minf) {
						break;	
					}
				}
			}
			return flow;
		}

		int dinic() {
			int rt = 0;
//			cerr << g.h[0] << '\n';
			while (bfs()) {
				for (int i = 0; i <= n; i++)
					cur[i] = g.h[i];
				rt += dfs(S, inf);
			}
			return rt;
		}
} Network;

const int N = 105, M = 1e3 + 4;

int n, m;
int s, t;
boolean in_cut[M], vis[N];
int u[M], v[M], ig[M], id[M], deg[N];

void bfs(MapManager& g) {
	queue<int> Q;
	Q.push(s);
	vis[s] = true;
	while (!Q.empty()) {
		int e = Q.front();
		Q.pop();
		for (int i = g.h[e], eu; ~i; i = g[i].nx) {
			eu = g[i].ed;
			if (!vis[eu] && g[i].r) {
				vis[eu] = true;
				Q.push(eu);
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	Network *network = new Network(n, s, t);
	MapManager& g1 = network->g;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", u + i, v + i, ig + i);
		if (ig[i]) {
			g1.add_arc(u[i], v[i], 1);
			g1.add_arc(v[i], u[i], inf >> 1);
		} else {
			g1.add_arc(u[i], v[i], inf >> 1);
			g1.add_arc(u[i], v[i], inf >> 1);
		}
	}
	printf("%d\n", network->dinic());
	bfs(g1);
	for (int i = 1; i <= m; i++) {
		if (ig[i] && !g1[(i - 1) << 2].r && (vis[u[i]] ^ vis[v[i]])) {
			in_cut[i] = true;
		}
	}
	network = new Network(n + 1, 0, n + 1);
	MapManager &g2 = network->g;
	for (int i = 1; i <= m; i++) {
		if (ig[i]) {
			id[i] = g2.size();
			deg[u[i]] -= 1;
			deg[v[i]] += 1;
			g2.add_arc(u[i], v[i], inf >> 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] < 0) {
			g2.add_arc(i, n + 1, -deg[i]);
		} else if (deg[i] > 0) {
			g2.add_arc(0, i, deg[i]);
		}
	}
	network->dinic();
	for (int i = 1; i <= m; i++) {
		if (!ig[i]) {
			puts("0 1");
		} else {
			int flow = (inf >> 1) - g2[id[i]].r + 1;
			printf("%d %d\n", flow, flow + !in_cut[i]);
		}
	}
	return 0;
}