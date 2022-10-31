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

vector<bool> isprime;
vector<int> primes;
void sieve(int n) {
	if((int)isprime.size() >= n + 1) return;
	isprime.assign(n + 1, true);
	isprime[0] = isprime[1] = false;
	int sqrtn = (int)(sqrt(n * 1.) + .5);
	for(int i = 2; i <= sqrtn; i ++) if(isprime[i]) {
		for(int j = i * i; j <= n; j += i)
			isprime[j] = false;
	}
	primes.clear();
	for(int i = 2; i <= n; i ++) if(isprime[i])
		primes.push_back(i);
}

vector<int> mobiusMu;
void calcMobiusMu() {
	int n = (int)isprime.size() - 1;
	mobiusMu.assign(n + 1, 1);
	for(int i = 2; i <= n; i ++) if(isprime[i]) {
		if((ll)i * i <= n) {
			for(int j = i * i; j <= n; j += i * i)
				mobiusMu[j] = 0;
		}
		for(int j = i; j <= n; j += i)
			mobiusMu[j] *= -1;
	}
}


int main() {
	int n; int k; int q;
	while(~scanf("%d%d%d", &n, &k, &q)) {
#if defined(_DEBUG)
		const int A = 1000;
#else
		const int A = 1000000;
#endif
		sieve(A);
		calcMobiusMu();
		nCr_computeFactinv(n + q);
		vector<vi> divs(A + 1);
		rer(i, 1, A) for(int j = i; j <= A; j += i)
			divs[j].push_back(i);
		vector<mint> coeff(A + 1);
		rer(i, 1, A) for(int j = i; j <= A; j += i)
			coeff[j] += mobiusMu[j / i] * i;
		vector<int> divcnt(A + 1);
		mint ans;
		rep(i, n + q) {
			int a;
			scanf("%d", &a);

			//\sum_{d | a} d * \sum_{d | f | a} mu(f / d) C(divcnt[f], k - 1)
			mint sum;
			for(int f : divs[a])
				sum += nCr(divcnt[f], k - 1) * coeff[f];

			for(int d : divs[a])
				++ divcnt[d];

			ans += sum;

			if(i >= n)
				printf("%d\n", ans.get());
		}
	}
	return 0;
}