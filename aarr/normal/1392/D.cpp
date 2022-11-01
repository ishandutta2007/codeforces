#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5, inf = 1000 * 1000 * 1000 + 7, F = 16;

int dp[N][20];

int get(int x, int y) {
	return (x >> y) & 1;
}

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		string s;
		cin >> n >> s;
		for (int mask = 0; mask < 16; mask++) {
			dp[1][mask] = 0;
			if (get(mask, 0) != get(mask, 2)) {
				dp[1][mask] = inf;
			}
			if (get(mask, 1) != get(mask, 3)) {
				dp[1][mask] = inf;
			}
			if (get(mask, 0) ^ (s[0] == 'L')) {
				dp[1][mask]++;
			}
			if (get(mask, 1) ^ (s[1] == 'L')) {
				dp[1][mask]++;
			}
		//	cout << "73 " << mask << " " << dp[1][mask] << endl;
		}
		for (int i = 2; i < n; i++) {
			for (int mask = 0; mask < F; mask++) {
				dp[i][mask] = inf;
				int mask2 = mask & 12;
				mask2 += (get(mask, 0) << 1);
				if (get(mask, 0) != get(mask, 1) || get(mask, 1) != get(mask2, 0) || get(mask2, 0) != get(mask2, 1)) {
					dp[i][mask] = min(dp[i][mask], dp[i - 1][mask2] + (get(mask, 1) ^ (s[i] == 'L')));
				}
				mask2 += 1;
				if (get(mask, 0) != get(mask, 1) || get(mask, 1) != get(mask2, 0) || get(mask2, 0) != get(mask2, 1)) {
					dp[i][mask] = min(dp[i][mask], dp[i - 1][mask2] + (get(mask, 1) ^ (s[i] == 'L')));
				}
			//	cout << "72 " << i << " " << mask << " " << mask2 << " " << dp[i][mask] << endl;
			}
		}
		int ans = inf;
		for (int mask = 0; mask < F; mask++) {
			if ((mask & 7) && (mask & 14) && ((~mask) & 7) && ((~mask) & 14)) {
			//	cout << "75 " << mask << " " << dp[n - 1][mask] << endl;
				ans = min(ans, dp[n - 1][mask]);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}