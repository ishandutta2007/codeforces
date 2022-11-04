#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, a[N], lst[N], st[N * 4], tag[N * 4];
void build(int i, int l, int r) {
	st[i] = tag[i] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
}
inline void pushdown(int i) {
	if (tag[i]) {
		st[i << 1] += tag[i];
		tag[i << 1] += tag[i];
		st[i << 1 | 1] += tag[i];
		tag[i << 1 | 1] += tag[i];
		tag[i] = 0;
	}
}
void Add(int i, int l, int r, int lf, int rg, int val) {
	if (lf <= l && r <= rg) {
		st[i] += val;
		tag[i] += val;
		return;
	}
	pushdown(i);
	int mid = (l + r) >> 1;
	if (lf <= mid) Add(i << 1, l, mid, lf, rg, val);
	if (rg > mid) Add(i << 1 | 1, mid + 1, r, lf, rg, val);
	st[i] = min(st[i << 1], st[i << 1 | 1]);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<int> v0;
		for (int i = 1; i <= n; i++) {
			lst[i] = n + 1;
			scanf("%d", &a[i]);
			if (!a[i]) v0.push_back(i);
		}
		int lim = v0.size() / 2;
		build(1, 1, n);
		int i, j, k;
		for (i = lim - 1, j = v0.size(), k = n; i >= 0; i--) {
			while (k >= v0[i]) {
				if (a[k]) {
					Add(1, 1, n, k, lst[a[k]] - 1, 1);
					lst[a[k]] = k;
				}
				k--;
			}
			j--;
			Add(1, 1, n, v0[j], n, -1);
			while (st[1] < 0) {
				Add(1, 1, n, v0[j], n, 1);
				j++;
			}
		}
		printf("%d\n", (int)v0.size() - j);
	}
	return 0;
}