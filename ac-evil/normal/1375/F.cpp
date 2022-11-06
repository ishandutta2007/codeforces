#include <bits/stdc++.h>
using std::max; using std::min;
typedef long long LL;
LL a[4];
int main() {
	scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
	puts("First");
	LL t = 100000000000;
	printf("%lld\n", t); fflush(stdout);
	int x; scanf("%d", &x); a[x] += t;
	LL mx = max({a[1], a[2], a[3]});
	t = 3 * mx - a[1] - a[2] - a[3];
	printf("%lld\n", t); fflush(stdout);
	int y; scanf("%d", &y); a[y] += t;
	printf("%lld\n", a[y] - a[x]);
	return 0;
}