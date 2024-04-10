#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int r, n, t[N], x[N], y[N], f[N], ps[N];
int main() {
	scanf("%d%d", &r, &n);
	memset(f, 0xbf, sizeof(f));
	t[0] = 0, x[0] = 1, y[0] = 1;
	f[0] = ps[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
		if (i >= 2 * r) f[i] = ps[i - 2 * r] + 1;
		for (int j = max(0, i - 2 * r + 1); j < i; j++) {
			if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])) f[i] = max(f[i], f[j] + 1);
		}
		ps[i] = max(ps[i - 1], f[i]);
	}
	printf("%d\n", ps[n]);
	return 0;
}