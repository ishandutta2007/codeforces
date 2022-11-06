#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isPrime(ll x) {
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

bool f() {
	ll a, b;
	cin >> b >> a;
	assert(a < b);
	if (b != a + 1)
		return false;
	return isPrime(a + b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << (f() ? "YES" : "NO") << '\n';
	return 0;
}