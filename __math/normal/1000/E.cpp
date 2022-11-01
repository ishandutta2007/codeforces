#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V v) { writer(x, ' '); writer(y, ' '); writer(z, ' '); writer(v, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
ll mod_inv(ll a, ll m) { ll x, y; extgcd<ll>(a, m, x, y); return (m + x % m) % m; }

class LowLink {
	void lowlink_dfs(int v, int par, int& cur_ord) {
		lowlink[v] = order[v] = cur_ord++;

		int child_tree = 0;
		bool is_articulation = false;

		for (auto to : G[v]) {
			if (to == par) continue;
			if (order[to] == -1) {
				lowlink_dfs(to, v, cur_ord);
				lowlink[v] = min(lowlink[v], lowlink[to]);

				child_tree++;
				if (par != -1 && order[v] <= lowlink[to]) is_articulation = true;
				if (order[v] < lowlink[to]) bridge.emplace_back(v, to);
			} else {
				lowlink[v] = min(lowlink[v], order[to]);
			}
		}

		if (par == -1 && child_tree > 1) is_articulation = true;
		if (is_articulation) articulation.push_back(v);
	}
public:
	const int n;
	vector<vector<int>>& G;
	vector<int> lowlink;
	vector<int> order;

	vector<int> articulation; //
	vector<Pii> bridge; // 

	LowLink(vector<vector<int>>& G) : G(G), n(sz(G)) {
		const int n = sz(G);
		lowlink.resize(n, -1);
		order.resize(n, -1);

		int cur_ord = 0;
		lowlink_dfs(0, -1, cur_ord);
	}
};

class UnionFind {
private:
	int n;
	vector<int> a;
public:
	UnionFind(int n) : n(n), a(n, -1) {}
	int find(int x) { return a[x] < 0 ? x : (a[x] = find(a[x])); }
	bool same(int x, int y) { return find(x) == find(y); }
	bool same(Pii& p) { return same(p.first, p.second); }
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (a[x] > a[y]) swap(x, y);
		a[x] += a[y];
		a[y] = x;
		n--;
		return true;
	}
	bool unite(Pii& p) { return unite(p.first, p.second); }
	int size() const { return n; }
	int size(int x) { return -a[find(x)]; }
};

//---------------------------------------------
Pii diameter_dfs(vector<vector<int>>& e, int p, int v) {
	Pii ret(0, v);
	for (auto to : e[v]) if (to != p) {
		Pii tmp = diameter_dfs(e, v, to);
		tmp.first++;
		if (ret.first < tmp.first) ret = tmp;
	}
	return ret;
}
int diameter(vector<vector<int>>& e, int v) {
	Pii x = diameter_dfs(e, -1, v);
	Pii y = diameter_dfs(e, -1, x.second);
	return y.first;
}


int main() {
	int n, m; reader(n, m);

	vector<vector<int>> g(n);
	FOR(i, m) {
		int a, b; reader(a, b); a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	LowLink ll(g);
	set<Pii> st(ll.bridge.begin(), ll.bridge.end());
	UnionFind uf(n);
	FOR(i, n) for (auto x : g[i]) {
		if (i > x) continue;
		if (st.count(Pii(i, x))) continue;
		if (st.count(Pii(x, i))) continue;
		uf.unite(i, x);
	}
	vector<int> valid;
	FOR(i, n) if (uf.find(i) == i) valid.push_back(i);
	vector<vector<int>> g2(uf.size());
	for (auto& uv : ll.bridge) {
		int u, v; tie(u, v) = uv;
		u = uf.find(u), v = uf.find(v);
		u = lower_bound(valid.begin(), valid.end(), u) - valid.begin();
		v = lower_bound(valid.begin(), valid.end(), v) - valid.begin();
		g2[u].push_back(v);
		g2[v].push_back(u);
	}

	int ans = diameter(g2, 0);
	writerLn(ans);

	return 0;
}