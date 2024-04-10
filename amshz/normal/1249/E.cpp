# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;

int a[xn], b[xn], dp[xn][2];

int main(){
		int n, c;
		cin >> n >> c;
		for (int i=1; i<n; i++) cin >> a[i];
		for (int i=1; i<n; i++) cin >> b[i];
		dp[0][0] = 0;
		dp[0][1] = c;
		for (int i=1; i<n; i++){
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i];
			dp[i][1] = min(dp[i-1][0]+c+b[i], dp[i-1][1]+b[i]);
		}
		for (int i=0; i<n; i++) cout << min(dp[i][0], dp[i][1]) << ' ';
}