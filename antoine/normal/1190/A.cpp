#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n, m, k;
	cin >> n >> m >> k;

	set<ll> s;
	for (int i = 0; i < m; ++i) {
		ll x;
		cin >> x;
		--x;
		s.insert(x);
	}

	ll offset = 0;
	ll ans = 0;
	for (; !s.empty(); ans++) {
		ll x = *s.begin() + offset;
		x += k;
		x = (x / k) * k;
		--x;

		ll cnt = 0;
		while (!s.empty() && *s.begin() + offset <= x) {
			++cnt;
			s.erase(s.begin());
		}
		assert(cnt > 0);

		offset -= cnt;
		offset = ((offset % k) + k) % k;
	}

	cout << ans;
	return 0;
}