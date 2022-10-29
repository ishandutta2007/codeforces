#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const double dinf = 1e100;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

template <typename T>
class Edge {
	public:
		int ed, nx;
		T r;

		Edge(int ed = 0, int nx = 0, T r = 0) : ed(ed), nx(nx), r(r) {	}
};

template <typename T>
class MapManager {
	public:
		int *h;
		vector<Edge<T> > es;

		MapManager() {	}
		MapManager(int n) {
			h = new int[(n + 1)];
			pfill(h, h + n + 1, -1);
		}
		~MapManager() {
			delete[] h;
			es.clear();
		}

		void addEdge(int u, int v, T r) {
			es.push_back(Edge<T>(v, h[u], r));
			h[u] = (signed) es.size() - 1;
		}

		void addArc(int u, int v, T cap) {
			addEdge(u, v, cap);
			addEdge(v, u, 0);
		}

		Edge<T>& operator [] (int p) {
			return es[p];
		}
};

class Dcmp {
	public:
		const static double eps;

		boolean operator () (double x) {
			return fabs(x) >= eps;
		}	
} dcmp;

const double Dcmp :: eps = 5e-8;

template <typename Type>
class Network {
	public:
		int S, T;
		int *cur, *div;
		MapManager<Type> g;

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
					if (!dcmp(g[i].r))
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

		Type dfs(int p, Type minf) {
			if (p == T || !dcmp(minf))
				return minf;
			Type flow = 0, f; 
			for (int& i = cur[p], e; (~i); i = cur[p], i = g[i].nx) {
				e = g[i].ed;
				if (div[e] == div[p] + 1 && dcmp(f = dfs(e, min(minf, g[i].r))) > 0) {
					flow += f;
					g[i].r -= f;
					g[i ^ 1].r += f;
					minf -= f;
					if (!dcmp(minf)) {
						break;	
					}
				}
			}
			return flow;
		}

		Type dinic() {
			Type rt = 0;
//			cerr << g.h[0] << '\n';
			while (bfs()) {
				for (int i = 0; i <= T; i++)
					cur[i] = g.h[i];
				rt += dfs(S, dinf);
			}
			return rt;
		}
};

const int N = 1e3 + 5, M = 2e3 + 5;

int n, m;
Network<double> *network;
int us[M], vs[M], as[M], bs[M], cs[M], ds[M];

inline void init() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d%d%d", us + i, vs + i, as + i, bs + i, cs + i, ds + i);
	}
}

double in[N], out[N];
double build(double t) {
	MapManager<double> &g = network->g;
	for (int i = 1; i <= n; i++) {
		in[i] = out[i] = 0.0;
	}
	double rt = 0;
	for (int i = 0; i < m; i++) {
		double low = as[i] * t + bs[i], dif;
		g[i << 1].r = dif = (cs[i] - as[i]) * t + ds[i] - bs[i];
		g[i << 1 | 1].r = 0.0;
		out[us[i]] += low;
		in[vs[i]] += low;
		rt += low;
//		cerr << us[i] << " " << vs[i] << " " << dif << '\n';
	}
	int s = (m << 1);
	for (int i = 0; i < n; i++, s += 2) {
		g[s].r = in[i + 1];
		g[s | 1].r = 0;
//		cerr << 0 << " " << i + 1 << " " << in[i + 1] << '\n';
	}
	for (int i = 0; i < n; i++, s += 2) {
		g[s].r = out[i + 1];
		g[s | 1].r = 0;
//		cerr << i + 1 << " " << n + 1 << " " << out[i + 1] << '\n';
	}
	return rt;
}

inline void solve() {
	network = new Network<double>(0, n + 1);
	MapManager<double> &g = network->g;
	for (int i = 0; i < m; i++) {
		g.addArc(us[i], vs[i], 0.0);
	}
	for (int i = 0; i < n; i++) {
		g.addArc(0, i + 1, 0.0);
	}
	for (int i = 0; i < n; i++) {
		g.addArc(i + 1, n + 1, 0.0);
	}
	double div_eps = 1e-7;
	double l = 0, r = 1 - div_eps, mid, f1, f2, low;
	for (int _ = 0; l + Dcmp :: eps < r && _ < 64; _++) {
		mid = (l + r) / 2;
		low = build(mid);
		f1 = low - network->dinic();
		low = build(mid + div_eps);
		f2 = low - network->dinic();
		if (!dcmp(f1 - f2)) {
			r = mid;
		} else if (f1 > f2) {
			l = mid;
		} else {
			r = mid;
		}
	}
	double L = r;
	l = L, r = 1 - div_eps; 
	for (int _ = 0; l + Dcmp :: eps < r && _ < 64; _++) {
		mid = (l + r) / 2;
		low = build(mid);
		f1 = low - network->dinic();
		low = build(mid + div_eps);
		f2 = low - network->dinic();
		if (!dcmp(f1 - f2)) {
			l = mid;
		} else if (f1 > f2) {
			l = mid;
		} else {
			r = mid;
		}
	}
	low = build(L);
	f1 = low - network->dinic();
	if (dcmp(f1)) {
		puts("0.000000");
	} else {
		printf("%.7lf\n", l - L);
	}
}

int main() {
	init();
	solve();
	return 0;
}