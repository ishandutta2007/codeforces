#include <cstdio>
long long abs(long long x) {
	return (x > 0L ? x : -x);
}
long long gcd(long long x, long long y) {
	long long a = abs(x), b = abs(y), r;
	if (b == 0) return a;
	r = a%b;
	while (r > 0) {
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}
int main() {
	int n, i, k[2], j;
	long long y[1000], p, q, g, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%I64d", &y[i]);
	for (i = 1; i < n; i++) {
		p = (long long)i;
		q = y[i] - y[0];
		g = gcd(p, q);
		p = p / g;
		q = q / g;
		if (p == 1L) {
			k[0] = 1;
			k[1] = 0;
			for (j = 1; j < n; j++) {
				if (y[j] == y[0] + q*((long long)j)) k[0]++;
				else {
					if (k[1] != 0) {
						if (y[j] == x + q*((long long)j)) k[1]++;
						else break;
					}
					else {
						k[1] = 1;
						x = y[j] - q*((long long)j);
					}
				}
			}
			if (j == n && k[1] != 0) break;
		}
		else if (p == 2L) {
			for (j = 2; j < n; j++) {
				if (j % 2 == 0) {
					if (y[j] != y[0] + q*((long long)(j / 2))) break;
				}
				else {
					if (y[j] != y[1] + q*((long long)(j / 2))) break;
				}
			}
			if (j == n) break;
		}
	}
	if (i == n) {
		q = y[2] - y[1];
		if (y[0] == y[1] - q) {
			printf("No");
		}
		else {
			for (j = 2; j < n; j++) {
				if (y[j] != y[1] + q*((long long)(j - 1))) break;
			}
			if (j == n) printf("Yes");
			else printf("No");
		}
	}
	else printf("Yes");
}