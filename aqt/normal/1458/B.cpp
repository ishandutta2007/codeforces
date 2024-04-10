
// Problem : B. Glass Half Spilled
// Contest : Codeforces - Codeforces Round #691 (Div. 1)
// URL : https://codeforces.com/contest/1458/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
short a[105], b[105];
short dp[105][105][20005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> a[i] >> b[i];
		a[i] *= 2;
		b[i] *= 2;
	}
	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	for(int i = 1; i<=N; i++){
		for(int k = 0; k<=i; k++){
			for(int w = 0; w<=20000; w++){
				if(dp[i-1][k][w]+1){
					dp[i][k][w] = dp[i-1][k][w] + b[i]/2;
				}
				if(k && w >= a[i] && dp[i-1][k-1][w-a[i]]+1){
					dp[i][k][w] = max(dp[i][k][w], (short) (dp[i-1][k-1][w-a[i]] + b[i]));
				}
			}
		}
	}
	for(int k = 1; k<=N; k++){
		short ans = 0;
		for(short w = 0; w<=20000; w++){
			ans = max(ans, min(w, dp[N][k][w]));
		}
		long double out = ans/2.0;
		cout << out << " ";
	}
}