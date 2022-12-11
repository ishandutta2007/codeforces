
// Problem : D. My pretty girl Noora
// Contest : Codeforces - Codeforces Round #422 (Div. 2)
// URL : https://codeforces.com/contest/822/problem/D
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long b, l, r;
int sieve[5000005];
long long dp[5000005];
const long long MOD = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> b >> l >> r;
	fill(sieve, sieve+1+r, INT_MAX/2);
	for(int i = 2; i<=r; i++){
		if(INT_MAX/2 == sieve[i]){
			for(int j = i; j<=r ;j += i){
				sieve[j] = min(sieve[j], i);
			}
		}
		int p = sieve[i];
		dp[i] = (dp[i/p] + 1LL*(i/p)*p*(p-1)/2)%MOD;
	}
	long long ans = 0;
	for(int i = r; i>=l; i--){
		ans *= b;
		ans += dp[i];
		ans %= MOD;
	}
	cout << ans;
}