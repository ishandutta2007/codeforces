#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class Data {
	public:
		int flow;
		int delta;
		ll cost;

		Data(int flow, int delta, ll cost) : flow(flow), delta(delta), cost(cost) {	}
} Data;

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
		Network(int S, int T) : S(S), T(T), g(T)  {
			f = new int[(T + 1)];
			le = new int[(T + 1)];
			mf = new int[(T + 1)];
			vis = new boolean[T + 1];
			F.emplace_back(0, 0, 0);
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

		vector<Data> F;
		boolean spfa() {
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
				return false;
			F.emplace_back(mf[T], f[T], 1ll * mf[T] * f[T]);
			int flow = mf[T], rt = 0;
			for (int p = T, e; p ^ S; p = g[le[p] ^ 1].ed) {
				e = le[p];
				rt += g[e].c;
				g[e].r -= flow;
				g[e ^ 1].r += flow;
			}
			return true;
		}
		
		void add_edge(int u, int v, int cap, int w) {
			g.add_arc(u, v, cap, w);		
		}
} Network;

int n, m, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	Network g (1, n);
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		g.add_edge(u, v, 1, w);
	}
	while (g.spfa());
	auto& F = g.F;
	int sumf = 0;
	ll sumc = 0;
	for (auto& p : F) {
		sumf += p.flow;
		sumc += p.cost;
		p.flow = sumf;
		p.cost = sumc;	
	}
	int X;
	cin >> q;
	while (q--) {
		cin >> X;
		int l = 1, r = (signed) F.size() - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			int f = F[mid].flow;
			if (1ll * f * F[mid].delta <= X + F[mid].cost) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		--l;
		printf("%.9lf\n", 1.0 * (X + F[l].cost) / F[r].flow);
	}
	return 0;
}