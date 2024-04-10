#include <stdio.h>
int main() {
	long long l, r, x, y, k, i;
	scanf("%I64d %I64d %I64d %I64d %I64d", &l, &r, &x, &y, &k);
	for (i = 0L; i <= 10000000L; i++) {
		if (x <= i && i <= y && l <= i*k && i*k <= r) break;
	}
	if (i == 10000001L) printf("NO");
	else printf("YES");
}