#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5, LG = 25;
int n, q, T;

struct node {
	int lc, rc;
	int sz, pre, suf, ans;
};

node res;

node mrg(node x, node y) {
	node z;
	z.lc = 0, z.rc = 0;
	z.sz = x.sz + y.sz;
	z.pre = x.pre;
	if (z.pre == x.sz) {
		z.pre += y.pre;
	}
	z.suf = y.suf;
	if (z.suf == y.sz) {
		z.suf += x.suf;
	}
	z.ans = max(x.ans, y.ans);
	z.ans = max(z.ans, x.suf + y.pre);
	return z;
}

int h[N];
int rt[N];
pair <int, int> a[N];
node seg[N * LG];

int update(int p, int id, int s = 0, int e = n) {
	T++;
	int nid = T;
	seg[nid].sz = N;
//	cout << "72 " << id << " " << nid << " " << s << " " << e << endl;
	if (e - s == 1) {
		seg[nid] = {0, 0, 1, 1, 1, 1};
		return nid;
	}
	int md = (s + e) / 2;
	int lc = seg[id].lc, rc = seg[id].rc;
	if (p < md) {
		lc = update(p, lc, s, md);
	}
	else {
		rc = update(p, rc, md, e);
	}
	seg[nid] = mrg(seg[lc], seg[rc]);
	seg[nid].lc = lc;
	seg[nid].rc = rc;
	return nid;
}

void get(int l, int r, int id, int s = 0, int e = n) {
//	cout << "71 " << id << endl;
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		res = mrg(res, seg[id]);
		return;
	}
	int md = (s + e) / 2;
	get(l, r, seg[id].lc, s, md);
	get(l, r, seg[id].rc, md, e);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		a[i + 1] = {-h[i], i};
	}
	seg[0].sz = N;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		rt[i] = update(a[i].second, rt[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
	//	res = {0, 0, 0, 0, 0, 0};
	//	get(1, n, rt[i]);
	//	cout << "74 " << res.ans << endl;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, w;
		cin >> l >> r >> w;
		l--;
		int dw = 0, up = n;
		while (up - dw > 1) {
			int md = dw + up - (dw + up) / 2;
			res = {0, 0, 0, 0, 0, 0};
			get(l, r, rt[md]);
			if (res.ans >= w) {
				up = md;
			}
			else {
				dw = md;
			}
		}
	//	cout << "75 " << dw << " " << up << endl;
		cout << -a[up].first << '\n';
	}
	return 0;
}