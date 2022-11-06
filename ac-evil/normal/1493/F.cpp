#include <bits/stdc++.h>
using std::max;
const int N = 1005;
int n, m;
int p[N], check[N];
void sieve(int n) {
	check[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!check[i]) p[++p[0]] = i;
		for (int j = 1; j <= p[0] && i * p[j] <= n; j++) {
			check[i * p[j]] = 1;
			if (!(i % p[j])) break;
		}
	}
}
int ask(int h, int w, int i1, int j1, int i2, int j2) {
	printf("? %d %d %d %d %d %d\n", h, w, i1, j1, i2, j2);
	fflush(stdout);
	int ok; scanf("%d", &ok); return ok;
}
bool testx(int a) {
	if (a * 2 == n) return ask(a, m, 1, 1, a + 1, 1);
	int b = n / a, l = (b - 1) / 2;
	if (b & 1) return ask(l * a, m, 1, 1, (b - l) * a + 1, 1) && ask(l * a, m, 1, 1, (b - l - 1) * a + 1, 1);
	return ask((l + 1) * a, m, 1, 1, (b - l - 1) * a + 1, 1) && ask(l * a, m, 1, 1, (b - l - 2) * a + 1, 1);
}
bool testy(int a) {
	if (a * 2 == m) return ask(n, a, 1, 1, 1, a + 1);
	int b = m / a, l = (b - 1) / 2;
	if (b & 1) return ask(n, l * a, 1, 1, 1, (b - l) * a + 1) && ask(n, l * a, 1, 1, 1, (b - l - 1) * a + 1);
	return ask(n, (l + 1) * a, 1, 1, 1, (b - l - 1) * a + 1) && ask(n, l * a, 1, 1, 1, (b - l - 2) * a + 1);
}
int main() {
	scanf("%d%d", &n, &m); sieve(max(n, m));
	int x = n, y = m, cntx = 0, cnty = 0;
	for (int i = 2; i <= x; i++)
		if (!check[i])
			while (!(x % i) && testx(x / i)) x /= i;
	for (int i = 2; i <= y; i++)
		if (!check[i])
			while (!(y % i) && testy(y / i)) y /= i;
	x = n / x, y = m / y;
	for (int i = 1; i <= x; i++)
		if (!(x % i)) cntx++;
	for (int i = 1; i <= y; i++)
		if (!(y % i)) cnty++;
	printf("! %d", cntx * cnty);
	return 0;
}