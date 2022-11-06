#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, int>> getFact(ll x) {
	vector<pair<ll, int>> v;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x % i == 0; x /= i)
				v.back().second++;
		}
	if (x != 1)
		v.emplace_back(x, 1);

	return v;
}

ll f(ll n, const ll d) {
	ll res = 0;
	for (; n; n /= d)
		res += n / d;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, b;
	cin >> n >> b;

	ll ans = 1LL << 61;

	const vector<pair<ll, int>> fact = getFact(b);

	for (const pair<ll, int> &p : fact) {
		const ll cnt = f(n, p.first);
		ans = min(ans, cnt / p.second);
	}
	cout << ans;
	return 0;
}