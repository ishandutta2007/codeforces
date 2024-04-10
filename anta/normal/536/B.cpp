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
		signed a = x, b = MOD, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
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

void z_algorithm(const char *s, int n, int z[]) {
    int L = 0, R = 0;
    for(int i = 1; i < n; i ++) {
        if(i > R) {
            L = R = i;
            while(R < n && s[R-L] == s[R]) R ++;
            z[i] = R-L; R --;
        }else {
            int k = i-L;
            if(z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while(R < n && s[R-L] == s[R]) R ++;
                z[i] = R-L; R --;
            }
        }
    }
	z[0] = n;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char *p = new char[n+1];
	scanf("%s", p);
	int len = strlen(p);
	vector<int> z(len+1);
	z_algorithm(p, len, &z[0]);
	vector<int> y(m);
	rep(i, m) scanf("%d", &y[i]), -- y[i];
	vector<int> cnt(n+1, 0);
	rep(i, m) ++ cnt[y[i]], -- cnt[y[i]+len];
	int qs = 0;
	rep(i, n) {
		if(cnt[i] == 0)
			++ qs;
		cnt[i+1] += cnt[i];
	}
	bool ok = true;
	rep(i, m-1) {
		int a = y[i], b = y[i+1];
		if(b - a < len) {
//			cerr << a << ", " << b << ": " << z[b - a] << ", " << a + len - b << endl;
			ok &= z[b - a] >= a + len - b;
		}
	}
	if(!ok)
		puts("0");
	else
		printf("%d\n", (mint(26) ^ qs).get());
	return 0;
}