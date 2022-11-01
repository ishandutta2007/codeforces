#include<bits/stdc++.h>
using namespace std;

const int N = 300005;
const int M = 1000005;
const int inf = 1000000;

int n, m;
class data {
	public:
		int l, r, w;
}a[N];
class tree {
	public:
		int tag, s;
}t[M * 4];

bool cmp(data x, data y) {
	return x.w < y.w;
}

void update(int d, int l, int r) {
	if (t[d].tag) t[d].s = r - l + 1;
	else {
		t[d].s = 0;
		if (l < r) t[d].s = t[d << 1].s + t[d << 1 | 1].s;
	}
}

void ins(int d, int l, int r, int x, int y, int w) {
	if (x <= l && r <= y) {
		t[d].tag += w;
		update(d, l, r);
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid) ins(d << 1, l, mid, x, y, w);
	if (y > mid) ins(d << 1 | 1, mid + 1, r, x, y, w);
	update(d, l, r);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
		if (a[i].l > 1) a[i].l++;
	}
	sort(a + 1, a + n + 1, cmp);
	int rig = 0, ans = inf;
	for (int lef = 1; lef <= n; lef++) {
		while (rig < n && t[1].s < m) {
			rig++;
			ins(1, 1, m, a[rig].l, a[rig].r, 1);
		}
		if (t[1].s == m) ans = min(ans, a[rig].w - a[lef].w);
		ins(1, 1, m, a[lef].l, a[lef].r, -1);
	}
	printf("%d\n", ans);
	return 0;
}