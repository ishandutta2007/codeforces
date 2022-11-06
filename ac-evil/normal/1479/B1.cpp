#include <bits/stdc++.h>
const int N = 100005;
int n, a[N], p, q;
int main() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < n && !(a[j] == a[j + 1] && a[j + 1] != a[j + 2])) j++;
		if (a[i] == a[j]) {
			if (p != a[i]) p = a[i], ans++;
			else if (q != a[i]) q = a[i], ans++;
		} else {
			if (p == a[j]) p = a[i], ans++;
			else if (q == a[j]) q = a[i], ans++;
			else if (p != a[i]) p = a[i], ans++;
			else if (q != a[i]) q = a[i], ans++;
		}
		if (i == j) j++;
	}
	printf("%d", ans);
	return 0;
}