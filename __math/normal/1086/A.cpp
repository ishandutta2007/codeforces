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

#ifdef _WIN32
template <typename ... Args>
void debugPrintf(const char *format, Args const & ... args) {
	fprintf(stdout, format, args ...);
	fflush(stdout);
}
#else
#define debugPrintf(...)
#endif

vector<set<Pii>> f(Pii a, Pii b) {
	if (a.first > b.first) {
		swap(a, b);
	}

	vector<set<Pii>> ret;
	{
		set<Pii> c;
		c.insert(a);
		c.insert(b);
		for (int x = a.first; x <= b.first; x++) c.insert(Pii(x, a.second));
		int d = a.second > b.second ? -1 : 1;
		for (int y = a.second; y != b.second; y += d) c.insert(Pii(b.first, y));
		ret.push_back(c);
	}

	{
		set<Pii> c;
		c.insert(a);
		c.insert(b);
		int d = a.second > b.second ? -1 : 1;
		for (int y = a.second; y != b.second; y += d) c.insert(Pii(a.first, y));
		for (int x = a.first; x <= b.first; x++) c.insert(Pii(x, b.second));
		ret.push_back(c);
	}

	return ret;
}

set<Pii> solve(set<Pii>& s, Pii a) {
	static int used[1001][1001];
	static Pii pv[1001][1001];
	memset(used, 0x10, sizeof(used));
	queue<Pii> q;
	for (auto x : s) used[x.first][x.second] = 0, q.push(x);
	
	while (!q.empty()) {
		Pii cur = q.front(); q.pop();
		if (cur == a) {
			break;
		}
		int i, j; tie(i, j) = cur;
		int d[] = { 0,1,0,-1,0 };
		FOR(k, 4) {
			int ni = cur.first + d[k], nj = cur.second + d[k + 1];
			if (ni < 0 || ni > 1000 || nj < 0 || nj > 1000) continue;
			int nc = used[i][j] + 1;
			if (nc < used[ni][nj]) {
				used[ni][nj] = nc;
				pv[ni][nj] = Pii(i, j);
				q.emplace(ni, nj);
			}
		}
	}

	Pii c = a;
	set<Pii> ret = s;
	ret.insert(c);
	while (used[c.first][c.second] != 0) {
		c = pv[c.first][c.second];
		ret.insert(c);
	}

	return ret;
}

set<Pii> mn(set<Pii> l, set<Pii> r) {
	return sz(l) < sz(r) ? l : r;
}


set<Pii> solve(vector<Pii> v) {
	auto paths = f(v[0], v[1]);
	auto path1 = solve(paths[0], v[2]);
	auto path2 = solve(paths[1], v[2]);

	return mn(path1, path2);
}

int main() {
	vector<Pii> vp;
	FOR(i, 3) {
		int a, b; reader(a, b);
		vp.emplace_back(a, b);
	}

	auto a1 = solve(vp);
	swap(vp[1], vp[2]);
	auto a2 = solve(vp);
	swap(vp[0], vp[2]);
	auto a3 = solve(vp);

	auto ans = mn(a1, mn(a2, a3));
	writerLn(sz(ans));
	for (auto x : ans) {
		writerLn(x.first, x.second);
	}

	return 0;
}