
// Problem : B. Kavi on Pairing Duty
// Contest : Codeforces - Codeforces Round #722 (Div. 1)
// URL : https://codeforces.com/contest/1528/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int fact[1000005];
long long dp[1000005];
const long long MOD = 998244353;

long long add(long long a, long long b){
	return (a + b)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			fact[j]++;
		}
	}
	dp[0] = 1;
	long long pre = 0;
	for(int i = 1; i <= N; i++){
		dp[i] = add(pre, fact[i]);
		pre = add(dp[i], pre);
	}
	cout << dp[N] << "\n";
}