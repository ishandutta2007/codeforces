
// Problem : E. Ehab and a component choosing problem
// Contest : Codeforces - Codeforces Round #525 (Div. 2)
// URL : https://codeforces.com/contest/1088/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[300005];
long long arr[300005];
long long dp[300005];
long long ans;
int cnt;

void dfs1(int n, int p){
	dp[n] = arr[n];
	for(int e : graph[n]){
		if(e != p){
			dfs1(e, n);
			dp[n] += max(dp[e], 0LL);
		}
	}
}

void dfs2(int n, int p){
	dp[n] = arr[n];
	for(int e : graph[n]){
		if(e != p){
			dfs2(e, n);
			dp[n] += max(dp[e], 0LL);
		}
	}
	if(dp[n] == ans){
		cnt++;
		dp[n] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i =1 ; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1(1, 0);
	ans = *max_element(dp+1, dp+1+N);
	dfs2(1, 0);
	cout << ans * cnt << " " << cnt << "\n";
}