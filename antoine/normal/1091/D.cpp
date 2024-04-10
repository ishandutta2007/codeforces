#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;
const int MaxN = (int) 1e6 + 9;
ll fact[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	/*
	 fact[0] = 1;
	 for (int i = 1; i <= MaxN; ++i)
	 fact[i] = fact[i - 1] * i % mod;
	 */

	ll n;
	cin >> n;

	ll x = 1;

	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		const ll prev = x;
		(x *= (n - i)) %= mod;
		// cerr << x - prev << endl;
		ans += (i+1) * (x - prev);
		ans %= mod;
	}
	cout << (ans % mod + mod) % mod;
	return 0;
}