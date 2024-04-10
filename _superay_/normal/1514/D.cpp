#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
inline pair<int, int> Merge(pair<int, int> x, pair<int, int> y) {
	if (!x.second) return y;
	if (!y.second) return x;
	if (x.first == y.first) return make_pair(x.first, x.second + y.second);
	if (x.second < y.second) return make_pair(y.first, y.second - x.second);
	else if (x.second > y.second) return make_pair(x.first, x.second - y.second);
	else return make_pair(0, 0);
}
int n, a[N];
vector<int> buck[N];
pair<int, int> st[N * 4];
void build(int i, int l, int r) {
	if (l == r) {
		st[i] = make_pair(a[l], 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	st[i] = Merge(st[i << 1], st[i << 1 | 1]);
}
pair<int, int> query(int i, int l, int r, int lf, int rg) {
	if (lf <= l && r <= rg) return st[i];
	int mid = (l + r) >> 1;
	pair<int, int> ret(0, 0);
	if (lf <= mid) ret = Merge(ret, query(i << 1, l, mid, lf, rg));
	if (rg > mid) ret = Merge(ret, query(i << 1 | 1, mid + 1, r, lf, rg));
	return ret;
}
int main() {
	int Q;
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		buck[a[i]].push_back(i);
	}
	build(1, 1, n);
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		pair<int, int> cur = query(1, 1, n, l, r);
		int ans = 1;
		if (cur.second) {
			int cnt = upper_bound(buck[cur.first].begin(), buck[cur.first].end(), r) - lower_bound(buck[cur.first].begin(), buck[cur.first].end(), l);
			if (cnt > (r - l + 2) / 2) {
				ans = cnt - ((r - l + 1) - cnt);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}