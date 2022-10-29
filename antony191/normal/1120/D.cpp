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
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

vector<int> g[200000];
vector<ll> c, d1, d2;
vector<bool> good1, good2;

void dfs(int v, int p = -1) {
	int cnt = 0;
	for (auto to : g[v]) {
		if (to != p)
			dfs(to, v), cnt++;
	}
	if (!cnt) {
		d1[v] = c[v];
		d2[v] = 0;
	}
	else {
		d1[v] = 0;
		for (auto to : g[v])
			if (to != p) d1[v] += d1[to];
		ll tmp = d1[v];
		ll mx = 0;
		for (auto to : g[v])
			if (to != p) uax(mx, d1[to] - d2[to]);
		d2[v] = tmp - mx;
		uin(d1[v], tmp + c[v] - mx);
	}
}

void dfs1(int v, int p = -1) {
	int cnt = 0;
	for (auto to : g[v]) {
		if (to != p)
			cnt++;
	}
	if (!cnt) {
		good1[v] = 1;
	}
	else {
		ll mx = -1, cn = 0;
		ll sum = 0;
		for (auto to : g[v]) if (to != p) sum += d1[to];
		for (auto to : g[v])
			if (to != p) {
				if (uax(mx, d1[to] - d2[to]))
					cn = 1;
				else if (d1[to] - d2[to] == mx) cn++;
			}
		if (d1[v] == sum + c[v] - mx) good1[v] = 1;
		for (auto to : g[v])
			if (to != p) {
				if (d1[to] - d2[to] < mx || cn >= 2)
					good2[to] = 1;
				else {
					if (d1[v] == sum && good2[v])
						good2[to] = 1;
				}
			}
	}
	for (auto to : g[v])
		if (to != p)
			dfs1(to, v);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	c.resize(n);
	d1.assign(n, inf);
	d2.assign(n, inf);
	forn(i, n) cin >> c[i];
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	good1.assign(n, 0);
	good2.assign(n, 0);
	good2[0] = 1;
	dfs1(0);
	cout << d1[0];
	int cnt = 0;
	forn(i, n) if (good1[i] && good2[i]) cnt++;
	cout << ' ' << cnt << el;
	forn(i, n) if (good1[i] && good2[i]) cout << i + 1 << ' ';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}