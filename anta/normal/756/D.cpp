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

template<typename T>
vector<pair<T, int> > runLength(const T a[], int n) {
	vector<pair<T, int> > r;
	if (n <= 0) return r;
	int cnt = 0;
	for (int i = 0; i <= n; i ++) {
		if (i == n || (i != 0 && a[i] != a[i - 1])) {
			r.push_back(make_pair(a[i - 1], cnt));
			cnt = 0;
		}
		cnt ++;
	}
	return r;
}

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

int main() {
	int n;
	while (~scanf("%d", &n)) {
		char S[5001];
		scanf("%s", S);
		auto runs = runLength(S, n);
		int k = (int)runs.size();
		const int A = 26;
		vector<mint> dp(k + 1);
		vector<vector<mint>> buckets(k + 1, vector<mint>(A));
		dp[0] = 1;
		for (auto run : runs) {
			int a = run.first - 'a';
			for (int j = k - 1; j >= 0; -- j) {
				mint x = dp[j];
				if (x.x == 0) continue;
				mint y = x;
				y -= buckets[j][a];
				y -= buckets[j + 1][a];
				buckets[j + 1][a] += y;
				dp[j + 1] += y;
			}
		}
		nCr_computeFactinv(n);
		mint ans;
		rer(j, 1, k)
			ans += nCr(n - 1, j - 1) * dp[j];
		printf("%d\n", ans.get());
	}
	return 0;
}