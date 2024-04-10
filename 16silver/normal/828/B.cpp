#include <cstdio>
#include <algorithm>
int main() {
	char c[100][103];
	int i, j, n, m;
	int l, r, u, d;
	int ans = 0, temp, k;
	int Min, Max;
	scanf("%d %d", &n, &m);
	l = m;
	r = -1;
	u = n;
	d = -1;
	for (i = 0; i < n; i++) {
		scanf("%s", c[i]);
		for (j = 0; j < m; j++) {
			if (c[i][j] == 'B') {
				if (j < l) l = j;
				if (j > r) r = j;
				if (i < u) u = i;
				if (i > d) d = i;
			}
		}
	}
	if (l == m) ans = 1;
	else if (r - l >= n || d - u >= m) ans = -1;
	else {
		if (r - l > d - u) {
			ans = (r - l + 1)*(r - l + 1);
			Min = (u - r + l > 0 ? u - r + l : 0);
			Max = (d < n - r + l - 1 ? d : n - r + l - 1);
			for (k = Min; k <= Max; k++) {
				temp = 0;
				for (i = k; i <= k + r - l; i++) {
					for (j = l; j <= r; j++) {
						if (c[i][j] == 'W') {
							temp++;
						}
					}
				}
				if (temp < ans) ans = temp;
			}
		}
		else {
			ans = (d - u + 1)*(d - u + 1);
			Min = (l - d + u > 0 ? l - d + u : 0);
			Max = (r < m - d + u - 1 ? r : m - d + u - 1);
			for (k = Min; k <= Max; k++) {
				temp = 0;
				for (j = k; j <= k + d - u; j++) {
					for (i = u; i <= d; i++) {
						if (c[i][j] == 'W') {
							temp++;
						}
					}
				}
				if (temp < ans) ans = temp;
			}
		}
	}
	printf("%d", ans);
}