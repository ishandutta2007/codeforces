#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void upd(ll &a, ll b) {
	a = min(a, b);
}

int m, n;
const int MAX = 1e5 + 1;
ll ar[MAX];
ll dp[MAX][2];

bool check(ll dist) {
	for (int w = 0; w < 2; w++) {
		for (int q = 0; q < 2; q++) {
			ll start = (q ? 0 : -dist);
			for (int g = 0; g < 2; g++) {
				ll INF = 1e15;
				for (int i = 0; i <= n; i++) {
					for (int j = 0; j < 2; j++)
						dp[i][j] = INF;
				}
				dp[0][q] = start;
				for (int i = 0; i < n; i++) {
					if (dp[i][1] <= dist)
						upd(dp[i][0], min(0LL, dp[i][1]));
					if (dp[i][1] <= 0)
						upd(dp[i][0], -dist);
					if (dp[i][0] <= 0) {
						if (-dp[i][0] >= ar[i + 1] - ar[i] - 1) {
							upd(dp[i + 1][1], 0);
						}
						upd(dp[i + 1][1], dp[i][0] + (ar[i + 1] - ar[i]) - 1);
					}
					if (ar[i + 1] - ar[i] + (dp[i][1] <= 0 ? -1 : dp[i][1]) <= dist) {
						upd(dp[i + 1][0], (ar[i + 1] - ar[i]) - dist);
					}
				}
				if ((q || g) && dp[n][q] <= start)
					return true;
				if (dp[n][q] == INF)
					break;
				start = dp[n][q];
			}
		}
		int z = ar[0];
		for (int i = 0; i < n; i++) {
			ar[i] = ar[i + 1] - z;
		}
		ar[n] = ar[0] + m;
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}
	if (n == 1) {
		cout << m - 1 << endl;
		return 0;
	}
	if (n == 2) {
		ll a = ar[1] - ar[0];
		ll b = m - a;
		ll ans = min(max(a - 1, b - 1), (a + b + min(a, b)) / 2);
		if (min(a, b) == 1)
			upd(ans, max(a, b) / 2);
		cout << ans << endl;
		return 0;
	}
	ar[n] = ar[0] + m;
	ll l = 0, r = 1e9;
	while (l < r) {
		ll x = (l + r) >> 1;
		if (check(x))
			r = x;
		else
			l = x + 1;
	}
	cout << l << endl;
}