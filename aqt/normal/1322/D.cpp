
// Problem : D. Reality Show
// Contest : Codeforces - Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1322/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[2005];
int val[2005];
int ual[4005];
int dp[4005][2005];
const int oo = INT_MAX/2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = N; i; i--){
		cin >> arr[i];
	}
	for(int i = N; i; i--){
		cin >> val[i];
	}
	for(int i = 1; i<=N+M; i++){
		cin >> ual[i];
	}
	for(int i = 1; i<=N+M; i++){
		for(int j = 1; j<=N; j++){
			dp[i][j] = -oo;
		}
	}
	int ans = 0;
	for(int i = 1; i<=N; i++){
		//cout << "idx: " << i << "\n";
		for(int c = i; c; c--){
			if(dp[arr[i]][c-1] != -oo){
				dp[arr[i]][c] = max(dp[arr[i]][c], dp[arr[i]][c-1] - val[i] + ual[arr[i]]);
				//ans = max(ans, dp[arr[i]][c]);
				//cout << c << " " << dp[arr[i]][c] << "\n";
			}
		}
		int k = i;
		for(int t = arr[i]; t<N+M; t++){
			for(int c = 0; c<=k; c++){
				if(dp[t][c] != -oo){
					dp[t+1][c/2] = max(dp[t+1][c/2], dp[t][c] + c/2*ual[t+1]);
					//ans = max(dp[t+1][c/2], ans);
				}
			}
			k /= 2;
		}
	}
	for(int k = 0; k<=N+M; k++){
		ans = max(dp[k][0], ans);
	}
	cout << ans;
}