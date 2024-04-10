//dp[i][j][b]ij(0)/(1)complexity 
#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int qmin(int a, int b){
	return (a < b) ? a : b;
}

int n;
int p[111];
int dp[111][111][2];

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &p[i]);
	memset(dp, 0x3f, sizeof(dp));
	if(p[0] > 0) dp[0][(p[0] & 1) ^ 1][(p[0] & 1) ^ 1] = 0;
	else {
		dp[0][0][0] = 0;
		dp[0][1][1] = 0;
	}
	for(int i = 1; i < n; i++){
		if(p[i] > 0){
			bool op = p[i] & 1;
			op ^= 1;
			rep(j, n/2+1){
				dp[i][j+op][op] = qmin(dp[i][j+op][op], qmin(dp[i-1][j][op], dp[i-1][j][op^1] + 1));
			}
		} else {
			rep(op, 2){
				rep(j, n/2+1){
					dp[i][j+op][op] = qmin(dp[i][j+op][op], qmin(dp[i-1][j][op], dp[i-1][j][op^1] + 1));
				}
			}
		}
	}
	cout << qmin(dp[n-1][n/2][0], dp[n-1][n/2][1]) << endl;
	return 0;
}