#define _CRT_SECURE_NO_WARNINGS
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct Val {
	long long x;
	Val(): x(0) { }
	explicit Val(long long x_): x(x_) { }
};
struct Sum {
	long long sum;
	Sum(): sum(0) { }
	Sum(const Val &val, int pos): sum(val.x) { }
	Sum &operator+=(const Sum &that) {
		sum += that.sum;
		return *this;
	}
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
struct Laziness {
	long long add;
	Laziness(): add(0) { }
	explicit Laziness(long long add_): add(add_) { }
	Laziness &operator+=(const Laziness &that) {
		add += that.add;
		return *this;
	}
	void addToVal(Val &val, int pos) const {
		val.x += add;
	}
	void addToSum(Sum &sum, int left, int right) const {
		sum.sum += (long long)add * (right - left);
	}
};

struct SegmentTree {
	vector<Val> leafs;
	vector<Sum> nodes;
	vector<Laziness> laziness;
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
		laziness.assign(n, Laziness());

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
			res += sum((n+i) / (i&-i));
		for(k = 0; i < j; j -= j&-j)
			indices[k ++] = (n+j) / (j&-j) - 1;
		while(-- k >= 0) res += sum(indices[k]);
		return res;
	}
	void set(int i, const Val &x) {
		int indices[128];
		int k = getIndices(indices, i, i+1);
		propagateRange(indices, k);
		leafs[i] = x;
		mergeRange(indices, k);
	}
	void addToRange(int i, int j, const Laziness &x) {
		if(i >= j) return;
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		int l = i + n, r = j + n;
		if(l & 1) { int p = (l ++) - n; x.addToVal(leafs[p], p); }
		if(r & 1) { int p = (-- r) - n; x.addToVal(leafs[p], p); }
		for(l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) laziness[l ++] += x;
			if(r & 1) laziness[-- r] += x;
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
		laziness[i].addToSum(nodes[i], leftpos[i], rightpos[i]);
		if(i * 2 < n) {
			laziness[i * 2] += laziness[i];
			laziness[i * 2 + 1] += laziness[i];
		}else {
			laziness[i].addToVal(leafs[i * 2 - n], i * 2);
			laziness[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1);
		}
		laziness[i] = Laziness();
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

map<int,pii>::iterator splitInterval(map<int,pii> &intervals, int i) {
	map<int,pii>::iterator it = -- intervals.upper_bound(i);
	if(it->first != i) {
		intervals.insert(mp(i, it->second));
		it->second.first = i;
		it = intervals.find(i);
	}
	return it;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	map<int,pair<int,int> > intervals;	//(L,R)
	rep(i, n) intervals[i] = mp(i+1, i+1);
	intervals[n] = mp(n, -1);
	SegmentTree segt; segt.init(n);
	rep(ii, m) {
		int ty;
		scanf("%d", &ty);
		if(ty == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x), l --;
			map<int,pair<int,int> >::iterator it, jt, kt;
			it = splitInterval(intervals, l);
			jt = splitInterval(intervals, r);
			for(kt = it; kt != jt; ++ kt) {
				int L = kt->first, R = kt->second.first;
				int add = abs(kt->second.second - x);
				segt.addToRange(L, R, Laziness(add));
			}
			intervals.erase(it, jt);
			intervals.insert(mp(l, mp(r, x)));
//			rep(i, n) cerr << segt.get(i).x << ","; cerr << endl;
		}else {
			int l, r;
			scanf("%d%d", &l, &r), l --;
			Sum sum = segt.getRange(l, r);
			cout << sum.sum << "\n";
		}
	}
	return 0;
}