
// Problem : F. Even Harder
// Contest : Codeforces - Codeforces Round #688 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1453/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[3005];
int dp[3005][3005];
int dif[3005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			for(int j = 1; j<=N+1; j++){
				dp[i][j] = INT_MAX/4;
			}
		}
		dp[1][1] = 0;
		for(int i = 1; i<=N; i++){
			fill(dif, dif+2+N, 1);
			int cnt = 0;
			for(int j = i; j<=arr[i]+i; j++){
				//cout << dp[i][j] << " " << i << " " << j << " " << cnt << "\n";
				if(i != j){
					cnt += dif[j];
					dif[arr[j]+j+1]--;
					dp[j][arr[i]+i+1] = min(dp[j][arr[i]+i+1], dp[i][j] + cnt - 1);
				}
				dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
			}
		}
		cout << dp[N][N+1] << "\n";
	}
}