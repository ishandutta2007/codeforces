#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k , d;
    cin >> n >> k >> d;
    long long dp[n + 1][2]; // 0, 1
    dp[0][0] = 1; dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
    	dp[i][0] = dp[i][1] = 0;
    	for (int j = 1; j <= k; ++j) {
    		if (i - j < 0) break;
    		dp[i][0] += dp[i - j][0];
			if (j >= d) dp[i][1] += dp[i - j][0]; 
    		else dp[i][1] += dp[i - j][1];
			dp[i][0] %= mod;
			dp[i][1] %= mod;
		}
		//cout << dp[i][0] << ' ' << dp[i][1] << endl;
	}
	cout << dp[n][1] << endl;
}