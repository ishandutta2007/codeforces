#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 100004;
const int64_t INF = 2e14;

const vector<int64_t> bad = {1, 42, 1764, 74088, 3111696, 130691232, 5489031744, 230539333248, 9682651996416};
int64_t calc_wait(int64_t x) { return *lower_bound(bad.begin(), bad.end(), x) - x; }

struct node_t {
	int64_t wait, val, inc;
	bool same;
	node_t(int64_t _val = INF, int64_t _inc = 0, bool _same = true):
	val(_val), inc(_inc), same(_same) {
		wait = calc_wait(val);
	}

	void apply_inc(int64_t x) {
		wait -= x, val += x, inc += x;
		assert(wait >= 0 || same);
		if (wait < 0) wait = calc_wait(val);
	}

	void push(node_t &lhs, node_t &rhs) {
		if (same) {
			lhs = rhs = *this;
		} else {
			if (inc) lhs.apply_inc(inc), rhs.apply_inc(inc);
		}
		inc = 0;
	}

	void pull(node_t &lhs, node_t &rhs) {
		if (lhs.wait < rhs.wait) wait = lhs.wait, val = lhs.val;
		else wait = rhs.wait, val = rhs.val;
		same = lhs.same and rhs.same and lhs.val == rhs.val;
	}
} st[MAXN << 2];

int N, Q, T[MAXN];

void build(int rt = 1, int lo = 1, int hi = N) {
	if (lo == hi) st[rt] = node_t(T[lo], 0, true);
	else {
		int lc = rt << 1, rc = lc | 1, md = (lo + hi) >> 1;
		build(lc, lo, md), build(rc, md + 1, hi);
		st[rt].pull(st[lc], st[rc]);
	}
}

void apply_set(int l, int r, int x, int rt = 1, int lo = 1, int hi = N) {
	if (hi < l || r < lo) return;
	if (l <= lo && hi <= r) return st[rt] = node_t(x, 0, true), void(0);
	int lc = rt << 1, rc = lc | 1, md = (lo + hi) >> 1;
	st[rt].push(st[lc], st[rc]);
	apply_set(l, r, x, lc, lo, md);
	apply_set(l, r, x, rc, md + 1, hi);
	st[rt].pull(st[lc], st[rc]);
}

int64_t apply_inc(int l, int r, int x, int rt = 1, int lo = 1, int hi = N) {
	if (hi < l || r < lo) return INF;
	if (l <= lo && hi <= r && (st[rt].same || st[rt].wait > x)) {
		st[rt].apply_inc(x);
		return st[rt].wait;
	}

	int lc = rt << 1, rc = lc | 1, md = (lo + hi) >> 1;
	st[rt].push(st[lc], st[rc]);
	int64_t lval = apply_inc(l, r, x, lc, lo, md);
	int64_t rval = apply_inc(l, r, x, rc, md + 1, hi);
	st[rt].pull(st[lc], st[rc]);
	return min(lval, rval);
}

int64_t get(int i) {
	int rt = 1, lo = 1, hi = N;
	while (lo < hi) {
		if (st[rt].same) return st[rt].val;
		int lc = rt << 1, rc = lc | 1, md = (lo + hi) >> 1;
		st[rt].push(st[lc], st[rc]);
		if (i <= md) rt = lc, hi = md;
		else rt = rc, lo = md + 1;
	}
	return st[rt].val;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> T[i];
	build();
	while (Q--) {
		int t; cin >> t;
		if (t == 1) {
			int i; cin >> i;
			cout << get(i) << '\n';
		} else if (t == 2) {
			int l, r, x; cin >> l >> r >> x;
			apply_set(l, r, x);
		} else {
			int l, r, x; cin >> l >> r >> x;
			while (apply_inc(l, r, x) == 0);
		}
	}
}