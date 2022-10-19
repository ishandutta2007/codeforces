#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int main() {
	ll t;
	scanf("%lld", &t);
	for (int i = 0; i < t; i++) {
		ll n, m;
		scanf("%lld%lld", &n, &m);
		if (n == 1 && m == 1) {
			printf("0\n");
		}
		else if (n == 1 || m == 1) {
			printf("1\n");
		} else {
			printf("2\n");
		}
	}
}