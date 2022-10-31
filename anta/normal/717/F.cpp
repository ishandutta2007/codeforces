#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

typedef long long Val;
struct Sum {
	int size;
	long long altSum;	//a - b + c - d + ...
	long long minSum;
	long long minPrefix[2];	//minPrefix[0]  -a, b, -c, d ... `
	long long minSuffix[2];	//minSuffix[0]  ... a, -b, c, -d `
	Sum() : size(0), altSum(0), minSum(INFL), minPrefix{ 0, INFL }, minSuffix{ 0, INFL } {}
	Sum(const Val &val, int pos) {
		size = 1;
		altSum = val;
		minSum = val;
		minPrefix[0] = minSuffix[0] = 0;
		minPrefix[1] = minSuffix[1] = val;
	}
	Sum &operator+=(const Sum &that) {
		return *this = *this + that;
	}
	Sum operator+(const Sum &that) const {
		if(size == 0)
			return that;
		if(that.size == 0)
			return *this;
		Sum res;
		res.size = size + that.size;
		res.altSum = altSum + (size % 2 == 0 ? that.altSum : -that.altSum);
		res.minSum = min(minSum, that.minSum);
		amin(res.minSum, minSuffix[0] + that.minPrefix[1]);
		amin(res.minSum, minSuffix[1] + that.minPrefix[0]);
		res.minPrefix[0] = min(minPrefix[0], -altSum + that.minPrefix[size % 2]);
		res.minPrefix[1] = min(minPrefix[1], altSum + that.minPrefix[(size + 1) % 2]);
		res.minSuffix[0] = min(minSuffix[that.size % 2] + (that.size % 2 == 0 ? that.altSum : -that.altSum), that.minSuffix[0]);
		res.minSuffix[1] = min(minSuffix[(that.size + 1) % 2] + (that.size % 2 == 0 ? -that.altSum : that.altSum), that.minSuffix[1]);
		return res;
	}
};
struct Add {
	long long add;
	Add() : add(0) {}
	explicit Add(long long add) : add(add) {}
	Add &operator+=(const Add &that) {
		add += that.add;
		return *this;
	}
	void addToVal(Val &val, int pos) const {
		if(add == 0) return;
		val += add;
	}
	void addToSum(Sum &sum, int left, int right) const {
		if(add == 0) return;
		if(sum.size == 0) return;
		sum.altSum += add * (sum.size % 2);
		sum.minSum += add;
		sum.minPrefix[1] += add;
		sum.minSuffix[1] += add;
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
		n = 1; while(n < (int)u.size()) n *= 2;
		n2 = (n - 1) / 2 + 1;
		leafs = u; leafs.resize(n, Val());
		nodes.resize(n);
		for(int i = n - 1; i >= n2; -- i)
			nodes[i] = Sum(leafs[i * 2 - n], i * 2 - n) + Sum(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		for(int i = n2 - 1; i > 0; -- i)
			nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
		add.assign(n, Add());

		leftpos.resize(n); rightpos.resize(n);
		for(int i = n - 1; i >= n2; -- i) {
			leftpos[i] = i * 2 - n;
			rightpos[i] = (i * 2 + 1 - n) + 1;
		}
		for(int i = n2 - 1; i > 0; -- i) {
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
		for(int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res += sum(l ++);
			if(r & 1) res += sum(-- r);
		}
		return res;
	}
	Sum getRange(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for(; i && i + (i&-i) <= j; i += i&-i)
			res += sum((n + i) / (i&-i));
		for(k = 0; i < j; j -= j&-j)
			indices[k ++] = (n + j) / (j&-j) - 1;
		while(-- k >= 0) res += sum(indices[k]);
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
		if(i >= j) return;
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		int l = i + n, r = j + n;
		if(l & 1) { int p = (l ++) - n; x.addToVal(leafs[p], p); }
		if(r & 1) { int p = (-- r) - n; x.addToVal(leafs[p], p); }
		for(l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) add[l ++] += x;
			if(r & 1) add[-- r] += x;
		}
		mergeRange(indices, k);
	}
private:
	int getIndices(int indices[], int i, int j) const {
		int k = 0, l, r;
		if(i >= j) return 0;
		for(l = (n + i) >> 1, r = (n + j - 1) >> 1; l != r; l >>= 1, r >>= 1) {
			indices[k ++] = l;
			indices[k ++] = r;
		}
		for(; l; l >>= 1) indices[k ++] = l;
		return k;
	}
	void propagateRange(int indices[], int k) {
		for(int i = k - 1; i >= 0; -- i)
			propagate(indices[i]);
	}
	void mergeRange(int indices[], int k) {
		for(int i = 0; i < k; ++ i)
			merge(indices[i]);
	}
	inline void propagate(int i) {
		if(i >= n) return;
		add[i].addToSum(nodes[i], leftpos[i], rightpos[i]);
		if(i * 2 < n) {
			add[i * 2] += add[i];
			add[i * 2 + 1] += add[i];
		} else {
			add[i].addToVal(leafs[i * 2 - n], i * 2 - n);
			add[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		}
		add[i] = Add();
	}
	inline void merge(int i) {
		if(i >= n) return;
		nodes[i] = sum(i * 2) + sum(i * 2 + 1);
	}
	inline Sum sum(int i) {
		propagate(i);
		return i < n ? nodes[i] : Sum(leafs[i - n], i - n);
	}
};


int main() {
	int n;
	mt19937 re;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		SegmentTree segt;
		vector<Val> initVals(n);
		rep(i, n) initVals[i] = a[i] - 1;
		segt.init(initVals);
		int q;
		scanf("%d", &q);
		for(int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int a; int b; int k;
				scanf("%d%d%d", &a, &b, &k), ++ b;
				segt.addToRange(a, b, Add(k));
			} else if(ty == 2) {
				int a; int b;
				scanf("%d%d", &a, &b), ++ b;
				Sum sum = segt.getRange(a, b);
				bool ans = true;
				ans &= sum.altSum == 0;
				ans &= sum.minSum >= 0;
				ans &= sum.minPrefix[0] >= 0;
				ans &= sum.minSuffix[0] >= 0;
				puts(ans ? "1" : "0");
			} else abort();
		}
	}
	return 0;
}