#include <bits/stdc++.h>
const int N = 100005;
int T, n, x[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
		for (int i = 2; i <= n; i++)
			if (x[i] <= x[i-1]) x[i]++;
		std::sort(x+1, x+n+1);
		printf("%d\n", std::unique(x+1, x+n+1) - x - 1);
	}
	return 0;
}