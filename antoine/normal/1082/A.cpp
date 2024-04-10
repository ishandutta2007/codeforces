#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	const ll Inf = 1LL << 60;

	int t;
	cin >> t;
	while (t--) {
		ll n, x, y, d;
		cin >> n >> x >> y >> d;

		ll ans = Inf;

		if ((y - x) % d == 0)
			ans = min(ans, llabs(y - x) / d);
		if ((y - 1) % d == 0)
			ans = min(ans, (y - 1) / d + (x - 1 + d - 1) / d);
		if ((n - y) % d == 0)
			ans = min(ans, (n - y) / d + (n - x + d - 1) / d);
		cout << (ans >= Inf ? -1 : ans) << '\n';
	}
	return 0;
}