#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


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
typedef ModInt<1000000007> mint;

vector<mint> fact, factinv;
void nCr_computeFactinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1); factinv.resize(N + 1);
	fact[0] = 1;
	rer(i, 1, N) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for(int i = N; i >= 1; i --) factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if(n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) * nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}

template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while(k) {
		if(k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		mint p;
		{
			int a; int b;
			scanf("%d%d", &a, &b);
			p = mint(a) / b;
		}
		int k;
		scanf("%d", &k);
		nCr_computeFactinv(max(k, m));
		vector<mint> ways(m);
		rep(i, m)
			ways[i] = nCr(k, i) * (p ^ i) * ((mint(1) - p) ^ (k - i));
		vector<mint> sumWays(m);
		sumWays[0] = ways[0];
		rep(i, m - 1)
			sumWays[i + 1] += sumWays[i] + ways[i + 1];
		vector<mint> dpTotal(n + 1);
		vector<vector<mint>> dpL(n + 1, vector<mint>(m + 1));
		vector<mint> sumProd(m + 1);
		dpTotal[0] = 1;
		rep(i, n) {
			for(int j = m - 1; j >= 0; -- j) {
				sumProd[j] = sumProd[j + 1];
				sumProd[j] += dpL[i][j + 1] * ways[m - 1 - j];
			}
			rep(nl, m) {
				mint sum;
				mint y = dpTotal[i] - dpL[i][m] * 2 + dpL[i][m - nl];
				sum += y * sumWays[m - 1 - nl];
				sum += sumProd[nl];
				sum *= ways[nl];
				dpL[i + 1][nl + 1] += sum;
				dpTotal[i + 1] += sum;
			}
			rep(j, m)
				dpL[i + 1][j + 1] += dpL[i + 1][j];
		}
		mint ans = dpTotal[n];
		printf("%d\n", ans.get());
	}
	return 0;
}