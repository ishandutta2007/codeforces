#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	ll a[3], d;
	for (ll &x : a)
		cin >> x;
	cin >> d;

	sort(a, a + 3);
	ll ans = max(0LL, a[0] - (a[1] - d)) + max(0LL, (a[1] + d) - a[2]);
	cout << ans;
	return 0;
}