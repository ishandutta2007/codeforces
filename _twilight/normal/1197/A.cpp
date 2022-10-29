#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int T, n;
int a[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		sort(a + 1, a + n + 1);
		int ans = min(n - 2, a[n - 1] - 1);
		printf("%d\n", ans);
	}
	return 0;
}