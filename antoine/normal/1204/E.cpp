#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 2009;

const int mod = 998244853;
ll dp[MxN + 9][MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int n = 0; n <= MxN; ++n)
		for (int m = 0; m <= n; ++m) {
			ll &res = dp[n][m];
			if (!n || !m)
				res = 1;
			else {
				if (n && n > m)
					res += dp[n - 1][m];
				if (m)
					res += dp[n][m - 1];
				res %= mod;
			}
		}

	int n, m;
	cin >> n >> m;
	ll ans = 0;

	for (int h = max(1, n - m); h <= n; ++h) {
		for (int i = h; i <= n + m; ++i) {
			if ((i + h) % 2)
				continue;
			const int n1 = (i + h) / 2;
			const int m1 = i - n1;
			assert(n1 >= 1);
			if (n1 > n || m1 < 0 || m1 > m)
				continue;
			int n2 = n - n1, m2 = m - m1;
			if (n2 > m2)
				swap(n2, m2);
			ans += h * dp[n1 - 1][m1] % mod * dp[m2][n2] % mod;

		}
	}

	cout << (ans % mod + mod) % mod;

	return 0;
}