#include <bits/stdc++.h>
using namespace std;
int p[10005], vis[10005];
int main() {
	int n;
	scanf("%d", &n);
	int s = 1;
	for (int i = 2; i <= n; i++) {
		printf("? %d %d\n", s, i);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		printf("? %d %d\n", i, s);
		fflush(stdout);
		int y;
		scanf("%d", &y);
		assert(x != y);
		if (!y || x > y) {
			p[s] = x;
			vis[x] = 1;
			s = i;
		} else {
			p[i] = y;
			vis[y] = 1;
		}
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) p[s] = i;
	printf("! "); for (int i = 1; i <= n; i++) printf("%d ", p[i]);
	puts("");
	fflush(stdout);
	return 0;
}