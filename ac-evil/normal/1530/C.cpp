#include <bits/stdc++.h>
const int N = 1e5 + 5;
int T, n, a[N], b[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		std::sort(a + 1, a + n + 1, std::greater<int>());
		std::sort(b + 1, b + n + 1, std::greater<int>());
		std::priority_queue<int> Q;
		int suma = 0, sumb = 0, cnta = n - n / 4, now = n;
		for (int i = 1; i <= n - n / 4; i++) suma += a[i], Q.push(-a[i]);
		std::partial_sum(b + 1, b + n + 1, b + 1);
		for (; suma < b[std::min(n, now - now / 4)]; ) {
			now++;
			if (cnta < now - now / 4) suma += 100, cnta++;
			else suma += 100 + Q.top(), Q.pop();
			Q.push(-100);
		}
		printf("%d\n", now - n);
	}
	return 0;
}