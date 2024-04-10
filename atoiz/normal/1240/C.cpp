/*input
2
4 1
1 2 5
3 1 2
3 4 3
7 2
1 2 5
1 3 4
1 4 2
2 5 1
2 6 2
4 7 3

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 5e5 + 7;
const ll INF = 1e12;
int n, k;
vector<pii> gr[MAXN];
ll dp[MAXN][2];

void dfs(int u, int p)
{
	ll cur = 0;
	vi vec; vec.reserve(SZ(gr[u]) + 1);

	FORA(a, gr[u]) if (a.se != p) {
		dfs(a.se, u);
		cur += dp[a.se][0];
		vec.push_back(max(0ll, dp[a.se][1] + a.fi - dp[a.se][0]));
	}
	sort(ALL(vec));
	reverse(ALL(vec));

	// cout << cur << endl;
	dp[u][1] = cur;
	FOR(i, 0, min(k - 1, SZ(vec)) - 1) dp[u][1] += vec[i];
	
	// cout << u << ": " << dp[u][0] << ' ' << dp[u][1] << endl;
	dp[u][0] = dp[u][1];
	if (SZ(vec) >= k) dp[u][0] += vec[k - 1];
	// cout << SZ(vec) << ' ' << k << endl;
	// cout << u << ": " << dp[u][0] << ' ' << dp[u][1] << endl;
}

ll solve()
{
	cin >> n >> k;
	FOR(i, 1, n) gr[i].clear();
	FOR(i, 1, n) dp[i][0] = dp[i][1] = -INF;
	FOR(i, 0, n - 2) {
		int u, v, w;
		cin >> u >> v >> w;
		gr[u].emplace_back(w, v);
		gr[v].emplace_back(w, u);
	}

	dfs(1, 0);
	return dp[1][0];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q; cin >> q;
	while (q--) {
		cout << solve() << '\n';
	}

	return 0;
}