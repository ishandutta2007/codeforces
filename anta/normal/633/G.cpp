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
#include <bitset>
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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int g_M;
struct Val {
	int val;
};
struct Sum {
	bitset<1000> sum;
	Sum() : sum() {}
	Sum(const Val &val, int pos) { sum.set(val.val); }
	Sum &operator+=(const Sum &that) { sum |= that.sum; return *this; }
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
struct Add {
	int shift;
	Add() : shift(0) {}
	Add &operator+=(const Add &that) { (shift += that.shift) %= g_M; return *this; }
	void addToVal(Val &val, int pos) const { (val.val += shift) %= g_M; }
	void addToSum(Sum &sum, int left, int right) const {
		if(shift != 0)
			sum.sum = sum.sum << shift | (sum.sum >> (g_M - shift));
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

vector<int> t_parent;
vi t_ord;
vector<int> t_left, t_right;

void tree_eulertour(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();
	t_left.assign(n, -1);
	t_right.assign(n, -1);

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		if(i < 0) {
			i = -i - 1;
			t_right[i] = t_ord.size();
			continue;
		}
		t_left[i] = t_ord.size();
		t_ord.push_back(i);
		stk.push_back(-(i + 1));
		for(int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	const vi primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997 };
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		bitset<1000> primeSet;
		for(int p : primes) if(p < m)
			primeSet.set(p);
		g_M = m;
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_eulertour(g, 0);
		vector<Val> initval(n);
		rep(i, n) initval[i].val = a[t_ord[i]] % m;
		SegmentTree segt; segt.init(initval);
		int q;
		scanf("%d", &q);
		for(int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int v; int x;
				scanf("%d%d", &v, &x), -- v;
				Add add; add.shift = x % m;
				segt.addToRange(t_left[v], t_right[v], add);
			} else if(ty == 2) {
				int v;
				scanf("%d", &v), -- v;
				Sum sum = segt.getRangeCommutative(t_left[v], t_right[v]);
				int ans = (sum.sum & primeSet).count();
				printf("%d\n", ans);
			} else abort();
		}
	}
	return 0;
}