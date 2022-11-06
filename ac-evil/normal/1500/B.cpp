#include <bits/stdc++.h>
const int N = 1000005;
typedef long long LL;
int L, n, m, a[N], b[N], ta[N], tb[N]; LL k, T, r[N];
void exgcd(int a, int b, int &x, int &y, int &d) {
	if (!b) { d = a, x = 1, y = 0; }
	else { exgcd(b, a % b, y, x, d), y -= a/b*x; }
}
int gcd(int a, int b) {
	int x, y, d; exgcd(a, b, x, y, d);
	return d;
}
int main() {
	memset(ta, -1, sizeof ta), memset(tb, -1, sizeof tb);
	scanf("%d%d%lld", &n, &m, &k); L = 2 * std::max(n, m);
	T = 1LL * n * m / gcd(n, m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ta[a[i]] = i % n;
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), tb[b[i]] = i % m;
	for (int i = 1; i <= L; i++)
		if (~ta[i] && ~tb[i]) {
			int x, y, d, t; exgcd(n, m, x, y, d);
			if ((ta[i] - tb[i]) % d) continue;
			r[i] = ta[i];
			t = m / d; x = 1LL * x * ((tb[i] - r[i]) / d) % t;
			(r[i] += 1LL * x * n) %= T;
			if (r[i] <= 0) r[i] += T;
		}
	//for (int i = 1; i <= L; i++) printf("%d:%lld ", i, r[i]);
	LL le = 0, ri = 1LL << 62;
	while (le <= ri) {
		LL mid = le + ri >> 1, ans = mid;
		for (int i = 1; i <= L; i++)
			if (r[i]) ans -= (mid - r[i] + T) / T;
		if (ans < k) le = mid + 1; else ri = mid - 1;
	}
	printf("%lld\n", le);
	return 0;
}