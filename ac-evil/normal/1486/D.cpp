#include <bits/stdc++.h>
using std::min;
const int N = 200005;
int n, k, a[N], b[N], c[N];
bool check(int x) {
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + (a[i] >= x ? 1 : -1), c[i] = min(c[i - 1], b[i]);
	for (int i = k; i <= n; i++)
		if (b[i] - c[i - k] > 0) return 1;
	return 0;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int l = 1, r = n;
	while (l <= r) {
		int mid = l+r>>1;
		if (check(mid)) l = mid + 1; else r = mid - 1;
	}
	printf("%d", l - 1);
	return 0;
}