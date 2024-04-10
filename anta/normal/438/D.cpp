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

typedef int Val;
struct Sum {
	int maxx;
	long long sum;
	Sum(): maxx(0), sum(0) { }
	Sum(const Val &val, int pos): maxx(val), sum(val) { }
	Sum &operator+=(const Sum &that) {
		amax(maxx, that.maxx);
		sum += that.sum;
		return *this;
	}
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
struct Laziness {
	Laziness &operator+=(const Laziness &that) { return *this; }
	void addToVal(Val &val, int pos) const { }
	void addToSum(Sum &sum, int left, int right) const { }
};

struct SegmentTree {
	vector<Val> leafs;
	vector<Sum> nodes;
	vector<int> leftpos, rightpos;
	int n, n2;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 2; while(n < (int)u.size()) n *= 2;
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
		return leafs[i];
	}
	Sum getRangeCommutative(int i, int j) {
		Sum res = Sum();
		for(int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res += sum(l ++);
			if(r & 1) res += sum(-- r);
		}
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
public:
	template<typename Pred>
	int searchAll(int i, int j, Pred pred, int out_ids[]) {
		int *p = out_ids;
		searchAllRec(1, i, j, pred, p);
		return p - out_ids;
	}
private:
	template<typename Pred>
	void searchAllRec(int i, int l, int r, Pred pred, int *&out_ids) {
		if(!pred(sum(i))) return;
		if(i >= n) {
			if(l <= i - n && i - n < r) *(out_ids ++) = i - n;
			return;
		}
		amax(l, leftpos[i]);
		amin(r, rightpos[i]);
		if(l >= r) return;
		searchAllRec(i*2, l, r, pred, out_ids);
		searchAllRec(i*2+1, l, r, pred, out_ids);
	}
};

struct MaxGeMod {
	int mod;
	MaxGeMod(int mod_): mod(mod_) { }
	bool operator()(const Sum &sum) const { return sum.maxx >= mod; }
};

int poses[100000];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<Val> a(n);
	rep(i, n) scanf("%d", &a[i]);
	SegmentTree segt; segt.init(a);
	rep(i, m) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int l, r;
			scanf("%d%d", &l, &r), l --;
			long long sum = segt.getRangeCommutative(l, r).sum;
			printf("%I64d\n", sum);
		}else if(type == 2) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x), l --;
			int k = segt.searchAll(l, r, MaxGeMod(x), poses);
			rep(j, k) {
				int p = poses[j];
				segt.set(p, segt.get(p) % x);
			}
		}else if(type == 3) {
			int k, x;
			scanf("%d%d", &k, &x), k --;
			segt.set(k, x);
		}
	}
	return 0;
}