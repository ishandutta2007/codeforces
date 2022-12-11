
// Problem : C. Kleof and the n-thlon
// Contest : Codeforces - Codeforces Round #333 (Div. 1)
// URL : https://codeforces.com/contest/601/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, P;
long double dp[105][100005];
int arr[105];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		P += arr[i];
	}
	if(M == 1){
		cout << 1 << "\n";
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i<=N; i++){
		partial_sum(dp[i-1], dp[i-1]+N*M+1, dp[i-1]);
		for(int j = 1; j<=N*M; j++){
			dp[i][j] = dp[i-1][j-1];
			if(j > M){
				dp[i][j] -= dp[i-1][j-M-1];
			}
			if(j >= arr[i]){
				dp[i][j] -= dp[i-1][j-arr[i]];
				if(j >= arr[i]+1){
					dp[i][j] += dp[i-1][j-arr[i]-1];
				}
			}
			dp[i][j] *= 1.0/(M-1);
		}
	}
	partial_sum(dp[N], dp[N]+N*M+1, dp[N]);
	cout << setprecision(10) << (M-1)*dp[N][P-1]+1 << "\n";
}