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

const int N = 105;

int n, m, W, H;
int s[N][N];
vector<int> Xs, Ys;
int x1[N], y1[N], x2[N], y2[N];

int main() {
	scanf("%d%d", &n, &m);
	if (!m) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
		Xs.push_back(x1[i]);
		Xs.push_back(++x2[i]);
		Ys.push_back(y1[i]);
		Ys.push_back(++y2[i]);
	}
	sort(Xs.begin(), Xs.end());
	sort(Ys.begin(), Ys.end());
	Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
	Ys.erase(unique(Ys.begin(), Ys.end()), Ys.end());
	W = Xs.size(), H = Ys.size();
	for (int i = 1; i <= m; i++) {
		x1[i] = lower_bound(Xs.begin(), Xs.end(), x1[i]) - Xs.begin() + 1;
		x2[i] = lower_bound(Xs.begin(), Xs.end(), x2[i]) - Xs.begin() + 1;
		y1[i] = lower_bound(Ys.begin(), Ys.end(), y1[i]) - Ys.begin() + 1;
		y2[i] = lower_bound(Ys.begin(), Ys.end(), y2[i]) - Ys.begin() + 1;
		s[x1[i]][y1[i]]++;
		s[x1[i]][y2[i]]--;
		s[x2[i]][y1[i]]--;
		s[x2[i]][y2[i]]++;
	}
	for (int i = 1; i < W; i++) {
		for (int j = 1; j < H; j++) {
			s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	int T;
	Network network(0, T = W + H - 1);
	MapManager& g = network.g;
	for (int i = 1; i < W; i++) {
		g.addArc(0, i, Xs[i] - Xs[i - 1]);
	}
	for (int i = 1; i < H; i++) {
		g.addArc(W - 1 + i, T, Ys[i] - Ys[i - 1]);
	}
	for (int i = 1; i < W; i++) {
		for (int j = 1; j < H; j++) {
			if (s[i][j]) {
				g.addArc(i, W - 1 + j, inf);
			}
		}
	}
	int ans = network.dinic();
	printf("%d\n", ans);
	return 0;
}