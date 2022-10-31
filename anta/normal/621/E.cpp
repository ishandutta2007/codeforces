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

struct Matrix {
	typedef mint Num;
	static const int MaxN = 100;
	int hei, wid;
	Num v[MaxN][MaxN];
	Matrix() {}
	Matrix(int n, int m) : hei(n), wid(m) { mset(v, 0); }
	inline int height() const { return hei; }
	inline int width() const { return wid; }
	inline Num& at(int i, int j) { return v[i][j]; }
	inline const Num& at(int i, int j) const { return v[i][j]; }
	static Matrix identity(int n) {
		Matrix A(n, n);
		rep(i, n) A.at(i, i) = 1;
		return A;
	}
	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
	Matrix& operator*=(const Matrix& B) {
		int n = height(), m = B.width(), p = B.height();
		assert(p == width());
		const unsigned(*b)[MaxN] = reinterpret_cast<const unsigned(*)[MaxN]>(B.v);
		Num w[MaxN][MaxN];
		unsigned long long pp = (1ULL << 32) % mint::Mod;
		rep(i, n) {
			const unsigned *ai = reinterpret_cast<const unsigned*>(v[i]);
			rep(j, m) {
				unsigned x0 = 0; unsigned long long x1 = 0;
				rep(k, p) {
					unsigned long long y = (unsigned long long)ai[k] * b[k][j];
					unsigned long long t = x0 + y;
					x1 += t >> 32;
					x0 = t & 0xffffffff;
				}
				w[i][j].x = (x0 + x1 % mint::Mod * pp) % mint::Mod;
			}
		}
		memcpy(v, w, sizeof(v));
		return *this;
	}
};
Matrix operator^(const Matrix& t, ll k) {
	Matrix A = t, B = Matrix::identity(t);
	while(k) {
		if(k & 1) B *= A;
		A *= A;
		k >>= 1;
	}
	return B;
}

int main() {
	int n; int b; int k; int x;
	while(~scanf("%d%d%d%d", &n, &b, &k, &x)) {
		int cnt[10] = {};
		rep(i, n) {
			int d;
			scanf("%d", &d);
			++ cnt[d];
		}
		Matrix A(x, x);
		rep(i, x) rep(d, 10)
			A.at(i, (i * 10 + d) % x) += cnt[d];
		Matrix v(1, x);
		v.at(0, 0) = 1;
		v *= A ^ b;
		mint ans = v.at(0, k);
		printf("%d\n", ans.get());
	}
	return 0;
}