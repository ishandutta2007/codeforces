#include <stdio.h>
int main() {
	long long b, m, M = 0, i, q, t;
	scanf("%I64d %I64d", &m, &b);
	for (i = 0; i < b; i++) {
		t = m*(b - i);
		q = (i + 1)*(t + 1)*(i + t) / 2;
		if (q > M) M = q;
	}
	printf("%I64d", M);
}