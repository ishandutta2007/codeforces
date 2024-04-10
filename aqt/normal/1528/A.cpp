
// Problem : A. Parsa's Humongous Tree
// Contest : Codeforces - Codeforces Round #722 (Div. 1)
// URL : https://codeforces.com/contest/1528/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int mn[100005], mx[100005];
long long dp[2][100005];
vector<int> graph[100005];

void dfs(int n, int p){
	for(int e : graph[n]){
		if(e != p){
			dfs(e, n);
			dp[0][n] += max(dp[1][e] + abs(mn[n] - mx[e]), dp[0][e] + abs(mn[n] - mn[e]));
			dp[1][n] += max(dp[1][e] + abs(mx[n] - mx[e]), dp[0][e] + abs(mx[n] - mn[e]));
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i <= N; i++){
			graph[i].clear();
			dp[0][i] = dp[1][i] = 0;
			cin >> mn[i] >> mx[i];
		}
		for(int i = 1; i < N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1, 0);
		cout << max(dp[0][1], dp[1][1]) << "\n";
	}
}