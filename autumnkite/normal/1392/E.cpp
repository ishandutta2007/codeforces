#include <cstdio>

int n, q;
long long a[25][25];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = 1ll * (i & 1) << (i + j);
			printf("%lld ", a[i][j]);
		}
		putchar('\n');
		fflush(stdout);
	}
	scanf("%d", &q);
	while (q--) {
		long long k;
		scanf("%lld", &k);
		int x = 0, y = 0;
		printf("1 1\n"), fflush(stdout);
		while (x != n - 1 || y != n - 1) {
			if (y == n - 1 || (x < n - 1 && (k & 1ll << (x + y + 1)) == a[x + 1][y])) {
				++x;
			} else {
				++y;
			}
			printf("%d %d\n", x + 1, y + 1), fflush(stdout);
		}
	}
}