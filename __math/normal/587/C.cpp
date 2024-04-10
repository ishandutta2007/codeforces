#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

//heavy-light decomposition
class HL_decomposition {
public:
	const vector<vector<int>>& e;
	const int n;
	vector<int> par, depth, ord; //e,[Ag|WJ\[g
	vector<int> cluster; //decompositionNX^
	vector<vector<int> > pathes; //eNX^ApX
	vector<int> path_idx; // path_idx[v] = LpXindex

	void init(int v) {
		depth.resize(n, 0);
		par.resize(n, 0);
		ord.resize(n, 0);

		depth[v] = 0;
		par[v] = -1;
		ord[0] = v; //ordL[gAbfs
		for (int p = 0, r = 1; p < r; p++) {
			int cur = ord[p];
			for (int nv : e[cur]) {
				if (nv == par[cur]) continue;
				ord[r++] = nv;
				par[nv] = cur;
				depth[nv] = depth[cur] + 1;
			}
		}
	}

	void decomposition() {
		vector<int> subtree_size(n, 1);
		for (int i = n - 1; i > 0; i--) subtree_size[par[ord[i]]] += subtree_size[ord[i]];
		cluster.resize(n, -1);
		int cluster_type = 0;
		FOR(i, n) {
			int u = ord[i];
			if (cluster[u] == -1) cluster[u] = cluster_type++;
			int max_subsize = -1, selected = -1;
			for (int v : e[u]) {
				if (par[u] != v && max_subsize < subtree_size[v]) {
					max_subsize = subtree_size[v];
					selected = v;
				}
			}
			if (selected != -1) cluster[selected] = cluster[u];
		}
	}

	void enum_pathes() {
		int cluster_num = 0;
		vector<int> rp(n);
		FOR(i, n) {
			rp[cluster[i]]++;
			cluster_num = max(cluster_num, cluster[i]);
		}
		cluster_num++;
		pathes.resize(cluster_num);
		FOR(i, cluster_num) pathes[i].resize(rp[i]);
		for (int i = n - 1; i >= 0; i--) {
			int u = ord[i];
			pathes[cluster[u]][--rp[cluster[u]]] = u;
		}
	}

	void set_path_idx() {
		path_idx.resize(n);
		for (const vector<int>& path : pathes) {
			FOR(i, sz(path)) path_idx[path[i]] = i;
		}
	}

public:
	HL_decomposition(const vector<vector<int>>& e) : e(e), n(sz(e)) {
		init(0);
		decomposition();
		enum_pathes();
		set_path_idx();
	}
};

struct P {
	int vp[20], len;
	static P zero() {
		P ret;
		ret.len = 0;
		return ret;
	}
	bool is_zero() const { return len == 0; }
	P operator+(const P& r) const {
		if (is_zero()) return r;
		else if (r.is_zero()) return *this;

		P ret;
		ret.len = len + r.len;
		merge(vp, vp + len, r.vp, r.vp + r.len, ret.vp);
		ret.len = min(ret.len, 10);
		return ret;
	}
};

//0-indexed segment tree
class seg_tree {
public:
	vector<P> dat;
	int n;

	void propagate(int i) {
		dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
	}

	void init(P* d, int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), P::zero());
		for (int i = 0; i < size; i++) dat[n - 1 + i] = d[i];
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	void update(int k, P val) {
		k += n - 1;
		dat[k] = val;
		// dat[k] = _mo(dat[k],val);
		while (k > 0) {
			k = (k - 1) / 2;
			propagate(k);
		}
	}

	//[a,b)
	P query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	P query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return P::zero();
		if (a <= l && r <= b) return dat[k];

		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1;
		P lval = query(a, b, nl, l, md);
		P rval = query(a, b, nr, md, r);

		return lval + rval;
	}
};

class LCA {
public:
	vector<vector<int>>& e;
	int V, logV;
	vector<int> depth;
	vector<vector<int> > parent;

