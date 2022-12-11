
// Problem : E. Clear the Multiset
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1400/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[5005];
int dp[5005][5005];
int mn[5005][5005];

long long solve(int l, int r, int t){
	if(l > r){
		return 0;
	}
	long long ret = r - l + 1;
	ret = min(ret, solve(l, mn[l][r]-1, arr[mn[l][r]]) + solve(mn[l][r]+1, r, arr[mn[l][r]]) + arr[mn[l][r]] - t);
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int l = 1; l<=N; l++){
		mn[l][l] = l;
		dp[l][l] = 1;
		for(int r = l+1; r<=N; r++){
			mn[l][r] = (arr[mn[l][r-1]] <= arr[r] ? mn[l][r-1] : r);
			dp[l][r] = r - l + 1;
		}
	}
	cout << solve(1, N, 0) << "\n";
}