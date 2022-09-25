#include <bits/stdc++.h>

using namespace std;

long double c[21][21], coef[21], sum[1 << 20], p[20];
int sz[1 << 20];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		double x;
		scanf("%lf", &x);

		p[i] = x;
	}

	c[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}

	for (int i = 0; i < (1 << n); i++) {
		sz[i] = 0;
		sum[i] = 0;

		for (int j = 0; j < n; j++)
			if (((i >> j) & 1) == 1) {
				sz[i]++;
				sum[i] += p[j];
			}
	}

	for (int i = k - 1; i >= 0; i--) {
		coef[i] = 1 - coef[i];

		for (int j = 1; i - j >= 0; j++) coef[i - j] += c[n - 1 - i + j][j] * coef[i];
	}

	for (int i = 0; i < n; i++) {
		long double ans = 0.0;
		if (p[i] > 0.005) {
			for (int msk = 0; msk < (1 << n); msk++) {
				if (((msk >> i) & 1) == 1) continue;
				if (sz[msk] >= k) continue;

				ans += coef[sz[msk]] / (1 - sum[msk]);
			}
		}

		printf("%.12lf ", (double)(p[i] * ans));
	}

	printf("\n");

	return 0;
}