
// Problem : D. Presents in Bankopolis
// Contest : Codeforces - Tinkoff Challenge - Elimination Round
// URL : https://codeforces.com/contest/793/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, M;
int dp[2][85][85][85];
bool vis[2][85][85][85];
vector<pair<int, int>> graph[85];

int solve(int d, int l, int r, int k){
	if(k == 1){
		return 0;
	}
	if(vis[d][l][r][k]){
		return dp[d][l][r][k];
	}
	vis[d][l][r][k] = 1;
	dp[d][l][r][k] = INT_MAX/2;
	if(d == 0){
		for(auto e : graph[l]){
			if(e.first > l && e.first <= r){
				dp[d][l][r][k] = min(dp[d][l][r][k], solve(d^1, l+1, e.first, k-1) + e.second);
				dp[d][l][r][k] = min(dp[d][l][r][k], solve(d, e.first, r, k-1) + e.second);
			}
		}
	}
	else{
		for(auto e : graph[r]){
			if(e.first >= l && e.first < r){
				dp[d][l][r][k] = min(dp[d][l][r][k], solve(d^1, e.first, r-1, k-1) + e.second);
				dp[d][l][r][k] = min(dp[d][l][r][k], solve(d, l, e.first, k-1) + e.second);
			}
		}
	}
	return dp[d][l][r][k];
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> M;
	for(int i = 1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}
	int mn = INT_MAX/2;
	for(int l = 1; l<=N; l++){
		for(int r = l; r<=N; r++){
			mn = min({mn, solve(0, l, r, K), solve(1, l, r, K)});
		}
	}
	cout << (mn == INT_MAX/2 ? -1 : mn) << "\n";
}