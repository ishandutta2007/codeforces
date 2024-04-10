
// Problem : D. Increase Sequence
// Contest : Codeforces Round #266 (Div. 2)
// URL : https://codeforces.com/contest/466/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, H;
int arr[2005];
long long dp[2005][2005];
int add[2005];
long long MOD = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> H;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		arr[i] = H - arr[i];
	}
	for(int i = 1; i<=N+1; i++){
		if(abs(arr[i] - arr[i-1]) > 1){
			cout << 0 << "\n";
			return 0;
		}
		else if(arr[i] > arr[i-1]){
			add[i]++;
		}
		else if(arr[i] < arr[i-1]){
			add[i]--;
		}
	}
	dp[0][0] = 1;
	for(int i = 1; i<=N; i++){
		for(int j = 0; j<=N; j++){
			if(add[i] == 1){
				if(j > 0){
					dp[i][j] = dp[i-1][j-1];
				}
			}
			else if(add[i] == 0){
				dp[i][j] = dp[i-1][j];
				if(j > 0){
					dp[i][j] += dp[i-1][j-1]*arr[i-1];
					dp[i][j] %= MOD;
				}
			}
			else{
				dp[i][j] = dp[i-1][j]*arr[i-1]%MOD;
			}
		}
	}
	/*
	for(int i = 1; i<=N; i++){
		for(int j = 0; j<=N; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	long long ans = 0;
	for(int i = 0; i<=N; i++){
		ans += dp[N][i];
		ans %= MOD;
	}
	cout << ans << "\n";
}