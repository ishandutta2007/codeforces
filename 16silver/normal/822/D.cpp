#include <stdio.h>
#define P 1000000007
int x[5000001] = { 1,1 };
long long y[5000001] = { 0 };
long long texp[5000001];
int main() {
	long long i = 1, j, t, l, r, ans;
	scanf("%I64d %I64d %I64d", &t, &l, &r);
	texp[0] = 1;
	while (i < 5000001) {
		for (; x[i] != 0; i++);
		for (j = 2; i*j < 5000001; j++) {
			if (x[i*j] == 0) x[i*j] = i;
		}
		i++;
	}
	for (i = 2; i < 5000001; i++) {
		if (x[i] == 0) {
			y[i] = (i*(i - 1) / 2) % P;
		}
		else {
			y[i] = ((i*(x[i] - 1) / 2) + y[i / x[i]]) % P;
		}
	}
	ans = y[l];
	for (i = 1; i <= r - l; i++) {
		texp[i] = (t*texp[i - 1]) % P;
		ans = (ans + texp[i] * y[l + i]) % P;
	}
	ans = ans%P;
	printf("%I64d", ans);
}