
// Problem : D. Nested Rubber Bands
// Contest : Codeforces Round #633 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1338/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100005];
int dp[2][100005], dgr[100005];
int par[100005];
int ans = 1;

void dfs(int n){
	dp[1][n] = dgr[n];
	dp[0][n] = 1;
	for(int e : graph[n]){
		if(par[n] != e){
			par[e] = n;
			dfs(e);
			ans = max(ans, dp[1][e] + 1);
			ans = max(ans, dp[1][n] + dp[1][e] - 1 + !!par[n]);
			ans = max(ans, dp[1][n] + dp[0][e] - 1 + !!par[n]);
			ans = max(ans, dp[0][n] + dp[1][e]);
			dp[1][n] = max(dp[1][n], dp[0][e] + dgr[n] - 1);
			dp[1][n] = max(dp[1][n], dp[1][e] + dgr[n] - 1);	
			dp[0][n] = max(dp[0][n], dp[1][e] + 1);
		}
	}
	//cout << n << " " << dp[0][n] << " " << dp[1][n] << "\n";
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i<=N; i++){
		dgr[i] = graph[i].size();
		dgr[i] -= (i != 1);
	}
	dfs(1);
	cout << ans << "\n";
}