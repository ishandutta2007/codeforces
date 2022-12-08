#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int n, r, f[50], s[50], p[50], sum[51];
ld dp[51][5001];

int main() {
	cin >> n >> r;
	for(int i = 0; i < n; i++) cin >> f[i] >> s[i] >> p[i], sum[i + 1] = sum[i] + s[i];
	ld bl = 0, br = 1e15;
	for(int cc = 0; cc < 120; cc++) {
		ld bm = 0.5 * (bl + br);
		for(int j = 0; j <= sum[n]; j++)
			if(j <= r) dp[n][j] = 0;
			else dp[n][j] = bm;
		for(int i = n - 1; i >= 0; i--)
			for(int j = 0; j <= sum[i]; j++) {
				dp[i][j] = 0.01 * ((dp[i + 1][j + f[i]] + f[i]) * p[i] + (dp[i + 1][j + s[i]] + s[i]) * (100 - p[i]));
				if(i != 0) dp[i][j] = min(dp[i][j], bm);
			}
		if(dp[0][0] > bm) bl = bm;
		else br = bm;
	}
	cout.precision(15);
	cout << fixed << bl;
}