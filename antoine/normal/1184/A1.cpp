#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v)  << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll r;
	cin >> r;
	r--;

	for (ll x = 1; x * x <= r; ++x)
		if (r % x == 0) {
			ll y = r / x;
			y--;
			y -= x;
			if (y % 2 == 0) {
				y /= 2;
				if (y > 0) {
					cout << x << ' ' << y << endl;
					return 0;
				}
			}
		}
	cout << "NO";
	return 0;
}