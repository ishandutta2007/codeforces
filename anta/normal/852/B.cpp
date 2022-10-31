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

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

int main() {
	int N; int L; int M;
	while (~scanf("%d%d%d", &N, &L, &M)) {
		vector<int> A(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &A[i]);
		vector<int> B(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &B[i]);
		vector<int> C(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &C[i]);
		vector<mint> res1(M);
		rep(k, N)
			res1[B[k] % M] += 1;
		auto mult = [M](const vector<mint> &v, const vector<mint> &w) {
			vector<mint> res(M);
			rep(i, M) rep(j, M)
				res[(i + j) % M] += v[i] * w[j];
			return res;
		};
		function<vector<mint>(int)> rec = [&rec, mult, M, res1, B](int L) -> vector<mint> {
			if (L == 0) {
				vector<mint> res(M);
				res[0] = 1;
				return res;
			}
			auto v = rec(L / 2);
			if (L % 2 == 0)
				return mult(v, v);
			else
				return mult(mult(v, v), res1);
		};
		vector<mint> dp0(M);
		rep(i, N)
			dp0[A[i] % M] += 1;
		auto prod = rec(L - 2);
		vector<mint> dplast = mult(dp0, prod);
		mint ans;
		rep(j, M) rep(k, N) if ((j + B[k] + C[k]) % M == 0)
			ans += dplast[j];
		printf("%d\n", ans.get());
	}
	return 0;
}