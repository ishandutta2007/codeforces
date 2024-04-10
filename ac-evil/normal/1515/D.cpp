#include <bits/stdc++.h>
const int N = 200005;
int T, n, l, r, a[N], b[N], c[N][2];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &l, &r);
		for (int i = 1; i <= n; i++) c[i][0] = c[i][1] = 0;
		for (int i = 1; i <= l; i++)
			scanf("%d", &a[i]), c[a[i]][0]++;
		for (int i = 1; i <= r; i++)
			scanf("%d", &b[i]), c[b[i]][1]++;
		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			while (l > r && c[i][0] > c[i][1] + 1) c[i][0]--, c[i][1]++, l--, r++, tmp++;
			while (l < r && c[i][0] + 1 < c[i][1]) c[i][0]++, c[i][1]--, l++, r--, tmp++;
		}
		int ans = n;
		for (int i = 1; i <= n; i++)
			ans -= std::min(c[i][0], c[i][1]) * 2;
		printf("%d\n", ans / 2 + tmp + (l < r ? r - l : l - r) / 2);
		/*
		// if ((l - r) / 2)
		if (
		printf("%d\n", ans);
		*/
	}
	return 0;
}