#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int B = 320;
int n, q, bel[N], a[N], f[N];
struct Block {
	int l, r, tag;
	bool sm;
	inline void Process() {
		sm = 1;
		for (int i = l; i <= r; i++) {
			if (a[i] < l) f[i] = a[i];
			else f[i] = f[a[i]], sm = 0;
		}
	}
	inline void Push() {
		if (tag) {
			for (int i = l; i <= r; i++) a[i] = max(1, a[i] - tag);
			tag = 0;
		}
	}
	inline void Small(int lf, int rg, int x) {
		Push();
		for (int i = lf; i <= rg; i++) a[i] = max(1, a[i] - x);
		if (!sm) Process();
	}
	inline void Big(int x) {
		if (sm) tag = min(n, tag + x);
		else {
			for (int i = l; i <= r; i++) a[i] = max(1, a[i] - x);
			Process();
		}
	}
} b[N / B + 5];
inline int Get(int x) {
	if (b[bel[x]].sm) return max(1, a[x] - b[bel[x]].tag);
	else return f[x];
}
inline int Geta(int x) {
	return max(1, a[x] - b[bel[x]].tag);
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
	int cb = 0;
	for (int i = 2, j; i <= n; i = j + 1) {
		j = min(n, i + B - 1);
		++cb;
		for (int k = i; k <= j; k++) bel[k] = cb;
		b[cb].l = i;
		b[cb].r = j;
		b[cb].tag = 0;
		b[cb].Process();
	}
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			if (bel[l] == bel[r]) {
				b[bel[l]].Small(l, r, x);
			} else {
				b[bel[l]].Small(l, b[bel[l]].r, x);
				b[bel[r]].Small(b[bel[r]].l, r, x);
				for (int k = bel[l] + 1; k < bel[r]; k++)
					b[k].Big(x);
			}
		} else {
			int u, v;
			scanf("%d%d", &u, &v);
			while (u != v) {
				if (u < v) swap(u, v);
				if (bel[u] != bel[v]) {
					u = Get(u);
				} else {
					if (Get(u) != Get(v)) {
						u = Get(u);
						v = Get(v);
					} else {
						while (u != v) {
							if (u < v) swap(u, v);
							u = Geta(u);
						}
					}
				}
			}
			printf("%d\n", u);
		}
	}
	return 0;
}