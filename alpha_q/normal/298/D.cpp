#include <bits/stdc++.h>

using namespace std;

bool cmp (int x, int y) {return x > y;}

int main() {
	int n, m, k, i, a[100005], b[100005];
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++) scanf("%d", a + i);
	for (i = 1; i <= m; i++) scanf("%d", b + i);
	sort (a + 1, a + 1 + n, cmp); sort (b + 1, b + 1 + m, cmp);
	if (n > m) {printf("YES\n"); return 0;}
	for (i = 1; i <= n; i++) {
		if (a[i] > b[i]) {
			printf("YES\n");
			return 0;
		} 
	} 
	printf("NO\n");
	return 0;
}