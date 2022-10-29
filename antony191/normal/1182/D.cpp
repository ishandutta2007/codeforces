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
const int inf = 1e9;
const ll llinf = 1e18, mod = 998244353, md = 998244352;
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
const int maxn = 100000;
vector<int> g[maxn], h, p;
void dfs(int v) {
	for (auto to : g[v]) {
		if (to != p[v]) {
			p[to] = v;
			h[to] = h[v] + 1;
			dfs(to);
		}
	}
}
set<int> q[maxn];
int n;
bool check(int v) {
	h.assign(n, 0); p.assign(n, v);
	dfs(v);
	forn(i, n) {
		q[h[i]].insert((int)g[i].size());
	}
	bool ok = 1;
	forn(i, n)
		if (q[i].size() > 1) ok = 0;
	forn(i, n) {
		q[i].clear();
	}
	return ok;
}
vector<bool> good;
void dfs1(int v) {
	if (p[v] == v) good[v] = 1;
	else {
		good[v] = good[p[v]];
		if (g[v].size() > 2) good[v] = 0;
	}
	for (auto to : g[v])
		if (to != p[v]) dfs1(to);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	h.assign(n, 0); p.assign(n, 0);
	dfs(0);
	int mx = 0;
	forn(i, n) {
		if (h[i] > h[mx]) mx = i;
	}
	h.assign(n, 0); p.assign(n, mx);
	dfs(mx);
	int t = mx;
	forn(i, n) {
		if (h[i] > h[mx]) mx = i;
	}
	int k = h[mx] / 2, v = mx;
	forn(i, k) v = p[v];
	if (check(v)) cout << v + 1 << el;
	else {
		if (check(t) || check(mx)) cout << (check(t) ? t: mx) + 1 << el;
		else {
			check(v);
			map<int, vector<int>> q;
			forn(i, n) {
				if (g[i].size() == 1) q[h[i]].push_back(i);
			}
			if (q.size() <= 2) {
				if (q.size() == 2) {
					if (q.begin()->y.size() == 1 || q.rbegin()->y.size() == 1) {
						int to = (q.begin()->y.size() == 1 ? q.begin()->y[0] : q.rbegin()->y[0]);
						if (check(to)) cout << to + 1;
						else cout << -1 << el;
					}
					else cout << -1 << el;
				}
				else {
					dfs1(v);
					int cnt = 0;
					forn(i, n) {
						if (cnt || g[i].size() > 1 || !good[i]) continue;
						cnt = 1;
						if (check(i)) cout << i + 1, cnt++;
					}
					if (cnt == 1) cout << -1 << el;
				}
			}
			else cout << -1 << el;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}