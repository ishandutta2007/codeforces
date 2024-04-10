#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N], b[N], x[2 * N], pos[N], p[N], q[N], it[8 * N], n, k;
char res[N];

void build(int k, int l, int r) {
	if (l == r) {
		it[k] = x[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * k, l, mid);
	build(2 * k + 1, mid + 1, r);
	it[k] = max(it[2 * k], it[2 * k + 1]);
}

int query(int k, int l, int r, int u, int v) {
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) {
		return it[k];
	}
	int mid = (l + r) / 2;
	int q1 = query(2 * k, l, mid, u, v);
	int q2 = query(2 * k + 1, mid + 1, r, u, v);
	return max(q1, q2);
}

int getmax(int k) {
	int q1 = query(1, 1, 2 * n, 1, k);
	int q2 = query(1, 1, 2 * n, n + 1, n + k);
	return max(q1, q2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
		b[i] = pos[q[i]];
	}
	for (int i = 1; i <= n; i++) {
		pos[q[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = pos[p[i]];
	}
	for (int i = 1; i <= n; i++) {
		x[i] = a[i];
		x[i + n] = b[i];
	}
	build(1, 1, 2 * n);
	int pre = 1, id = 0;
	for (int i = 1; i <= n; i++) {
		if (getmax(i) == i) {
			for (int j = pre ; j <= i; j++) {
				res[p[j]] = 'a' + id;
			}
			id++;
			if (id > 26) id = 26;
			pre = i + 1;
		}
	}
	id--;
	if (id < k - 1) {
		cout << "NO";
	} else {
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++) {
			if (res[i] - 'a' >= k) res[i] = 'a' + k - 1;
			cout << res[i];
		}
	}
	return 0;
}