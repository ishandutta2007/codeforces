#define _USE_MATH_DEFINES
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

// #pragma comment(linker,"/STACK:36777216")

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

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

template<class T> void chmax(T& l, const T r){ l = max(l, r); }
template<class T> void chmin(T& l, const T r){ l = min(l, r); }

template<class T> T extgcd(T a, T b, T& x, T& y){ for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m){ T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

vector<Pii> e[ten(5)];
bool used[ten(5)];
bool used_edge[ten(5)];
int depth[ten(5)];

void dfs(int v,int dep, vector<int>& p){
	used[v] = true;
	depth[v] = dep;
	p.push_back(v);
	for (auto to : e[v]) {
		if (used[to.first]) continue;
		used_edge[to.second] = true;
		dfs(to.first, dep + 1, p);
	}
}

int main(){
	int n, m; reader(n, m);
	vector<Pii> edges;
	FOR(i, m){
		int a, b; reader(a, b); a--; b--;
		e[a].emplace_back(b, i);
		e[b].emplace_back(a, i);
		edges.emplace_back(a, b);
	}
	if (m == 0) {
		ll ans = ll(n) * (n - 1) * (n - 2);
		ans /= 6;
		writerLn(3, ans);
		return 0;
	}

	int mx = 0;
	FOR(i, n) mx = max(mx, sz(e[i]));
	if (mx == 1) {
		ll ans = ll(n - 2) * m;
		writerLn(2, ans);
		return 0;
	}

	vector<vector<int>> grp;
	FOR(i, n){
		if (!used[i]) {
			grp.emplace_back();
			dfs(i, 0,grp.back());
		}
	}

	bool found = false;
	FOR(i, m) if (!used_edge[i]) {
		int u, v;
		tie(u, v) = edges[i];
		int diff = abs(depth[u] - depth[v]);
		if (diff % 2 == 0) {
			found = true;
		}
	}
	if (found) {
		writerLn(0, 1);
		return 0;
	}

	ll ans = 0;
	for (auto& g : grp) {
		ll o[2] = {};
		for (auto v : g) {
			o[depth[v] % 2]++;
		}
		ans += o[0] * (o[0] - 1) / 2;
		ans += o[1] * (o[1] - 1) / 2;
	}

	writerLn(1, ans);

	return 0;
}