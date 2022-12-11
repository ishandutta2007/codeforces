#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

// Problem : C. The Hard Work of Paparazzi
// Contest : Codeforces - Codeforces Global Round 11
// URL : https://codeforces.com/contest/1427/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[100005];
int mx[100005];
int t[100005], x[100005], y[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	x[0] = y[0] = 1;
	int ans = 0;
	for(int i = 1; i<=K; i++){
		cin >> t[i] >> x[i] >> y[i];
		dp[i] = -1e6;
		for(int j = i-1; j>=max(0, i-3*N-5); j--){
			if(dp[j] >= 0 && dp[i] < dp[j]+1 && abs(x[i]-x[j]) + abs(y[i]-y[j]) <= t[i] - t[j]){
				dp[i] = dp[j] + 1;
			}
		}
		mx[i] = max(mx[i-1], dp[i]);
		if(i >= 3*N+5){
			dp[i] = max(dp[i], mx[i-3*N-5]+1);
		}
	}
	cout << mx[K];
}