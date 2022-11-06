#include <bits/stdc++.h>
const int N = 100005;
int n, m, a[N], la[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if (x != a[m]) a[++m] = x;
	}
	int ans = m;
	for (int i = 1, p = 0; i <= m; i++) {
		if (la[a[i]]) {
			if (la[a[i]] >= p-1) p = i, ans--;
		}
		la[a[i]] = i;
	}
	printf("%d", ans);
	return 0;
}