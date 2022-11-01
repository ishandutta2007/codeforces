#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution(ll a, ll b, ll c, ll& x0, ll& y0, ll& g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 *= -1;
	if (b < 0) y0 *= -1;
	return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
	x += cnt * b;
	y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
	ll x, y, g;
	if (!find_any_solution(a, b, c, x, y, g))
		return 0;
	a /= g;  b /= g;

	ll sign_a = a > 0 ? +1 : -1;
	ll sign_b = b > 0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	ll lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution(x, y, a, b, -sign_b);
	ll rx1 = x;

	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	ll lx2 = x;

	shift_solution(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift_solution(x, y, a, b, sign_a);
	ll rx2 = x;

	if (lx2 > rx2)
		swap(lx2, rx2);
	ll lx = max(lx1, lx2);
	ll rx = min(rx1, rx2);

	return (rx - lx) / abs(b) + 1;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// L <= a1 * x + b1 && a1 * x + b1 <= R
	// L - b1 <= a1 * x && a1 * x <= R - b1
	// (L - b1) / a1 <= x && x <= (R - b1) / a1
	// a1 * x - a2 * y = b2 - b1
	ll a1, b1, a2, b2, L, R;
	cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	ll x0, y0, g;
	if (!find_any_solution(a1, -a2, b2 - b1, x0, y0, g)) {
		return cout << 0, 0;
	}
	ll lb = (L - b1) / a1;
	ll rb = (R - b1) / a1;
	if ((L - b1) % a1 > 0) {
		lb++;
	}
	if ((R - b1) % a1 < 0) {
		rb--;
	}
	lb = max(0LL, lb);

	ll lby = (L - b2) / a2;
	ll rby = (R - b2) / a2;
	if ((L - b2) % a2 > 0) {
		lby++;
	}
	if ((R - b2) % a2 < 0) {
		rby--;
	}
	lby = max(0LL, lby);


	cout << find_all_solutions(a1, -a2, b2 - b1, lb, rb, lby, rby);

	return 0;
	a2 /= g;
	// lb <= x0 + k * a2 && x0 + k * a2 <= rb
	// (lb - x0) / a2 <= k && k <= (rb - x0) / a2
	ll lk = (lb - x0) / a2;
	ll rk = (rb - x0) / a2;
	if ((lb - x0) % a2 > 0) {
		lk++;
	}
	if ((rb - x0) % a2 < 0) {
		rk--;
	}
	/*for (auto k = lk; k <= rk; k++) {
		cout << a1 * (x0 + k * a2) + b1 << endl;
	}
	cout << "PROKEK" << endl;*/
	cout << max(0LL, rk - lk + 1);
}