#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll g(const ll n) {
	for (ll d = 2; d * d <= n; ++d)
		if (n % d == 0)
			return d;
	return n;
}

ll f(const ll n) {
	if(!n) return 0;
	if(n%2 == 0)
		return n >> 1;
	const ll d = g(n);
	return 1 + + f(n - d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n;
	cin >> n;
	cout << f(n);
	return 0;
}