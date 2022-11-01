#include <iostream>
using namespace std;

const int N = 17, inf = 2000 * 1000 * 1000 + 37;

int r[N], b[N], a[N];
int sr[1 << N], sb[1 << N];
int dp[1 << N][N * N + 20];

int get(int x, int y) {
	return (x >> y) & 1;
}

int main() {
	int n, rs = 0, bs = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c >> r[i] >> b[i];
		if (c == 'R') {
			a[i] = 1;
		}
		rs += r[i], bs += b[i];
	}
	for (int mask = 1; mask < (1 << n); mask++) {
		int x = __builtin_ctz(mask);
		sr[mask] = sr[mask ^ (1 << x)], sb[mask] = sb[mask ^ (1 << x)];
		if (a[x]) {
			sr[mask]++;
		}
		else {
			sb[mask]++;
		}
		for (int i = 0; i <= n * n; i++) {
			dp[mask][i] = -1;
		}
	//	cout << "52 " << mask << " " << sr[mask] << " " << sb[mask] << endl;
	}
	for (int i = 1; i <= n * n; i++) {
		dp[0][i] = -1;
	}
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i <= n * n + n; i++) {
		//	cout << "51 " << mask << " " << i << " " << dp[mask][i] << endl;
			for (int j = 0; j < n; j++) {
				if (dp[mask][i] == -1) {
					continue;
				}
				if (!get(mask, j)) {
					int mask2 = mask ^ (1 << j);
				/*	if (a[j]) {
						dp[mask2][min(r[j], sr[mask]) + i] = max(dp[mask2][min(r[j], sr[mask]) + i], dp[mask][i]);
					}
					else {
						dp[mask2][i] = max(dp[mask2][i], dp[mask][i] + min(b[j], sb[mask]));
					}*/
					int x = dp[mask][i];
					dp[mask2][i + min(r[j], sr[mask])] = max(dp[mask2][i + min(r[j], sr[mask])], x + min(sb[mask], b[j]));
				}
			}
		}
	}
//	cout << "53 " << dp[(1 << n) - 1][0] << endl;
	int ans = inf;
	for (int i = 0; i <= n * n; i++) {
		int x = dp[(1 << n) - 1][i];
		if (x != -1) {
			ans = min(ans, max(rs - i, bs - x));
		}
	}
	cout << ans + n;
	return 0;
}