#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Rect {
	ll xl, yl, xr, yr;

	Rect(ll xl, ll yl, ll xr, ll yr) :
			xl(xl), yl(yl), xr(xr), yr(yr) {
	}

	Rect() {
		cin >> xl >> yl >> xr >> yr;
	}

	Rect(const Rect r1, const Rect r2) {
		xl = max(r1.xl, r2.xl);
		xr = min(r1.xr, r2.xr);
		yl = max(r1.yl, r2.yl);
		yr = min(r1.yr, r2.yr);
	}

	ll size() const {
		return max(0LL, xr - xl + 1LL) * max(0LL, yr - yl + 1LL);
	}

	ll cntW() const {
		if (!size())
			return 0;
		const ll c1 = (yr - yl + 1) >> 1;
		const ll c2 = (yr - yl + 2) >> 1;

		const ll w = (xr - xl + 1);
		const ll tmp = (w / 2) * (c1 + c2);
		if (w % 2 == 0)
			return tmp;
		if ((xl + yl) % 2 == 0)
			return tmp + c2;
		else
			return tmp + c1;
	}

	ll cntB() const {
		return size() - cntW();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		ll n, m;
		cin >> n >> m;
		const Rect re0(0, 0, n - 1, m - 1);
		const Rect re1;
		const Rect re2;
		const Rect re3(re1, re2);

		const ll ans = re0.cntW() - re1.cntW() - re2.cntW() + re3.cntW() + re1.size() - re3.size();
		cout << ans << ' ' << n * m - ans << '\n';
	}
	return 0;
}