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
#include <random>

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n
#define fi(n) for (int i = 0; i < (int)n; ++i)
#define fie(n) for (int i = 1; i <= (int)n; ++i)
#define fir(l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define fj(n) for (int j = 0; j < (int)n; ++j)
#define fje(n) for (int j = 1; j <= (int)n; ++j)
#define fjr(l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define fv(i, n) for (int i = 0; i < (int)n; ++i)
#define fve(i, n) for (int i = 1; i <= (int)n; ++i)
#define fvr(j, l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%l64d", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;
typedef vector <ll> vll;
typedef vector <vll> vvll;

const ld EPS = 1e-9;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

void dfs_sz(int v, vvi& a, vi& sz, int p = -1) {
	sz[v] = 1;
	fi(a[v].size()) {
		if (a[v][i] != p) {
			dfs_sz(a[v][i], a, sz, v);
			sz[v] += sz[a[v][i]];
		}
	}
	return;
}

void dfs(int v, vvi& a, vi& sz, vi& dp, int n, int p = -1) {
	if (p != -1)
		dp[v] = dp[p] + n - 2 * sz[v];
	fi(a[v].size()) {
		if (a[v][i] != p)
			dfs(a[v][i], a, sz, dp, n, v);
	}
	return;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(n);
	vvi a(n);
	fi(n - 1) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		a[u].pb(v);
		a[v].pb(u);
	}
	vi sz(n);
	dfs_sz(0, a, sz);
	vi dp(n);
	fi(n) dp[0] += sz[i];
	dfs(0, a, sz, dp, n);
	int ans = 0;
	fi(n) ans = max(ans, dp[i]);
	cout << ans;

	return 0;
}