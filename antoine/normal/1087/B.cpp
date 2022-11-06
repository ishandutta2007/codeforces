#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// :25

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll ans = 1LL << 62;

	ll n, k;
	cin >> n >> k;

	for (ll d = 1; d <= min(n, k - 1); ++d) {
		if (n % d)
			continue;
		const ll x = d + (n / d) * k;
		ans = min(ans, x);
	}
	cout << ans;
	return 0;
}