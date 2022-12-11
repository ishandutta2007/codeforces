
// Problem : F. Independent Set
// Contest : Codeforces - Codeforces Round #630 (Div. 2)
// URL : https://codeforces.com/contest/1332/problem/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[300005];
long long dp[3][300005];
const long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long sub(long long a, long long b){
	return ((a-b)%MOD+MOD)%MOD;
}

void dfs(int n, int p){
	dp[2][n] = 1;
	for(int e : graph[n]){
		if(e != p){
			dfs(e, n);
			dp[2][n] = mult(dp[2][n], dp[0][e] + dp[1][e] + dp[2][e]);
		}
	}
	dp[1][n] = dp[0][n] = 1;
	for(int e : graph[n]){
		if(e != p){
			dp[1][n] = mult(dp[1][n], 2*dp[0][e] + dp[1][e] + 2*dp[2][e]);
			dp[0][n] = mult(dp[0][n], 2*dp[0][e] + 2*dp[1][e] + 3*dp[2][e]);
		}
	}
	dp[1][n] = sub(dp[1][n], dp[2][n]);
	dp[0][n] = sub(dp[0][n], dp[2][n]);
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
	dfs(1, 0);
	long long ans = dp[0][1] + dp[1][1] + dp[2][1];
	ans %= MOD;
	cout << sub(ans, 1) << "\n";
}