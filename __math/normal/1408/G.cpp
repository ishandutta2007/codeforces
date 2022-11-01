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
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k && k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k < '0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k && k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k < '0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V& w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x < 0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x < 0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V v) { writer(x, ' '); writer(y, ' '); writer(z, ' '); writer(v, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }
void reader(ull& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k && k <= '9') { x = ull(k - '0'); break; } }for (;;) { mygc(k); if (k < '0' || k>'9')break; x = x * 10 + k - '0'; } }
void writer(ull x, char c) { int s = 0, m = 0; char f[20]; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
template<class T> vector<T> readerArray(int n) { vector<T> ret(n); for (int i = 0; i < n; i++) reader(ret[i]); return ret; }

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

#ifdef _MSC_VER
// #ifdef _DEBUG
template <typename ... Args>
void debugPrintf(const char* format, Args const& ... args) {
	fprintf(stderr, format, args ...);
	fflush(stderr);
}
#else
#define debugPrintf(...)
#endif

class UnionFind {
private:
	int n;
	vector<int> a;
	vector<int> _callCount;
	vector<int> _groupids;
	int gid;
public:
	vector<int> parents;


	UnionFind(int n) : n(n), a(n, -1), _callCount(n, 0), _groupids(n, 0), parents(2 * n - 1, -1) {
		FOR(i, n) _groupids[i] = i;
		gid = n;
	}
	int find(int x) { return a[x] < 0 ? x : (a[x] = find(a[x])); }
	bool same(int x, int y) { return find(x) == find(y); }
	bool same(Pii& p) { return same(p.first, p.second); }
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			_callCount[x]++;
			return false;
		}
		if (a[x] > a[y]) swap(x, y);
		a[x] += a[y];
		a[y] = x;
		_callCount[x] += _callCount[y] + 1;
		_callCount[y] = -1;
		n--;

		parents[_groupids[x]] = gid;
		parents[_groupids[y]] = gid;
		_groupids[x] = _groupids[y] = gid;

		gid++;
		return true;
	}
	bool unite(Pii& p) { return unite(p.first, p.second); }
	int size() const { return n; }
	int size(int x) { return -a[find(x)]; }

	int callCount(int x) {
		return _callCount[find(x)];
	}
	int groupId(int x) {
		return _groupids[find(x)];
	}
};


vector<ll> memo[4000];
bool validVertex[3000];

vector<int> e[3000];
int numChilds[3000];

const int MOD = 998244353;

void dfs(int v) {
	for (auto to : e[v]) {
		dfs(to);
	}
	memo[v].push_back(1);
	vector<ll>& cur = memo[v];

	static vector<ll> nt;
	for (auto to : e[v]) {
		auto& tt = memo[to];
		nt.clear();
		nt.resize(sz(cur) + sz(tt) - 1, 0);
		FOR(i, sz(cur)) FOR(j, sz(tt)) {
			(nt[i + j] += cur[i] * tt[j]) %= MOD;
		}
		swap(cur, nt);
	}

	cur.resize(numChilds[v] + 1);
	if (validVertex[v]) {
		cur[1]++;
	}
	if (numChilds[v] == 1) cur[0] = 0;
}

int main() {
	int n; reader(n);
	static int a[1500][1500];
	FOR(i, n) FOR(j, n) reader(a[i][j]);
	static Pii edges[1500 * 1500 / 2];
	int numE = 0;
	FOR(i, n) FOR(j, i) {
		numE++;
		edges[a[i][j] - 1] = Pii(i, j);
	}

	UnionFind uf(n);
	FOR(i, n) validVertex[i] = true;

	FOR(i, numE) {
		int u, v; tie(u, v) = edges[i];
		uf.unite(u, v);
		int s = uf.size(u);
		int count = uf.callCount(u);
		if (s * (s - 1) == count * 2) {
			int gid = uf.groupId(u);
			validVertex[gid] = true;
		}
	}

	FOR(i, 2 * n - 1) {
		if (uf.parents[i] != -1) {
			e[uf.parents[i]].push_back(i);
		}

		if (i < n) numChilds[i] = 1;
		else {
			for (auto t : e[i]) numChilds[i] += numChilds[t];
		}
	}

	dfs(2 * n - 2);
	vector<ll> ans;
	for (int i = 1; i <= n; i++) ans.push_back((memo[2 * n - 2][i] % MOD + MOD) % MOD);
	writerArr(ans);

	return 0;
}