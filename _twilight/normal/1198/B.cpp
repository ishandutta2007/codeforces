#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n, q;
int a[N], b[N], T[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	scanf("%d", &q);
	int opt, x, y;
	for (int t = 1; t <= q; t++) {
		scanf("%d%d", &opt, &x);
		if (opt == 1) {
			scanf("%d", &y);
			a[x] = y;
			T[x] = t;
		} else {
			b[t] = x;
		}
	}
	for (int i = q; i; i--)
		b[i] = max(b[i + 1], b[i]);
	b[0] = b[1];
	for (int i = 1; i <= n; i++) {
		a[i] = max(a[i], b[T[i]]);
		printf("%d ", a[i]);
	}
	return 0;
}