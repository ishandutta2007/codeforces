#include<cstdio>
long long n, p;
int main() {
	int i, j, k;
	scanf("%lld%lld", &n, &p);
	for (i = 1;i<=100; i++) {
		long long t = n - p * i;
		if (t >= i) {
			int c = 0;
			for (k = 0; k < 50; k++) {
				if ((t >> k) & 1)c++;
			}
			if (c <= i) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	printf("-1\n");
}