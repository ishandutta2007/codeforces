#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll p, k;

ll f(ll x) {
	ll y = x * x % p;
	y = y * y % p;
	y -= k * x % p;
	return (y % p + p) % p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n >> p >> k;

	map<ll, ll> occ;
	ll ans = 0;

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		ans += occ[f(x)]++;
	}
	cout << ans;
	return 0;
}