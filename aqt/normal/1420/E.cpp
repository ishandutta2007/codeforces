
// Problem : E. Battle Lemmings
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[85];
int pos[85];
int dp[85][85][85*85/2];
int ans[85*85];
const int oo = INT_MAX/2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(arr[i] == 1){
			K++;
			pos[K] = i;
		}
	}
	for(int i = 0; i<=N+1; i++){
		for(int k = 0; k<=K; k++){
			for(int d = 0; d<=N*(N-1)/2; d++){
				dp[i][k][d] = oo;
			}
		}
	}
	dp[1][0][0] = 0;
	for(int i = 1; i<=N; i++){
		for(int k = 0; k<=K; k++){
			for(int d = 0; d<=N*(N-1)/2; d++){
				if(dp[i][k][d] != oo){
					if(k == K){
						dp[N+1][k][d] = min(dp[N+1][k][d], dp[i][k][d] + (N-i+2)*(N-i+1)/2);
					}
					else{
						for(int m = i; m<=N; m++){
							dp[m+1][k+1][d+abs(pos[k+1]-m)] = min(dp[m+1][k+1][d+abs(pos[k+1]-m)], dp[i][k][d] + (m-i)*(m-i+1)/2);
						}
					}
				}
			}
		}
	}
	for(int k = 0; k<=N*(N+1)/2; k++){
		ans[k] = (N-K)*(N-K+1)/2 - dp[N+1][K][k];
		//cout << k << " " << dp[N+1][K][k] << "\n";
		ans[k] = max(ans[k], ans[k-1]);
	}
	for(int k = 0; k<=N*(N-1)/2; k++){
		cout << ans[k] << " ";
	}
}