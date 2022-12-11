#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")
// Problem : E. Bash Plays with Functions
// Contest : Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/757/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
long long dp[22][1000005];
const long long MOD = 1e9+7;
int pr[1000005];
bool sieve[1000005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int i = 2; i<=1000000; i++){
		if(!sieve[i]){
			for(int j = i; j<=1000000; j+=i){
				sieve[j] = 1;
				pr[j] = i;
			}
		}
	}
	fill(dp[0], dp[0]+1000001, 1);
	for(int p = 1; p<=20;p++){
		dp[p][0] = 2;
		for(int n = 1; n<=1000000; n++){
			dp[p][n] = (dp[p-1][n] + dp[p][n-1])%MOD;
		}
	}
	while(T--){
		long long r, n;
		cin >> r >> n;
		long long ans = 1;
		while(n-1){
			int p = pr[n];
			int cnt = 0;
			while(n%p == 0){
				n/=p;
				cnt++;
			}
			ans *= dp[cnt][r];
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}