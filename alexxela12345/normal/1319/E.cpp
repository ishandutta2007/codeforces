#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

struct event {
	int type;
	int a, b, c;
	event(int a, int b) : a(a), b(b) {
		type = 1;
	}

	event(int a, int b, int c) : a(a), b(b), c(c) {
		type = 2;
	}
};

bool operator<(const event &a, const event &b) {
	if (a.a != b.a)
		return a.a < b.a;
	return a.type < b.type;
}


vector<pair<int, int>> arrb;
vector<int> tree;
vector<int> mod;

void build(int v, int l, int r) {
	if (l + 1 == r) {
		tree[v] = -arrb[l].second;
	} else {
		int m = l + (r - l) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
	}
}

void push(int v, int l, int r) {
	tree[v] += mod[v];
	if (l + 1 != r) {
		mod[2 * v + 1] += mod[v];
		mod[2 * v + 2] += mod[v];
	}
	mod[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int val) {
	push(v, l, r);
	if (l >= qr || r <= ql) {
		return;
	}
	if (ql <= l && r <= qr) {
		mod[v] += val;
		push(v, l, r);
		return;
	}
	int m = l + (r - l) / 2;
	update(2 * v + 1, l, m, ql, qr, val);
	update(2 * v + 2, m, r, ql, qr, val);
	tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	int n, m, p;
	cin >> n >> m >> p;
	vector<event> evs;
	for (int i = 0; i < n; i++) {
		int a, ca;
		cin >> a >> ca;
		evs.push_back(event(a, ca));
	}
	arrb.resize(m);
	tree.resize(4 * m);
	mod.resize(4 * m);
	for (int i = 0; i < m; i++) {
		cin >> arrb[i].first >> arrb[i].second;
	}
	sort(arrb.begin(), arrb.end());
	build(0, 0, m);
	for (int i = 0; i < p; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		evs.push_back(event(x, y, z));
	}
	sort(evs.begin(), evs.end());
	int max_ans = INT_MIN;
	for (auto &e : evs) {
		if (e.type == 1) {
			max_ans = max(max_ans, -e.b + tree[0]);
		} else {
			int l = -1;
			int r = m;
			while (r - l > 1) {
				int mm = l + (r - l) / 2;
				if (arrb[mm].first <= e.b) {
					l = mm;
				} else {
					r = mm;
				}
			}
			update(0, 0, m, r, m, e.c);
		}
	}
	cout << max_ans << endl;
	return 0;
}