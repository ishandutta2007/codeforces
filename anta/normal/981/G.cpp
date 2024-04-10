#include "bits/stdc++.h"
using namespace std;


template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) { }
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<998244353> mint;

using Val = mint;
struct Sum {
	mint sum;
	Sum() : sum() {}
	Sum(const Val &val, int pos) : sum(val) { }
	Sum &operator+=(const Sum &that) { sum += that.sum; return *this; }
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
struct Add {
	mint a, b;
	Add() : a(1), b() { }
	Add &operator+=(const Add &that) {
		b = b * that.a + that.b;
		a = a * that.a;
		return *this;
	}
	void addToVal(Val &val, int pos) const { val = a * val + b; }
	void addToSum(Sum &sum, int left, int right) const {
		sum.sum = a * sum.sum + b * (right - left);
	}
};

struct SegmentTree {
	vector<Val> leafs;
	vector<Sum> nodes;
	vector<Add> add;
	vector<int> leftpos, rightpos;
	int n, n2;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while (n < (int)u.size()) n *= 2;
		n2 = (n - 1) / 2 + 1;
		leafs = u; leafs.resize(n, Val());
		nodes.resize(n);
		for (int i = n - 1; i >= n2; -- i)
			nodes[i] = Sum(leafs[i * 2 - n], i * 2 - n) + Sum(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		for (int i = n2 - 1; i > 0; -- i)
			nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
		add.assign(n, Add());

		leftpos.resize(n); rightpos.resize(n);
		for (int i = n - 1; i >= n2; -- i) {
			leftpos[i] = i * 2 - n;
			rightpos[i] = (i * 2 + 1 - n) + 1;
		}
		for (int i = n2 - 1; i > 0; -- i) {
			leftpos[i] = leftpos[i * 2];
			rightpos[i] = rightpos[i * 2 + 1];
		}
	}
	Val get(int i) {
		int indices[128];
		int k = getIndices(indices, i, i + 1);
		propagateRange(indices, k);
		return leafs[i];
	}
	Sum getRangeCommutative(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for (int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += sum(l ++);
			if (r & 1) res += sum(-- r);
		}
		return res;
	}
	Sum getRange(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for (; i && i + (i&-i) <= j; i += i & -i)
			res += sum((n + i) / (i&-i));
		for (k = 0; i < j; j -= j & -j)
			indices[k ++] = (n + j) / (j&-j) - 1;
		while (-- k >= 0) res += sum(indices[k]);
		return res;
	}
	void set(int i, const Val &x) {
		int indices[128];
		int k = getIndices(indices, i, i + 1);
		propagateRange(indices, k);
		leafs[i] = x;
		mergeRange(indices, k);
	}
	void addToRange(int i, int j, const Add &x) {
		if (i >= j) return;
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		int l = i + n, r = j + n;
		if (l & 1) { int p = (l ++) - n; x.addToVal(leafs[p], p); }
		if (r & 1) { int p = (-- r) - n; x.addToVal(leafs[p], p); }
		for (l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) add[l ++] += x;
			if (r & 1) add[-- r] += x;
		}
		mergeRange(indices, k);
	}
private:
	int getIndices(int indices[], int i, int j) const {
		int k = 0, l, r;
		if (i >= j) return 0;
		for (l = (n + i) >> 1, r = (n + j - 1) >> 1; l != r; l >>= 1, r >>= 1) {
			indices[k ++] = l;
			indices[k ++] = r;
		}
		for (; l; l >>= 1) indices[k ++] = l;
		return k;
	}
	void propagateRange(int indices[], int k) {
		for (int i = k - 1; i >= 0; -- i)
			propagate(indices[i]);
	}
	void mergeRange(int indices[], int k) {
		for (int i = 0; i < k; ++ i)
			merge(indices[i]);
	}
	inline void propagate(int i) {
		if (i >= n) return;
		add[i].addToSum(nodes[i], leftpos[i], rightpos[i]);
		if (i * 2 < n) {
			add[i * 2] += add[i];
			add[i * 2 + 1] += add[i];
		} else {
			add[i].addToVal(leafs[i * 2 - n], i * 2 - n);
			add[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		}
		add[i] = Add();
	}
	inline void merge(int i) {
		if (i >= n) return;
		nodes[i] = sum(i * 2) + sum(i * 2 + 1);
	}
	inline Sum sum(int i) {
		propagate(i);
		return i < n ? nodes[i] : Sum(leafs[i - n], i - n);
	}
};
template<typename T>
typename map<int, pair<int, T> >::iterator splitInterval(map<int, pair<int, T> > &intervals, int i) {
	typename map<int, pair<int, T> >::iterator it = -- intervals.upper_bound(i);
	if (it->first != i) {
		intervals.insert(make_pair(i, it->second));
		it->second.first = i;
		it = intervals.find(i);
	}
	return it;
}

int main() {
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<map<int, pair<int, bool>>> intervals(n);
		for (int i = 0; i < n; ++ i)
			intervals[i][0] = make_pair(n, false);
		SegmentTree segt;
		segt.init(n);
		for (int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				int l; int r; int x;
				scanf("%d%d%d", &l, &r, &x), -- l, -- x;
				auto &S = intervals[x];
				auto itL = splitInterval(S, l);
				auto itR = splitInterval(S, r);
				for (auto it = itL; it != itR; ++ it) {
					int L = it->first, R = it->second.first;
					Add add;
					if (it->second.second)
						add.a = 2;
					else
						add.b = 1;
					segt.addToRange(L, R, add);
				}
				S.erase(itL, itR);
				S.insert(make_pair(l, make_pair(r, true)));
			} else if (ty == 2) {
				int l; int r;
				scanf("%d%d", &l, &r), -- l;
				mint ans = segt.getRangeCommutative(l, r).sum;
				printf("%d\n", ans.get());
			} else abort();
		}
	}
}