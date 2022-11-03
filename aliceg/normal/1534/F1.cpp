#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <numeric>
#include <functional>
#include <limits>
#include <ctime>
#include <random>
#include <bitset>
#include <numeric>
#include <complex>
#include <stdlib.h>
#include <cassert>

#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const ld PI = 3.141592653589793;
const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

void dfs_ts(int v, vvi& g, vi& ts, vc& used) {
	used[v] = 1;
	for (int u : g[v]) {
		if (!used[u])
			dfs_ts(u, g, ts, used);
	}
	ts.push_back(v);
	return;
}

void dfs(int v, vvi& g, vi& c, int p) {
	c[v] = p;
	for (int u : g[v]) {
		if (c[u] == -1)
			dfs(u, g, c, p);
	}
	return;
}

void solve() {

	int n, m;
	cin >> n >> m;
	vector<string> f(n);
	for (int i = 0; i < n; ++i)
		cin >> f[i];
	vector<vii> b(m);
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (f[i][j] == '#') {
				b[j].push_back({ i, k });
				++k;
			}
		}
	}
	vvi g(k);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < b[i].size(); ++j) {
			int x = b[i][j].first, num = b[i][j].second;
			if (j && b[i][j - 1].first == x - 1)
				g[num].push_back(b[i][j - 1].second);
			if (j + 1 != b[i].size())
				g[num].push_back(b[i][j + 1].second);
			if (i) {
				auto it = upper_bound(b[i - 1].begin(), b[i - 1].end(), mp(x, -1LL));
				if (it != b[i - 1].end())
					g[num].push_back(it->second);
			}
			if (i != m - 1) {
				auto it = upper_bound(b[i + 1].begin(), b[i + 1].end(), mp(x, -1LL));
				if (it != b[i + 1].end())
					g[num].push_back(it->second);
			}
		}
	}
	vi ts;
	vc used(k);
	for (int i = 0; i < k; ++i) {
		if (!used[i])
			dfs_ts(i, g, ts, used);
	}
	vi c(k, -1);
	int r = 0;
	vvi gg(k);
	for (int v = 0; v < k; ++v) {
		for (auto u : g[v]) {
			gg[u].push_back(v);
		}
	}
	reverse(ts.begin(), ts.end());
	for (int v : ts) {
		if (c[v] == -1) {
			dfs(v, gg, c, r);
			++r;
		}
	}
	vc beg(r, 1);
	for (int v = 0; v < k; ++v) {
		for (auto u : g[v]) {
			if (c[u] != c[v]) {
				beg[c[u]] = 0;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < r; ++i) {
		if (beg[i])
			++cnt;
	}
	cout << cnt << endl;

	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;
	
	/*int t;
	cin >> t;
	for (int i = 0; i < t; ++i)*/
		solve();

	return 0;
}