
// Problem : E. Exam Cheating
// Contest : Codeforces - Codeforces Round #408 (Div. 2)
// URL : https://codeforces.com/contest/796/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int dp[2][1005][55][55];
bool arr[1005], brr[1005];

void cal(int &a, int b){
	a = max(a, b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	int X;
	cin >> X;
	while(X--){
		int n;
		cin >> n;
		arr[n] = 1;
	}
	cin >> X;
	while(X--){
		int n;
		cin >> n;
		brr[n] = 1;
	}
	if(M*K > 3*N){
		int cnt = 0;
		for(int n = 1;n <=N; n++){
			cnt += (arr[n] || brr[n]);
		}
		cout << cnt << "\n";
		return 0;
	}
	for(int j = 0; j<=M; j++){
		for(int a = 0; a<=K; a++){
			for(int b = 0; b<=K; b++){
				dp[0][j][a][b] = dp[1][j][a][b] = INT_MIN/2;
			}
		}
	}
	dp[0][0][0][0] = 0;
	for(int i = 0; i<=N; i++){
		for(int j = 0; j<=M; j++){
			for(int a = 0; a<=K; a++){
				for(int b = 0; b<=K; b++){
					dp[i&1^1][j][a][b] = INT_MIN/2;
				}
			}
		}
		for(int j = 0; j<=M; j++){
			for(int a = 0; a<=K; a++){
				for(int b = 0; b<=K; b++){
					if(!a && !b){
						cal(dp[i&1^1][j+1][K][0], dp[i&1][j][a][b] + arr[i+1]);
						cal(dp[i&1^1][j+1][0][K], dp[i&1][j][a][b] + brr[i+1]);
						cal(dp[i&1^1][j][0][0], dp[i&1][j][a][b]);
					}
					else if(!a){
						cal(dp[i&1^1][j+1][K][b-1], dp[i&1][j][a][b] + (arr[i+1] || (b-1 && brr[i+1])));					
						cal(dp[i&1^1][j][0][b-1], dp[i&1][j][a][b] + (brr[i+1] && b-1));
						cal(dp[i&1^1][j+1][0][K], dp[i&1][j][a][b] + (brr[i+1]));
					}
					else if(!b){
						cal(dp[i&1^1][j+1][a-1][K], dp[i&1][j][a][b] + (brr[i+1] || (a-1 && arr[i+1])));
						cal(dp[i&1^1][j][a-1][0], dp[i&1][j][a][b] + (a-1 && arr[i+1]));
						cal(dp[i&1^1][j+1][K][0], dp[i&1][j][a][b] + (arr[i+1]));
					}
					else{
						cal(dp[i&1^1][j][a-1][b-1], dp[i&1][j][a][b] + ((a-1 && arr[i+1])||(b-1 && brr[i+1])));
						cal(dp[i&1^1][j+1][K][b-1], dp[i&1][j][a][b] + (arr[i+1] || (b-1 && brr[i+1])));
						cal(dp[i&1^1][j+1][a-1][K], dp[i&1][j][a][b] + (brr[i+1] || (a-1 && arr[i+1])));
					}
					cal(dp[i&1^1][j+2][K][K], dp[i&1][j][a][b] + (arr[i+1] || brr[i+1]));		
					//cout << "dp: " << i << " " << j << " " << a << " " << b << "\n" << dp[i&1][j][a][b] << "\n";			
				}
			}
		}
	}
	int ans = 0;
	for(int j = 0; j<=M; j++){
		for(int a = 0; a<=K; a++){
			for(int b = 0; b<=K; b++){
				ans = max({ans, dp[0][j][a][b], dp[1][j][a][b]});
			}
		}
	}
	cout << ans << "\n";
}