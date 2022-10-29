#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9, maxn = 100'228;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int tin[maxn], tout[maxn], p[maxn][20], h[maxn];
vector<int> g[maxn];
bool used[maxn];
int timer = 0;
void dfs(int v, int pr = 0) {
	p[v][0] = pr;
	firn(k, 20) {
		p[v][k] = p[p[v][k - 1]][k - 1];
	}
	tin[v] = timer++;
	for (auto to : g[v]) {
		if (to != pr) {
			h[to] = h[v] + 1;
			dfs(to, v);
		}
	}
	tout[v] = timer++;
}
bool anc(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}
int lca(int v, int u) {
	if (anc(v, u)) return v;
	if (anc(u, v)) return u;
	for (int k = 19; k + 1; --k) {
		if (!anc(p[v][k], u)) {
			v = p[v][k];
		}
	}
	return p[v][0];
}
int dist(int v, int u) {
	return h[v] + h[u] - 2 * h[lca(v, u)];
}
int sz[maxn];
vector<int> order;
void jfs(int v, int pr = -1) {
	sz[v] = 1;
	order.push_back(v);
	for (auto to : g[v]) {
		if (used[to] || to == pr) continue;
		jfs(to, v);
		sz[v] += sz[to];
	}
}
int find_centroid() {
	int tsz = (int)order.size() / 2;
	for (auto v : order) {
		if ((int)order.size() - sz[v] > tsz) continue;
		bool good = 1;
		for (auto to : g[v]) {
			if (!used[to] && sz[to] < sz[v] && sz[to] > tsz) {
				good = 0;
				break;
			}
		}
		if (good) return v;
	}
	return -1;
}
int pr[maxn];
vector<int> res;
void build(int v, int par = -1) {
	order.clear();
	jfs(v);
	int c = find_centroid();
	pr[c] = par;
	used[c] = 1;
	for (auto to : g[c]) {
		if (!used[to]) {
			build(to, c);
		}
	}
}
void upd(int v) {
	int u = v;
	for (; v + 1; v = pr[v]) {
		uin(res[v], dist(v, u));
	}
}
int get(int v) {
	int ans = inf, u = v;
	for (; v + 1; v = pr[v]) {
		uin(ans, res[v] + dist(v, u));
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	res.assign(n, inf);
	dfs(0);
	build(0);
	upd(0);
	forn(q, m) {
		int com;
		cin >> com;
		if (com == 1) {
			int v;
			cin >> v;
			v--;
			upd(v);
			continue;
		}
		int v;
		cin >> v;
		v--;
		cout << get(v) << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}