
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

int main() {
	int n, m; reader(n, m);
	int cl, ce, v; reader(cl, ce, v);
	set<int> l, e;
	FOR(i, cl) {
		int x; reader(x);
		l.insert(x);
	}
	FOR(i, ce) {
		int x; reader(x);
		e.insert(x);
	}

	int q; reader(q);

	auto solveWithEl = [&](int x1, int y1, int x2, int y2, set<int>::iterator it) {
		if (it == e.end()) return ten(9);
		const int xadd = (abs(x1 - x2) + v - 1) / v;
		const int yval = *it;

		return xadd + abs(y1 - yval) + abs(y2 - yval);
	};

	auto solveWithSt = [&](int x1, int y1, int x2, int y2, set<int>::iterator it) {
		if (it == l.end()) return ten(9);
		const int xadd = (abs(x1 - x2) + 1 - 1) / 1;
		const int yval = *it;

		return xadd + abs(y1 - yval) + abs(y2 - yval);
	};

	FOR(i, q) {
		int x1, y1, x2, y2; reader(x1, y1, x2, y2);
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		int ans;
		if (x1 == x2) {
			ans = abs(y1 - y2);
		} else {
			ans = ten(9);
			if (sz(l)) {
				{
					auto it = l.lower_bound(y1);
					chmin(ans, solveWithSt(x1, y1, x2, y2, it));
					if (it != l.begin()) {
						auto it2 = prev(it);
						chmin(ans, solveWithSt(x1, y1, x2, y2, it2));
					}
				}
				{
					auto it = l.lower_bound(y2);
					chmin(ans, solveWithSt(x1, y1, x2, y2, it));
					if (it != l.begin()) {
						auto it2 = prev(it);
						chmin(ans, solveWithSt(x1, y1, x2, y2, it2));
					}
				}
			}
			if (sz(e)) {
				{
					auto it = e.lower_bound(y1);
					chmin(ans, solveWithEl(x1, y1, x2, y2, it));
					if (it != e.begin()) {
						auto it2 = prev(it);
						chmin(ans, solveWithEl(x1, y1, x2, y2, it2));
					}
				}
				{
					auto it = e.lower_bound(y2);
					chmin(ans, solveWithEl(x1, y1, x2, y2, it));
					if (it != e.begin()) {
						auto it2 = prev(it);
						chmin(ans, solveWithEl(x1, y1, x2, y2, it2));
					}
				}
			}
		}

		writerLn(ans);
	}

	return 0;
}