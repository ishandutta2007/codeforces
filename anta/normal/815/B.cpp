#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) { }
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};
typedef ModInt<1000000007> mint;

vector<mint> fact, factinv;
void nCr_computeFactinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1); factinv.resize(N + 1);
	fact[0] = 1;
	rer(i, 1, N) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for (int i = N; i >= 1; i --) factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if (n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) * nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}
template<int MOD> int mintToSigned(ModInt<MOD> a) {
	int x = a.get();
	if (x <= MOD / 2)
		return x;
	else
		return x - MOD;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> A(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &A[i]);
		vector<mint> coeffs(n);
		nCr_computeFactinv(n);
		if (n % 4 == 2) {
			rep(j, n)
				coeffs[j] = nCr(n / 2 - 1, j / 2);
		} else if (n % 4 == 3) {
			vector<mint> C(n - 1);
			rep(j, n - 1)
				C[j] = nCr(n / 2 - 1, j / 2);
			coeffs[0] = 1;
			coeffs[n - 1] = -1;
			rep(j, n - 2)
				coeffs[j + 1] = j % 2 == 0 ? C[j] + C[j + 1] : C[j + 1] - C[j];
		} else if (n % 4 == 0) {
			rep(j, n)
				coeffs[j] = nCr(n / 2 - 1, j / 2) * (j % 2 == 0 ? 1 : -1);
		} else {
			rep(j, n)
				coeffs[j] = j % 2 == 0 ? nCr(n / 2, j / 2) : 0;
		}
		mint ans;
		rep(i, n)
			ans += coeffs[i] * A[i];
		printf("%d\n", ans.get());
	}
	return 0;
}