
// Problem : B. Zuma
// Contest : Codeforces - Codeforces Round #336 (Div. 1)
// URL : https://codeforces.com/contest/607/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[505];
int dp[505][505];

int solve(int l, int r){
	if(l > r){
		return 0;
	}
	if(dp[l][r] + 1){
		return dp[l][r];
	}
	dp[l][r] = INT_MAX;
	for(int i = l; i<=r; i++){
		if(arr[i] == arr[l]){
			dp[l][r] = min(dp[l][r], max(0, solve(l+1, i-1)-1) + solve(i+1, r) + 1);
		}
	}
	return dp[l][r];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i= 1; i<=N; i++){
		cin >> arr[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1, N) << "\n";
}