
// Problem : F. Subsequences of Length Two
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[205][205][205];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	string s, t;
	cin >> s >> t;
	if(t[0] == t[1]){
		int cnt = 0;
		for(char n : s){
			cnt += (n == t[0]);
		}
		cnt += K;
		cnt = min(cnt, N);
		cout << cnt*(cnt-1)/2;
		return 0;
	}
	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	for(int i = 0; i<N; i++){
		for(int f = 0; f<N; f++){
			for(int k = 0; k<=K; k++){
				if(dp[i][f][k] + 1 == 0){
					continue;
				}
				if(s[i] == t[0]){
					dp[i+1][f+1][k] = max(dp[i+1][f+1][k], dp[i][f][k]);
				}
				else{
					dp[i+1][f+1][k+1] = max(dp[i+1][f+1][k+1], dp[i][f][k]);
				}
				if(s[i] == t[1]){
					dp[i+1][f][k] = max(dp[i+1][f][k], dp[i][f][k] + f);
				}
				else{
					dp[i+1][f][k+1] = max(dp[i+1][f][k+1], dp[i][f][k] + f);
				}
				dp[i+1][f][k] = max(dp[i+1][f][k], dp[i][f][k]);
			}
		}
	}
	int ans = 0;
	for(int f = 0; f<=N; f++){
		for(int k = 0; k<=K;k ++){
			ans = max(dp[N][f][k], ans);
		}
	}
	cout << ans;
}