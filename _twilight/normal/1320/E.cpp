#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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
int vsize(vector<T>& x) {
	return (signed) x.size(); 
}

template <typename T>
void discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

const int bzmax = 20;
const int N = 2e5 + 5, N2 = N << 1;

typedef class Edge {
	public:
		int ed;
		ll w;

		Edge(int ed = 0, ll w = 0) : ed(ed), w(w) {}
} Edge;

template <typename T>
class SparseTable {
	public:
		int n;
		int Log2[N2];
		T st[bzmax][N2];

		void init(int n, T* a) {
			Log2[0] = -1;
			for (int i = 1; i <= n; i++) {
				Log2[i] = Log2[i >> 1] + 1;
			}
			for (int i = 1; i <= n; i++) {
				st[0][i] = a[i];
			}
			for (int i = 1; i < bzmax; i++) {
				for (int j = 1; j + (1 << i) - 1 <= n; j++) {
					st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
				}
			}
		}

		T query(int l, int r) {
			int b = Log2[r - l + 1];
			return min(st[b][l], st[b][r - (1 << b) + 1]);
		}
};

typedef class Tree {
	public:
		int n;
		int dfc;
		int dep[N];
		ll sdis[N];
		pii seq[N2];
		vector<Edge>* G;
		int in[N], out[N];
		SparseTable<pii> st;

		void dfs1(int p, int fa, ll fw) {
			in[p] = ++dfc;
			dep[p] = dep[fa] + 1;
			sdis[p] = sdis[fa] + fw;
			seq[dfc] = pii(dep[p], p);
			for (auto par : G[p]) {
				int e = par.ed;
				if (e ^ fa) {
					dfs1(e, p, par.w);
					seq[++dfc] = pii(dep[p], p);
				}
			}
			out[p] = dfc;
		}

		int _lca(int l, int r) { return st.query(l, r).second; }
		int lca(int u, int v) {
			(in[u] > in[v]) && (swap(u, v), 0);
			return _lca(in[u], in[v]);
		}
		ll dist(int u, int v) { return sdis[u] + sdis[v] - (sdis[lca(u, v)] << 1); }

		void init(int n, vector<Edge>* G) {
			this->G = G;
			this->n = n;
			dfc = 0;
			dfs1(1, 0, 0);
			st.init(dfc, seq);
		}

		boolean in_tree(int p, int x) { return in[p] <= in[x] && out[p] >= in[x]; }

		void build_virtual_tree(vector<int>& S, vector<int>* Tr) {
			static int st[N];
			int top = 0, ts = S.size();
			sort(S.begin(), S.end(), [&](int a, int b) { return in[a] < in[b]; });
			for (int i = 1; i < ts; i++) {
				S.push_back(lca(S[i - 1], S[i]));
			}
			sort(S.begin(), S.end(), [&](int a, int b) { return in[a] < in[b]; });
			S.erase(unique(S.begin(), S.end(), [&](int a, int b) { return in[a] == in[b]; }), S.end());
			for (auto p : S) {
				while (top && !in_tree(st[top], p)) top--;
				if (top) {
					Tr[st[top]].push_back(p);
					Tr[p].push_back(st[top]);
				}
				st[++top] = p;
			}
		}
} Tree;

typedef class Node {
	public:
		int p, d, s, id;

		Node() {	}
		Node(int p, int d, int s, int id) : p(p), d(d), s(s), id(id) {	}

		boolean operator < (Node b) const {
			return pii((d + s - 1) / s, id) < pii((b.d + b.s - 1) / b.s, b.id);
		}
		boolean operator > (Node b) const {
			return pii((d + s - 1) / s, id) > pii((b.d + b.s - 1) / b.s, b.id);
		}
} Node;

const Node ninf (-1, inf, 1, -1);

int _abs(int x) {
	return (x < 0) ? (-x) : x;
}

int n, q;
Tree tr;
vector<Edge> G[N];
vector<int> Tr[N];

Node f[N];
priority_queue<Node, vector<Node>, greater<Node>> Q;
void dijkstra() {
	while (!Q.empty()) {
		Node e = Q.top();
		Q.pop();
		if (e.id != f[e.p].id)
			continue;
		for (auto p : Tr[e.p]) {
			Node eu = e;
			eu.p = p;
			eu.d += tr.dist(e.p, p);
			if (eu < f[p]) {
				Q.push(f[p] = eu);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].eb(v, 1);
		G[v].eb(u, 1);
	}
	tr.init(n, G);
	for (int i = 1; i <= n; i++)
		f[i] = ninf;
	cin >> q;
	while (q--) {
		int k, m, s;
		cin >> k >> m;
		vector<int> a (k), b (m);
		int t = 0;
		for (auto& y : a) {
			cin >> y >> s;
			Q.push(f[y] = Node(y, 0, s, ++t));
		}
		for (auto& y : b) {
			cin >> y;
			a.push_back(y);
		}
		tr.build_virtual_tree(a, Tr);
		dijkstra();
		for (auto x : b)
			cout << f[x].id << " ";
		cout << '\n';
		for (auto x : a) {
			f[x] = ninf;
			Tr[x].clear();
		}
	}
	return 0;
}