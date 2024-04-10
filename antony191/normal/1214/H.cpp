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

const int maxn = 200'000;
vector<int> g[maxn];
vector<int> d, h, dup, pr;
int n, k;
void dfs(int v, int p = -1) {
	d[v] = 1;
	for (auto to : g[v]) {
		if (to != p) {
			pr[to] = v;
			h[to] = h[v] + 1;
			dfs(to, v);
			uax(d[v], d[to] + 1);
		}
	}
}
bool bad = 0;
void dfsup(int v, int p = -1) {
	int mx1 = 0, mx2 = 0;
	for (auto to : g[v]) {
		if (to != p) {
			if (d[to] > mx1) {
				mx2 = mx1;
				mx1 = d[to];
			}
			else if (d[to] > mx2) mx2 = d[to];
		}
	}
	for (auto to : g[v]) {
		if (to != p) {
			dup[to] = dup[v] + 1;
			if (d[to] != mx1) uax(dup[to], mx1 + 1);
			else uax(dup[to], mx2 + 1);
			dfsup(to, v);
		}
	}
	vector<int> tmp;
	tmp.reserve(g[v].size());
	tmp.push_back(dup[v]);
	for (auto to : g[v])
		if (to != p)
			tmp.push_back(d[to]);
	sort(all(tmp));
	reverse(all(tmp));
	if (tmp.size() >= 3 && tmp[1] + tmp[2] >= k - 1 && tmp[2] > 0) bad = 1;
}
vector<bool> used;
vector<int> cl;
int add = 1;
void draw(int v, int c) {
	cl[v] = c;
	used[v] = 1;
	for (auto to : g[v])
		if (!used[to]) draw(to, c + add);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	d.resize(n, 0); dup.resize(n, 0); h.resize(n, 0); pr.resize(n, 0);
	dfs(0);
	dfsup(0);
	if (k == 2) {
		cout << "Yes" << el;
		forn(i, n) cout << (h[i] & 1) + 1 << ' ';
		return 0;
	}
	if (bad)
		cout << "No" << el;
	else {
		int mx = 0;
		forn(i, n)
			if (h[i] > h[mx]) mx = i;
		d.assign(n, 0); dup.assign(n, 0); h.assign(n, 0); pr.assign(n, mx);
		dfs(mx);
		int mx2 = 0;
		forn(i, n)
			if (h[i] > h[mx2]) mx2 = i;
		used.assign(n, 0);
		vector<int> tmp;
		for (int i = mx2; i != mx; i = pr[i]) used[i] = 1, tmp.push_back(i);
		tmp.push_back(mx);
		reverse(all(tmp));
		used[mx] = 1;
		int t = h[mx2] + 1;
		cl.assign(n, 0);
		for (int i = (t / 2); i < t; ++i) {
			cl[tmp[i]] = i;
			draw(tmp[i], i);
		}
		add = -1;
		for (int i = 0; i < (t / 2); ++i) {
			cl[tmp[i]] = i;
			draw(tmp[i], i);
		}
		forn(i, n) cl[i] = (cl[i] % k) + 1;
		cout << "Yes" << el;
		output(cl);
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}