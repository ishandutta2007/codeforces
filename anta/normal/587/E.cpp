#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const int B = 30;

typedef unsigned Val;
int findBasis(Val *v, int n, Val *t) {
	int rank = 0;
	int used = 0;
	for(int j = B-1; j >= 0; j --) {
		int i = used;
		while(i < n && (~v[i] >> j & 1)) i ++;
		if(i < n) {
			Val x = v[i];
			swap(v[i], v[used ++]);
			t[rank ++] = x;
			for(i = used; i < n; i ++)
				if(v[i] >> j & 1)
					v[i] ^= x;
		}
	}
	return rank;
}

struct Sum {
	Val basis[B];
	int rank;
	Sum(): rank(0) { }
	Sum(const Val &val, int pos) {
		if(val == 0) {
			rank = 0;
		} else {
			basis[0] = val;
			rank = 1;
		}
	}
	Sum &operator+=(const Sum &that) {
		Val tmp[B * 2];
		rep(i, rank) tmp[i] = basis[i];
		rep(i, that.rank) tmp[rank + i] = that.basis[i];
		rank = findBasis(tmp, rank + that.rank, basis);
		return *this;
	}
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};

struct SegmentTree {
	vector<Val> leafs;
	vector<Sum> nodes;
	vector<int> leftpos, rightpos;
	int n, n2;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while(n < (int)u.size()) n *= 2;
		n2 = (n - 1) / 2 + 1;
		leafs = u; leafs.resize(n, Val());
		nodes.resize(n);
		for(int i = n-1; i >= n2; -- i)
			nodes[i] = Sum(leafs[i*2-n], i*2-n) + Sum(leafs[i*2+1-n], i*2+1-n);
		for(int i = n2-1; i > 0; -- i)
			nodes[i] = nodes[i*2] + nodes[i*2+1];
		leftpos.resize(n); rightpos.resize(n);
		for(int i = n-1; i >= n2; -- i) {
			leftpos[i] = i*2-n;
			rightpos[i] = (i*2+1-n) + 1;
		}
		for(int i = n2-1; i > 0; -- i) {
			leftpos[i] = leftpos[i*2];
			rightpos[i] = rightpos[i*2+1];
		}
	}
	Val get(int i) {
		int indices[128];
		int k = getIndices(indices, i, i+1);
		return leafs[i];
	}
	Sum getRangeCommutative(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
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
		Sum res = Sum();
		for(; i && i + (i&-i) <= j; i += i&-i)
			res += sum((n+i) / (i&-i));
		for(k = 0; i < j; j -= j&-j)
			indices[k ++] = (n+j) / (j&-j) - 1;
		while(-- k >= 0) res += sum(indices[k]);
		return res;
	}
	void set(int i, const Val &x) {
		int indices[128];
		int k = getIndices(indices, i, i+1);
		leafs[i] = x;
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
	void mergeRange(int indices[], int k) {
		for(int i = 0; i < k; ++ i)
			merge(indices[i]);
	}
	inline void merge(int i) {
		if(i >= n) return;
		nodes[i] = sum(i * 2) + sum(i * 2 + 1);
	}
	inline Sum sum(int i) {
		return i < n ? nodes[i] : Sum(leafs[i - n], i - n);
	}
};

struct FenwickTree {
	typedef Val T;
	vector<T> v;
	void init(int n) { v.assign(n, 0); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] ^= x;
	}
	T sum(int i) const {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r ^= v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) ^ sum(left);
	}
};

int main() {
	int n; int q;
	while(~scanf("%d%d", &n, &q)) {
		vector<Val> initvals(n+1);
		FenwickTree ft; ft.init(n);
		int preva = 0;
		rep(i, n) {
			int a;
			scanf("%d", &a);
			initvals[i] = a ^ preva;
			ft.add(i, initvals[i]);
			preva = a;
		}
		initvals[n] = preva;
		SegmentTree segt;
		segt.init(initvals);
		rep(ii, q) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int l, r, k;
				scanf("%d%d%d", &l, &r, &k), -- l;
				segt.set(l, segt.get(l) ^ k);
				segt.set(r, segt.get(r) ^ k);
				ft.add(l, k);
				ft.add(r, k);
			} else if(ty == 2) {
				int l, r;
				scanf("%d%d", &l, &r), -- l;
				Val left = ft.sum(l+1);
				Sum sum = segt.getRangeCommutative(l+1, r);
				sum += Sum(left,-1);
				unsigned ans = 1U << sum.rank;
				printf("%u\n", ans);
			} else abort();
		}
	}
	return 0;
}