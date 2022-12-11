// Problem : D. Beautiful Pairs of Numbers
// Contest : Codeforces - Codeforces Round #236 (Div. 1)
// URL : https://codeforces.com/contest/403/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, K;
int M = 2000;
long long pas[2005][2005];
long long dp[55][2005];
const long long MOD = 1e9+7;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i<=M; i++){
		pas[i][0] = 1;
		for(int j = 1; j<=i; j++){
			pas[i][j] = add(pas[i-1][j-1], pas[i-1][j]);
		}
	}
	dp[0][0] = 1;
	for(int l = 1; l<=1000; l++){
		for(int k = 50; k; k--){
			for(int n = 1000; n>=l; n--){
				dp[k][n] = add(dp[k][n], dp[k-1][n-l]);
			}
		}
	}
	cin >> T;
	while(T--){
		cin >> N >> K;
		if(K > 50){
			cout << 0 << "\n";
			continue;
		}
		long long ans = 0;
		for(int n = 1; n<=N; n++){
			ans = add(ans, mult(dp[K][n], pas[N-n+K][K]));
		}
		for(int k = 1; k<=K; k++){
			ans = mult(ans, k);
		}
		cout << ans << "\n";
	}
}