#include <bits/stdc++.h>
const int N = 300005;
int T, n, a[N], b[N];
int f(int a, int b, int c) { return b > a && b > c || b < a && b < c; }
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = 0;
		a[0] = a[1], a[n+1] = a[n];
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] > a[i-1] && a[i] > a[i+1] || a[i] < a[i-1] && a[i] < a[i+1]) b[i] = 1, ans++;
		/*for (int i = 1; i <= n; i++) {
			if (b[i] && b[i-1] && b[i-2]) { ok = 3; break; }
			if (b[i] && b[i-1] && (i == n || (a[i] < a[i+1] ? a[i+1] >= a[i-1] : a[i+1] <= a[i-1]) || a[i+1] == a[i+2])) ok = 2;
			if (b[i] && b[i+1] && (i == 1 || (a[i] < a[i-1] ? a[i-1] >= a[i+1] : a[i-1] <= a[i+1]) || a[i-1] >= a[i+1] || a[i-2] == a[i-1])) ok = 2;
		}*/
		int tot = ans;
		for (int i = 2; i < n; i++)
			tot = std::min(tot, ans - b[i] - b[i-1] - b[i+1] + std::min(f(a[i-1], a[i+1], a[i+2]), f(a[i-2], a[i-1], a[i+1])));
		printf("%d\n", tot);
	}
	return 0;
}