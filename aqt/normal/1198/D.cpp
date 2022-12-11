
// Problem : D. Rectangle Painting 1
// Contest : Codeforces - Codeforces Round #576 (Div. 1)
// URL : https://codeforces.com/contest/1198/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[55][55][55][55];
int pre[55][55];

long long solve(int l1, int r1, int l2, int r2){
	if(dp[l1][r1][l2][r2]+1){
		return dp[l1][r1][l2][r2];
	}
	if(pre[l2][r2] - pre[l1-1][r2] - pre[l2][r1-1] + pre[l1-1][r1-1]){
		dp[l1][r1][l2][r2] = max(r2-r1, l2-l1)+1;
	}
	else{
		dp[l1][r1][l2][r2] = 0;
	}
	long long &ret = dp[l1][r1][l2][r2];
	for(int k = l1; k<l2; k++){
		ret = min(solve(l1, r1, k, r2) + solve(k+1, r1, l2, r2), ret);
	}
	for(int k = r1; k<r2; k++){
		ret = min(solve(l1, r1, l2, k) + solve(l1, k+1, l2, r2), ret);
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			char c;
			cin >> c;
			pre[i][j] = (c == '#');
			pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			for(int n = 1; n<=N; n++){
				for(int m = 1; m<=N; m++){
					dp[i][j][n][m] = -1;
				}
			}
		}
	}	
	cout << solve(1, 1, N, N);
}