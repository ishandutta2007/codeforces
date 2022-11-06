#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	if (!count(s.begin(), s.end(), '1')) {
		cout << n;
		return 0;
	}

	vector<bool> dp(n, false);
	for (int d = 1; d < n; ++d)
		if (n % d == 0) {
			vector<int> sum(d, 0);
			for (int i = 0; i < n; ++i)
				if (s[i] == '1')
					sum[i % d] ^= 1;
			dp[d] = !count(sum.begin(), sum.end(), 1);
		}
	int ans = 0;
	for (int k = 1; k < n; ++k)
		ans += dp[gcd(n, k)];
	cout << ans;
	return 0;
}