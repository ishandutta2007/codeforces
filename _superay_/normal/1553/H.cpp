#include <bits/stdc++.h>
using namespace std;
int K, f[1 << 19][20], mn[1 << 19][20], mx[1 << 19][20];
bool has[1 << 20];
inline void Ins(int x) {
	int p = 1;
	for (int i = K - 1; i >= 0; i--) {
		p = p * 2 + (x >> i & 1);
		has[p] = 1;
	}
}
void F(int mask, int dep, int p) {
	if (f[mask][dep]) return;
	if (!dep) {
		f[mask][dep] = 1e9;
		mn[mask][dep] = mx[mask][dep] = 0;
		return;
	}
	f[mask][dep] = 1e9;
	mn[mask][dep] = 1e9;
	mx[mask][dep] = -1e9;
	for (int ty = 0; ty < 2; ty++) if (has[p * 2 + ty]) {
		int nmask = (!ty) ? (mask & ~(1 << (dep - 1))) : (mask | (1 << (dep - 1)));
		F(nmask, dep - 1, p * 2 + ty);
		f[mask][dep] = min(f[mask][dep], f[nmask][dep - 1]);
		mn[mask][dep] = min(mn[mask][dep], mn[nmask][dep - 1] + (((mask >> (dep - 1) & 1) ^ ty) << (dep - 1)));
		mx[mask][dep] = max(mx[mask][dep], mx[nmask][dep - 1] + (((mask >> (dep - 1) & 1) ^ ty) << (dep - 1)));
	}
	int lson = p * 2, rson = p * 2 + 1;
	if (!has[lson] || !has[rson]) return;
	if (!(mask >> (dep - 1) & 1)) {
		f[mask][dep] = min(f[mask][dep],
		(mn[(mask | (1 << (dep - 1)))][dep - 1] + (1 << (dep - 1))) - mx[(mask & ~(1 << (dep - 1)))][dep - 1]);
	} else {
		f[mask][dep] = min(f[mask][dep],
		mn[(mask & ~(1 << (dep - 1)))][dep - 1] + (1 << (dep - 1)) - mx[(mask | (1 << (dep - 1)))][dep - 1]);
	}
}
int n;
int main() {
	scanf("%d%d", &n, &K);
	has[1] = 1;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		Ins(x);
	}
	for (int i = 0; i < (1 << K); i++) {
		F(i, K, 1);
		printf("%d ", f[i][K]);
	}
	return 0;
}