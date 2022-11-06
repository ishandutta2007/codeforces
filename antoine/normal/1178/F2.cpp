#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;
const ll mod2 = (ll) mod * mod;
const int MxN = 1009;
const int MxM = (int) 1e6 + 9;
int a[MxM + 9];
ll dp[MxN + 9][MxN + 9];
vector<int> occ[MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int _n, m;
	cin >> _n >> m;

	for (int i = 1; i <= m; ++i)
		cin >> a[i];

	// remove eq
	for (int i = m; i >= 2; --i)
		if (a[i] == a[i - 1])
			a[i] = 0;
	m = remove(a + 1, a + 1 + m, 0) - (a + 1);

	if (m > MxN) {
		cout << 0;
		return 0;
	}

	// occ & check
	for (int i = 1; i <= m; ++i)
		occ[a[i]].push_back(i);

	// assert(m <= 2 * _n - 1);

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
			const int x = *min_element(a + i, a + i + len);
			const int L = occ[x][0];
			const int R = occ[x].back();

			if (L < i || R > j) {
				res = 0;
				continue;
			}

			ll sumL = 0, sumR = 0;
			for (int l = i; l <= L; ++l) {
				sumL += dp[i][l - 1] * dp[l][L - 1];
				if (sumL > mod2)
					sumL -= mod2;
			}

			for (int r = R; r <= j; ++r) {
				sumR += dp[R + 1][r] * dp[r + 1][j];
				if (sumR > mod2)
					sumR -= mod2;
			}
			sumL %= mod, sumR %= mod;
			res = sumL * sumR % mod;
			for (int i = 0; i + 1 < (int) occ[x].size(); ++i) {
				res *= dp[occ[x][i] + 1][occ[x][i + 1] - 1];
				res %= mod;
			}
		}
	}
	cout << (dp[1][m] % mod + mod) % mod;
	return 0;
}