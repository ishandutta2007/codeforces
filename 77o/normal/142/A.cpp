#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll low = LLONG_MAX;
	ll high = 0;

	for (ll i = 1; i * i * i <= n; i++) {
		if (n % i) {
			continue;
		}
		for (ll j = i; j * j <= n; j++) {
			if (n / i % j) {
				continue;
			}
			ll k = n / i /  j;
			low = min(low, (i + 1) * (j + 2) * (k + 2));
			high = max(high, (i + 2) * (j + 2) * (k + 1));
		}
	}
	cout << low - n << ' ' << high - n << endl;
    return 0;
}