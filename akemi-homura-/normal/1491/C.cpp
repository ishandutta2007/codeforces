#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long cur = 0, dlt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			for (int j = 1; j < i - 1; j++) if (j + a[j] >= i) cur++;
			int mn = max(1, n - i);
			if (a[i] > mn) {
				cur = max(0ll, cur - (a[i] - mn));
				dlt += a[i] - mn;
				a[i] = mn;
			}
			cur = max(0ll, cur - (a[i] - 1));
		}
		printf("%lld\n", cur + dlt);
	}
	return 0;
}