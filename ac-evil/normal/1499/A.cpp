#include <bits/stdc++.h>
int T, n, k1, k2, w, b;
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d", &n, &k1, &k2, &w, &b);
		if (k1 + k2 >= w * 2 && (n * 2 - k1 - k2) >= b * 2) puts("YES"); else puts("NO");
	}
	return 0;
}