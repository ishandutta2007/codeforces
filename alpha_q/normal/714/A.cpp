#include <bits/stdc++.h>

using namespace std;

long long l, r, l1, r1, l2, r2, k;

int main (int argc, char const *argv[]) {
	scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);

	if (l1 > l2) swap(l1, l2), swap(r1, r2);

	if (r1 < l2) {
		puts("0");
		return 0;
	}
	else if (r1 > r2) l = l2, r = r2;
	else l = l2, r = r1;

	if (l <= k and k <= r) --r;

	printf("%lld\n", r - l + 1);
	return 0;
}