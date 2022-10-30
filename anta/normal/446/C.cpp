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

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt(): x(0) { }
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }
	
	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000009> mint;


struct WeightedRangeAddSumSegmentTree {
	typedef mint Val;
	typedef mint Sum;

	struct Laziness {
		static const int K = 2;
		mint add[K];

		Laziness &operator+=(const Laziness &that) {
			rep(k, K)
				add[k] += that.add[k];
			return *this;
		}
		void addToVal(Val &val, int pos) const {
			bool zero = true;
			rep(k, K) zero &= add[k].get() == 0;
			if(zero) return;
			rep(k, K)
				val += coefs[k][pos] * add[k];
		}
		void addToSum(Sum &sum, int left, int right) const {
			bool zero = true;
			rep(k, K) zero &= add[k].get() == 0;
			if(zero) return;
			rep(k, K)
				sum += (coefsums[k][right] - coefsums[k][left]) * add[k];
		}
		static void calcCoefSums() {
			rep(k, K) {
				coefsums[k].assign(coefs[k].size() + 1, mint());
				rep(i, coefs[k].size())
					coefsums[k][i+1] = coefsums[k][i] + coefs[k][i];
			}
		}
		static vector<mint> coefs[K];
		static vector<mint> coefsums[K];
	};

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
			nodes[i] = Sum(leafs[i*2-n]) + Sum(leafs[i*2+1-n]);
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
		return i < n ? nodes[i] : Sum(leafs[i - n]);
	}
};
vector<mint> WeightedRangeAddSumSegmentTree::Laziness::coefs[K];
vector<mint> WeightedRangeAddSumSegmentTree::Laziness::coefsums[K];

typedef WeightedRangeAddSumSegmentTree SegmentTree;
typedef SegmentTree::Laziness Laziness;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<mint> *coefs = Laziness::coefs;
	rep(k, 2) coefs[k].resize(max(2, n));
	coefs[0][0] = 1; coefs[1][0] = 0;
	coefs[0][1] = 0; coefs[1][1] = 1;
	reu(i, 2, n) rep(k, 2)
		coefs[k][i] = coefs[k][i-1] + coefs[k][i-2];
	Laziness::calcCoefSums();

	//F_{n-2} = F_n - F_{n-1}
	vector<mint> negfib[2];
	rep(k, 2) negfib[k].resize(max(2, n));
	negfib[0][0] = 1; negfib[1][0] = 1;
	negfib[0][1] = 0; negfib[1][1] = 1;
	reu(i, 2, n) rep(k, 2)
		negfib[k][i] = negfib[k][i-2] - negfib[k][i-1];

	vector<mint> inita(n);
	rep(i, n) {
		int x;
		scanf("%d", &x);
		inita[i] = x;
	}

	SegmentTree segt;
	segt.init(inita);

	rep(ii, m) {
//		rep(i, n) cerr << segt.get(i).get() << ", "; cerr << endl;
		int ty, l, r;
		scanf("%d%d%d", &ty, &l, &r), -- l;
		if(ty == 1) {
			//a x + b y
			Laziness add = { negfib[0][l], negfib[1][l] };
			segt.addToRange(l, r, add);
		}else {
			mint ans = segt.getRangeCommutative(l, r);
			printf("%d\n", ans.get());
		}
	}

	return 0;
}