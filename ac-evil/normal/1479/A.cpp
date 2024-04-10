#include <bits/stdc++.h>
const int N = 100005;
int n, a[N];
void ask(int x) {
	if (x <= 0 || x > n) return;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &a[x]);
}
int main() {
	scanf("%d", &n);
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (ask(mid), ask(mid + 1), a[mid] < a[mid + 1]) r = mid; else l = mid + 1;
	}
	printf("! %d", l); fflush(stdout);
	return 0;
}