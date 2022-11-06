#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

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

ll intPow(ll x, int y) {
	assert(y >= 0);
	ll res = 1;
	while (y--) {
		res *= x;
	}
	return res;
}

ll f() {
	int n;
	cin >> n;
	map<ll, int> mp;
	ll mx = 0;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		mx = max(mx, x);
		for (const pair<ll, int> p : getFact(x))
			mp[p.first] = max(mp[p.first], p.second);
	}

	if (mp.size() == 1) {
		const pair<ll, int> p = *mp.begin();
		if (n != p.second)
			return -1;
		return intPow(p.first, p.second + 1);
	}
	{
		ll pr = 1;
		for (auto p : mp) {
			pr *= p.second + 1;
			if (pr > n + 2)
				return -1;
		}
		if (n + 2 != pr)
			return -1;
	}
	ll res = 1;
	for (auto p : mp)
		res *= intPow(p.first, p.second);
	if (res <= mx)
		return -1;
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << f() << endl;
	return 0;
}