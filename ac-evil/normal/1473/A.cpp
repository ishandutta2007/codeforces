#include <bits/stdc++.h>
const int N = 100005;
int T, n, d, a[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		std::sort(a+1, a+n+1);
		int ok = 1;
		for (int i = 1; i <= n; i++) if (a[i] > d) ok = 0;
		if (ok || a[1] + a[2] <= d) puts("YES"); else puts("NO");
	}
	return 0;
}