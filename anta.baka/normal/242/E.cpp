#include <bits/stdc++.h>

using namespace std;

struct segTree {
	struct node {
		int s, xr;
	};
	node merge(node a, node b) {
		node c;
		c.s = a.s + b.s;
		c.xr = 0;
		return c;
	}
	int n;
	vector<node> t;
	segTree(int _n) {
		n = _n;
		t.assign(4 * n, {0, 0});
	}
	void push(int v, int l, int r) {
		if(t[v].xr == 0) return;
		t[v].xr = 0;
		int m = (l + r) / 2;
		t[v * 2 + 1].s = m - l + 1 - t[v * 2 + 1].s;
		t[v * 2 + 1].xr ^= 1;
		t[v * 2 + 2].s = r - m - t[v * 2 + 2].s;
		t[v * 2 + 2].xr ^= 1;
	}
	void upd(int v, int l, int r, int l1, int r1) {
		if(r < l1 || r1 < l) return;
		if(l1 <= l && r <= r1) {
			t[v].s = r - l + 1 - t[v].s;
			t[v].xr ^= 1;
			return;
		}
		push(v, l, r);
		int m = (l + r) / 2;
		upd(v * 2 + 1, l, m, l1, r1);
		upd(v * 2 + 2, m + 1, r, l1, r1);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
	long long get(int v, int l, int r, int l1, int r1) {
		if(r < l1 || r1 < l) return 0;
		if(l1 <= l && r <= r1) return t[v].s;
		push(v, l, r);
		int m = (l + r) / 2;
		return get(v * 2 + 1, l, m, l1, r1) + get(v * 2 + 2, m + 1, r, l1, r1);
	}
};

int bit(int a, int b) {
	return ((a & (1 << b)) ? 1 : 0);
}

int n, a[100000], q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<segTree> st(20, segTree(n));
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for(int j = 0; j < 20; j++)
			if(bit(x, j))
				st[j].upd(0, 0, n - 1, i, i);
	}
	cin >> q;
	for(int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if(type == 1) {
			int l, r;
			cin >> l >> r;
			--l; --r;
			long long ans = 0;
			for(int j = 0; j < 20; j++)
				ans += (1 << j) * st[j].get(0, 0, n - 1, l, r);
			cout << ans << '\n';
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			--l; --r;
			for(int j = 0; j < 20; j++)
				if(bit(x, j))
					st[j].upd(0, 0, n - 1, l, r);
		}
	}
}