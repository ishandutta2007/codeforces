
// Problem : D. Sum of Paths
// Contest : Codeforces - Codeforces Round #695 (Div. 2)
// URL : https://codeforces.com/contest/1467/problem/D
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, Q;
long long arr[5005];
long long dp[5005][5005];
long long tot[5005];
const long long MOD = 1e9+7;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long sub(long long a, long long b){
	return ((a - b)%MOD + MOD)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int n = 1; n<=N; n++){
		dp[0][n] = 1;
	}
	for(int l = 1; l<=K; l++){
		for(int n = 1; n<=N; n++){
			if(n != 1){
				dp[l][n] = dp[l-1][n-1];
			}
			if(n != N){
				dp[l][n] = add(dp[l][n], dp[l-1][n+1]);
			}
		}
	}
	for(int l = 0; l<=K; l++){
		for(int n = 1; n<=N; n++){
			tot[n] = add(tot[n], mult(dp[l][n], dp[K-l][n]));
		}
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		ans = add(ans, mult(arr[i], tot[i]));
	}
	while(Q--){
		int n, v;
		cin >> n >> v;
		ans = sub(ans, mult(arr[n], tot[n]));
		arr[n] = v;
		ans = add(ans, mult(arr[n], tot[n]));
		cout << ans << "\n";
	}
}