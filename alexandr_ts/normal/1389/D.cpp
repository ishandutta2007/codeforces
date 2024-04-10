#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e17 + 10;
const ll MOD = 1e9 + 7;
const int M = 21;
const int N = 1e6 + 10;



void solve() {
	ll n, k;
	cin >> n >> k;
	ll l1, l2, r1, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	if (l1 > l2) {
		swap(l1, l2);
		swap(r1, r2);
	}

	ll A = max({0ll, l2 - r1, l1 - r2});
	ll B = 2 * (max(r1, r2) - min(l1, l2)) - A - (r1 - l1) - (r2 - l2);

	ll ans = INF;
	if (l2 >= r1) {
		for (int i = 1; i <= n; ++i) {
			ll cur = A * i;
			ll buf = B * i;
			if (buf >= k) {
				cur += k;
				ans = min(ans, cur);
			} else {
				cur += buf;
				ll k1 = k - buf;
				cur += k1 * 2;
				ans = min(ans, cur);
			}
		}	
	} else {
		ll inter_len = min(r2, r1) - l2;
		k -= n * inter_len;
		if (k <= 0) {
			ans = 0;
		} else {
			ll buf = B * n;
			if (buf >= k) {
				ans = k;
			} else {
				ans = buf + 2 * (k - buf);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();	
	}
}