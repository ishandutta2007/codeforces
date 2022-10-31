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

const int A = 26;
typedef int Val;
struct Sum {
	int cnt[A];
	Sum() { mset(cnt, 0); }
	Sum(const Val &val, int pos) { mset(cnt, 0); cnt[val] = 1; }
	Sum &operator+=(const Sum &that) {
		rep(k, A) cnt[k] += that.cnt[k];
		return *this;
	}
	Sum operator+(const Sum &that) const {
		Sum res;
		rep(k, A) res.cnt[k] = cnt[k] + that.cnt[k];
		return res;
	}
};

struct Add {
	int assign;
	Add(): assign(-1) { }
	Add(int a): assign(a) { }
	Add &operator+=(const Add &that) {
		if(that.assign != -1)
			*this = that;
		return *this;
	}
	void addToVal(Val &val, int pos) const {
		if(assign != -1)
			val = assign;
	}
	void addToSum(Sum &sum, int left, int right) const {
		if(assign != -1) {
			mset(sum.cnt, 0);
			sum.cnt[assign] = right - left;
		}
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
		for(int i = n-1; i >= n2; -- i)
			nodes[i] = Sum(leafs[i*2-n], i*2-n) + Sum(leafs[i*2+1-n], i*2+1-n);
		for(int i = n2-1; i > 0; -- i)
			nodes[i] = nodes[i*2] + nodes[i*2+1];
		add.assign(n, Add());

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
		}else {
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
	int n, q;
	while(cin >> n >> q) {
		string S(n, '?');
		cin >> S;
//		rep(i, n) S[i]=rand()%A+'a';
//		int dbgaaa=0;
		vector<Val> initval(n);
		rep(i, n) initval[i] = S[i] - 'a';
		SegmentTree segt; segt.init(initval);
		rep(ii, q) {
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k), -- i;
//			i=rand()%n,j=rand()%n;if(i>j)swap(i,j);++j;k=rand()%2;
//			i=0,j=n,k=ii%2;
			Sum sum = segt.getRangeCommutative(i, j);
			if(k == 1) {
				int pos = i;
				rep(a, A) {
//					dbgaaa+=sum.cnt[a]!=0;
					segt.addToRange(pos, pos + sum.cnt[a], Add(a));
					pos += sum.cnt[a];
				}
			}else {
				int pos = j;
				rep(a, A) {
//					dbgaaa+=sum.cnt[a]!=0;
					segt.addToRange(pos - sum.cnt[a], pos, Add(a));
					pos -= sum.cnt[a];
				}
			}
		}
//		cout<<dbgaaa<<endl;
		string ans(n, '?');
		rep(i, n)
			ans[i] = 'a' + segt.get(i);
		puts(ans.c_str());
	}
	return 0;
}