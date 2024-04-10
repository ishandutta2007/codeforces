#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define all(a) (a).begin(), (a).end()

using namespace std;

struct SegTree {
	int n;
	vector<int> t;
	function<int(int, int)> op;

	SegTree(int n, function<int(int, int)> op) : n(n), op(op), t(2 * n, 0) {}

	void upd(int v, int x) {
		t[v += n] = x;
		for (v >>= 1; v; v >>= 1) {
			t[v] = op(t[v << 1], t[v << 1 | 1]);
		}
	}

	int get(int l, int r) const {
		int ret = 0;
		for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if (l & 1) {
				ret = op(ret, t[l]);
			}
			if (!(r & 1)) {
				ret = op(ret, t[r]);
			}
		}
		return ret;
	}

	int get(int l, const vector<int>& nxt) const {
		int pos = lower_bound(all(nxt), l) - nxt.begin();
		return (pos > 0 ? get(0, pos - 1) : 0);
	}
};

int get(int l, int r, const vector<SegTree>& t, const vector<vector<int>>& nxt) {
	int n = t.size() / 2;
	int ret = 0;
	int lft = l;
	for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
		if (l & 1) {
			ret += t[l].get(lft, nxt[l]);
		}
		if (!(r & 1)) {
			ret += t[r].get(lft, nxt[r]);
		}
	}
	return ret;
}

void upd(int v, int val, vector<SegTree>& t, const vector<vector<int>>& nxt) {
	v += t.size() / 2;
	while (v > 0) {
		int pos = lower_bound(all(nxt[v]), val) - nxt[v].begin();
		t[v].upd(pos, 1);
		v >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> ci(n + 2);
	bool any = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ci[--a[i]].push_back(i);
		any |= (a[i] > 0);
	}
	if (!any) {
		cout << 1 << '\n';
		return 0;
	}
	vector<vector<int>> nxt(2 * n);
	for (int c = 0; c < n; c++) {
		const auto& vec = ci[c];
		if (vec.empty()) {
			continue;
		}
		nxt[n + vec[0]] = { -(c + 1) };
		for (int i = 1; i < vec.size(); i++) {
			nxt[n + vec[i]] = { vec[i - 1] };
		}
	}
	for (int i = n - 1; i > 0; i--) {
		merge(all(nxt[i << 1]), all(nxt[i << 1 | 1]), back_inserter(nxt[i]));
	}
	vector<SegTree> t;
	for (int i = 0; i < 2 * n; i++) {
		t.emplace_back(SegTree(nxt[i].size(), [](int a, int b) { return a + b; }));
	}
	int mex = 0;
	while (true) {
		if (mex > 0) {
			int lst = -1;
			ci[mex].push_back(n);
			bool succ = false;
			for (int r : ci[mex]) {
				succ |= (r - lst > mex && get(lst + 1, r - 1, t, nxt) == mex);
				lst = r;
			}
			if (!succ) {
				cout << mex + 1 << '\n';
				return 0;
			}
			ci[mex].pop_back();
		}
		for (int i = 0; i < ci[mex].size(); i++) {
			upd(ci[mex][i], (i ? ci[mex][i - 1] : -(mex + 1)), t, nxt);
		}
		mex++;
	}
}