#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prime(ll x) {
	for (ll i = 2; i * i <= x; i++)
		if (!(x % i))
			return false;
	return true;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		puts(a - b == 1 && prime(a + b) ? "YES" : "NO");
	}
	return 0;
}