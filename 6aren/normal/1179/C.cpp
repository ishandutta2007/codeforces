#include<bits/stdc++.h>

using namespace std;

const int MX = 1000005;
const int N = 300005;

int n, m, a[N], b[N], it[4 * MX], lazy[4 * MX];

void lazy_down(int k) {
	lazy[2 * k] += lazy[k];
	lazy[2 * k + 1] += lazy[k];
	it[2 * k] += lazy[k];
	it[2 * k + 1] += lazy[k];
	lazy[k] = 0;
	return;
}

void update(int k, int l, int r, int u, int v, int val) {
	if (l > v || r < u) {
		return;
	}

	if (l >= u && r <= v) {
		it[k] += val;
		lazy[k] += val;
		return;
	}

	int mid = (l + r) / 2;
	lazy_down(k);
	update(2 * k, l, mid, u, v, val);
	update(2 * k + 1, mid + 1, r, u, v, val);
	
	it[k] = max(it[2 * k], it[2 * k + 1]);
}

int query(int k, int l, int r) {
	if (it[k] < 0) return -1;

	if (l == r) {
		if (it[k] > 0) return l;
		else return -1;
	}

	int mid = (l + r) / 2;
	lazy_down(k);
	if (it[2 * k + 1] > 0) {
		return query(2 * k + 1, mid + 1, r);
	} else {
		return query(2 * k, l, mid);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		update(1, 1, MX - 1, 1, a[i], 1);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", b + i);
		update(1, 1, MX - 1, 1, b[i], -1);
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int type, id, val;
		scanf("%d%d%d", &type, &id, &val);
		if (type == 1) {
			update(1, 1, MX - 1, 1, a[id], -1);
			a[id] = val;
			update(1, 1, MX - 1, 1, val, 1);
		} else {
			update(1, 1, MX - 1, 1, b[id], 1);
			b[id] = val;
			update(1, 1, MX - 1, 1, val, -1);
		}
		printf("%d\n", query(1, 1, MX - 1));
	}
	return 0;
}