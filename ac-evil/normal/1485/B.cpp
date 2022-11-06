#include <bits/stdc++.h>
const int N = 100005;
using std::min;
int n, q, k, a[N];
int main() {
	scanf("%d%d%d", &n, &q, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", 2 * (k - r + l - 1) - a[l] - (k - a[r]) + 1);
	}
	return 0;
}