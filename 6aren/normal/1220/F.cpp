#include<bits/stdc++.h>
using namespace std;

const int N = 400005;

int n, a[N], l[N], r[N];

struct IT {
	int x[200005], it[4 * N], lazy[4 * N];
	IT(int *t, int n) {
		for (int i = 1; i <= n; i++) {
			x[i] = t[i];
		}
		build(1, 1, n);
	}

	void build(int node, int l, int r) {
		if (l == r) {
			it[node] = x[l];
			return;
		}
		int mid = (l + r) >> 2;
		build(node << 1, l, mid);
		build(node << 1 | 1, mid + 1, r);
		combine(node);
	}

	void combine(int node) {
		it[node] = max(it[node << 1], it[node << 1 | 1]); 
	}

	void down(int node) {
		if (lazy[node] == 0) return;
		int left = node << 1;
		int right = node << 1 | 1;
		int val = lazy[node];
		lazy[left] += val;
		lazy[right] += val;
		it[left] += val;
		it[right] += val;
		lazy[node] = 0;
		return;
	}

	void update(int node, int l, int r, int u, int v, int val) {
		if (l > v || r < u) return;
		if (l >= u && r <= v) {
			it[node] += val;
			lazy[node] += val;
			return;
		}
		down(node);
		int mid = (l + r) >> 1;
		update(node << 1, l, mid, u, v, val);
		update(node << 1 | 1, mid + 1, r, u, v, val);
		combine(node);
	}

	int get(int node, int l, int r, int u, int v) {
		if (l > v || r < u) return 0;
		if (l >= u && r <= v) {
			return it[node];
		}
		down(node);
		int mid = (l + r) >> 1;
		int q1 = get(node << 1, l, mid, u, v);
		int q2 = get(node << 1 | 1, mid + 1, r, u, v);
		return max(q1, q2);
	}
	IT() {
		memset(it, 0, sizeof(it));
		memset(lazy, 0, sizeof(lazy));
	}
} it;

deque<int> dq;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	dq.push_back(0);
	for (int i = 1; i <= 2 * n; i++) {
		while (a[dq.back()] >= a[i]) {
			dq.pop_back();
		}
		l[i] = dq.back() + 1;
		dq.push_back(i);
	}
	while (!dq.empty()) {
		dq.pop_back();
	}
	dq.push_back(2 * n + 1);
	for (int i = 2 * n; i >= 1; i--) {
		while (a[dq.back()] >= a[i]) {
			dq.pop_back();
		}
		r[i] = dq.back() - 1;
		dq.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		it.update(1, 1, 2 * n, l[i], r[i], 1);
	}
	int ans1 = it.get(1, 1, 2 * n, 1, n), ans2 = 0;
	for (int i = 1; i <= n; i++) {
		it.update(1, 1, 2 * n, l[i], r[i], -1);
		it.update(1, 1, 2 * n, l[i + n], r[i + n], 1);
		//cout << l[i] << ' ' << r[i] << ' ' << l[i + n] << ' ' << r[i + n] << endl;
		int q = it.get(1 , 1, 2 * n, i + 1, i + n);
		if (ans1 > q) {
			ans1 = q;
			ans2 = i;
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}