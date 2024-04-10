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
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
	
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
	
	ModInt inverse() const {
		long long a = x, b = MOD, u = 1, v = 0;
		while(b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		return ModInt(u);
	}
	
	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
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

struct SaturationInt {
	typedef long long T; typedef double Float;
	static T Max;
	T x;
	static inline T sat(T x) { return x > Max ? Max : x; }
	SaturationInt() { }
	SaturationInt(T x_): x(sat(x_)) { }
	T get() const { return x; }

	SaturationInt operator+(const SaturationInt &that) const {
		return SaturationInt(x + that.x);
	}
	SaturationInt operator*(const SaturationInt &that) const {
		return SaturationInt((Float)x * that.x > Max ? Max : x * that.x);
	}
	SaturationInt &operator+=(const SaturationInt &that) { return *this = *this + that; }
	SaturationInt &operator*=(const SaturationInt &that) { return *this = *this * that; }

	SaturationInt operator^(long long k) const {
		long long r = 1, a = x;
		while(k) {
			if(k & 1) r *= a;
			if(k >>= 1) {
				if((Float)a * a * r > Max) return SaturationInt(Max);
				a *= a;
			}
		}
		return SaturationInt(r);
	}
};
SaturationInt::T SaturationInt::Max = INFL;


ll t, a, b;
const int K = 63;
SaturationInt powt[K+1], powa[K+1];
mint rec(int i, ll rema, ll remb) {
	if(i == 1) {
		mint res = 0;
		ll tt = powt[i].get(), aa = powa[i].get();
		//x tt + y = rema, x aa + y = remb
		if(tt == aa) {
			if(rema == remb)
				res += max(0LL, (remb + tt) / tt);	//remb / tt >= x;
		}else {
			ll d = tt - aa;
			if((rema - remb) % d == 0) {
				ll x = (rema - remb) / d;
				if(x >= 0 && rema / tt >= x)	//rema - x tt >= 0
					res += 1;
			}
		}
		return res;
	}
	ll tt = powt[i].get(), aa = powa[i].get();
	int mx = (int)min(rema / tt, remb / aa);
	mint res = 0;
	rer(ai, 0, mx)
		res += rec(i-1, rema - ai * tt, remb - ai * aa);
	return res;
}

mint solve() {
	mint inf; inf.x = -1;
	if(t == 1 && a == 1 && b == 1)
		return inf;
	powt[0] = powa[0] = 1;
	for(int k = 1; k <= K; ++ k) {
		powt[k] = powt[k-1] * t;
		powa[k] = powa[k-1] * a;
	}
	return rec(K, a, b);
}

int main() {
	cin >> t >> a >> b;
	mint ans = solve();
	if(ans.x == -1)
		puts("inf");
	else
		printf("%d\n", ans.get());
	return 0;
}