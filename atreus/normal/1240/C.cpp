#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 10;

int k;
ll dp[maxn][2];
vector<pair<int, int> > t[maxn];

void dfs(int v, int par = -1){
	dp[v][0] = dp[v][1] = 0;
	ll sum = 0;
	vector<ll> c;
	for (auto edge : t[v]){
		int u = edge.first, w = edge.second;
		if (u != par){
			dfs(u, v);
			sum += dp[u][1];
			c.push_back(w - dp[u][1] + dp[u][0]);
		}
	}
	sort(c.begin(), c.end(), greater<ll>());
	dp[v][0] = sum;
	ll partial = 0;
	for (int i = 0; i < min((int)c.size(), k - 1); i++){
		partial += c[i];
		dp[v][0] = max(dp[v][0], partial + sum);
	}
	if (c.size() >= k)
		partial += c[k - 1];
	dp[v][1] = max(dp[v][1], partial + sum);
	dp[v][1] = max(dp[v][1], dp[v][0]);
}

int main(){
	ios_base::sync_with_stdio (false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++){
			int v, u, w;
			cin >> v >> u >> w;
			t[v].push_back({u, w});
			t[u].push_back({v, w});
		}
		dfs(1);
		cout << dp[1][1] << endl;
		for (int i = 1; i <= n; i++)
			t[i].clear();
	}
}