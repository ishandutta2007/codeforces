#include <bits/stdc++.h>
using std::sort; using std::swap;
const int N = 5005;
int n;
struct node { int x, y, id; } a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i;
	for (;;) {
		int ok = 1;
		for (int j = 2; j < n; j++)
			if (1LL*(a[j-1].x-a[j].x)*(a[j+1].x-a[j].x) + 1LL*(a[j-1].y-a[j].y)*(a[j+1].y-a[j].y) <= 0) swap(a[j], a[j+1]), ok = 0;
		if (ok) break;
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i].id);
	return 0;
}