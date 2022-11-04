#include <bits/stdc++.h>
using namespace std;
int n, a[200005], cnt[20];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < 20; j++) if (x >> j & 1) cnt[j]++;
	}
	for (int j = 0; j < 20; j++)
		for (int i = 1; i <= cnt[j]; i++) a[i] += (1 << j);
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += 1ll * a[i] * a[i];
	printf("%lld\n", ans);
	return 0;
}