	LCA(vector<vector<int>>& e) : e(e) {
		this->V = sz(e);
		logV = 0;
		while (V >= (1 << logV)) logV++;
		this->depth = vector<int>(V);
		this->parent = vector<vector<int> >(logV, vector<int>(V));

		dfs(0, -1, 0);
		build();
	}

	void dfs(int v, int par, int d) {
		depth[v] = d;
		parent[0][v] = par;
		for (auto to : e[v]) {
			if (par == to) continue;
			dfs(to, v, d + 1);
		}
	}

	void build() {
		for (int k = 0; k + 1 < logV; k++) {
			for (int v = 0; v < V; v++) {
				if (parent[k][v] < 0) parent[k + 1][v] = -1;
				else parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}

	int prev_parent(int u, int par) {
		for (int k = logV - 1; k >= 0; k--) {
			int diff = depth[u] - depth[par];
			if ((diff - (1 << k)) > 0) {
				u = parent[k][u];
			}
		}
		return u;
	}

	int query(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < logV; k++) {
			if ((depth[v] - depth[u]) >> k & 1)
				v = parent[k][v];
		}
		if (u == v) return u;

		for (int k = logV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};

// example of how to use
class tree_query {
	LCA* lca;
	HL_decomposition *hl;
	vector<seg_tree*> segs;
public:
	tree_query(vector<vector<int>>& e, vector<vector<int>>& a) {
		lca = new LCA(e);
		hl = new HL_decomposition(e);
		segs.resize(sz(hl->pathes));
		FOR(i, sz(segs)) {
			vector<P> dat;
			for (auto v : hl->pathes[i]) {
				P nw;
				FOR(i, sz(a[v])) nw.vp[i] = a[v][i];
				nw.len = sz(a[v]);
				dat.push_back(nw);
			}
			segs[i] = new seg_tree();
			segs[i]->init(&dat[0], sz(dat));
		}
	}

	pair<Pii, Pii> expose(int u, int v) {
		auto l = lca->query(u, v);
		int l2 = -1;
		if (l != v) l2 = lca->prev_parent(v, l);
		return make_pair(Pii(u, l), Pii(v, l2));
	}

	P query_core(int u, int par) {
		P ret = P::zero();
		if (par == -1) return ret;
		while (true) {
			int l_index = 0;
			if (hl->cluster[u] == hl->cluster[par]) l_index = hl->path_idx[par];
			auto cur = segs[hl->cluster[u]]->query(l_index, hl->path_idx[u] + 1);
			ret = cur + ret;
			if (hl->cluster[u] == hl->cluster[par]) break;
			u = hl->par[hl->pathes[hl->cluster[u]][0]];
		}
		return ret;
	}

	P query(int u, int v) {
		auto ep = expose(u, v);
		auto ans1 = query_core(ep.first.first, ep.first.second);
		auto ans2 = query_core(ep.second.first, ep.second.second);

		return ans1 + ans2;
	}
};

vector<vector<int>> e;
int c[ten(5)];

int main() {
	int n, m, q; reader(n, m, q);
	e.resize(n);
	FOR(i, n - 1) {
		int x, y; reader(x, y);
		x--; y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	FOR(i, m) reader(c[i]);
	vector<vector<int>> v(n);
	FOR(i, m) v[c[i] - 1].push_back(i + 1);
	FOR(i, n) {
		sort(v[i].begin(), v[i].end());
		if (sz(v[i]) > 10) v[i].resize(10);
	}

	tree_query tq(e, v);

	vector<int> anses;
	FOR(i, q) {
		int v, u, a; reader(v, u, a);
		v--; u--;
		auto ans = tq.query(u, v);
		anses.clear();
		FOR(i, ans.len) {
			if (sz(anses) >= a) break;
			anses.push_back(ans.vp[i]);
		}
		if (sz(anses) == 0) puts("0");
		else {
			writer(sz(anses), ' ');
			writerArr(&anses[0], sz(anses));
		}
	}
}