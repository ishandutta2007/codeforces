
// Problem : B. Up the Strip
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/B
// Memory Limit : 128 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD;
long long dp[4000005];
long long pre[4000005];

long long add(long long a, long long b){
	return (a + b) % MOD;
}

long long mult(long long a, long long b){
	return (a * b) % MOD;
}

long long sub(long long a, long long b){
	return ((a - b) % MOD + MOD)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> MOD;
	/*
	dp[1] = 1;
	long long pre = 1;
	for(int i = 2; i <= N; i++){
		dif[i] = 1;
	}
	for(int i = 2; i <= N; i++){
		for(int j = 1; j < i; j++){
			dp[i] = add(dp[i], dp[j]);
		}
		for(int x = 2; x <= N; x++){
			dp[i] = add(dp[i], dp[i/x]);
		}
	}
	for(int i = 1; i <= N; i++){
		cout << i << " " << dp[i] << "\n";
	}
	cout << dp[N] << "\n";
	*/
	dp[N] = 1;
	pre[N] = 1;
	long long tot = 1;
	for(int i = N-1; i; i--){
		dp[i] = tot;
		for(int x = 1; x * i <= N; x++){
			int r = max(x*i, i+1);
			int l = min(x*(i+1), N+1);
			if(r <= l){
				dp[i] = add(dp[i], sub(pre[r], pre[l]));
			}
			
			/*
			for(int j = max(x*i, i+1); j < x * (i+1); j++){
				dp[i] = add(dp[i], dp[j]);
			}
			*/
		}
		tot = add(dp[i], tot);
		pre[i] = add(dp[i], pre[i+1]);
	}
	cout << dp[1] << "\n";
}