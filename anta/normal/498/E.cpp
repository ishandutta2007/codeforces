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
typedef ModInt<1000000007> mint;

struct Matrix {
	typedef mint Num;
	static const int MaxN = 1 << 7;
	int hei, wid;
	Num v[MaxN][MaxN];
	Matrix() {}
	Matrix(int n, int m): hei(n), wid(m) { mset(v, 0); }
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
		const unsigned (*b)[MaxN] = reinterpret_cast<const unsigned (*)[MaxN]>(B.v);
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
					x0  = t & 0xffffffff;
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
	int K = 7;
	vector<int> w(K);
	rep(i, K) scanf("%d", &w[i]);
	Matrix b(1, 1 << K);
	b.at(0, 1) = 1;
	rer(h, 1, K) {
		Matrix A(1 << K, 1 << K);
		rep(j, 1 << K) {
			rep(k, 1 << K) {
				rep(l, 1 << (h-1)) {
					int l2 = 1 | l << 1 | 1 << h;
					bool ok = true;
					rep(y, K) {
						ok &= !((j >> y & 1) && (k >> y & 1) && (l2 >> y & 3) == 3);
						ok &= !(y >= h && (k >> y & 1));
					}
					if(ok)
						A.at(j, k) += 1;
				}
			}
		}
		b *= A ^ w[h-1];
		if(h < K) {
			Matrix B(1 << K, 1 << K);
			rep(j, 1 << K)
				B.at(j, j | 1 << h) = 1;
			b *= B;
		}
//		rep(i, 1 << K) if(b.at(0, i).get())
//			cerr << h << ", " << bitset<7>(i) << ": " << b.at(0, i).get() << endl;
	}
	mint ans = b.at(0, (1 << K) - 1);
	printf("%d\n", ans.get());
	return 0;
}