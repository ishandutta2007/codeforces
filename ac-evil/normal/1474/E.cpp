#include <bits/stdc++.h>
#define x first
#define y second
using std::vector; using std::pair; using std::make_pair; using std::swap;
typedef long long LL;
const int N = 100005;
int n, T, a[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		int mid = n/2; LL ans = 0;
		for (int i = 1; i <= n; i++) a[i] = i;
		for (int i = 2; i <= mid; i++) ans += (LL)(n - i) * (n - i);
		for (int i = mid+1; i <= n; i++) ans += (LL)(i - 1) * (i - 1);
		printf("%lld\n", ans);
		for (int i = n; i > mid; i--) swap(a[1], a[i]);
		for (int i = mid; i > 1; i--) swap(a[i], a[n]);
		for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		printf("\n%d\n", n-1);
		for (int i = 2; i <= mid; i++) printf("%d %d\n", i, n);
		for (int i = mid+1; i <= n; i++) printf("%d %d\n", i, 1);
	}
	return 0;
}