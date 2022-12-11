
// Problem : F. Decreasing Heights
// Contest : Codeforces - Codeforces Round #642 (Div. 3)
// URL : https://codeforces.com/contest/1353/problem/F
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
//vector<long long> v;
int N, M;
long long arr[105][105];
long long dp[105][105];

long long solve(long long st){
	if(arr[1][1] >= st){
		dp[1][1] = arr[1][1]-st;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				if(i == 1 && j == 1){
					continue;
				}
				dp[i][j] = LLONG_MAX/2;
				if(arr[i][j] >= st){
					if(i != 1){
						dp[i][j] = min(dp[i][j], dp[i-1][j] + arr[i][j] - st);
					}
					if(j != 1){
						dp[i][j] = min(dp[i][j], dp[i][j-1] + arr[i][j] - st);
					}
				}
			}
		}
		return dp[N][M];
	}
	else{
		return LLONG_MAX/2;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cin >> arr[i][j];
				arr[i][j] -= i + j;
			}
		}
		long long ans = LLONG_MAX/2;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				ans = min(ans, solve(arr[i][j]));
			}
		}
		cout << ans << "\n";
	}
}