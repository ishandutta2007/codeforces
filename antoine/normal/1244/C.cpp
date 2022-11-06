#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
	// Base Case
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	ll x1, y1; // To store results of recursive call
	ll gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of
	// recursive call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n, p, w, d;
	cin >> n >> p >> w >> d;

	ll x, y;
	{
		ll g = gcdExtended(w, d, &x, &y);
		assert(g > 0);
		if (p % g) {
			cout << -1;
			return 0;
		}
		w /= g;
		d /= g;
		p /= g;
	}

	x = p / w + p % w * x;
	y = p % w * y;

	if (y >= 0) {
		const ll c = y / w;
		y -= c * w;
		x += c * d;
	} else {
		const ll c = (-y + w - 1) / w;
		y += c * w;
		x -= c * d;
	}

	if (x >= 0 && y >= 0 && x + y <= n)
		cout << x << ' ' << y << ' ' << n - x - y << '\n';
	else
		cout << -1;
	return 0;
}