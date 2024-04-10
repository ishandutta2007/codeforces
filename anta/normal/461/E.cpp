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


struct SaturationMinPlus {
	typedef SaturationInt T;
	T t;
	explicit SaturationMinPlus(T x): t(x){}
	SaturationMinPlus(): t(T::Max) {}
	static SaturationMinPlus One() {
		return SaturationMinPlus(0);
	}
	inline bool isPlusInf() const { return t.get() == T::Max; }
	SaturationMinPlus operator+(const SaturationMinPlus& y) const {
		return SaturationMinPlus(min(t.get(), y.t.get()));
	}
	SaturationMinPlus &operator+=(const SaturationMinPlus& y) {
		if(t.get() > y.t.get()) t = y.t;
		return *this;
	}
	SaturationMinPlus operator*(const SaturationMinPlus& y) const {
		if(isPlusInf() || y.isPlusInf()) return SaturationMinPlus();
		else return SaturationMinPlus(t + y.t);
	}
};

struct Matrix {
	typedef SaturationMinPlus Num;
	vector<vector<Num> > v, w;
	Matrix() {}
	Matrix(int n, int m): v(n, vector<Num>(m)) { }
	inline int height() const { return (int)v.size(); }
	inline int width() const { return (int)v[0].size(); }
	inline Num& at(int i, int j) { return v[i][j]; }
	inline const Num& at(int i, int j) const { return v[i][j]; }
	static Matrix identity(int n) {
		Matrix A(n, n);
		rep(i, n) A.at(i, i) = Num::One();
		return A;
	}
	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
	Matrix& operator*=(const Matrix& B) {
		int n = height(), m = B.width(), p = B.height();
		assert(p == width());
		w.assign(n, vector<Num>(m, Num()));
		rep(i, n) rep(j, m) {
			Num x = Num();
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

int main() {
	long long n;
	cin >> n;
	char *t = new char[100001];
	scanf("%s", t);
	int len = strlen(t);
	const int MaxM = 12;
	const int Alphas = 4;
	vector<vector<int> > matrix(Alphas, vector<int>(Alphas, INF));
	rer(m, 1, MaxM) {
		vector<bool> ok(1 << (2 * m), false);
		rer(i, 0, len-m) {
			int x = 0;
			rep(j, m)
				x = x * Alphas + (t[i+j] - 'A');
			ok[x] = true;
		}
		rep(i, 1 << (2 * m)) if(!ok[i])
			amin(matrix[i >> (2 * m - 2) & 3][i & 3], m - 1);
	}
	Matrix A(Alphas, Alphas);
	rep(i, Alphas) rep(j, Alphas) {
//		cerr << char('A' + i) << " -> " << char('A' + j) << ": " << matrix[i][j] << endl;
		A.at(i, j) = SaturationMinPlus(matrix[i][j]);
	}
	long long ans;
	bool one = true;
	rep(i, Alphas) rep(j, Alphas)
		one &= matrix[i][j] >= n;
	if(one) {
		ans = 1;
	}else {
		//1
		long long l = 0, u = n;
		while(u - l > 0) {
			long long mid = (l + u) / 2;
			Matrix Apowmid = A ^ mid;
			SaturationMinPlus x;
			rep(i, Alphas) rep(j, Alphas)
				x += Apowmid.at(i, j);
//			cerr << mid << ": " << x.t.get() << endl;
			if(x.t.get() >= n) {
				u = mid;
			}else {
				l = mid + 1;
			}
		}
		ans = u;
	}
	cout << ans << endl;
	return 0;
}