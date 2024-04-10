#include <bits/stdc++.h>
const int N = 100005;
int T, n;
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		if (n == 1) puts("9");
		else if (n == 2) puts("98");
		else {
			printf("989");
			for (int i = 4; i <= n; i++) printf("%d", (6+i)%10);
			puts("");
		}
	}
	return 0;
}