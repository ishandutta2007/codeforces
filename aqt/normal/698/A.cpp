
// Problem : A. Vacations
// Contest : Codeforces - Codeforces Round #363 (Div. 1)
// URL : https://codeforces.com/contest/698/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[3][105];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int m;
		cin >> m;
		dp[0][i] = max(dp[0][i-1], max(dp[1][i-1], dp[2][i-1]));
		if(m&1){
			dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + 1;
		}
		if(m>>1&1){
			dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + 1;
		}
	}
	int ans = max({dp[0][N], dp[1][N], dp[2][N]});
	cout << N - ans << "\n";
}