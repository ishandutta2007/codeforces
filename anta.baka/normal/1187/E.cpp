#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define pb push_back

using namespace std;
using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = 3e5 + 1;

int n;
vi g[N];
ll dp[N];
int s[N];
ll ans;

void dfs(int v, int p) {
	s[v] = 1;
	for (int to : g[v]) if (to != p) { dfs(to, v); s[v] += s[to]; dp[v] += dp[to]; }
	dp[v] += s[v];
}

void dfs1(int v, int p, ll up) {
	ans = max(ans, dp[v] + up + (n - s[v]));
	//ll dpk = 0;
	//for (int to : g[v]) if (to != p) dpk += dp[to];
	for (int to : g[v]) if (to != p) dfs1(to, v, up + (n - s[to]) + (dp[v] - dp[to] - s[v]));
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n; for (int i = 0; i < n - 1; i++) { int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u); }
	dfs(0, -1); dfs1(0, -1, 0); cout << ans;
}