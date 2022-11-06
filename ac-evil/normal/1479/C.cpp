#include <bits/stdc++.h>
int n, m, l, r, e[40][40];
int main() {
	scanf("%d%d", &l, &r);
	if (l == 1 && r == 1) {
		puts("YES\n2 1\n1 2 1");
		return 0;
	}
	n = 23;
	if (l == 1) e[1][23] = 1, l++;
	for (int i = 2; i <= 22; i++) {
		e[i][23] = l - 1;
		for (int j = 2; j < i; j++)
			e[j][i] = 1 << 22 - i;
	}
	int d = r - l + 1;
	for (int i = 0, _d = 0; _d < d; i++)
		if (d & (1 << i)) {
			_d += 1 << i;
			e[1][22 - i] = d - _d + 1;
		}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			m += (bool)e[i][j];
	printf("YES\n%d %d\n", n, m);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (e[i][j]) printf("%d %d %d\n", i, j, e[i][j]);
	return 0;
}