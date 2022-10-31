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
#include <complex>
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
	vector<vector<Num> > v, w;
	Matrix() {}
	Matrix(int n, int m): v(n, vector<Num>(m)) { }
	inline int height() const { return (int)v.size(); }
	inline int width() const { return (int)v[0].size(); }
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
		w.assign(n, vector<Num>(m, 0));
		rep(i, n) rep(j, m) {
			Num x = 0;
			rep(k, p) x += at(i, k) * B.at(k, j);
			w[i][j] = x;
		}
		v.swap(w);
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

Matrix getRotateMatrix(int k, int t) {
	t = (t % k + k) % k;
	Matrix A(k + 3, k + 3);
	rep(i, k)
		A.at(i, (i + t) % k) = 1;
	A.at(k, k) = A.at(k+1, k+1) = A.at(k+2, k+2) = 1;
	return A;
}

Matrix getSingletonMatrix(int k, int j) {
	assert(0 <= j && j < k);
	Matrix A(k + 3, k + 3);
	rep(i, k) if(i != j)
		A.at(i, i) += 1;
	A.at(k + 1, k + 1) = A.at(k + 2, k + 2) = 1;

	A.at(k, k + 1) += 1;
//	A.at(k + 2, k + 1) += 1;
	A.at(j, k + 1) -= 1;

	A.at(k, k) += 2;
//	A.at(k + 2, k) += 1;
	A.at(j, k) -= 1;

	A.at(k, j) += 1;
//	A.at(k + 2, j) += 1;
//	A.at(j, j) -= 1;
	return A;
}

int s_k(int k, long long j) {
	long long t = j; int u = 0;
	while(t > 0) {
		(u += t % k) %= k;
		t /= k;
	}
	return u;
}

int main() {
	long long n; int k;
	while(cin >> n >> k) {
	Matrix b(1, k + 3);
	b.at(0, k) = 1;
	b.at(0, k + 1) = b.at(0, k + 2) = 1;
	/*
	{
		Matrix bb = b;
			rep(i, k+3) cerr << bb.at(0, i).get() << ", "; cerr << endl;
		for(int j = 0; j < n; ++ j) {
			int u = s_k(k, j);
			Matrix A = getSingletonMatrix(k, u);
			bb *= A;
			rep(i, k+3) cerr << bb.at(0, i).get() << ", "; cerr << endl;
		}
		rep(j, n) cerr << s_k(k, j) << ", "; cerr << endl;
		mint ans2 = bb.at(0, k + 1);
		cerr << "ans2 = " << ans2.get() << endl;
	}
//	*/
	long long powk = 1; int digits = 0;
	while(powk <= n / k) powk *= k, ++ digits;

	vector<Matrix> P(digits + 1);
	P[0] = getSingletonMatrix(k, 0);
	rer(i, 1, digits) {
		P[i] = Matrix::identity(k + 3);
		rep(j, k) {
			P[i] *= P[i-1];
			P[i] *= getRotateMatrix(k, -1);
		}
	}

	long long offset = 0;
	while(powk > 0) {
		int t = (int)((n - offset) / powk);
		rep(j, t) {
			int s = s_k(k, offset);
			b *= getRotateMatrix(k, -s);
			b *= P[digits];
			b *= getRotateMatrix(k, +s);
			offset += powk;
		}
		powk /= k;
		-- digits;
	}

	mint ans = b.at(0, k + 1);
	cout << ans.get() << endl;
	}
	return 0;
}