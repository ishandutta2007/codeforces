
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

vector<int> check4(vector<vector<int>>& e, vector<int>& bfsCost) {
	const int n = sz(e);

	for (auto to : e[0]) {
		for (auto to2 : e[to]) {
			if (to2 == 0) continue;
			if (bfsCost[to2] == 2) return { 0, to, to2, 0, n - 1 };
		}
	}

	return {};
}

vector<int> check5(vector<vector<int>>& e) {
	const int n = sz(e);
	vector<int> connectToStart(n);
	for (auto to : e[0]) connectToStart[to] = 1;
	connectToStart[0] = 0; //

	int level = 1;
	vector<int> used(n);
	FOR(i, n) {
		if (!connectToStart[i]) continue;
		if (used[i] != 0) continue;
		used[i] = level;
		vector<int> cur;
		{
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int v = q.front(); q.pop();
				cur.push_back(v);
				for (auto to : e[v]) {
					if (!connectToStart[to]) continue;
					if (used[to] == level) continue;
					used[to] = level;
					q.push(to);
				}
			}
		}

		level++;

		if (sz(cur) <= 2) continue;
		for (auto c : cur) {
			int edgeRem = 0;
			for (auto to : e[c]) {
				if (connectToStart[to]) edgeRem++;
			}

			if (edgeRem == sz(cur) - 1) continue;

			{
				static int pv[ten(5) * 3 + 10] = {};
				static int cost[ten(5) * 3 + 10] = {};
				for (auto c2 : cur) {
					cost[c2] = -1;
				}
				queue<int> q;
				q.push(c);
				cost[c] = 0;
				while (!q.empty()) {
					int v = q.front(); q.pop();
					for (auto to : e[v]) {
						if (!connectToStart[to]) continue;
						if (cost[to] != -1) continue;
						pv[to] = v;
						cost[to] = cost[v] + 1;
						q.push(to);
					}
				}

				for (auto c2 : cur) {
					if (cost[c2] == 2) {
						int md = pv[c2];
						return { 0, c, md, c2, c, n - 1 };
					}
				}
			}
		}
	}

	return {};
}

int main() {
	int n, m; reader(n, m);
	vector<vector<int>> e(n);
	FOR(i, m) {
		int a, b; reader(a, b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	vector<int> cost(sz(e), -1);
	vector<int> pv(sz(e));
	cost[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto to : e[v]) {
			if (cost[to] != -1) continue;
			cost[to] = cost[v] + 1;
			pv[to] = v;
			q.push(to);
		}
	}

	vector<int> ans;
	if (cost[n - 1] != -1) {
		ans.push_back(n - 1);
		while (ans.back() != 0) {
			int nt = pv[ans.back()];
			ans.push_back(nt);
		}
		reverse(ans.begin(), ans.end());
	}

	if (sz(ans) == 0 || sz(ans) > 5) {
		auto ans2 = check4(e, cost);
		if (sz(ans2)) ans = ans2;
	}

	if (sz(ans) == 0 || sz(ans) > 6) {
		auto ans2 = check5(e);
		if (sz(ans2)) ans = ans2;
	}

	if (sz(ans) == 0) {
		puts("-1");
	} else {
		writerLn(sz(ans) - 1);
		for (auto& c : ans) c++;
		writerArr(ans);
	}

	return 0;
}