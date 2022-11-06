#include <bits/stdc++.h>
using std::max; using std::min;
const int N = 105;
int T, n, k, h[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
		for (int i = 1; i < k; i++) {
			int flag = 1;
			for (int j = 1; j < n; j++)
				if (h[j] < h[j+1]) { h[j]++; flag = 0; break; }
			if (flag) break;
		}
		int ok = 0;
		for (int i = 1; i < n; i++)
			if (h[i] < h[i+1]) { ok = 1; printf("%d\n", i); break; }
		if (!ok) puts("-1");
	}
	return 0;
}