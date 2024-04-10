
// Problem : D. Maxim and Increasing Subsequence
// Contest : Codeforces - Codeforces Round #160 (Div. 1)
// URL : https://codeforces.com/contest/261/problem/D
// Memory Limit : 256 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int Q, N, M, T;
vector<pair<int, int>> dp[100005];
vector<int> nxt[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> Q >> N >> M >> T;
	for(int i = 0; i<=N+1; i++){
		dp[i].resize(M+1);
		nxt[i].resize(M+1);
	}
	while(Q--){
		vector<int> v;
		for(int i = 0; i<=N+1; i++){
			fill(dp[i].begin(), dp[i].end(), make_pair(T+1, 0));
			fill(nxt[i].begin(), nxt[i].end(), 3*N);
		}
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
			nxt[i-1][n] = i-1;
		}
		for(int i = N-1; i>=0; i--){
			for(int j = 1; j<=M; j++){
				nxt[i][j] = min(nxt[i+1][j], nxt[i][j]);
			}
		}
		for(int i = N-1; i>=0; i--){
			for(int j = 1; j<=M; j++){
				nxt[i][j] = min(nxt[i][j], nxt[0][j] + N);
			}
		}
		dp[0][0] = {0, 0};
		for(int i = 0; i<=N; i++){
			for(int j = 0; j<M; j++){
				//cout << j+1 << " " << nxt[dp[i][j].second][j+1] << "\n";
				if(nxt[dp[i][j].second][j+1] < 3*N){
					pair<int, int> p = make_pair(dp[i][j].first + (nxt[dp[i][j].second][j+1] >= N), 
					nxt[dp[i][j].second][j+1] % N);
					dp[i+1][j+1] = min(p, dp[i+1][j+1]);
					//cout << i+1 << " " << j+1 << " " << dp[i+1][j+1].first << " " << dp[i+1][j+1].second << "\n";				
				}
				//cout << " " << dp[i+1][j+1].first << " " << dp[i+1][j+1].second << "\n";
				//cout << "opt2: " << i << " " << j << " " << dp[i][j].first << " " << dp[i][j].second << "\n";
				dp[i][j+1] = min(dp[i][j], dp[i][j+1]);
			}
		}
		int ans = 0;
		for(int i = 0; i<=N; i++){
			//cout << " " << i << " " << M << " " << dp[i][M].first << " " << dp[i][M].second << "\n";
			if(dp[i][M] < make_pair(T, 0)){
				ans = i;
			}
		}
		cout << ans << "\n";
	}
}