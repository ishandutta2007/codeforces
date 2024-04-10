#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll LOG = 40;

ll n, k, f[MAXN], deg[MAXN], s[MAXN], dp[MAXN][LOG];
vector<int> adj[MAXN];

void dfs1(int v, int p) {
	f[v] = f[p] / deg[p];
	for (int u : adj[v])
		dfs1(u, v);
	
	for (int i = 0; i < LOG - 1; i++) {
		ll t = f[v] + i;
		dp[v][i] = t * s[v];
		
		if (!deg[v]) continue;
		ll a = t / deg[v], b = t % deg[v];
		vector<ll> diff;

		for (int u : adj[v]) {
			dp[v][i] += dp[u][a - f[u]];
			diff.push_back(dp[u][a + 1 - f[u]] - dp[u][a - f[u]]);
		}

		sort(all(diff), greater<ll>());	
		for (int j = 0; j < b; j++)
			dp[v][i] += diff[j];	
	}
}

inline void solve() {
	for (int i = 0; i < n + 10; i++) {
		f[i] = deg[i] = s[i] = 0;
		memset(dp[i], 0, sizeof dp[i]);
		adj[i].clear();
	}

	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
		deg[p]++;
	}

	for (int i = 1; i <= n; i++)
		cin >> s[i];

	deg[0] = 1;
	f[0] = k;
	dfs1(1, 0);
	cout << dp[1][0] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}