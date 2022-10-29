#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 5;

int n, m;
int a[N], b[N], c[N];

int main() {
	scanf("%d%d", &n, &m);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", a + i);
		sum += a[i];
	}
	a[0] += (n - sum % n) % n;
	c[0] = a[0] % n;
	for (int i = 1; i < m; i++) {
		c[i] = (a[i] + c[i - 1]) % n;
	}
	c[m] = n;
	sort(c, c + m);
	for (int i = 0; i < m; i++) {
		b[i] = c[i + 1] - c[i];
	}
	printf("%d\n", (sum + n - 1) / n);
	for (int i = 0; i < m; i++) {
		printf("%d ", b[i]);
	}
	putchar('\n');
	int cur = 0, nxt = (cur == m - 1) ? (0) : (cur + 1);
	for (int i = 0; i < m; i++) {
		while (a[i] > 0) {
			a[i] -= b[cur];
			printf("%d%c", i + 1, (!nxt) ? ('\n') : (' '));
			cur = nxt, nxt = (cur == m - 1) ? (0) : (cur + 1);
		}
	}
	while (cur) {
		putchar('1'), putchar(' ');
		cur = nxt, nxt = (cur == m - 1) ? (0) : (cur + 1);
	}
	return 0;
}