#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

const int Mx = (int) 2e5 + 9;
bool dp[Mx + 9];

ll f(ll g, ll m) {
	ll res = 0;
	while (m && m % g != g - 1) {
		res += m / g + 1;
		m--;
	}
	if (!m)
		return ++res;

	ll n = (m + 1) / g;
	res += n * (n + 1) / 2 * g;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int m, a, b;
	cin >> m >> a >> b;

	dp[0] = 1;
	int cnt = 1;
	ll ans = 1;

	for (int x = 1; x <= min(m, Mx); ++x) {
		function<void(int)> propagate;

		propagate = [&](const int y) {
			if(dp[y])
			return;
			cnt++;
			dp[y] = 1;
			if(y + a <= x)
			propagate(y + a);
			if(y - b >= 0)
			propagate(y-b);
		};
		if (x - a >= 0 && dp[x - a])
			propagate(x);
		ans += cnt;
	}

	if (m > Mx) {
		const int g = gcd(a, b);
		ans += f(g, m) - f(g, Mx);
	}
	cout << ans;

	return 0;
}