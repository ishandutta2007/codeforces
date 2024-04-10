#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
int k;
int a[100100];
int dp[333][333];
int tmp[333];
vector<int> g[333];
int ans = 0;
int N = 205;
void dfs(int v, int p) {
	dp[v][0] = 0;
	dp[v][1] = a[v];
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		for(int j = 0; j <= N; j++) {
			tmp[j] = dp[v][j];
		}
		for(int x = 0; x <= N; x++) {
			for(int y = 0; y <= N; y++) {
				if(y==0) continue;
				if(x==0) dp[v][y+1] = max(dp[v][y+1], dp[to][y]);
				else if(x+y-1 > k){
					dp[v][min(x, y+1)] = max(dp[v][min(x, y+1)], tmp[x]+dp[to][y]);
				}
			}
		}
	}
}
int main () {
	//memset(dp, -1, sizeof dp);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0;j <= n; j++)
			dp[i][j] = -1e9;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, -1);
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= N; j++) ans = max(ans, dp[i][j]);
	cout << ans << "\n";
 	return 0;
}