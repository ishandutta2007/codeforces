// is this also wrong... (;)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 500007;
int N, Q, A[MAXN];
map<int, int> AT;

struct SegmentTree {
	struct Node {
		int val, inc, cnt;
		Node() {}
	} T[MAXN << 2];

	void build(int rt, int lo, int hi) {
		T[rt].val = 0, T[rt].inc = 0, T[rt].cnt = hi - lo + 1;
		if (lo < hi) {
			int lc = rt << 1, rc = rt << 1 | 1, md = (lo + hi) >> 1;
			build(lc, lo, md), build(rc, md + 1, hi);
		}
	}
	void build() { build(1, 1, N - 1); }

	void modify(int rt, int lo, int hi, int l, int r, int d) {
		if (r < lo || hi < l) return;
		if (l <= lo && hi <= r) return T[rt].val += d, T[rt].inc += d, void();
		int lc = rt << 1, rc = rt << 1 | 1, md = (lo + hi) >> 1;
		modify(lc, lo, md, l, r, d);
		modify(rc, md + 1, hi, l, r, d);

		T[rt].cnt = (T[lc].val <= T[rc].val) * T[lc].cnt + (T[rc].val <= T[lc].val) * T[rc].cnt;
		T[rt].val = min(T[lc].val, T[rc].val) + T[rt].inc;
	}
	void modify(int l, int r, int d) { 
		if (l <= r) modify(1, 1, N - 1, l, r, d); 
	}
} st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		AT[A[i]] = i;
	}
	st.build();

	for (auto i = AT.begin(); next(i) != AT.end(); ++i) {
		st.modify(i->second, next(i)->second - 1, 1);
	}

	while (Q--) {
		int i, x;
		cin >> i >> x;

		auto j = AT.find(A[i]);
		if (j != AT.begin()) st.modify(prev(j)->second, j->second - 1, -1);
		if (next(j) != AT.end()) st.modify(j->second, next(j)->second - 1, -1);
		if (j != AT.begin() && next(j) != AT.end()) st.modify(prev(j)->second, next(j)->second - 1, 1);
		AT.erase(j);

		j = AT.insert(make_pair(A[i] = x, i)).first;
		if (j != AT.begin()) st.modify(prev(j)->second, j->second - 1, 1);
		if (next(j) != AT.end()) st.modify(j->second, next(j)->second - 1, 1);
		if (j != AT.begin() && next(j) != AT.end()) st.modify(prev(j)->second, next(j)->second - 1, -1);

		cout << 1 + st.T[1].cnt * !st.T[1].val << '\n';
	}
}