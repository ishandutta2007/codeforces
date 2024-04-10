#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

const ll Inf = (ll) 1e12 + 9;

ll dp[109][109];
int nxt[109][26];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	ll K;
	string s;
	cin >> n >> K >> s;

	for (int i = n; i >= 0; --i) {
		if (i == n)
			fill(nxt[i], nxt[i] + 26, n);
		else {
			copy(nxt[i + 1], nxt[i + 1] + 26, nxt[i]);
			nxt[i][s[i] - 'a'] = i;
		}
	}

	for (int i = n; i >= 0; --i) {
		for (int j = n; j >= 0; --j) {
			ll &res = dp[i][j];
			if (j == 0)
				res = 1;
			else if (i == n)
				res = 0;
			else {
				const int k = nxt[i + 1][s[i] - 'a'];
				res = dp[i + 1][j - 1] + dp[i + 1][j] - (k < n ? dp[k + 1][j - 1] : 0);
				// res = min(Inf, res);
			}
		}
	}

	ll ans = 0;
	for (int i = n; i >= 0 && K; --i) {
		ll c = min(K, dp[0][i]);
		K -= c;
		ans += c * (n - i);
	}

	if (K > 0)
		ans = -1;
	cout << ans;

	return 0;
}