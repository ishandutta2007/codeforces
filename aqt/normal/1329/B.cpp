
// Problem : B. Dreamoon Likes Sequences
// Contest : Codeforces Round #631 (Div. 1) - Thanks, Denis aramis Shitov!
// URL : https://codeforces.com/contest/1329/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
long long dp[40];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int K;
		long long MOD;
		cin >> K >> MOD;
		int L = 31 - __builtin_clz(K);
		for(int i = 0; i<=L; i++){
			dp[i] = 1;
			for(int j = 0; j<i; j++){
				dp[i] += dp[j];
			}
			dp[i] %= MOD;
			if(i == L){
				dp[i] *= (K-(1<<L)+1);
			}
			else{
				dp[i] *= (1<<i);
			}
			dp[i] %= MOD;
		}
		partial_sum(dp, dp+1+L, dp);
		cout << dp[L]%MOD << "\n";
	}
}