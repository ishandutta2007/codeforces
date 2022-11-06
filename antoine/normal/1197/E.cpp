#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = (int) 1e9 + 7;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	for (pair<ll, ll> &p : a) {
		cin >> p.first >> p.second;
		swap(p.first, p.second);
		assert(p.first < p.second);
	}
	sort(a.begin(), a.end());

	map<ll, ll> mp;
	vector<ll> dp1(n, 0), dp2(n, 1);
	vector<pair<ll, ll>> dp3(n);

	for (int i = n - 1; i >= 0; --i) {
		const int k = lower_bound(a.begin(), a.end(), pair<ll, ll> { a[i].second, 0 }) - a.begin();
		if (k < n) {
			dp1[i] = dp3[k].first - a[i].second;
			dp2[i] = dp3[k].second;
		}

		(mp[dp1[i] + a[i].first] += dp2[i]) %= mod;
		dp3[i] = *mp.begin();
	}

	ll minR = (ll) 1e18;
	ll ans1 = (ll) 1e18, ans2 = 0;
	for (int i = 0; i < n; ++i) {
		minR = min(minR, a[i].second);
		if (a[i].first < minR) {
			const ll tmp1 = dp1[i] + a[i].first;
			if (tmp1 < ans1) {
				ans1 = tmp1;
				ans2 = dp2[i];
			} else if (tmp1 == ans1)
				(ans2 += dp2[i]) %= mod;
		}
	}

	DBG(ans1);
	ans2 = (ans2 % mod + mod) % mod;
	cout << ans2;

	return 0;
}