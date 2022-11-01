#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;
int n, q, m;

struct node {
	int mx, mn, ans, L, R, lazy;
	node() {
		mx = mn = ans = L = R = lazy = 0;
	}
};

string t;
node seg[N * 4];
int lazy[N * 4];
int a[N];

node merge(node x, node y) {
	node res;
	res.mx = max(x.mx, y.mx);
	res.mn = min(x.mn, y. mn);
	res.ans = max(x.ans, y.ans);
	res.L = max(x.L, y.L);
	res.R = max(x.R, y.R);
	res.L = max(res.L, x.mx - 2 * y.mn);
	res.R = max(res.R, y.mx - 2 * x.mn);
	res.ans = max(res.ans, x.L + y.mx);
	res.ans = max(res.ans, x.mx + y.R);
	return res;
}

void build(int id = 1, int s = 0, int e = m) {
//	cout << "48 " << id << " " << s << " " << e << endl;
	if (e - s == 1) {
		seg[id].mx = a[s];
		seg[id].mn = a[s];
		seg[id].L = -a[s];
		seg[id].R = -a[s];
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
	seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

void add(node &x, int p) {
	x.lazy += p;
	x.mx += p;
	x.mn += p;
	x.L -= p;
	x.R -= p;	
}

/*void shift(int id) {
	add(seg[id * 2], seg[id].lazy);
	add(seg[id * 2 + 1], seg[id].lazy);
	seg[id].lazy = 0;
}*/

void update(int l, int r, int p, int id = 1, int s = 0, int e = m) {
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
	//	cout << "73 " << id << " " << s << " " << e << " " << p << " " << seg[id].mx << endl;
		add(seg[id], p);
	//	cout << "73 " << id << " " << s << " " << e << " " << p << " " << seg[id].mx << endl;
		return;
	}
	int md = (s + e) / 2;
	update(l, r, p, id * 2, s, md);
	update(l, r, p, id * 2 + 1, md, e);
	int x = seg[id].lazy;
	seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
	add(seg[id], x);
}


int main() {
	cin >> n >> q >> t;
	m = t.size() + 1;
	for (int i = 1; i <= t.size(); i++) {
		a[i] = a[i - 1];
		if (t[i - 1] == '(') {
			a[i]++;
		}
		else {
			a[i]--;
		}
	}
	build();
	cout << seg[1].ans << endl;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (l > r) {
			swap(l, r);
		}
		if (t[l - 1] == '(' && t[r - 1] == ')') {
			update(l, r, -2);
		}
		if (t[r - 1] == '(' && t[l - 1] == ')') {
			update(l, r, 2);
		}
		swap(t[l - 1], t[r - 1]);
		cout << seg[1].ans << endl;
	//	for (int j = 1; j < 32; j++) {
		//	cout << "37 " << j << " " << seg[j].mx << endl;
	//	}
	}
	return 0;
}