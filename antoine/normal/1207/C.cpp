#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
ll dp[MxN + 9][2];

ll f() {
	ll n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	dp[n + 1][0] = dp[n + 1][1] = 0;
	for (int i = n; i >= 0; --i)
		for (int j = 0; j < 2; ++j) {
			ll &res = dp[i][j] = (ll) 1e18;
			if (i == n && j)
				continue;
			if (!j) {
				if ((i < n && s[i] == '1') || (i && s[i - 1] == '1'))
					continue;
			}
			res = j * b + min(dp[i + 1][j], a + dp[i + 1][!j]);
		}

	return dp[0][0] + n * a + (n + 1) * b;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		cout << f() << '\n';
	return 0;
}