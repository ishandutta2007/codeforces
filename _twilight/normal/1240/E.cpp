#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 5e5 + 5;

int n, m;
int a[N];
int c[N];
ll s[N];

boolean check(int x, int y) {
	if (s[x] < 2)
		return false;
	if (x > s[y])
		return false;
	int vd = x / y, vr = x - vd * y;
	boolean flag1 = (s[y] - vd * 2 >= x), flag2 = (s[y] - vd * 2 > x);
	if (!flag1)
		return false;
	int vu = (x + y - 1) / y;
	if (s[y] - 2 * vu >= x)
		return true;
	int v2d = (x << 1) / y, v2r = (x << 1) - v2d * y, v2u = v2d + 1 - !v2r;
	if (s[y] - v2u >= x && s[x << 1])
		return true;
	if (s[y] - v2d >= x) {
		for (int l = v2d * y - 1 + v2r, r = (v2d + 1) * y - 1; l < m; l += y, r += y) {
			if (c[min(r, m)] - c[max(l, 0)]) {
				return true;
			}
		}
	}
	int c0 = 0, c1 = c[m] - c[x - 1];
	for (int l = vd * y - 1 + vr, r = (vd + 1) * y - 1; l < m; l += y, r += y) {
		c0 += c[min(r, m)] - c[max(l, 0)];
	}
	return c0 > 1 || (flag2 && c0 == 1 && c1 > 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		c[a[i]]++;
		m = max(m, a[i]);
	}
	for (int i = 1; i <= m; i++)
		c[i] += c[i - 1];
	for (int i = 1; i <= m; i++) {
		for (int l = i - 1, r = (i << 1) - 1, t = 1; l < m; r += i, l += i, t++) {
			s[i] += 1ll * t * (c[min(r, m)] - c[l]);
		}
	}
	ll ans = 4;
	for (int y = m, x = 0; y >= 2; y--) {
		while (x < m && check(x + 1, y))
			x++;
		if (x >= 2)
			ans = max(1ll * x * y, ans);
//		cerr << y << " " << x << '\n';
	}
	printf("%lld\n", ans);
	return 0;
}