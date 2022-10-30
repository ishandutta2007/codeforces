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
#include <bitset>
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
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while(k) {
		if(k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

typedef ModInt<1000000007> mint;
typedef ModInt<1000000007-1> phimint;

int main() {
	char *s = new char[100001], *t = new char[200001], *buf = new char[100005];
	scanf("%s", s);
	int Q;
	scanf("%d", &Q);
	vector<int> ds(Q);
	vector<char*> ts(Q);
	char *tp = t;
	rep(i, Q) {
		int d;
		scanf("%s", buf);
		*tp = 0;
		sscanf(buf, "%d->%s", &d, tp);
		ds[i] = d;
		ts[i] = tp;
		tp += strlen(tp) + 1;
	}
	const int D = 10;
	vector<phimint> len(D);
	vector<mint> val(D);
	rep(d, D) {
		len[d] = 1;
		val[d] = d;
	}
	for(int i = Q-1;i >= 0; -- i) {
		int d = ds[i];
		phimint nlen = 0; mint nval = 0;
		for(char *p = ts[i]; *p; ++ p) {
			int e = *p - '0';
			nlen += len[e];
			nval = nval * (mint(10) ^ len[e].get()) + val[e];
		}
		len[d] = nlen;
		val[d] = nval;
	}
	mint ans = 0;
	for(char *p = s; *p; ++ p) {
		int d = *p - '0';
		ans = ans * (mint(10) ^ len[d].get()) + val[d];
	}
	printf("%d\n", ans.get());
	return 0;
}