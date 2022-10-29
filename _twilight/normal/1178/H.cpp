#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const signed int inf = (signed) (~0u >> 1);

#define ll long long

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

		void addEdge(int u, int v, int r, int c = 0) {
			es.push_back(Edge(v, h[u], r, c));
			h[u] = (signed) es.size() - 1;
		}

		void addArc(int u, int v, int cap, int c = 0) {
			addEdge(u, v, cap, c);
			addEdge(v, u, 0, -c);
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

		boolean *vis;
		int *f, *le, *mf;

		Network() {	}
		Network(int S, int T) : S(S), T(T), g(T + 1) {
			cur = new int[(T + 1)];
			div = new int[(T + 1)];
			vis = new boolean[(T + 1)];
			f = new int[(T + 1)];
			le = new int[(T + 1)];
			mf = new int[(T + 1)];	
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
			int times = 0;
			int rt = 0;
//			cerr << g.h[0] << '\n';
			while (bfs()) {
				for (int i = 0; i <= T; i++)
					cur[i] = g.h[i];
				rt += dfs(S, inf);
				times++;
			}
			cerr << "argue time: " << times << '\n';
			return rt;
		}

		int spfa() {
			queue<int> Q;
			for (int i = 0; i <= T; i++) {
				f[i] = inf >> 1, vis[i] = false;
			}
			f[S] = 0, mf[S] = inf, le[S] = -1;
			Q.push(S);
			while (!Q.empty()) {
				int e = Q.front();
				Q.pop();
				vis[e] = false;
				for (int i = g.h[e]; ~i; i = g[i].nx) {
					int eu = g[i].ed, w = f[e] + g[i].c;
					if (g[i].r <= 0) {
						continue;
					}
					if (w < f[eu]) {
						f[eu] = w, le[eu] = i, mf[eu] = min(mf[e], g[i].r);
						if (!vis[eu]) {
							Q.push(eu);
							vis[eu] = true;
						}
					}
				}
			}
			if (f[T] == (inf >> 1))
				return inf;
			for (int p = T, e; p ^ S; p = g[le[p] ^ 1].ed) {
				e = le[p];
				g[e].r -= mf[T];
				g[e ^ 1].r += mf[T];
			}
			return f[T] * mf[T];
		}

		int min_cost() {
			int rt = 0, d;
			while ((d = spfa()) ^ inf) {
				rt += d;
			}
			return rt;
		}
} Network;

const int N = 2205, N2 = N << 1;

int n, mb;
ll vab[N2];
Network* network;
int a[N2], b[N2], vb[N2];

void build(int mid) {
	int T, n2 = n << 1, n4 = n << 2, n6 = n2 + n4;
	network = new Network(0, T = 10 * n + 1);
	MapManager& g = network->g;
	for (int i = 1; i <= n; i++)
		g.addArc(0, i, 1);
	for (int i = 1; i <= n2; i++) {
		int db = lower_bound(vb + 1, vb + mb + 1, b[i]) - vb;
		if (i <= n) g.addArc(i, n6 + db, 1, 1);
		g.addArc(n6 + db, n2 + i, inf);
		if (i <= n) g.addArc(i, n2 + i, 1);
	}
	for (int i = 1; i < mb; i++)
		g.addArc(n6 + i + 1, n6 + i, inf);
	for (int i = 1; i <= n2; i++) {
		vab[i] = b[i] + 1ll * a[i] * mid;
	}
	sort(vab + 1, vab + n2 + 1);
	int mab = unique(vab + 1, vab + n2 + 1) - vab - 1;
	for (int i = 1; i <= n2; i++) {
		int d = lower_bound(vab + 1, vab + mab + 1, b[i] + 1ll * a[i] * mid)- vab;
		g.addArc(n2 + i, n6 + mb + d, inf, 1);
		if (i > n) g.addArc(n6 + mb + d, n4 + i, inf);
		if (i > n) g.addArc(n2 + i, n4 + i, 1);
	}
	for (int i = 1; i < mab; i++)
		g.addArc(n6 + mb + i + 1, n6 + mb + i, inf);
	for (int i = n + 1; i <= n2; i++)
		g.addArc(n4 + i, T, 1);
}

int c[N2];
#define pli pair<ll, int>
boolean check(int mid) {
	static vector<pli> V;
	V.clear();
	int n2 = n << 1;
	for (int i = 1; i <= n2; i++) {
		V.emplace_back(b[i], i);
		vab[i] = a[i] * 1ll * mid + b[i];
		c[i] = 0;
	}
	sort(V.begin(), V.end(), [&] (pli a, pli b) {
			return (a.first ^ b.first) ? (a.first < b.first) : (a.second > b.second); 	
		});
   	int id = -1;
	ll mx = -1e18;
	for (auto par : V) {
		if (vab[par.second] > mx) {
			id = par.second;
			mx = vab[par.second];
		}
		if (par.second <= n) {
			c[id]++;
		}
	}
	for (int i = 1; i <= n2; i++)
		V[i - 1] = pli(vab[i], i);
	sort(V.begin(), V.end());
	for (int i = 1; i < n2; i++) {
		if (V[i - 1].first == V[i].first) {
			c[V[i].second] += c[V[i - 1].second];
			c[V[i - 1].second] = 0;
		}	
	}
	reverse(V.begin(), V.end());
	int sum = 0;
	for (auto par : V) {
		sum += c[par.second] - (par.second > n);
		if (sum < 0) {
			return false;
		}	
	}
	return true;
}

int main() {
	scanf("%d", &n);
	int n2 = n << 1;
	for (int i = 1; i <= n2; i++) {
		scanf("%d%d", a + i, b + i);
		vb[i] = b[i];
	}
	sort(vb + 1, vb + n2 + 1);
	mb = unique(vb + 1, vb + n2 + 1) - vb - 1;
	int l = 0, r = 1e9, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
//		cerr << "cur: " << l << " " << r << " " << clock() << '\n';
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
//	cerr << clock() << "ms\n";
 	if (++r > 1000000000) {
		puts("-1");
	} else {
		build(r);
		int ans = network->min_cost();
		printf("%d %d\n", r, ans);
	}
//	cerr << clock() << "ms\n";
	return 0;
}