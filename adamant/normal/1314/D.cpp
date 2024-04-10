#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int inf = 1e9 + 42;
const int mod = 1e9 + 7;
const int MAGIC = 30000;

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	n = 80;
	k = 10;
	cin >> n >> k;
	int a[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = rng() % (100000000);
			cin >> a[i][j];
		}
	}
	int ans = inf;
	for(int i = 0; i < MAGIC; i++) {
		int color[n];
		int64_t A = rng();
		int64_t B = rng();
		for(int i = 0; i < n; i++) {
			color[i] = i < 40 ? ((A >> i) & 1) : ((B >> (i - 40)) & 1);
		}
		int dp[n][k + 1];
		memset(dp, 0x3F, sizeof(dp));
		dp[0][0] = 0;
		for(int ln = 1; ln <= k; ln++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(color[i] != color[j]) {
						dp[j][ln] = min(dp[j][ln], dp[i][ln - 1] + a[i][j]);
					}
				}
			}
		}
		ans = min(ans, dp[0][k]);
	}
	cout << ans << endl;
	return 0;
}