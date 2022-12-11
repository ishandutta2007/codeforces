
// Problem : F. Emotional Fishermen
// Contest : Codeforces - Educational Codeforces Round 97 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1437/F
// Memory Limit : 1024 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[5005], lim[5005];
long long dp[5005][5005];
const long long MOD = 998244353;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	for(int i = 1; i<=N; i++){
		lim[i] = lim[i-1];
		while(arr[lim[i]+1]*2 <= arr[i]){
			lim[i]++;
		}
	}
	dp[0][0] = 1;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=lim[i]+1; j++){
			dp[i][j] = 1LL*(lim[i]+1-j+1)*dp[i][j-1];
			dp[i][j] += dp[lim[i]][j-1];
			dp[i][j] %= MOD;
		}
		dp[i][0] = 1;
		for(int j = 1; j<=lim[i]+1; j++){
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[N][N] << "\n";
}