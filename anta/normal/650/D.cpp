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
#include <random>
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


template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
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
typedef ModInt<1000000007> mint;

struct LenSum {
	int len;
	mint sum;

	LenSum() : len(0), sum() { }
	explicit LenSum(mint weight) : len(1), sum(weight) {}
	LenSum(int len, mint weight) : len(len), sum(weight) {}
	LenSum &operator+=(const LenSum &that) {
		if(len < that.len)
			len = that.len, sum = that.sum;
		else if(len == that.len)
			sum += that.sum;
		return *this;
	}
	LenSum operator+(const LenSum &that) const { return LenSum(*this) += that; }
	LenSum operator*(const LenSum &that) const {
		LenSum res;
		res.len = len + that.len;
		res.sum = sum * that.sum;
		return res;
	}
};

struct SegmentTreeLenSum {
	int n;
	vector<LenSum> nodes;
	SegmentTreeLenSum(int x) {
		n = 1;
		while(n < x) n *= 2;
		nodes.assign(n * 2, LenSum());
	}
	LenSum getRange(int i, int j) const {
		LenSum sum;
		for(int l = n + i, r = n + j; l < r; l >>= 1, r >>= 1) {
			if(l & 1) sum += nodes[l ++];
			if(r & 1) sum += nodes[-- r];
		}
		return sum;
	}
	LenSum get(int i) const {
		return nodes[n + i];
	}
	void set(int i, const LenSum &val) {
		nodes[n + i] = val;
		for(int l = (n + i) >> 1; l > 0; l >>= 1)
			nodes[l] = nodes[l * 2] + nodes[l * 2 + 1];
	}
};

struct Query {
	int pos, val;
	int i;
	bool operator<(const Query &that) const { return pos < that.pos; }
};

LenSum lisQueries(vector<int> A, vector<Query> queries, vector<LenSum> &res) {
	int N = A.size();
	vector<int> values; values.reserve(A.size() + queries.size() + 2);
	for(int a : A) values.push_back(a);
	for(const auto &q : queries) values.push_back(q.val);
	values.push_back(numeric_limits<int>::min());
	values.push_back(numeric_limits<int>::max());
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	int X = (int)values.size();
	rep(i, N)
		A[i] = (int)(lower_bound(values.begin(), values.end(), A[i]) - values.begin());
	LenSum whole;
	default_random_engine re{ random_device{}() };
	uniform_int_distribution<int> randomMint{1, mint::Mod - 1};
	vector<mint> weights(N);
	rep(i, N)
		weights[i].x = randomMint(re);
	const LenSum One(0, mint(1));
	SegmentTreeLenSum segtR(X);
	segtR.set(X - 1, One);
	vector<LenSum> history(N);
	for(int i = N - 1; i >= 0; -- i) {
		int a = A[i];
		LenSum sum = LenSum(weights[i]) * segtR.getRange(a + 1, X);
		history[i] = segtR.get(a);
		segtR.set(a, history[i] + sum);
	}
	SegmentTreeLenSum segtL(X);
	segtL.set(0, One);
	int Q = (int)queries.size();
	res.assign(Q, LenSum());
	sort(queries.begin(), queries.end());
	int qi = 0;
	rep(i, N) {
		int a = A[i];
		segtR.set(a, history[i]);
		LenSum sum = segtL.getRange(0, a) * LenSum(weights[i]);
		for(; qi < Q && queries[qi].pos == i; ++ qi) {
			if(values[a] == queries[qi].val) {
				res[queries[qi].i] += sum * segtR.getRange(a + 1, X);
			} else {
				int b = (int)(lower_bound(values.begin(), values.end(), queries[qi].val) - values.begin());
				res[queries[qi].i] += segtL.getRange(0, b) * LenSum(weights[i]) * segtR.getRange(b + 1, X);
			}
		}
		whole += sum;
		segtL.set(a, segtL.get(a) + sum);
	}
	return whole;
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> h(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &h[i]);
		vector<Query> queries(n + m);
		rep(i, n)
			queries[i] = { i, h[i], i };
		for(int i = 0; i < m; ++ i) {
			int a; int b;
			scanf("%d%d", &a, &b), -- a;
			queries[n + i] = {a, b, n + i};
		}
		vector<LenSum> lenSums;
		LenSum whole = lisQueries(h, queries, lenSums);
		vector<bool> dispensable(n);
		rep(i, n)
			dispensable[i] = lenSums[i].sum.get() != whole.sum.get();
		rep(i, m) {
			int ans = lenSums[n + i].len;
			amax(ans, whole.len - (dispensable[queries[n + i].pos] ? 0 : 1));
			printf("%d\n", ans);
		}
	}
	return 0;
}