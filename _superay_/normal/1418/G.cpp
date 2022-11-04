#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
pair<int, int> st[N * 4];
int tag[N * 4];
void build(int i, int l, int r) {
	st[i] = make_pair(0, r - l + 1), tag[i] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
}
inline void pushdown(int i) {
	st[i << 1].first += tag[i];
	tag[i << 1] += tag[i];
	st[i << 1 | 1].first += tag[i];
	tag[i << 1 | 1] += tag[i];
	tag[i] = 0;
}
inline void pushup(int i) {
	if (st[i << 1].first != st[i << 1 | 1].first) st[i] = max(st[i << 1], st[i << 1 | 1]);
	else st[i] = make_pair(st[i << 1].first, st[i << 1].second + st[i << 1 | 1].second);
}
void modify(int i, int l, int r, int lf, int rg, int v) {
	if (lf <= l && r <= rg) {
		st[i].first += v;
		tag[i] += v;
		return;
	}
	if (tag[i]) pushdown(i);
	int mid = (l + r) >> 1;
	if (lf <= mid) modify(i << 1, l, mid, lf, rg, v);
	if (rg > mid) modify(i << 1 | 1, mid + 1, r, lf, rg, v);
	pushup(i);
}
pair<int, int> query(int i, int l, int r, int lf, int rg) {
	if (lf <= l && r <= rg) return st[i];
	if (tag[i]) pushdown(i);
	int mid = (l + r) >> 1;
	if (rg <= mid) return query(i << 1, l, mid, lf, rg);
	else if (lf > mid) return query(i << 1 | 1, mid + 1, r, lf, rg);
	pair<int, int> p1 = query(i << 1, l, mid, lf, rg), p2 = query(i << 1 | 1, mid + 1, r, lf, rg);
	if (p1.first != p2.first) return max(p1, p2);
	else return make_pair(p1.first, p1.second + p2.second);
}
int n, a[N];
vector<int> buck[N];
struct Event {
	int l, r, v;
};
vector<Event> vec[N];
inline void Add1(int l, int r) {
	vec[l].push_back((Event){l, r, 1});
	vec[r + 1].push_back((Event){l, r, -1});
}
inline void Add2(int tl, int tr, int l, int r) {
	vec[tl].push_back((Event){l, r, 1});
	vec[tr + 1].push_back((Event){l, r, -1});
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		buck[a[i]].push_back(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (buck[i].size()) {
		cnt++;
		if (buck[i][0] > 1) {
			Add1(1, buck[i][0] - 1);
		}
		for (int j = 0; j < (int)buck[i].size() - 1; j++) {
			if (buck[i][j] + 1 <= buck[i][j + 1] - 1) {
				Add1(buck[i][j] + 1, buck[i][j + 1] - 1);
			}
		}
		if (buck[i].back() < n) {
			Add1(buck[i].back() + 1, n);
		}
		for (int j = 0; j < (int)buck[i].size() - 2; j++) {
			int lb = (j ? buck[i][j - 1] + 1 : 1);
			int rb = (j + 3 < (int)buck[i].size() ? buck[i][j + 3] - 1 : n);
			Add2(buck[i][j + 2], rb, lb, buck[i][j]);
		}
	}
	build(1, 1, n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (Event ev : vec[i]) {
			modify(1, 1, n, ev.l, ev.r, ev.v);
		}
		auto p = query(1, 1, n, 1, i);
		if (p.first == cnt) ans += p.second;
	}
	printf("%lld\n", ans);
	return 0;
}