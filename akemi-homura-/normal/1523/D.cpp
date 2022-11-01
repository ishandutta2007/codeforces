#include <bits/stdc++.h>
using namespace std;
#define ppcnt __builtin_popcountll
int n, m, p, cnt[1 << 15], cc[100], idx[100];
long long a[200005], b[200005];
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		char str[65];
		scanf(" %s", str);
		for (int j = 0; j < m; j++) if (str[j] == '1') a[i] |= (1ll << j);
	}
	mt19937 rng(time(0) + 114514);
	long long ans = 0;
	for (int t = 0; t < 20; t++) {
		int pos = uniform_int_distribution<int>(1, n)(rng);
		p = 0;
		for (int j = 0; j < m; j++) if (a[pos] >> j & 1) {
			cc[p] = j;
			idx[j] = p++;
		}
		for (int i = 0; i < (1 << p); i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			int mask = 0;
			for (int j = 0; j < p; j++) if (a[i] >> cc[j] & 1) {
				mask |= (1 << j);
			}
			cnt[mask]++;
		}
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < (1 << p); j++) if (j >> i & 1) {
				cnt[j ^ (1 << i)] += cnt[j];
			}
		}
		for (int j = 0; j < (1 << p); j++) if (cnt[j] >= (n + 1) / 2 && ppcnt(j) > ppcnt(ans)) {
			ans = 0;
			for (int i = 0; i < p; i++) if (j >> i & 1) ans |= (1ll << cc[i]);
		}
	}
	for (int i = 0; i < m; i++) if (ans >> i & 1) putchar('1'); else putchar('0');
	return 0;
}