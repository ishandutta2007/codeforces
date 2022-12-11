
// Problem : B. The Cake Is a Lie
// Contest : Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1519/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

bool dp[105][105][10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	dp[1][1][0] = 1;
	for(int i = 1; i<=100; i++){
		for(int j = 1; j<=100; j++){
			for(int k = 0; k<=10000; k++){
				if(dp[i][j][k] && k + i <= 10000){
					dp[i][j+1][k+i] = 1;
				}
				if(dp[i][j][k] && k + j <= 10000){
					dp[i+1][j][k+j] = 1;
				}
			}
		}
	}
	while(T--){
		int N, M, K;
		cin >> N >> M >> K;
		if(dp[N][M][K]){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}	
}