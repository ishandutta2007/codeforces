
// Problem : D. Bacterial Melee
// Contest : Codeforces - 8VC Venture Cup 2017 - Final Round
// URL : https://codeforces.com/problemset/problem/756/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long dp[5005][5005], bad[30][5005], pre[5005];
const long long MOD = 1e9+7;
long long fact[5005];

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret = qikpow(a, b/2);
	ret *= ret;
	ret %= MOD;
	if(b&1){
		ret *= a;
		ret %= MOD;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	fact[0] = 1;
	dp[0][0] = 1;
	pre[0] = 1;
	for(int i =1 ; i<=N; i++){
		char c;
		cin >> c;
		fact[i] = (fact[i-1] * i)%MOD;
		for(int k = 1; k<=i; k++){
			dp[i][k] = pre[k-1];
			dp[i][k] = (dp[i][k] - bad[c-'a'][k-1] + MOD) % MOD;
			//cout << dp[i][k] << "\n";
			dp[i][k] = (dp[i][k] - bad[c-'a'][k] + MOD) %MOD;
			//cout << i << " " << k << " " << dp[i][k] << "\n"; 
		}
		for(int k = 1; k<=i; k++){
			bad[c-'a'][k] = (bad[c-'a'][k] + dp[i][k])%MOD;
			pre[k] = (pre[k] + dp[i][k])%MOD;
		}
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		//cout << pre[i] << " " << pre[i] * (fact[N-1] * qikpow(fact[i-1]*fact[N-i]%MOD, MOD-2))%MOD<< "\n";
		//cout << dp[N][i] << "\n";
		//cout << fact[N-1] <<" " <<  i-1 << " " <<N-i << "\n";
		//cout << fact[i-1]*fact[N-i]%MOD << "\n";
		//cout << (fact[N-1] * qikpow(fact[i-1]*fact[N-i]%MOD, MOD-2))%MOD << "\n";
		//cout << (fact[N-1] * qikpow(fact[i-1]*fact[N-i]%MOD, MOD-2))%MOD << "\n";
		ans += pre[i] * fact[N-1]%MOD * qikpow(fact[i-1]*fact[N-i]%MOD, MOD-2)%MOD;
		ans %= MOD;
	}
	cout << ans;
}