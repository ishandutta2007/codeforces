#include <stdio.h>
int x[50][50];
int col[50], row[50];
long long pow2[53] = { 1 };
int main() {
	int n, m, i, j;
	for (i = 1; i < 52; i++) pow2[i] = pow2[i - 1] * 2;
	long long ans = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) row[i] = 0;
	for (j = 0; j < m; j++) col[j] = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &x[i][j]);
			row[i] += x[i][j];
			col[j] += x[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		ans += pow2[row[i]];
		ans += pow2[m - row[i]];
		ans -= 2;
	}
	for (j = 0; j < m; j++) {
		ans += pow2[col[j]];
		ans += pow2[n - col[j]];
		ans -= 2;
	}
	ans -= (long long)(n*m);
	printf("%I64d", ans);
}