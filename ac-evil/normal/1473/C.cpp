#include <bits/stdc++.h>
const int N = 200005;
int T, n, k;
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= 2*k-n-1; i++) printf("%d ", i);
		for (int i = 1; i <= n-k+1; i++) printf("%d ", k-i+1);
		puts("");
	}
	return 0;
}