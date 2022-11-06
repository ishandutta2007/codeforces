#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll l1, r1, t1;
	cin >> l1 >> r1 >> t1;
	ll l2, r2, t2;
	cin >> l2 >> r2 >> t2;

	++r1, ++r2;

	const ll g = gcd(t1, t2);
	ll ans = 0;

	for (int rep = 0; rep < 2; ++rep) {

		const ll oh = (l2 - l1 + t1) % g;

		const ll len1 = r1 - l1;
		const ll len2 = r2 - l2;

		ans = max(ans, min(len1, oh + len2) - oh);

		swap(l1, l2);
		swap(r1, r2);
		swap(t1, t2);
	}
	cout << ans << '\n';
	return 0;
}