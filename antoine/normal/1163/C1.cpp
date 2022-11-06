#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll h(ll a, ll b) {
	const ll g = gcd(a, b);
	a /= g, b /= g;
	if (b < 0 || (b == 0 && a < 0))
		a = -a, b = -b;
	return a << 32 | b;

}

ll C2(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	map<ll, set<ll>> mp;

	int n;
	cin >> n;
	vector<pair<int, int>> pts(n);
	for (auto &&p : pts)
		cin >> p.first >> p.second;

	for (auto &&p1 : pts)
		for (auto&&p2 : pts)
			if (p1 != p2) {
				const ll dx = p1.first - p2.first;
				const ll dy = p1.second - p2.second;
				set<ll> &s = mp[h(dx, dy)];
				assert(dx || dy);
				// p1.second = p1.first * dy / dx + b
				if(dx)
					s.insert(h(p1.second * dx - p1.first * dy, dx));
				else
					s.insert(h(p1.first * dy - p1.second * dx, dy));
			}


	ll total = 0, ans =0;;
	for(auto &&e : mp) {
		ans -= C2(e.second.size());
		total += e.second.size();
	}
	ans += C2(total);
	cout << ans;
	return 0;
}