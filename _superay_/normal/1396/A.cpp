#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n == 1) {
		puts("1 1");
		printf("%d\n", -a[1]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
	} else {
		printf("%d %d\n", 1, n);
		for (int i = 1; i <= n; i++) printf("%lld%c", -1ll * a[i] * n, " \n"[i == n]);
		printf("%d %d\n", 1, n - 1);
		for (int i = 1; i <= n - 1; i++) printf("%lld%c", 1ll * a[i] * (n - 1), " \n"[i == n - 1]);
		printf("%d %d\n", 2, n);
		for (int i = 2; i <= n; i++) printf("%lld%c", (i == n) ? 1ll * a[i] * (n - 1) : 0ll, " \n"[i == n]);
	}
	return 0;
}