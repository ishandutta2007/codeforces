#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 998244353;
int n;
int a[(int) 1e5 + 9];
ll dp[2][205][2];

inline const ll &c(const int i, const int k, const int b) {
	return dp[i & 1][k][b];
}

inline const ll f(const int i, const int k, const int b) {
	return c(i, k, b) - c(i, k - 1, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = n; i >= 0; --i) {
		for (int k = 1; k <= 200; ++k) {
			for (int b = 0; b < 2; ++b) {
				ll &res = dp[i & 1][k][b] = 0;
				if (i == n)
					res = !b;
				else if (a[i] != -1) {
					if (b && k > a[i])
						res = 0;
					else
						res = f(i + 1, a[i], k < a[i]);
				} else {
					if (!b) {
						res = c(i + 1, k, 0) + c(i + 1, 200, 1)
								- c(i + 1, k, 1);
					} else {
						res = f(i + 1, k, 0) + c(i + 1, 200, 1)
								- c(i + 1, k, 1);
					}
				}
				res += dp[i & 1][k - 1][b];
				res %= mod;
			}
		}
	}

	ll ans = 0;
	for (int k = 1; k <= 200; ++k)
		if (a[0] == -1 || k == a[0]) {
			ans += f(1, k, 1);
			ans %= mod;
		}
ans += mod;
ans %= mod;
	cout << ans;
	return 0;
}