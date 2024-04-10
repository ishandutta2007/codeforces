#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int M = 2e3 + 10;
const int N = 1e6 + 10;

ld calc(ll h, ll c, ll t, ll k) {
	return abs(((ld)h * (k + 1) + (ld)k * c) / (2 * k + 1) - t);
}

void solve() {
	ll h, c, t;
	cin >> h >> c >> t;
	if (t >= h) {
		cout << 1 << "\n";
		return;
	}
	if (2 * t <= h + c) {
		cout << 2 << "\n";
		return;
	}

	ll tl = 0, tr = INF;

	while (tr - tl > 1) {
		ll tm = (tl + tr) / 2;
		
		if ((h * (tm + 1) + tm * c) >= (2 * tm + 1) * t) {
			tl = tm;
		}	else {
			tr = tm;
		}
	}

	//cout << tl << " " << tr << endl;
	//ll lhs = (h - c) * (tl * (2 * tr + 1) + tr * (2 * tl + 1));
	ll lhs = (2 * tr + 1) * (h * (tl + 1) + tl * c) + (2 * tl + 1) * (h * (tr + 1) + tr * c);
	//ll rhs = 2 * (t - c) * (2 * tl + 1) * (2 * tr + 1);
	ll rhs = 2 * t * (2 * tl + 1) * (2 * tr + 1);

	if (lhs <= rhs) {
		cout << 2 * tl + 1 << "\n";
	} else {
		cout << 2 * tr + 1 << "\n";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin>> t;
	while (t--) {
		solve();
	}
}