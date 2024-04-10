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
#include <functional>
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
	int len;
	bool covered;
};
struct Sum {
	int notcovered;
	Sum(): notcovered(0) { }
	Sum(const Val &val, int pos): notcovered(val.covered ? 0 : val.len) { }
	Sum &operator+=(const Sum &that) { notcovered += that.notcovered; return *this; }
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
struct Laziness {
	bool cover;
	Laziness(): cover(false) { }
	Laziness &operator+=(const Laziness &that) { cover |= that.cover; return *this; }
	void addToVal(Val &val, int pos) const { if(cover) val.covered = true; }
	void addToSum(Sum &sum, int left, int right) const { if(cover) sum.notcovered = 0; }
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
			laziness[i].addToVal(leafs[i * 2 - n], i * 2 - n);
			laziness[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
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


int main() {
	int n;
	scanf("%d", &n);
	vi p(n), l(n);
	rep(i, n)
		scanf("%d%d", &p[i], &l[i]);
	int q;
	scanf("%d", &q);
	vector<pair<pii,int> > queries(q);
	rep(i, q) {
		int x, y;
		scanf("%d%d", &x, &y), -- x, -- y;
		queries[i] = mp(mp(x, y), i);
	}
	sort(all(queries));
	vi poses;
	rep(i, n) {
		poses.push_back(p[i]);
		poses.push_back(p[i] + l[i]);
	}
	sort(all(poses));
	poses.erase(unique(all(poses)), poses.end());
	int V = poses.size();

	vector<Val> initval(V-1);
	rep(i, V-1) {
		initval[i].covered = false;
		initval[i].len = poses[i+1] - poses[i];
	}
	SegmentTree segt;
	segt.init(initval);

	vector<int> ans(q, -1);
	int qi = q-1;
	for(int i = n-1; i >= 0; -- i) {
		int L = lower_bound(all(poses), p[i]) - poses.begin();
		int R = lower_bound(all(poses), p[i] + l[i]) - poses.begin();
		Laziness laziness; laziness.cover = true;
		segt.addToRange(L, R, laziness);

		while(qi >= 0 && queries[qi].first.first == i) {
			const pair<pii,int> &qp = queries[qi];
			int y = qp.first.second;
			int Y = lower_bound(all(poses), p[y]) - poses.begin();
			Sum sum = segt.getRange(L, Y);
			ans[qp.second] = sum.notcovered;
			-- qi;
		}
	}
	rep(i, q)
		printf("%d\n", ans[i]);
	return 0;
}