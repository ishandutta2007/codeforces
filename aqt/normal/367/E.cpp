
// Problem : E. Sereja and Intervals
// Contest : Codeforces Round #215 (Div. 1)
// URL : https://codeforces.com/contest/367/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long dp[2][405][405];
long long MOD = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, X;
	cin >> N >> M >> X;
	if(N > M){
		cout << 0 << "\n";
		return 0;
	}	
	dp[0][0][0] = 1;
	for(int i = 1; i<=M; i++){
		for(int j = 0; j<=N; j++){
			for(int k = 0; k<=N; k++){
				dp[i&1][j][k] = 0;
			}
		}
		for(int j = 0; j<=N; j++){
			for(int k = 0; k<=N; k++){
				if(i == X){
					if(j){
						dp[i&1][j][k] = dp[i&1^1][j-1][k];
					}
					if(k){
						dp[i&1][j][k] += dp[i&1^1][j][k-1];
					}
					if(j && k){
						//dp[i&1][j][k] += dp[i&1^1][j][k-1];
					}
				}
				else{
					dp[i&1][j][k] = dp[i&1^1][j][k];
					if(j) {
						dp[i&1][j][k] += dp[i&1^1][j-1][k]; //[
					}
					if(k){
						dp[i&1][j][k] += dp[i&1^1][j+1][k-1]; //]
						dp[i&1][j][k] += dp[i&1^1][j][k-1]; //[]
					}
					if(j && k){
						//dp[i&1][j][k] += dp[i&1^1][j][k-1]; //][
					}
				}
				dp[i&1][j][k] %= MOD;
			}
		}
	}
	long long ans = dp[M&1][0][N];
	for(int i = 1; i<=N; i++){
		ans *= i;
		ans %= MOD;
	}
	cout << ans << "\n";
}