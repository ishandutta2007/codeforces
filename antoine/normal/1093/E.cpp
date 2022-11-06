#include <bits/stdc++.h>

using namespace std;
typedef int ll;

vector<int> getPerm(const int n) {
	vector<int> res(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> res[i];
	return res;
}

vector<int> invPerm(vector<int> v) {
	vector<int> res(v.size());
	for (int i = 1; i < (int) v.size(); ++i)
		res[v[i]] = i;
	return res;
}

vector<int> applyPerm(vector<int> perm, vector<int> arr) {
	for (int i = 1; i < (int) perm.size(); ++i)
		arr[i] = perm[arr[i]];
	return arr;
}

struct FT {
	int n;
	vector<int> vals;
	FT(int n) :
			n(n), vals(vector<int>(n + 1, 0)) {
	}

	void update(int i, const int a) {
		for (++i; i <= n; i += i & -i)
			vals[i] += a;
	}
	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += vals[i];
		return sum;
	}
	int query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};

struct FT2 {
	FT ft = FT(0);
	vector<int> keys;

	void preKey(const int key) {
		keys.emplace_back(key);
	}

	void process() {
		sort(keys.begin(), keys.end());
		keys.erase(unique(keys.begin(), keys.end()), keys.end());
		ft = FT(keys.size());
	}

	void update(const int key, const int val) {
		auto it = lower_bound(keys.begin(), keys.end(), key);
		assert(it != keys.end() && *it == key);
		ft.update(it - keys.begin(), val);
	}

	int query(const int key) {
		auto it = upper_bound(keys.begin(), keys.end(), key);
		return it == keys.begin() ? 0 : ft.query(prev(it) - keys.begin());
	}

	int query(const int keyL, const int keyR) {
		return query(keyR) - query(keyL - 1);
	}
};

struct FT1 {
	int n;
	vector<FT2> ft2s;

	FT1(const int n) :
			n(n), ft2s(vector<FT2>(n + 1)) {
	}

	void preKey(int x, const int y) {
		for (++x; x <= n; x += x & -x)
			ft2s[x].preKey(y);
	}

	void process() {
		for (FT2 &ft2 : ft2s)
			ft2.process();
	}

	void update(int x, const int y, const int val) {
		for (++x; x <= n; x += x & -x)
			ft2s[x].update(y, val);
	}

	int query(int x, const int yl, const int yr) {
		assert(x >= -1 && x < n);

		int sum = 0;
		for (++x; x; x -= x & -x)
			sum += ft2s[x].query(yl, yr);
		return sum;
	}
	int query(const int xl, const int xr, const int yl, const int yr) {
		return query(xr, yl, yr) - query(xl - 1, yl, yr);
	}
};

struct Query {
	int type, l1, r1, l2, r2;
};

int n;

void pre(vector<int> perm, const vector<Query> &queries, FT1 &ft1) {
	for (int i = 1; i <= n; ++i)
		ft1.preKey(i, perm[i]);

	for(const Query &q : queries)
		if(q.type == 2) {
			swap(perm[q.l2], perm[q.r2]);
			ft1.preKey(q.l2, perm[q.l2]);
			ft1.preKey(q.r2, perm[q.r2]);
		}
}

void solve(vector<int> &perm, const vector<Query> &queries, FT1 &ft1) {

	for (int i = 1; i <= n; ++i)
		ft1.update(i, perm[i], +1);


	for(const Query &q : queries)
		if(q.type == 1)
			cout << ft1.query(q.l2, q.r2, q.l1, q.r1) << '\n';
		else {
			assert(q.type == 2);
			ft1.update(q.l2, perm[q.l2], -1);
			ft1.update(q.r2, perm[q.r2], -1);
			swap(perm[q.l2], perm[q.r2]);
			ft1.update(q.l2, perm[q.l2], +1);
			ft1.update(q.r2, perm[q.r2], +1);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Q;
	cin >> n >> Q;

	vector<int> perm = []() {
		vector<int> a = getPerm(n);
		vector<int> b = getPerm(n);
		return applyPerm(invPerm(a), b);
	}();

	vector<Query> queries(Q);
	for (Query &q : queries) {
		cin >> q.type;
		if (q.type == 1)
			cin >> q.l1 >> q.r1 >> q.l2 >> q.r2;
		else {
			assert(q.type == 2);
			cin >> q.l2 >> q.r2;
		}
	}

	FT1 ft1(n + 1);

	pre(perm, queries, ft1);
	ft1.process();
	solve(perm, queries, ft1);
	return 0;
}