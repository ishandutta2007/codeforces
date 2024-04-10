#include<bits/stdc++.h>
using namespace std;
struct node {
	int c0, c1, tag;
}nd[1000001];
string s1, s2;
void pushdown(int p) {
	if (nd[p].tag == -1) return;
	nd[p*2].tag = nd[p*2+1].tag = nd[p].tag;
	if (nd[p].tag) {
		nd[p*2].c1 += nd[p*2].c0, nd[p*2].c0 = 0;
		nd[p*2+1].c1 += nd[p*2+1].c0, nd[p*2+1].c0 = 0;
	}
	else {
		nd[p*2].c0 += nd[p*2].c1, nd[p*2].c1 = 0;
		nd[p*2+1].c0 += nd[p*2+1].c1, nd[p*2+1].c1 = 0;
	}
	nd[p].tag = -1;
}
void update(int p) {
	nd[p].c0 = nd[p*2].c0 + nd[p*2+1].c0;
	nd[p].c1 = nd[p*2].c1 + nd[p*2+1].c1;
}
void build(int p, int l, int r) {
	nd[p].tag = -1;
	if (l == r) {
		if (s2[l-1] == '0') nd[p].c0 = 1, nd[p].c1 = 0;
		else nd[p].c0 = 0, nd[p].c1 = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	update(p);
}
void modify(int p, int l, int r, int l0, int r0, int col) {
	if (l >= l0 && r <= r0) {
		nd[p].tag = col;
		if (col) nd[p].c1 += nd[p].c0, nd[p].c0 = 0;
		else nd[p].c0 += nd[p].c1, nd[p].c1 = 0;
		return;
	}
	pushdown(p);
	int mid = (l + r) / 2;
	if (l0 <= mid) modify(p * 2, l, mid, l0, r0, col);
	if (r0 > mid) modify(p * 2 + 1, mid + 1, r, l0, r0, col);
	update(p);
}
int query(int p, int l, int r, int l0, int r0) {
	if (l >= l0 && r <= r0) return nd[p].c1;
	pushdown(p);
	int mid = (l + r) / 2, ans = 0;
	if (l0 <= mid) ans += query(p * 2, l, mid, l0, r0);
	if (r0 > mid) ans += query(p * 2 + 1, mid + 1, r, l0, r0);
	return ans;
}
int l[200001], r[200001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		cin >> s1 >> s2;
		build(1, 1, n);
		for (int i = 1; i <= q; i++) cin >> l[i] >> r[i];
		bool flag = 0;
		for (int i = q; i >= 1; i--) {
			int cnt = query(1, 1, n, l[i], r[i]);
			if (cnt * 2 == r[i]-l[i]+1) {
				flag = 1;
				puts("NO");
				break;
			}
			if (cnt * 2 < r[i]-l[i]+1) modify(1, 1, n, l[i], r[i], 0);
			else modify(1, 1, n, l[i], r[i], 1);
		}
		if (flag) continue;
		for (int i = 1; i <= n; i++)
			if (query(1, 1, n, i, i) != s1[i-1] - '0') {
				flag = 1, puts("NO");
				break;
			}
		if (!flag) puts("YES");
	}
}