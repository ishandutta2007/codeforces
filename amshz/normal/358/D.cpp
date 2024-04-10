# include <bits/stdc++.h>

using namespace std;

const int xn = 3e3+10;
int a[xn], b[xn], c[xn], dp[xn][5];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	for (int i=0; i<n; i++) cin >> c[i];
	dp[0][0] = a[0];
	dp[0][1] = -1e9-10;
	dp[0][2] = b[0];
	dp[0][3] = -1e9-10;
	
	for (int i=1; i<n; i++){
		dp[i][0] = max(dp[i-1][2], dp[i-1][3]) + a[i];
		dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + b[i];
		dp[i][2] = max(dp[i-1][2], dp[i-1][3]) + b[i];
		dp[i][3] = max(dp[i-1][0], dp[i-1][1]) + c[i];
	}
	cout << max(dp[n-1][0], dp[n-1][1]);
}