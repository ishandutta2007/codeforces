#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);

		ll n;

		if (x > y) {
			n = x+y;
		} else if (x == y) {
			n = x;
		} else {
			n = y-1;
			ll ans = n%x;
			n -= ans/2;
		}


		printf("%lld\n", n);

		assert(n%x == y%n);
	}

}