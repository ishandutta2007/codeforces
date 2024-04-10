
// Problem : A. Alternative Thinking
// Contest : Codeforces - Codeforces Round #334 (Div. 1)
// URL : https://codeforces.com/contest/603/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int dp[2][4][100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	int ans = 0;
	for(int i = 1; i<=N; i++){
		for(int k = 0; k<2; k++){
			for(int j = 0; j<4; j++){
				dp[k][j][i] = dp[k][j][i-1];
			}
		}
		int c = s[i-1] - '0';
		dp[c][1][i] = dp[c^1][1][i-1] + 1;
		dp[c][2][i] = max(dp[c][1][i-1], dp[c^1][2][i-1]) + 1;
		dp[c][3][i] = max(dp[c][2][i-1], dp[c^1][3][i-1]) + 1;
		for(int k = 0; k<2; k++){
			for(int j = 0; j<4; j++){
				ans = max(dp[k][j][i], ans);
			}
		}
	}
	cout << ans;
}