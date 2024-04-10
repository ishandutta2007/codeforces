
// Problem : F. Vasya and Endless Credits
// Contest : Codeforces - Educational Codeforces Round 59 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1107/problem/F
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[505][505];
pair<long long, pair<long long, long long>> arr[505];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].second.first >> arr[i].first >> arr[i].second.second;
	}
	sort(arr+1, arr+1+N, greater<pair<int, pair<int, int>>>());
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 0; j<=i; j++){
			dp[i][j] = dp[i-1][j];
			dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i].second.first - arr[i].first * arr[i].second.second);
			if(j){
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + arr[i].second.first - arr[i].first * (j-1));
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
}