#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 300005;

int n, mx, bel[N], B;
LL a[N], c1[N], c2[N], s1[N], s2[N];

void ins(LL *c, LL *s, int x, LL y) {
	for (int i = bel[x]; i <= bel[mx]; i++) s[i] += y;
	for (int i = x; bel[i] == bel[x]; i++) c[i] += y;
}

LL find(LL *c, LL *s, int x) {
	if (x <= 0) return 0;
	x = min(x, mx);
	return s[bel[x] - 1] + c[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), mx = max(mx, (int)a[i]);
	B = sqrt(mx);
	for (int i = 1; i <= mx; i++) bel[i] = (i + B - 1) / B;
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= mx; j += a[i]) {
			ans += find(c1, s1, j + (int)a[i] - 1) - find(c1, s1, j - 1);
			ans -= (LL)j * (find(c2, s2, j + (int)a[i] - 1) - find(c2, s2, j - 1));
		}
		ans += a[i] * (i - 1);
		for (int k = 1, last; k <= a[i]; k = last + 1) {
			last = a[i] / (a[i] / k);
			ans -= (a[i] / k) * (find(c1, s1, last) - find(c1, s1, k - 1));
		}
		printf("%lld ", ans);
		ins(c1, s1, a[i], a[i]);
		ins(c2, s2, a[i], 1);
	}
	return 0;
}