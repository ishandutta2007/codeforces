
// Problem : D. Memory and Scores
// Contest : Codeforces - Codeforces Round #370 (Div. 2)
// URL : https://codeforces.com/contest/712/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int OFF = 150000;
const int MOD = 1e9+7;
const int LIM = 125000;
long long dp1[105][300005], dp2[105][300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int A, B, K, T;
	cin >> A >> B >> K >> T;
	dp1[0][A+OFF] = 1;
	dp2[0][B+OFF] = 1;
	for(int t = 1; t<=T; t++){
		for(int k = -LIM; k<=LIM; k++){
			dp1[t][k+OFF-K] += dp1[t-1][k+OFF];
			dp1[t][k+OFF+K+1] -= dp1[t-1][k+OFF];
			dp2[t][k+OFF+K+1] -= dp2[t-1][k+OFF];
			dp2[t][k+OFF-K] += dp2[t-1][k+OFF];
		}
		for(int k = -LIM-K; k<=LIM+K+1; k++){
			dp1[t][k+OFF] += dp1[t][k+OFF-1];
			dp1[t][k+OFF] %= MOD;
			dp1[t][k+OFF] += MOD;
			dp1[t][k+OFF] %= MOD;
			dp2[t][k+OFF] += dp2[t][k+OFF-1];
			dp2[t][k+OFF] %= MOD;
			dp2[t][k+OFF] += MOD;
			dp2[t][k+OFF] %= MOD;
		}
	}
	int sum = 0;
	long long ans = 0;
	for(int k = -LIM; k<=LIM; k++){
		ans += 1LL * sum * dp1[T][k+OFF];
		ans %= MOD;
		sum += dp2[T][k+OFF];
		sum %= MOD;
	}
	cout << ans;
}