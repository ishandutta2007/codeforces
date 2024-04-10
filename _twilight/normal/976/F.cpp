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

		void addEdge(int u, int v, int r) {
			es.push_back(Edge(v, h[u], r));
			h[u] = (signed) es.size() - 1;
		}

		void addArc(int u, int v, int cap) {
			addEdge(u, v, cap);
			addEdge(v, u, 0);
		}

		Edge& operator [] (int p) {
			return es[p];
		}
} MapManager;

typedef class Network {
	public:
		int S, T;
		int *cur, *div;
		MapManager g;

		Network() {	}
		Network(int S, int T) : S(S), T(T), g(T + 1) {
			cur = new int[(T + 1)];
			div = new int[(T + 1)];
		}
		~Network() {
			delete[] cur;
			delete[] div;
		}

		boolean bfs() {
			static queue<int> que;
			pfill(div, div + T + 1, -1);
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
				for (int i = 0; i <= T; i++)
					cur[i] = g.h[i];
				rt += dfs(S, inf);
			}
			return rt;
		}
} Network;

const int N = 2e3 + 5;

int nX, nY, m;
int deg[N << 1];
Network *_network;
vector<int> ans[N];

int main() {
	scanf("%d%d%d", &nX, &nY, &m);
	int n = nX + nY;
	_network = new Network(0, n + 1);
	Network &network = *_network;
	MapManager& g = network.g;
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g.addArc(u, v + nX, 1);
		deg[u]++, deg[v + nX]++;
	}
	int min_deg = m, sid = g.es.size();
	for (int i = 1; i <= n; i++) {
		min_deg = min(min_deg, deg[i]);
	}
	for (int i = 1; i <= nX; i++) {
		g.addArc(0, i, deg[i] - min_deg);
	}
	for (int i = 1; i <= nY; i++) {
		g.addArc(i + nX, n + 1, deg[i + nX] - min_deg);
	}
	for (int k = min_deg; k; k--) {
		network.dinic();
		for (int i = 0; i < m; i++) {
			if (g[i << 1].r) {
				ans[k].push_back(i + 1);
			}
		}
		for (int i = 0; i < n; i++) {
			g[sid + (i << 1)].r++;
		}
	}
	for (int k = 0; k <= min_deg; k++) {
		printf("%d", (signed) ans[k].size());
		for (int i = 0; i < (signed) ans[k].size(); i++) {
			printf(" %d", ans[k][i]);
		}
		putchar('\n');
	}
	return 0;
}