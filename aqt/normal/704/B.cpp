
// Problem : B. Ant Man
// Contest : Codeforces - Codeforces Round #366 (Div. 1)
// URL : https://codeforces.com/contest/704/problem/B
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, S, E;
long long dp[5005][5005];
long long x[5005], a[5005], b[5005], c[5005], d[5005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S >> E;
	for(int i = 1; i<=N; i++){
		cin >> x[i];
	}
	for(int j = 1; j<=N; j++){
		cin >> a[j];
	}
	for(int i = 1; i<=N;i++){
		cin >> b[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> c[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> d[i];
	}
	for(int i = 0 ; i<=N; i++){
		for(int j = 0; j<=N; j++){
			dp[i][j] = LLONG_MAX/2;
		}
	}
	dp[0][0] = 0;
	int hasS = 0, hasE = 0;
	if(1 == S){
		dp[1][1] = -x[1] + d[1];
	}
	else if(1 == E){
		dp[1][1] = -x[1] + b[1];
	}
	else{
		dp[1][1] = - 2*x[1] + d[1] + b[1];	
	}
	for(int i = 1; i<N-1; i++){
		if(i == S){
			hasS = 1;
		}
		else if(i == E) {
			hasE = 1;
		}
		for(int j = 1; j<=i; j++){
			//cout << i << " " << j << " " << dp[i][j] << "\n";
			if(j < hasS + hasE){
				continue;
			}
			if(i+1 == S){
				if(j > hasE){
					dp[i+1][j] = min(dp[i+1][j], dp[i][j] + x[i+1] + c[i+1]);
				}
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] - x[i+1] + d[i+1]);
			}
			else if(i+1 == E){
				if(j > hasS){
					dp[i+1][j] = min(dp[i+1][j], dp[i][j] + x[i+1] + a[i+1]);
				}
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] - x[i+1] + b[i+1]);
			}
			else{
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] - 2*x[i+1] + d[i+1] + b[i+1]);
				/*
				if(j >= hasS + hasE){
					dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i+1] + c[i+1]);
					dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b[i+1] + d[i+1]);
				}
				*/
				if(j > hasE){
					dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i+1] + d[i+1]);					
				}
				if(j > hasS){
					dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b[i+1] + c[i+1]);
				}
				if(j >= 2 && j-1 >= hasS + hasE){
					dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + 2*x[i+1] + a[i+1] + c[i+1]);
				}
			}
		}
	}
	if(N == E){
		cout << dp[N-1][1] + x[N] + a[N];
	}
	else if(N == S){
		cout << dp[N-1][1] + x[N] + c[N];
	}
	else{
		cout << dp[N-1][2] + 2*x[N] + c[N] + a[N] << "\n";
	}
}