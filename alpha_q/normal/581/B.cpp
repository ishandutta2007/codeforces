#include <bits/stdc++.h>

using namespace std;

main() {
	int n, h[100005], rec[100005], res; scanf("%d", &n);
	for (int j = 1; j <= n; j++) scanf("%d", &h[j]);
	rec[n] = h[n]; for (int i = n - 1; i >= 1; i--) rec[i] = max(rec[i + 1], h[i]);
	for (int k = 1; k < n; k++) {
		if (h[k] > rec[k + 1]) res = 0;
		else res = rec[k] - h[k] + 1;
		printf("%d ", res);
	}
	printf("0\n");
}