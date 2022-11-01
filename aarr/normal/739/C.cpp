#include <iostream>
using namespace std;

const int N = 300 * 1000 + 5;
int n, q;

struct node {
	int sz, pre, suf, ansl, ansr, ans;
	node() {
		sz = pre = suf = ansl = ansr = ans = 0;
	}
};

int a[N * 2];
long long d[N * 2];
node seg[N * 4];

node mrg(node x, node y) {
	node z;
	z.sz = x.sz + y.sz;
	z.pre = x.pre;
	z.suf = y.suf;
	z.ansl = x.ansl;
	z.ansr = y.ansr;
	z.ans = max(x.ans, y.ans);
	if (x.pre == x.sz) {
		z.pre = x.pre + y.pre;
	//	if (d[md] > 0)
			
	}
	if (x.suf == x.sz) {
		z.ansl = x.suf + y.ansl;
	}
	if (y.suf == y.sz) {
		z.suf = x.suf + y.suf;
	//	if (d[md - 1] < 0)
			
	}
	if (y.pre == y.sz) {
		z.ansr = x.ansr + y.pre;
	}
	if (y.ansr == y.sz) {
		z.ansr = max(z.ansr, x.suf + y.ansr);
	}
	if (x.ansl == x.sz) {
		z.ansl = max(z.ansl, x.ansl + y.pre);
	}
	z.ans = max(z.ans, x.ansr + y.pre);
	z.ans = max(z.ans, x.suf + y.ansl);
	return z;
}



/*void build(int id = 1, int s = 1) {
	if (e == s) {
		return;
	}
	if (e - s == 1) {
		seg[id] = node();
		seg[id].sz = 1;
		if (d[s] > 0) {
			seg[id].ansl = seg[id].ansr = seg[id].ans = seg[id].suf = 1;
		} 
		if (d[s] < 0) {
			seg[id].ansl = seg[id].ansr = seg[id].ans = seg[id].pre = 1;
		}
	//	cout << "72 " << id << " " << s << " " << e << " " << seg[id].ans << endl;
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
	seg[id] = mrg(seg[id * 2], seg[id * 2 + 1], md); 
//	cout << "71 " << id << " " << s << " " << e << " " << seg[id].ans << endl;
}*/
void update(int p, long long val) {
	d[p] += val;
//	cout << "78 " << p << " " << d[p] << endl;
	p += n;
	seg[p] = node();
	seg[p].sz = 1;
	if (d[p - n] > 0) {
		seg[p].ansl = seg[p].ansr = seg[p].ans = seg[p].suf = 1;
	} 
	if (d[p - n] < 0) {
		seg[p].ansl = seg[p].ansr = seg[p].ans = seg[p].pre = 1;
	}
	while (1) {
		p /= 2;
		seg[p] = mrg(seg[p * 2], seg[p * 2 + 1]);
	//	cout << "71 " << p << endl;
		if (p == 1) {
			break;
		} 
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	int m = n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int l, r, val;
			cin >> l >> r >> val;
			cout << 1 << endl;
		}
		return 0;
	}
	fill(a + n, a + N * 2, a[n - 1]);
	while (__builtin_popcount(n) > 1) {
		n++;
	}
//	cout << "41 " << n << endl;
	for (int i = 0; i < n; i++) {
		d[i] = a[i + 1] - a[i];
		update(i, 0);
	}
//	cout << seg[1].ans + 1 << endl;
//	for (int j = 0; j < 16; j++) {
//		cout << "75 " << seg[j].ans << endl;
//	}
	cin >> q;
//	build();
//	cout << seg[1].ans + 1 << endl;
	for (int i = 0; i < q; i++) {
		int l, r;
		int val;
		cin >> l >> r >> val;
		l -= 2, r--;
		if (r < m - 1) {
			update(r, -val);
		}
		if (l >= 0) {
			update(l, val);
		}
	//	for (int j = 0; j < 16; j++) {
	//		cout << "75 " << j << " " << seg[j].ans << endl;
	//	}
		cout << seg[1].ans + 1 << '\n';
	}
	return 0;
}