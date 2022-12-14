#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil; 
const int maxn = 3000 + 10;
const ll inf = 1e13;
 
vector<int> g[maxn];
int n, m, sz[maxn];
int b[maxn], w[maxn];
pil dp[maxn][maxn];
 
void dfs(int v, int par = -1){
	dp[v][1].second = w[v] - b[v];
	dp[v][1].first = 0;
	sz[v] = 1;
	for (auto u : g[v]){
		if (u == par)
			continue;
		dfs(u, v);
		sz[v] += sz[u];
		for (int j = sz[v]; j >= 1; j--){
			pil me = {0, -inf};
			for (int k = max(1, j - sz[v] + sz[u]); k <= min(j - 1, sz[u]); k++){ // edge will erased
				me = max(me, make_pair(dp[v][j - k].first + dp[u][k].first + (dp[u][k].second > 0), dp[v][j - k].second));
			}
			for (int k = max(1, j - sz[v] + sz[u] + 1); k <= min(j, sz[u]); k++){
				int a = dp[v][j - k + 1].first, c = dp[u][k].first;
				ll b = dp[v][j - k + 1].second, d = dp[u][k].second;
				me = max(me, make_pair(a + c, b + d));
			}
			dp[v][j] = me;
		}
	}
//	for (int i = 1; i <= sz[v]; i++)
//		cout << v << " " << i << " : " << dp[v][i].first << " " << dp[v][i].second << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 0; i < n - 1; i++){
			int v, u;
			cin >> v >> u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		dfs(1);
		cout << dp[1][m].first + (dp[1][m].second > 0) << endl;
	}
}