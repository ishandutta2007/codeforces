#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, l, r;
	cin >> n >> l >> r;

	l += 6, r += 6;
	ll cnt[3];
	for (int i = 0; i < 3; ++i)
		cnt[i] = (r - i) / 3 - (l - i - 1) / 3;

	const int mod = (int) 1e9 + 7;
	vector<array<ll, 3>> dp(n + 1);
	dp[n] = {1,0,0};
	for (int i = n - 1; i >= 0; --i) {
		for (int x = 0; x < 3; ++x) {
			ll &res = dp[i][x] = 0;
			for (int y = 0; y < 3; ++y)
				res += cnt[y] * dp[i + 1][(x + y) % 3];
			res %= mod;
		}
	}
	cout << dp[0][0];
	return 0;
}