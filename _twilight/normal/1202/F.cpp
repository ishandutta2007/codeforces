#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int a, b, n;

int main() {
	scanf("%d%d", &a, &b);
	n = a + b;
	int ans = 0;
	for (int i = 1, j; i <= n; i = j + 1) {
		j = n / (n / i);
		int l = n / i;
		if ((b + l) / (l + 1) > b / l || (a + l) / (l + 1) > a / l)
			continue;
		int L = i, R = j;
		L = max(L, (a + l) / (l + 1) + (b + l) / (l + 1));
		R = min(R, a / l + b / l);
		if (L <= R) {
			ans += R - L + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}