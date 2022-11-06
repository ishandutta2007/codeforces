#include <bits/stdc++.h>
typedef long long ll;
const int N = 3e4 + 5;
int T, n, a[N], b[N], c[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = n; i; i--) a[i] -= a[i - 1];
		ll sum = 0;
		for (int i = 2; i <= n; i++)
			if (a[i] < 0) sum += -a[i];
		puts(sum > a[1] ? "NO" : "YES");
	}
	return 0;
}