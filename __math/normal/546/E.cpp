#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
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
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

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
template<class T> void writerArr(vector<T>& v) { if (sz(v)) writerArr(&v[0], sz(v)); else writer("\n"); }


struct E {
	int to, rev, cap;
	E(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
};

const int MAX_V = 1000;
int level[MAX_V], iter[MAX_V];
vector<E> e[MAX_V];

void add_undirected_edge(int f, int t, int c) {
	e[f].push_back(E(t, sz(e[t]), c));
	e[t].push_back(E(f, sz(e[f]) - 1, c));
}

void add_directed_edge(int f, int t, int c) {
	e[f].push_back(E(t, sz(e[t]), c));
	e[t].push_back(E(f, sz(e[f]) - 1, 0));
}

void bfs(int s) {
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto t : e[v]) {
			if (t.cap > 0 && level[t.to] < 0) {
				level[t.to] = level[v] + 1;
				q.push(t.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t) return f;
	for (int &i = iter[v]; i < sz(e[v]); i++) {
		E& _e = e[v][i];
		if (_e.cap > 0 && level[v] < level[_e.to]) {
			int d = dfs(_e.to, t, min(f, _e.cap));
			if (d > 0) {
				_e.cap -= d;
				e[_e.to][_e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

const int INF = ten(8);

int max_flow(int s, int t) {
	int flow = 0;
	while (true) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}

int n, m;
int ans[200][200];

bool solve(){
	cin >> n >> m;
	vector<int> a(n), b(n);
	FOR(i, n) cin >> a[i];
	FOR(i, n) cin >> b[i];

	int asum = accumulate(a.begin(), a.end(), 0);
	int bsum = accumulate(b.begin(), b.end(), 0);
	if (asum != bsum) return false;

	FOR(i, m){
		int x, y; cin >> x >> y;
		x--; y--;
		add_directed_edge(x, y + n, a[x]);
		add_directed_edge(y, x + n, a[y]);
	}

	FOR(i, n){
		add_directed_edge(i, i + n, a[i]);
		add_directed_edge(2 * n, i, a[i]);
		add_directed_edge(i + n, 2 * n + 1, b[i]);
	}

	int f = max_flow(2 * n, 2 * n + 1);
	if (f != asum) return false;

	FOR(i, n){
		for (auto edge : e[i]) {
			if (edge.to == 2 * n) continue;
			ans[i][edge.to - n] = a[i] - edge.cap;
		}
	}

	return true;
}

int main(){
	bool b = solve();
	if (b) {
		puts("YES");
		FOR(i, n) writerArr(ans[i], n);
	} else {
		puts("NO");
	}
}