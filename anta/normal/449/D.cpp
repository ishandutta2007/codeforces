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
};
typedef ModInt<1000000007> mint;

int main() {
	//bit1
	//mask1a[i]mask
	//f(mask) = |_{bit \in mask} {bit \in a[i]}|
	//f(mask) = Sum_{mask  S} |{a[i] = S}|
	int n;
	while(~scanf("%d", &n)) {
	vector<int> a(n);
	rep(i, n)
		scanf("%d", &a[i]);
	const int Bits = 20;
	vector<int> f(1 << Bits);
	int alls = (1 << Bits) - 1;
	rep(i, n) f[alls ^ a[i]] ++;
	rep(i, Bits) for(int j = (1 << Bits)-1; j >= 0; j --) if(j >> i & 1) f[j] += f[j & ~(1 << i)];
//	rep(i, 1 << Bits) if(f[alls ^ i] != 0) cerr << i << ": " << f[alls ^ i] << endl;
	vector<mint> pow2(n+1);
	pow2[0] = 1;
	rer(i, 1, n) pow2[i] = pow2[i-1] + pow2[i-1];
	mint ans = 0;
	rep(mask, 1 << Bits) {
		int cnt = mask == 0 ? n : f[alls ^ mask];
		mint x = pow2[cnt];
		bool parity = false;
		rep(i, Bits) parity ^= mask >> i & 1;
		if(!parity) ans += x; else ans -= x;
	}
	printf("%d\n", ans.get());
	}
	return 0;
}