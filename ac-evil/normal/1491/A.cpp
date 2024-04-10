#include <bits/stdc++.h>
const int N = 100005;
int n, Q, a[N], zero = 0;
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), zero += a[i] == 0;
	while (Q--) {
		int ty, x; scanf("%d%d", &ty, &x);
		if (ty == 1) {
			if (a[x] == 0) zero--;
			else zero++;
			a[x] ^= 1;
		} else printf("%d\n", x <= n - zero ? 1 : 0);
	}
	return 0;
}