
// Problem : E. Erase Subsequences
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
short dp[405][405];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;	
	while(T--){
		//cout << "testcase: " << T << "\n";
		string s, t;
		cin >> s >> t;
		N = s.size(), M = t.size();
		bool b = 0;
		for(int splt = 0; splt < M; splt++){
			//cout << "split: " << splt << "\n";
			for(int i = 0; i<=N; i++){
				for(int j = 0; j<=M; j++){
					dp[i][j] = -1;
				}
			}
			dp[0][0] = splt+1;
			for(int i = 0; i<N; i++){
				for(int j = 0; j<=splt+1; j++){
					if(dp[i][j] != -1){
						//cout << i << " " << j << " " << dp[i][j] << "\n";
						dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
						if(t[j] == s[i]){
							dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
						}
						if(dp[i][j] < M && t[dp[i][j]] == s[i]){
							dp[i+1][j] = max(dp[i+1][j], (short) (dp[i][j] + 1));
						}
					}
				}
			}
			for(int idx = 0; idx<=N; idx++){
				if(dp[idx][splt+1] == M){
					b = 1;
					break;
				}
			}
		}
		cout << (b ? "YES\n" : "NO\n");
	}
}