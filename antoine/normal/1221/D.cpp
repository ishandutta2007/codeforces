#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 3e5 + 9;

ll a[MxN + 9];
ll b[MxN + 9];
ll dp[MxN + 9][3];

ll f() {

	a[0] = -9;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	fill(dp[n + 1], dp[n + 1] + 3, 0);
	for (int i = n; i > 0; --i)
		for (int j = 0; j < 3; ++j) {
			ll &res = dp[i][j] = (ll) 1e18;
			for (int k = 0; k < 3; ++k)
				if (a[i - 1] + j != a[i] + k)
					res = min(res, dp[i + 1][k] + k * b[i]);
		}
	return dp[1][0];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int Q;
	cin >> Q;
	while (Q--)

		cout << f() << '\n' << endl;

	return 0;
}