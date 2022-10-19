#include<bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, u[N], cnt[N];

struct Get {
	int mx, mn, cnt;
} it[4 * N];

void update (int k, int l, int r, int id) {
	if (l > id || r < id) return;
	if (l == id && r == id) {
		it[k].mx = cnt[id];
		it[k].mn = cnt[id];
		if (cnt[id] > 0) it[k].cnt = 1;
		else it[k].cnt = 0;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * k, l, mid, id);
	update(2 * k + 1, mid + 1, r, id);
	it[k].mx = max(it[2 * k].mx, it[2 * k + 1].mx);
	if (it[2 * k].mn > 0 && it[2 * k + 1].mn > 0) {
		it[k].mn = min(it[2 * k].mn, it[2 * k + 1].mn);
	} else {
		it[k].mn = max(it[2 * k].mn, it[2 * k + 1].mn);
	}
	it[k].cnt = it[2 * k].cnt + it[2 * k + 1].cnt;
	return;
}

Get get(int k, int l, int r, int u, int v) {
	Get res;
	if (l > v || r < u) {
		res.mx = 0; res.mn = 0; res.cnt = 0;
		return res;
	}
	if (l >= u && r <= v) {
		return it[k];
	}
	int mid = (l + r) / 2;
	Get g1 = get(2 * k, l, mid, u, v);
	Get g2 = get(2 * k + 1, mid + 1, r, u, v);
	res.mx = max(g1.mx, g2.mx);
	if (g1.mn > 0 && g2.mn > 0) {
		res.mn = min(g1.mn, g2.mn);
	} else {
		res.mn = max(g1.mx, g2.mx);
	}
	res.cnt = g1.cnt + g2.cnt;
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> u[i];
		cnt[u[i]]++;
	}
	for (int i = 1; i <= 100000; i++) {
		update(1, 1, 100000, i);
	}
	for (int i = n; i >= 1; i--) {
		Get g = get(1, 1, 100000, 1, 100000);
		if (g.cnt == 1) return cout << i, 0;
		if (g.mx - g.mn == 1) {
			if (g.mn * g.cnt + 1 == i) {
				return cout << i, 0;
			} 
		}
		if (g.mn == 1 && (g.mx * (g.cnt - 1) + 1) == i) {
				return cout << i, 0;
		}
		cnt[u[i]]--;
		update(1, 1, 100000, u[i]);
	}

	return 0;
}