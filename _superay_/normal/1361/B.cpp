#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
inline int qp(int a, int b, const int &mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
const int mod = 1000000007;
const int mod1 = 998244353;
const int mod2 = 999911659;
int n, p, a[N], val[N], val1[N], val2[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &p);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n, greater<int>());
		if (p == 1) {
			printf("%d\n", n % 2);
			continue;
		}
		for (int i = 1; i <= n; i++) {
			val[i] = qp(p, a[i], mod);
			val1[i] = qp(p, a[i], mod1);
			val2[i] = qp(p, a[i], mod2);
		}
		int ans = 0;
		for (int i = 1, j; i <= n; i = j + 1) {
			int fa = val[i], fa1 = val1[i], fa2 = val2[i];
			int s = 0, s1 = 0, s2 = 0;
			int found = 0;
			for (j = i + 1; j <= n; j++) {
				s = (s + val[j]) % mod;
				s1 = (s1 + val1[j]) % mod1;
				s2 = (s2 + val2[j]) % mod2;
				if (s == fa && s1 == fa1 && s2 == fa2) {
					found = 1;
					break;
				}
			}
			if (found) {
				continue;
			}
			ans = (fa - s + mod) % mod;
			break;
		}
		printf("%d\n", ans);
	}
	return 0;
}