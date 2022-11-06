#include <bits/stdc++.h>
using std::max;
typedef long long LL;
const int N = 300005, K = 1000000;
int T, n, q, a[N], b[K+5], fa[K+5];
int fset(int x) { return fa[x] == x ? x : fa[x] = fset(fa[x]); }
void merge(int x, int y) {
	fa[fset(x)] = fset(y);
}
LL sqr(LL x) { return x * x; }
bool check(LL x) { return x == sqr((LL)(sqrt(x)+0.5)); }
int main() {
	for (int i = 1; i <= K; i++) fa[i] = i;
	for (int i = 1; i <= K; i++)
		for (int j = 2; j <= sqrt(K); j++) {
			if (1LL * i * j * j > K) break;
			merge(i, i*j*j);
		}
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[fset(a[i])]++;
		int ans0 = 0, ans1 = 0;
		for (int i = 1; i <= n; i++) {
			//printf("%d %d\n", a[i], b[a[i]]);a
			ans0 = max(ans0, b[fset(a[i])]);
			if (check(a[i]) || b[fset(a[i])] % 2 == 0) ans1 += b[fset(a[i])];
			b[fset(a[i])] = 0;
		}
		for (scanf("%d", &q); q; q--) {
			LL w; scanf("%lld", &w);
			printf("%d\n", w ? max(ans1, ans0) : ans0);
		}
	}
	return 0;
}