
// Problem : C. Karen and Supermarket
// Contest : Codeforces - Codeforces Round #419 (Div. 1)
// URL : https://codeforces.com/contest/815/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, B;
long long dp[5005][5005];
long long cst[5005][5005];
int sz[5005];
long long val1[5005], val2[5005];
vector<int> graph[5005];
long long tmp[5005];

void dfs(int n){
	sz[n] = 1;
	cst[n][1] = val2[n];
	for(int e : graph[n]){
		dfs(e);
		for(int i = 0; i<=sz[n]+sz[e]; i++){
			tmp[i] = LLONG_MAX/4;
		}
		for(int i = 0; i<=sz[n]; i++){
			for(int j = 0; j<=sz[e]; j++){
				tmp[i+j] = min(tmp[i+j], cst[n][i] + cst[e][j]);
			}
		}
		for(int i = 0; i<=sz[n]+sz[e]; i++){
			cst[n][i] = tmp[i];
			tmp[i] = LLONG_MAX/4;
		}
		for(int i = 0; i<sz[n]; i++){
			for(int j = 0; j<=sz[e]; j++){
				tmp[i+j] = min(tmp[i+j], dp[n][i] + dp[e][j]);
			}
		}
		for(int i = 0; i<sz[n]+sz[e]; i++){
			dp[n][i] = tmp[i];
		}
		sz[n] += sz[e];
	}
	for(int i = sz[n]; i; i--){
		dp[n][i] = dp[n][i-1] + val1[n];
		dp[n][i] = min(dp[n][i], cst[n][i]);
	}
	/*
	cout << n << "\n";
	for(int i = 1; i<=sz[n]; i++){
		cout << i << ": " << dp[n][i] << " " << cst[n][i] << "\n";
	}
	*/
	//dp[n][0] = LLONG_MAX/4;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> B;
	cin >> val2[1] >> val1[1];
	val1[1] = val2[1] - val1[1];
	for(int i = 2; i<=N; i++){
		int p;
		cin >> val2[i] >> val1[i] >> p;
		val1[i] = val2[i] - val1[i];
		graph[p].push_back(i);
	}
	dfs(1);
	int ans = 0;
	for(int i = 0; i<=N; i++){
		if(dp[1][i] <= B){
			ans = i;
		}
	}
	cout << ans << "\n";
}