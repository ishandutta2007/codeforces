#include <bits/stdc++.h>

using namespace std;

int Q, N;
vector<int> graph[300005];
int dp[300005];
int ans = 0;

void dfs(int n, int p){
	dp[n] = 1 + graph[n].size();
	for(int e : graph[n]){
		if(e != p){
			dfs(e, n);
			ans = max(ans, dp[e] + dp[n] - 2);
			dp[n] = max(dp[n], (int) (dp[e] + graph[n].size() - 1));
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> Q;
	while(Q--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			graph[i].clear();
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1, 0);
		cout << ans << "\n";
		ans = 0;
	}
}