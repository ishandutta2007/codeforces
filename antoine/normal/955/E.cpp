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
typedef int ll;


template<class T> struct LazyST {
	int n;
	int stOffset;
	int stHi;
	vector<T> st;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		stHi = st.size() - 1 - stOffset;
	}

	LazyST(const int n, istream &in) : LazyST(n) { // O(n)
		for (int i = 0; i < n; ++i)
			in >> st[i + stOffset];
		for (int si = stOffset - 1; si; --si)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}

	T query(const int i, const int j, const int si, const int lo, const int hi) {
		if (i <= lo && hi <= j)
			return st[si];
		auto mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return T(query(i, j, si << 1, lo, mid), query(i, j, si << 1 | 1, mid + 1, hi));
	}

	T query(const int i, const int j) {
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : T();
	}

	void set(const int i, const int v) {
		st[stOffset + i] = v;
	}

	void build() {
		for (int si = stOffset - 1; si; --si)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal { // define
	int v = 0;
	StVal() {}
	StVal(const int v) : v(v) {}
	StVal(const StVal &v1, const StVal &v2) {
		v = min(v1, v2);
	}
	operator int() const {
		return v;
	}
};

struct DS {
	int offset = 0; // stored value = actual - offset
	set<pair<int, int>> positives;
	set<pair<int, int>> nonpos;
	set<pair<int, int>> values;

	void insert(int i, int v) {
		if (v > 0)
			positives.emplace(i, v - offset);
		else
			nonpos.emplace(i, v - offset);
		values.emplace(v - offset, i);
	}

	void incAll() {
		for (auto it = values.lower_bound({ -offset, -1e8 }); it!= values.end() && it->first == -offset; ++it) {
			nonpos.erase({ it->second, it->first });
			positives.insert({ it->second, it->first });
		}
		++offset;
	}

	void decAll() {
		for (auto it = values.lower_bound({ -offset + 1, -1e8 }); it != values.end() && it->first == -offset + 1; ++it) {
			positives.erase({ it->second, it->first });
			nonpos.insert({ it->second, it->first });
		}
		--offset;
	}

	pair<int, int> pollMinIdx() {
		pair<int, int> res;
		if (positives.empty() || (!nonpos.empty() && nonpos.begin()->first < positives.begin()->first)) {
			res = *nonpos.begin();
			nonpos.erase(nonpos.begin());
		}
		else {
			res = *positives.begin();
			positives.erase(positives.begin());
		}
		values.erase({ res.second, res.first });
		res.second += offset;
		return res;
	}

	pair<int, int> query() {
		if (nonpos.empty())
			return{ -1, -1 };
		return{ nonpos.begin()->first, nonpos.begin()->second + offset };
	}
};

pair<int, int> query(DS &dsL, DS &dsR) {
	auto res1 = dsL.query();
	if (res1.first != -1)
		return res1;
	return dsR.query();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	DS dsL, dsR;
	for (int i = 0; i < n;  ++i) {
		dsR.insert(i, a[i]);
	}

	vector<int> firstTrap(n, -1);

	bool hasSol = false;
	for (int i = 0; i < n; ++i) {
		int j = query(dsL, dsR).first;
		if (j != -1) {
			hasSol = true;
			firstTrap[i] = j;
		}
		if (i != n - 1) { // update dsL, dsR
			auto p = dsR.pollMinIdx();
			dsL.insert(p.first, p.second);
			dsL.incAll();
			dsR.decAll();
		}
	}
	if (!hasSol) {
		cout << -1;
		return 0;
	}
	
	LazyST<StVal> stL(n), stR(n);
	for (int i = 0; i < n; ++i) {
		stL.set(i, a[i] + n - i);
		stR.set(i, a[i] + i);
	}
	stL.build();
	stR.build();

	
	int ans = 1e8;
	for (int i = 1; i < n; ++i) {
		if (firstTrap[i] != -1) {
			const int j = firstTrap[i] - 1;
			int leftTrappedTime;
			if (i >= j)
				leftTrappedTime = stL.query(0, j) - (n - j) + (i - j);
			else
				leftTrappedTime = min(stL.query(0, i) - (n - i), stR.query(i, j) - i);

			int rightTrappedTime;
			if (i <= j + 1)
				rightTrappedTime = stR.query(j + 1, n - 1) - (j + 1) + ((j + 1) - i);
			else
				rightTrappedTime = min(stL.query(j + 1, i) - (n - i), stR.query(i, n - 1) - i);
			
			ans = min(ans, max(rightTrappedTime, leftTrappedTime));
		}
	}
	cout << ans;
	return 0;
}