#include <bits/stdc++.h>
using namespace std;
int n, x, a[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &x);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum == x) {
			puts("NO");
			continue;
		}
		sort(a + 1, a + 1 + n);
		sum = 0;
		for (int i = 1; i <= n; i++) {
			if (sum + a[i] == x) {
				swap(a[i], a[i + 1]);
			}
			sum += a[i];
		}
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}