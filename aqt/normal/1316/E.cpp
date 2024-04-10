
// Problem : E. Team Building
// Contest : Codeforces - CodeCraft-20 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1316/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, P, K;
int val[8][100005];
pair<int, int> srt[100005];
long long dp[100005][1<<8];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P >> K;
	for(int i = 1; i<=N; i++){
		cin >> srt[i].first;
		srt[i].second = i;
	}
	for(int i = 1; i<=N; i++){
		for(int k = 0; k<P; k++){
			cin >> val[k][i];
		}
	}
	sort(srt+1, srt+1+N, greater<pair<int, int>>());
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i<=N; i++){
		for(int m = 0; m<1<<P; m++){
			if(i - __builtin_popcount(m) <= K){
				if(dp[i-1][m] != -1){
					dp[i][m] = dp[i-1][m] + srt[i].first;
				}
			}
			else{
				dp[i][m] = dp[i-1][m];
			}
			for(int k = 0; k<P; k++){
				if(m>>k&1){
					if(dp[i-1][m^(1<<k)] != -1){
						dp[i][m] = max(dp[i][m], dp[i-1][m^(1<<k)] + val[k][srt[i].second]);
					}
				}
			}
			//cout << i << " " << m << " " << dp[i][m] << "\n";
		}
	}
	cout << dp[N][(1<<P)-1] << "\n";
}