#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll r;
	scanf("%lld", &r);
	for(ll x = 1; x * x + x + 1 < r; x++) if((r - x * x - x - 1) % (2 * x) == 0) {
		printf("%lld %lld\n", x, (r - x * x - x - 1) / (2 * x));
		return 0;
	}
	puts("NO");
	return 0;
}