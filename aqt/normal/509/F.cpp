
// Problem : F. Progress Monitoring
// Contest : Codeforces - Codeforces Round #289 (Div. 2, ACM ICPC Rules)
// URL : https://codeforces.com/contest/509/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[505];
long long dp[2][505][505];
const long long MOD = 1e9+7;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long solve(bool hasrt, int l, int r){
	if(l > r){
		return 1;
	}
	if(1+dp[hasrt][l][r]){
		return dp[hasrt][l][r];
	}
	if(hasrt){
		return dp[hasrt][l][r] = solve(0, l+1, r);
	}
	dp[hasrt][l][r] = solve(1, l, r);
	for(int i = l+1; i<=r; i++){
		if(arr[l] <= arr[i]){
			dp[hasrt][l][r] += solve(1, l, i-1) * solve(0, i, r);
			dp[hasrt][l][r] %= MOD;
		}
	}
	return dp[hasrt][l][r];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1, 1, N);
}