
// Problem : E. Kuro and Topological Parity
// Contest : Codeforces - Codeforces Round #482 (Div. 2)
// URL : https://codeforces.com/problemset/problem/979/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, P;
int arr[55];
long long dp[2][55][55][55][55];
long long pas[55][55];
long long pows[55];
const long long MOD = 1e9+7;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P;
	dp[0][0][0][0][0] = 1;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	pows[0] = 1;
	for(int i = 1; i<=N; i++){
		pows[i] = mult(pows[i-1], 2);
	}
	for(int i = 0; i<=N; i++){
		pas[i][0] = 1;
		for(int j = 1; j<=i; j++){
			pas[i][j] = add(pas[i-1][j-1], pas[i-1][j]);
		}
	}
	long long ans = 0;
	for(int w0 = 0; w0 <= N; w0++){
		for(int w1 = 0; w1 <= N; w1++){
			for(int b0 = 0; b0 <= N; b0++){
				for(int b1 = 0; b1 <= N; b1++){
					if(w0+w1+b0+b1 >= N){
						if(w0+w1+b0+b1 == N){
							ans = add(ans, dp[P][w0][w1][b0][b1]);
						}
						break;
					}
					int idx = w0+w1+b0+b1+1;
					for(int p = 0; p<2; p++){
						if(arr[idx] != 1){
							for(int k = 0; k<=b0; k++){
								dp[p^(k&1)^1][w0+(k&1^1)][w1+(k&1)][b0][b1] = add(dp[p^(k&1)^1][w0+(k&1^1)][w1+(k&1)][b0][b1], 
								mult(dp[p][w0][w1][b0][b1], mult(pas[b0][k], pows[idx-b0-1])));
							}
						}
						if(arr[idx] != 0){
							for(int k = 0; k<=w0; k++){
								dp[p^(k&1)^1][w0][w1][b0+(k&1^1)][b1+(k&1)] = add(dp[p^(k&1)^1][w0][w1][b0+(k&1^1)][b1+(k&1)], 
								mult(dp[p][w0][w1][b0][b1], mult(pas[w0][k], pows[idx-w0-1])));
							}
						}
					}
				}
			}
		}
	}
	cout << ans;
}