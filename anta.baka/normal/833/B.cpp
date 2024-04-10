#include <bits/stdc++.h>

using namespace std;

struct RMQ {
	struct node {
		int add, max;
	};
	node merge(node a, node b) {
		node c;
		c.add = 0;
		c.max = max(a.max, b.max);
		return c;
	}
	int n;
	vector<node> t;
	RMQ(int _n) {
		n = _n;
		t.resize(4 * n);
		build(0, 0, n - 1);
	}
	void build(int v, int l, int r) {
		if(l == r) {
			t[v].add = t[v].max = 0;
		} else {
			int m = (l + r) / 2;
			build(v * 2 + 1, l, m);
			build(v * 2 + 2, m + 1, r);
			t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
		}
	}
	void push(int v) {
		int x = t[v].add;
		if(!x)
			return;
		t[v].add = 0;
		t[v * 2 + 1].add += x;
		t[v * 2 + 1].max += x;
		t[v * 2 + 2].add += x;
		t[v * 2 + 2].max += x;
	}
	void upd(int v, int l, int r, int l1, int r1, int x) {
		if(r < l1 || r1 < l)
			return;
		if(l1 <= l && r <= r1) {
			t[v].add += x;
			t[v].max += x;
			return;
		}
		push(v);
		int m = (l + r) / 2;
		upd(v * 2 + 1, l, m, l1, r1, x);
		upd(v * 2 + 2, m + 1, r, l1, r1, x);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
	int get(int v, int l, int r, int l1, int r1) {
		if(r < l1 || r1 < l)
			return 0;
		if(l1 <= l && r <= r1)
			return t[v].max;
		push(v);
		int m = (l + r) / 2;
		return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m + 1, r, l1, r1));
	}
};

int n, k, a[35000], dp[35000][50], p;
vector<int> last(35000, -1);
vector<RMQ> t;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i], --a[i];
	for(int i = 0; i < k; i++)
		t.emplace_back(RMQ(n));
	// TODO
	for(int i = 0; i < n; i++) {
		if(last[a[i]] != -1) {
			--p;
			for(int j = 0; j < min(k, i); j++)
				t[j].upd(0, 0, n - 1, last[a[i]], i - 1, 1);
		}
		last[a[i]] = i;
		++p;
		for(int j = 0; j < min(k, i + 1); j++)
			dp[i][j] = p + (j ? t[j - 1].get(0, 0, n - 1, 0, i - 1) : 0);
		for(int j = 0; j < min(k, i + 1); j++)
			t[j].upd(0, 0, n - 1, i, i, dp[i][j] - p);
	}
	// TODO
	cout << dp[n - 1][k - 1];
}