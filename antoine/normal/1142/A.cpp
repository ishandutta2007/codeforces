#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, k, a, b;
	cin >> n >> k >> a >> b;

	ll ans1 = 1LL << 60, ans2 = 0;

	for (const ll start : { a, k - a }) {
		for (int i = 0; i < n; ++i) {
			for (ll end : { i * k + b, (i * k + k - b) % (n * k) }) {
				ll g = gcd(end - start, n * k);
				g = llabs(g);
				const ll res = n * k / g;
				ans1 = min(ans1, res);
				ans2 = max(ans2, res);
			}
		}
	}

	cout << ans1 << ' ' << ans2;
	return 0;
}