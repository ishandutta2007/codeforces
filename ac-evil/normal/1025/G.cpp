#include <bits/stdc++.h>
const int N = 505, P = 1e9 + 7;
int n, c[N], pw[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if (~x) c[x]++;
	}
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * 2 % P;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans - (pw[c[i]] - 1) + P) % P;
	ans = (ans + pw[n - 1] - 1) % P;
	printf("%d\n", ans);
	return 0;
}