#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

// 11:16:40
const int mod = 998244353;
const int MxN = 509;
int a[MxN + 9];
ll dp[MxN + 9][MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int _n, m;
	cin >> _n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];

	for (int len = 0; len <= m; ++len) {
		for (int i = 1;; ++i) {
			const int j = i + len - 1;
			if (j > m)
				break;
			ll &res = dp[i][j];
			if (!len) {
				res = 1;
				continue;
			}
			const int k = min_element(a + i, a + i + len) - a;
			assert(i <= k && k <= j);
			ll sumL = 0, sumR = 0;
			for (int l = i; l <= k; ++l)
				sumL += dp[i][l - 1] * dp[l][k - 1] % mod;

			for (int r = k; r <= j; ++r)
				sumR += dp[k + 1][r] * dp[r + 1][j] % mod;
			sumL %= mod, sumR %= mod;
			res = sumL * sumR % mod;
		}
	}
	cout << dp[1][m];
	return 0;
}