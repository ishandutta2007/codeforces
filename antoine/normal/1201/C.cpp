#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	sort(a.rbegin(), a.rend());
	a.resize(n / 2 + 1);
	n = n / 2 + 1;
	sort(a.begin(), a.end());

	ll lo = 0, hi = (ll) 2e9 + 9;
	while (lo < hi) {
		const ll mid = (lo + hi + 1) / 2;
		ll sum = 0;
		for (ll x : a)
			sum += max(0LL, mid - x);

		sum <= k ? lo = mid : hi = mid - 1;
	}

	cout << lo;
	return 0;
}