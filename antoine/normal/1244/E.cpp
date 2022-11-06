#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f(const vector<ll> &a, ll k) {
	const int n = (int) a.size();
	for (int i = 0; i < n; ++i)
		k -= a.back() - a[i];
	ll res = a.back() - a[0];
	for (int i = n - 1, j = n - 1; i >= 0; --i) {
		for (; j > i; --j) {
			ll diff = (a[j] - a[j - 1]) * (n - j);
			if (k - diff < 0)
				break;
			k -= diff;
		}

		if (k >= 0) {
			if (i == j)
				return 0;
			res = min(res, a[j] - a[i] - k / (n - j));
		}

		if (i > 0) {
			k += i * (a[i] - a[i - 1]);
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	ll ans = f(a, k);
	for (ll &x : a)
		x = -x;
	reverse(a.begin(), a.end());
	ans = min(ans, f(a, k));
	cout << ans;
	return 0;
}