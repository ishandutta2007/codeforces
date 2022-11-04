#include <bits/stdc++.h>
using namespace std;
const int N = 25005;
const int Q = 100005;
const int B = 80;
int n, q, a[N], pos[N], ql[Q], qr[Q], idx[Q], ans[Q], bit[N];
vector<int> vl[N], vr[N], sl[N], sr[N], tl[N], tr[N];
vector<pair<int, int*> > buck[N];
vector<pair<int, int> > buckq[N];
inline void add(int i, int x) {
	while (i <= n) {
		bit[i] = min(bit[i], x);
		i += i & -i;
	}
}
inline int qry(int i) {
	int ret = q + 1;
	while (i > 0) {
		ret = min(ret, bit[i]);
		i -= i & -i;
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &ql[i], &qr[i]);
		idx[i] = i;
		buckq[qr[i]].push_back(make_pair(ql[i], i));
	}
	sort(idx + 1, idx + 1 + q, [](int i, int j) {
		return (ql[i] - 1) / B != (ql[j] - 1) / B ? ql[i] < ql[j] : qr[i] < qr[j];
	});
	set<int> st;
	set<pair<int, int> > cur;
	function<void(int)> Ins = [&](int x) {
		auto it = st.insert(x).first;
		if (it != st.begin()) cur.insert(make_pair(*prev(it), x));
		if (next(it) != st.end()) cur.insert(make_pair(x, *next(it)));
		if (it != st.begin() && next(it) != st.end()) cur.erase(make_pair(*prev(it), *next(it)));
	};
	function<void(int)> Del = [&](int x) {
		auto it = st.find(x);
		if (it != st.begin()) cur.erase(make_pair(*prev(it), x));
		if (next(it) != st.end()) cur.erase(make_pair(x, *next(it)));
		if (it != st.begin() && next(it) != st.end()) cur.insert(make_pair(*prev(it), *next(it)));
		st.erase(it);
	};
	for (int _ = 1, curl = 1, curr = 0; _ <= q; _++) {
		int i = idx[_];
		while (curr < qr[i]) Ins(a[++curr]);
		while (curl > ql[i]) Ins(a[--curl]);
		while (curr > qr[i]) Del(a[curr--]);
		while (curl < ql[i]) Del(a[curl++]);
		for (auto &P : cur) {
			int i = pos[P.first], j = pos[P.second];
			if (i < j) vr[i].push_back(j);
			else vl[i].push_back(j);
		}
		cur.clear();
	}
	vector<pair<int, int> > ev;
	for (int i = 1; i <= n; i++) {
		sort(vl[i].begin(), vl[i].end());
		vl[i].resize(unique(vl[i].begin(), vl[i].end()) - vl[i].begin());
		reverse(vl[i].begin(), vl[i].end());
		sort(vr[i].begin(), vr[i].end());
		vr[i].resize(unique(vr[i].begin(), vr[i].end()) - vr[i].begin());
		sl[i].resize(vl[i].size());
		tl[i].resize(vl[i].size());
		sr[i].resize(vr[i].size());
		tr[i].resize(vr[i].size());
		for (int j = 0, k = 0; j < (int)vl[i].size(); j++) {
			buck[i].push_back(make_pair(vl[i][j], &sl[i][j]));
			while (k < (int)vr[i].size() && a[vl[i][j]] < a[vr[i][k]]) k++;
			if (k < (int)vr[i].size()) {
				buck[vr[i][k]].push_back(make_pair(vl[i][j], &tl[i][j]));
			} else {
				tl[i][j] = q + 1;
			}
		}
		for (int j = 0, k = 0; j < (int)vr[i].size(); j++) {
			buck[vr[i][j]].push_back(make_pair(i, &sr[i][j]));
			while (k < (int)vl[i].size() && a[vr[i][j]] < a[vl[i][k]]) k++;
			if (k < (int)vl[i].size()) {
				buck[vr[i][j]].push_back(make_pair(vl[i][k], &tr[i][j]));
			} else {
				tr[i][j] = q + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) bit[i] = q + 1;
	for (int i = n; i >= 1; i--) {
		for (auto &P : buckq[i]) {
			add(P.first, P.second);
		}
		for (auto &P : buck[i]) {
			*P.second = qry(P.first);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)vl[i].size(); j++) {
			int L = sl[i][j], R = min(j < (int)vl[i].size() - 1 ? sl[i][j + 1] : q + 1, tl[i][j]);
			if (L < R) ans[L]++, ans[R]--;
		}
		for (int j = 0; j < (int)vr[i].size(); j++) {
			int L = sr[i][j], R = min(j < (int)vr[i].size() - 1 ? sr[i][j + 1] : q + 1, tr[i][j]);
			if (L < R) ans[L]++, ans[R]--;
		}
	}
	for (int i = 1; i <= q; i++) ans[i] += ans[i - 1];
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}