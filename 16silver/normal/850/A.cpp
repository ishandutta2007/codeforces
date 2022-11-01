#include <cstdio>
int pn[1000][5], qq[1000];
int main() {
	int n, i, ans = 0, j, k, dst, l;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d %d %d %d %d", &pn[i][0], &pn[i][1], &pn[i][2], &pn[i][3], &pn[i][4]);
	if (n < 15) {
		for (i = 0; i < n; i++) qq[i] = 1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (j == i) continue;
				for (k = 0; k < n; k++) {
					if (k == i || k == j) continue;
					dst = 0;
					for (l = 0; l < 5; l++) dst += (pn[k][l] - pn[i][l])*(pn[j][l] - pn[i][l]);
					if (dst > 0) {
						qq[i] = 0;
						break;
					}
				}
				if (qq[i] == 0) break;
			}
			if (qq[i] == 1) ans++;
		}
	}
	printf("%d\n", ans);
	for (i = 0; i < n; i++) {
		if (qq[i] == 1) printf("%d\n", i + 1);
	}
}