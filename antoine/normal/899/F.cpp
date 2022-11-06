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
#include <memory>

using namespace std;

struct LazyST {
	struct Val {
		int v = 0;
		Val() { }
		Val(const Val &v1, const Val &v2) {
			v = v1.v + v2.v;
		}
	};

	struct Lz {
		bool allZero = false;
	};


	int n;
	int stOffset;
	int stHi;
	vector<Val> st;
	vector<Lz> lazy;

	LazyST() {
		cout << "empty consttr\n";
	}

	LazyST(const LazyST &) = delete;
	
	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		lazy.resize(st.size());
		stHi = st.size() - 1 - stOffset;
	}

	void build() { // O(n)
		for (int i = 1; i < n; ++i)
			st[i + stOffset].v = 1;
		for (int si = stOffset - 1; si; --si)
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}

	void build(string &s, char c) { // O(n)
		for (int i = 1; i < n; ++i)
			st[i + stOffset].v = s[i - 1] == c;
		for (int si = stOffset - 1; si; --si)
			st[si] = Val(st[si << 1], st[si << 1 | 1]);
	}


	void updateLazy(const int si) {
		if (!lazy[si].allZero)
			return;
		st[si].v = 0;
		if (si < stOffset) {
			lazy[si << 1].allZero = 1;
			lazy[si << 1 | 1].allZero = 1;
		}
		lazy[si].allZero = 0;
	}

	void addLazy(const int si, const Val &v) {
		st[si].v = 0;
		if (si < stOffset) {
			lazy[si << 1].allZero = 1;
			lazy[si << 1 | 1].allZero = 1;
		}
	}

	Val query(const int i, const int j, const int si, const int lo, const int hi) {
		updateLazy(si);
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
		updateLazy(si);
		if (hi < i || j < lo)
			return;
		if (i <= lo && hi <= j)
			return addLazy(si, v);
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
		updateLazy(si);
		if (!st[si].v || hi < i || j < lo)
			return;
		if (si >= stOffset) {
			res.push_back(si - stOffset);
			st[si].v = 0;
		} else {
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

	void updateAllLazy() {
		for (int i = 1; i < st.size(); ++i)
			updateLazy(i);
	}
};

int updateIdx(const int i, LazyST &st) {
	int lo = 1;
	int hi = st.n - 1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (st.query(1, mid).v >= i)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	map<char, LazyST> charST;
	for (auto &&c : s)
		if (!charST.count(c)) {
			charST.emplace(c, n + 1);
			charST[c].build(s, c);
		}
	LazyST mainST(n + 1);
	mainST.build();
	while (m-- > 0) {
		int l, r;
		char c;
		cin >> l >> r >> c;
		if (!charST.count(c))
			continue;
		l = updateIdx(l, mainST);
		r = updateIdx(r, mainST);

		for (auto &&x : charST[c].remAll(l, r))
			mainST.update(x, x, {});
	}
	mainST.updateAllLazy();
	for (int i = 1; i <= n; ++i)
		if (mainST.st[mainST.stOffset + i].v)
			cout << s[i - 1];
	return 0;
}