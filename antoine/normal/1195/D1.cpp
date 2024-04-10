#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		const string s = to_string(a[i]);

		ll sum = 0;
		ll p100 = 1;
		for (int j = (int) s.size() - 1; j >= 0; --j) {
			(sum += (s[j] - '0') * p100) %= mod;
			(p100 *= 100) %= mod;
		}
		ans += sum * n;
		ans += sum * 10 % mod * n;
		ans %= mod;
	}
	cout << (ans % mod + mod) % mod;
	return 0;
}