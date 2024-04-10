
// Problem : C. Xenon's Attack on the Gangs
// Contest : Codeforces Round #614 (Div. 1)
// URL : https://codeforces.com/contest/1292/problem/C
// Memory Limit : 512.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
int dist[3005][3005];
int par[3005][3005];
long long dp[3005][3005];
long long sz[3005][3005];
vector<pair<int, int>> v[3005];
vector<int> graph[3005];

void dfs(int n, int s){
	sz[s][n] = 1;
	for(int e : graph[n]){
		if(par[s][n] != e){
			par[s][e] = n;
			dist[s][e] = dist[s][n] + 1;
			v[dist[s][e]].push_back({s, e});
			dfs(e, s);
			sz[s][n] += sz[s][e];
		}
	}
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
	for(int n = 1; n<=N; n++){
		dfs(n, n);
	}
	long long ans = 0;
	for(int k = 1; k<=N; k++){
		for(auto p : v[k]){
			int n = p.first, m = p.second;
			long long c = sz[n][m]*sz[m][n];
			dp[n][m] = max(dp[n][m], dp[par[m][n]][m] + c);
			dp[n][m] = max(dp[n][m], dp[n][par[n][m]] + c);
			ans = max(dp[n][m], ans);
		}
	}
	cout << ans << endl;
}