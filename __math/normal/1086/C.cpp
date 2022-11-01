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

char al[26][ten(6) + 10];

void init() {
	FOR(a, 26) FOR(i, ten(6)) al[a][i] = 'a' + a;
}

bool solve(int k, char* s, char* a, char *b, int ans[26], int ansInv[26]) {
	while (true) {
		if (*s == '\0') {
			return true;
		}

		char cur = ans[*s - 'a'];
		if (cur == -1) break;
		if (cur < *a - 'a' || *b - 'a' < cur) return false;
		if (cur != *a - 'a') a = al[0];
		if (cur != *b - 'a') b = al[k-1];
		s++, a++, b++;
	}

	for (char c = *a; c <= *b; c++) {
		int from = *s - 'a';
		int to = c - 'a';
		if (ansInv[to] != -1) continue;
		ans[from] = to;
		ansInv[to] = from;

		if (c != *a && c != *b) {
			return true;
		} else if (c == *a && c == *b) {
			bool ret = solve(k, s + 1, a + 1, b + 1, ans, ansInv);
			if (ret) return true;
		} else if (c == *a) {
			bool ret = solve(k, s + 1, a + 1, al[k-1], ans, ansInv);
			if (ret) return true;
		} else {
			// c == *b
			bool ret = solve(k, s + 1, al[0], b + 1, ans, ansInv);
			if (ret) return true;
		}

		ans[from] = -1;
		ansInv[to] = -1;
	}

	return false;
}


string solve() {
	int k; reader(k);
	string s, a, b; reader(s, a, b);
	int ans[26], ansInv[26];
	memset(ans, -1, sizeof(ans));
	memset(ansInv, -1, sizeof(ansInv));
	bool ok = solve(k, (char*)s.c_str(), (char*)a.c_str(), (char*)b.c_str(), ans, ansInv);
	if (!ok) return "";

	string ret;
	FOR(i, k) {
		if (ans[i] == -1) {
			int to = 0;
			while (ansInv[to] != -1) to++;
			ans[i] = to;
			ansInv[to] = i;
		}
		ret.push_back(ans[i] + 'a');
	}

	return ret;
}

int main() {
	init();

	int t; reader(t);
	while (t--) {
		auto ans = solve();
		if (sz(ans)) {
			writerLn("YES");
			writerLn(ans);
		} else {
			writerLn("NO");
		}
	}

	return 0;
}