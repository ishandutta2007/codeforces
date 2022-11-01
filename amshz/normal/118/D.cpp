# include <bits/stdc++.h>

using namespace std;

const int xn = 2e2+10;
const int md = 1e8;
long long dp[xn][xn][2], p[xn][2][2];

int main(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int sm = n+m;
	//for (int i=1; i<=n; i++) dp[i][1][1] = 1;
	//for (int i=1; i<=m; i++) dp[1][i][0] = 1;
	dp[0][0][0] = 1, dp[0][0][1] = 1;
	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			for (int k=1; k<=min(300,a); k++) if (i-k >= 0) dp[i][j][0] += dp[i-k][j][1], dp[i][j][0] %= md;
			for (int k=1; k<=min(300,b); k++) if (j-k >= 0) dp[i][j][1] += dp[i][j-k][0], dp[i][j][1] %= md;
		}
	}
	//cout << dp[0][4
	cout << (dp[n][m][0]+dp[n][m][1])%md;
}