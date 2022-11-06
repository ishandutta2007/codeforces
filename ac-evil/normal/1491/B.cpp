#include <bits/stdc++.h>
using std::min; using std::max;
const int N = 105;
int T, n, u, v, a[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &u, &v);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int mn = 1e6, mx = 0;
		for (int i = 1; i <= n; i++)
			mn = min(mn, a[i]), mx = max(mx, a[i]);
		if (mx - mn == 0)
			printf("%d\n", min(u + v, 2 * v));
		else if (mx - mn == 1)
			printf("%d\n", min(u, v));
		else {
			int ok = 1;
			for (int i = 2; i <= n; i++)
				if (abs(a[i] - a[i - 1]) > 1) ok = 0;
			if (ok) printf("%d\n", min(u, v));
			else puts("0");
		}
	}
	return 0;
}