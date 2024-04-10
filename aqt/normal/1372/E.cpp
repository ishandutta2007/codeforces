
// Problem : E. Omkar and Last Floor
// Contest : Codeforces - Codeforces Round #655 (Div. 2)
// URL : https://codeforces.com/contest/1372/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dp[105][105];
int mn[105][105];
int mx[105][105];

int solve(int l, int r){
	if(l > r){
		return 0;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	for(int i = l; i<=r; i++){
		int cnt = 0;
		for(int n = 1; n<=N; n++){
			if(mn[n][i] >= l && mx[n][i] <= r){
				cnt++;
			}
		}
		dp[l][r] = max(dp[l][r], solve(l, i-1) + solve(i+1,r) + cnt*cnt);
	}
	return dp[l][r];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		int k;
		cin >> k;
		while(k--){
			int l, r;
			cin >> l >> r;
			for(int j = l; j<=r; j++){
				mn[i][j] = l;
				mx[i][j] = r;
			}
		}
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1, M) << "\n";
}