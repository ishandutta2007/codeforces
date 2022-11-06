#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	ll g = 0;
	for (int i = 1; i < n; ++i)
		g = gcd(g, a[i] - a[i - 1]);

	for (int i = 1; i <= m; ++i) {
		ll x;
		cin >> x;
		if (g % x == 0) {
			cout << "YES\n" << a[0] << ' ' << i;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}