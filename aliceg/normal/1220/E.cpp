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

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n;
#define fi(n) for (int i = 0; i < n; ++i)
#define fie(n) for (int i = 1; i <= n; ++i)
#define fir(l, r) for (int i = (l); i <= (r); ++i)
#define fj(n) for (int j = 0; j < n; ++j)
#define fje(n) for (int j = 1; j <= n; ++j)
#define fjr(l, r) for (int j = (l); j <= (r); ++j)
#define fv(i, n) for (int i = 0; i < n; ++i)
#define fve(i, n) for (int i = 1; i <= n; ++i)
#define fvr(j, l, r) for (int j = (l); j <= (r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%lld", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifndef LOCALFILE
#define _putchar_nolock putchar_unlocked
#define _getchar_nolock getchar_unlocked
#endif
#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:134217728")

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
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

vi p(N), r(N);

int up(int v) {
	if (v == p[v])
		return v;
	p[v] = up(p[v]);
	return p[v];
}

void merge(int u, int v) {
	u = up(u); v = up(v);
	if (u == v)
		return;
	if (r[u] == r[v]) {
		p[u] = v;
		++r[v];
	}
	else if (r[u] < r[v])
		p[u] = v;
	else
		p[v] = u;
	return;
}

void dfs(int v, vvi& a, vi& res, vi& deg, vi& w) {
	deg[v] = 0;
	for (int u : a[v]) {
		if (deg[u]) {
			--deg[u];
			res[u] = max(res[u], res[v] + w[u]);
			merge(u, v);
			if (deg[u] == 1)
				dfs(u, a, res, deg, w);
		}
	}
	return;
}

void dfs1(int v, vvi& a, vi& deg, vi& w, vi& dp, int p = -1) {
	if (deg[v] != 0 && p != -1)
		return;
	int maxx = 0;
	dp[v] = w[v];
	for (int u : a[v]) {
		if (u == p)
			continue;
		dfs1(u, a, deg, w, dp, v);
		if (dp[u] + w[v] <= dp[v])
			maxx = max(dp[u] + w[v], maxx);
		else if (dp[u] + w[v] > dp[v]) {
			maxx = max(maxx, dp[v]);
			dp[v] = dp[u] + w[v];
		}
	}
	return;
}

void dfs2(int v, vvi& a, vi& deg, vi& d, vi& pred, vi& w, int p = -1) {
	if (deg[v] && p != -1)
		return;
	pred[v] = p;
	if (p == -1)
		d[v] = w[v];
	else
		d[v] = d[p] + w[v];
	for (int u : a[v]) {
		if (p != u)
			dfs2(u, a, deg, d, pred, w, v);
	}
	return;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n); rn(m);
	fi(n) p[i] = i;
	vi w(n);
	fi(n) cin >> w[i];
	vvi a(n);
	fi(m) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		a[u].pb(v);
		a[v].pb(u);
	}
	rn(s);
	--s;
	vi res(n), deg(n);
	if (m == n - 1) {
		int ans = 0;
		vi dp(n);
		dfs1(s, a, deg, w, dp);
		cout << dp[s];
		return 0;
	}
	fi(n) {
		res[i] = w[i];
		deg[i] = a[i].size();
	}
	fi(n) {
		if (deg[i] == 1)
			dfs(i, a, res, deg, w);
	}
	if (deg[s] == 0) {
		int maxx = 0, ans = 0, s1 = up(s), s0;
		fi(n) {
			if (deg[i] == 0)
				continue;
			if (up(i) == s1) {
				s0 = i;
				continue;
			}
			ans += w[i];
			maxx = max(maxx, res[i] - w[i]);
		}
		vi d(n), dp(n), pred(n), dp1(n);
		dfs2(s0, a, deg, d, pred, w);
		dfs1(s, a, deg, w, dp);
		dfs1(s0, a, deg, w, dp1);
		int ans1 = 0;
		for (int i = s, j = -1; i != -1; j = i, i = pred[i]) {
			for (int u : a[i]) {
				if (u == pred[i] || u == j)
					continue;
				ans1 = max(ans1, d[s] + dp1[u]);
			}
		}
		cout << max(ans + maxx + d[s], max(ans + ans1, dp[s]));
	}
	else {
		int maxx = 0, ans = 0;
		fi(n) {
			if (deg[i] == 0)
				continue;
			maxx = max(maxx, res[i] - w[i]);
			ans += w[i];
		}
		cout << ans + maxx;
	}

	return 0;
}