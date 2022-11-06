#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct DS {
	int dx = 0, dy = 0, mnx = 0, mny = 0, mxx = 0, mxy = 0;
	DS() {
	}
	DS(const char c) {
		if (c == 'W')
			mnx = dx = -1;
		else if (c == 'S')
			mxx = dx = +1;
		else if (c == 'A')
			mny = dy = -1;
		else {
			assert(c == 'D');
			mxy = dy = +1;
		}
	}

	DS operator+(const DS other) const {
		DS res;
		res.dx = dx + other.dx;
		res.dy = dy + other.dy;
		res.mnx = min(mnx, dx + other.mnx);
		res.mny = min(mny, dy + other.mny);
		res.mxx = max(mxx, dx + other.mxx);
		res.mxy = max(mxy, dy + other.mxy);
		return res;
	}

	ll area() const {
		return (mxx - mnx + 1LL) * (mxy - mny + 1LL);
	}
};

void f() {
	string s;
	cin >> s;
	const int n = (int) s.size();
	vector<DS> L(n), R(n);
	for (int i = 0; i < n; ++i)
		L[i] = R[i] = DS(s[i]);
	for (int i = 1; i < n; ++i)
		L[i] = L[i - 1] + L[i];

	for (int i = n - 2; i >= 0; --i)
		R[i] = R[i] + R[i + 1];

	ll ans = R[0].area();
	assert(ans == L[n - 1].area());

	for (int i = 0; i + 1 < n; ++i) {
		for (char c : { 'W', 'S', 'A', 'D' })
			ans = min(ans, (L[i] + DS(c) + R[i + 1]).area());
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		f();
	return 0;
}