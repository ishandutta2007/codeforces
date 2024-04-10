#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 4e5 + 5;

int n, I;
int tot;
int a[N], b[N], c[N];

int main() {
	scanf("%d%d", &n, &I);
	I <<= 3;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	a[0] = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			c[tot] = i;
		} else {
			b[++tot] = a[i];
			c[tot] = i;
		}
	}
	int k = 0, K;
	while (k <= 29 && (k + 1) * n <= I)
		k++;
	K = 1 << k;
	int mx = 0;
	for (int i = 1; i <= tot; i++) {
		int R = min(tot, i + K - 1);
		mx = max(c[R] - c[i - 1], mx);
	}
	printf("%d\n", n - mx);
	return 0;
}