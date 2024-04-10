#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
	ll k, n, a, b;
	cin >> k >> n >> a >> b;
	--k;

	if (k / b < n)
		return -1;

	ll lo = 0, hi = n;
	while (lo < hi) {
		ll mid = (lo + hi + 1) / 2;
		if (mid * a + (n - mid) * b <= k)
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--)
		cout << f() << '\n';
	return 0;
}