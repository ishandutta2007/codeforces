#include<bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

ii cnt[200005];
int a[200005], b[100005], it[4 * 200005];

void update(int k, int l, int r, int id, int val) {
	if (l > id || r < id) {
		return;
	}
	if (l == id && r == id) {
		it[k] = l;
		return;
	}

	int mid = (l + r) / 2;
	update(2 * k, l, mid, id, val);
	update(2 * k + 1, mid + 1, r, id, val);
	if (b[it[2 * k]] > b[it[2 * k + 1]]) {
		it[k] = it[2 * k];
	} else {
		it[k] = it[2 * k + 1];
	}
}

int que(int k, int l, int r, int u, int v) {
	if (l > v || r < u) {
		return 0;
	}
	if (l >= u && r <= v) {
		return it[k];
	}

	int mid = (l + r) / 2;
	int q1 = que(2 * k, l, mid, u, v);
	int q2 = que(2 * k + 1, mid + 1, r, u, v);
	if (b[q1] > b[q2]) return q1;
	return q2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cnt[i] = make_pair(0, 0);
		}
		for (int i = 1; i <= n; i++) {
			int u, v;
			cin >> u >> v;
			cnt[u].first++;
			cnt[u].second += v;
		}
		sort(cnt + 1, cnt + 1 + n);
		for (int i = 1; i <= n; i++) {
			a[i] = cnt[i].first;
			b[i] = cnt[i].second;
		}
		for (int i = 1; i <= n; i++) {
			update(1, 1, n, i, b[i]);
		}
		b[0] = -1;
		int res1 = 0, res2 = 0;
		for (int i = n; i >= 1; i--) {
			int k = lower_bound(a + 1, a + 1 + n, i) - a;
			if (k > n) continue;
			int res = que(1, 1, n, k, n);
			if (b[res] < 0) continue;
			res1 += i;
			res2 += min(b[res], i);
			b[res] = -1;
			update(1, 1, n, res, -1);
		}
		cout << res1 << ' ' << res2 << endl;
	}
	return 0;
}