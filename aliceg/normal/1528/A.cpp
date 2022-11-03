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
#include <functional>
#include <limits>
#include <ctime>
#include <cassert>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifndef _getchar_nolock
#define _putchar_nolock putchar_unlocked
#define _getchar_nolock getchar_unlocked
#endif
#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:536870912")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;

const ld EPS = 1e-8;
const int N = (int)5e5 + 10;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;

void dfs(int v, vvi& a, vii& c, vii& dp, int p = -1) {
	for (int u : a[v]) {
		if (u == p)
			continue;
		dfs(u, a, c, dp, v);
		dp[v].first += max(abs(c[v].first - c[u].first) + dp[u].first, abs(c[v].first - c[u].second) + dp[u].second);
		dp[v].second += max(abs(c[v].second - c[u].first) + dp[u].first, abs(c[v].second - c[u].second) + dp[u].second);
	}
	return;
}

void solve() {
	int n;
	cin >> n;
	vii c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i].first >> c[i].second;
	vvi a(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vii dp(n);
	dfs(0, a, c, dp);
	cout << max(dp[0].first, dp[0].second) << endl;
	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();

	return 0;
}