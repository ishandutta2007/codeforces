#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 12;
const int MxM = 2009;

ll f() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (vector<int> &v : a)
		for (int &x : v)
			cin >> x;
	static int dp[2][1 << MxN];
	memset(dp, 0, sizeof dp);
	for (int j = m - 1; j >= 0; --j)
		for (int mask = (1 << n) - 1; mask >= 0; --mask) {
			int &res = dp[j & 1][mask] = 0;
			for (int o = 0; o < n; ++o)
				for (int mask2 = (1 << n) - 1; mask2 >= 0; --mask2)
					if ((mask & mask2) == mask) {
						int diff = 0;
						for (int i = 0; i < n; ++i)
							if (!(mask & (1 << i)) && (mask2 & (1 << i)))
								diff += a[(i + o) % n][j];
						res = max(res, diff + dp[~j & 1][mask2]);
					}
		}
	return dp[0][0];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}