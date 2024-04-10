
// Problem : D. Dr. Evil Underscores
// Contest : Codeforces - Codeforces Round #613 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1285/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int idx = 1;
int cld[4000005][2];
int dp[4000005];

int solve(int n, int b){
	if(dp[n]+1){
		return dp[n];
	}
	if(!cld[n][0] && !cld[n][1]){
		return 0;
	}
	else if(!cld[n][0]){
		dp[n] = solve(cld[n][1], b-1);
	}
	else if(!cld[n][1]){
		dp[n] = solve(cld[n][0], b-1);
	}
	else{
		dp[n] = min(solve(cld[n][1], b-1), solve(cld[n][0], b-1)) + (1<<b);
	}
	return dp[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		int crnt = 1;
		for(int b = 30; b>=0; b--){
			if(n&(1<<b)){
				if(!cld[crnt][1]){
					cld[crnt][1] = ++idx;
				}
				crnt = cld[crnt][1];
			}
			else{
				if(!cld[crnt][0]){
					cld[crnt][0] = ++idx;
				}
				crnt = cld[crnt][0];
			}
		}
	}
	fill(dp+1, dp+1+idx, -1);
	cout << solve(1, 30);
}