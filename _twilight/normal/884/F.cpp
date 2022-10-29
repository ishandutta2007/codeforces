#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class Edge {
	public:
		int ed, nx, r, c;

		Edge(int ed = 0, int nx = 0, int r = 0, int c = 0) : ed(ed), nx(nx), r(r), c(c) {	} 
} Edge;

typedef class MapManager {
	public:
		int* h;
		vector<Edge> es;

		MapManager() {	}
		MapManager(int n) {
			h = new int[(n + 1)];
			pfill(h, h + n + 1, -1);
		}

		void addEdge(int u, int v, int r, int c) {
			es.push_back(Edge(v, h[u], r, c));
			h[u] = (signed) es.size() - 1;
		}

		void addArc(int u, int v, int cap, int c) {
			addEdge(u, v, cap, c);
			addEdge(v, u, 0, -c);
		}

		Edge& operator [] (int p) {
			return es[p];
		}
} MapManager;

const signed int inf = (signed) (~0u >> 1);

typedef class Graph {
	public:
		int S, T;
		MapManager g;
		
		int *le;
		int *f, *mf;
		boolean *vis;

		// be sure T is the last node
		Graph(int S, int T) : S(S), T(T), g(T) {
			f = new int[(T + 1)];
			le = new int[(T + 1)];
			mf = new int[(T + 1)];
			vis = new boolean[(T + 1)];
			pfill(vis, vis + T, false);
		}

		int spfa() {
			queue<int> que;
			pfill(f, f + T + 1, -inf);
			que.push(S);
			f[S] = 0, le[S] = -1, mf[S] = inf;
			while (!que.empty()) {
				int e = que.front();
				que.pop();
				vis[e] = false; 
				for (int i = g.h[e], eu, w; ~i; i = g[i].nx) {
					if (!g[i].r)
						continue;
					eu = g[i].ed, w = f[e] + g[i].c;
					if (w > f[eu]) {
						f[eu] = w, le[eu] = i, mf[eu] = min(mf[e], g[i].r);
						if (!vis[eu]) {
							vis[eu] = true;
							que.push(eu);
						}
					}
				}
			}
			if (f[T] == -inf)
				return -inf;
			int rt = 0;
			for (int p = T, e; ~le[p]; p = g[e ^ 1].ed) {
//				cerr << p << "<-";
				e = le[p];
				g[e].r -= mf[T];
				g[e ^ 1].r += mf[T];
				rt += mf[T] * g[e].c;
			}
//			cerr << S << '\n';
			return rt;
		}

		int max_cost() {
			int rt = 0, delta;
			while ((delta = spfa()) != -inf) {
				rt += delta;
//				cerr << delta << '\n';
			}
			return rt;
		}
} Graph;

int n;
Graph *graph;
char str[105];
int b[105], c[30];

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	for (int i = 1; i <= n; i++) {
		c[str[i] -= 'a']++;
	}
	graph = new Graph(0, ((n >> 1) + 1) * 26 + n + 1);
	MapManager &g = graph->g;
	for (int i = 1; i <= 26; i++) {
		g.addArc(0, i, c[i - 1], 0);
	}
	int sid = ((n >> 1) + 1) * 26;
	for (int i = 1; (i << 1) <= n; i++) {
		int a = i, b = n - i + 1;
		for (int ch = 1; ch <= 26; ch++) {
			g.addArc(ch, i * 26 + ch, 1, 0);
			g.addArc(i * 26 + ch, sid + a, 1, (ch - 1 == (int) str[a]) * :: b[a]);
			g.addArc(i * 26 + ch, sid + b, 1, (ch - 1 == (int) str[b]) * :: b[b]);
		}
	}
	for (int i = 1; i <= n; i++) {
		g.addArc(sid + i, graph->T, 1, 0);
	}
	printf("%d\n", graph->max_cost());
	return 0;
}