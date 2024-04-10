#include <bits/stdc++.h>
using namespace std;
int n, a[55];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
		if (!sum) puts("NO");
		else if (sum > 0) {
			sort(a + 1, a + 1 + n, greater<int>());
			puts("YES");
			for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
		} else {
			sort(a + 1, a + 1 + n);
			puts("YES");
			for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
		}
	}
	return 0;
}