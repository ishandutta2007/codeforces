#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

struct LazyST {
	struct Val { // define
		long long v = 0;
		Val() {}
		Val(const long long v) : v(v) {}
		Val(const Val &v1, const Val &v2) {
			v = v1 + v2;
		}
		operator long long() const {
			return v;
		}
	};

	struct Lz { // define
		long long v = 0;
		Lz() {}
		Lz(const long long v) : v(v) {}
		operator long long() {
			return v;
		}
	};

	int n;
	int stOffset;
	int stHi;
	vector<Val> st;
	vector<Lz> lazy;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		lazy.resize(st.size());
		stHi = st.size() - 1 - stOffset;
	}

	void build() { // O(n)
		for (int i = 0; i < n; ++i)
			cin >> st[i + stOffset].v;
		for (int si = stOffset - 1; si; --si)
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}

	void updateLazy(const int si, const int lo, const int hi) { // define
		st[si].v += (hi - lo + 1) * lazy[si];
		if (lo != hi) {
			lazy[si << 1].v += lazy[si];
			lazy[si << 1 | 1].v += lazy[si];
		}
		lazy[si] = 0;
	}

	void addLazy(const Val &v, const int si, const int lo, const int hi) { // define
		st[si].v += v * (hi - lo + 1);
		if (lo != hi) {
			lazy[si << 1].v += v;
			lazy[si << 1 | 1].v += v;
		}
	}

	Val query(const int i, const int j, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (i <= lo && hi <= j)
			return st[si];
		int mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return Val(query(i, j, si << 1, lo, mid),
			query(i, j, si << 1 | 1, mid + 1, hi));
	}

	Val query(const int i, const int j) {
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : Val();
	}

	void update(const int i, const int j, const Val &v, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (hi < i || j < lo)
			return;
		if (i <= lo && hi <= j)
			return addLazy(v, si, lo, hi);
		int mid = (lo + hi) >> 1;
		update(i, j, v, si << 1, lo, mid);
		update(i, j, v, si << 1 | 1, mid + 1, hi);
		st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}

	void update(const int i, const int j, const Val v) {
		if (i <= j)
			update(i, j, v, 1, 0, stHi);
	}

	// remove all non-zero values in a range
	void remAll(const int i, const int j, const int si, const int lo, const int hi, vector<int> &res) {
		updateLazy(si, lo, hi);
		if (!st[si] || hi < i || j < lo)
			return;
		if (lo == hi) {
			res.push_back(si - stOffset);
			st[si] = 0;
		}
		else {
			int mid = (lo + hi) >> 1;
			remAll(i, j, si << 1, lo, mid, res);
			remAll(i, j, si << 1 | 1, mid + 1, hi, res);
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
		}
	}

	vector<int> remAll(const int i, const int j) { // ^^
		vector<int> res;
		remAll(i, j, 1, 0, stHi, res);
		return res;
	}

	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			int mid = (lo + hi) >> 1;
			updateAllLazy(si >> 1, lo, mid);
			updateAllLazy(si >> 1 | 1, mid + 1, hi);
		}
	}

	void updateAllLazy() {
		updateAllLazy(1, 0, stHi);
	}

	const Val * const retreive() {
		updateAllLazy();
		return &st[stOffset];
	}

	vector<Val> retreiveVector() {
		updateAllLazy();
		return vector<Val>(&st[stOffset], &st[stOffset + n]);
	}

	void output() {
		updateAllLazy();
		for (int i = 0; i < n; ++i) {
			if (i)
				cout << ' ';
			cout << st[stOffset + i].v;
		}
		cout << '\n';
	}
};

int n;
const int NodeLimit = (int)2e5 + 1;
vector<pair<int, int>> adj[NodeLimit];
int ans[NodeLimit] = { 0 };
long long dist[NodeLimit] = { 0 };
int a[NodeLimit];

void dfs(const int u, vector<long long> &d, vector<int> &cs) {
	auto it = lower_bound(d.begin(), d.end(), dist[u] - a[u]);
	if (it != d.end()) {
		++cs.back();
		if(it != d.begin())
			--cs[it - d.begin() - 1];
	}
	d.push_back(dist[u]);
	cs.push_back(0);

	for (auto &&e : adj[u]) {
		dist[e.first] = dist[u] + e.second;
		dfs(e.first, d, cs);
	}
	
	d.pop_back();
	ans[u] = cs.back();
	cs.pop_back();
	if (!cs.empty())
		cs.back() += ans[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 2; i <= n; ++i) {
		int p, w;
		cin >> p >> w;
		adj[p].push_back({ i, w });
	}

	vector<long long> d;
	vector<int> cs;
	dfs(1, d, cs);
	for (int i = 1; i <= n; ++i) {
		if (i > 1)
			cout << ' ';
		cout << ans[i];
	}
	return 0;
}