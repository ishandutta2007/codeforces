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
typedef ModInt<1000003> mint;


#pragma region for precomputing
int berlekampMassey(const vector<mint> &s, vector<mint> &C) {
	int N = (int)s.size();
	C.assign(N + 1, mint());
	vector<mint> B(N + 1, mint());
	C[0] = B[0] = 1;
	int degB = 0;
	vector<mint> T;
	int L = 0, m = 1;
	mint b = 1;
	for(int n = 0; n < N; ++ n) {
		mint d = s[n];
		for(int i = 1; i <= L; ++ i)
			d += C[i] * s[n - i];
		if(d == mint()) {
			++ m;
		} else {
			if(2 * L <= n)
				T.assign(C.begin(), C.begin() + (L + 1));
			mint coeff = -d * b.inverse();
			for(int i = 0; i <= degB; ++ i)
				C[m + i] += coeff * B[i];
			if(2 * L <= n) {
				L = n + 1 - L;
				B.swap(T);
				degB = (int)B.size() - 1;
				b = d;
				m = 1;
			} else {
				++ m;
			}
		}
	}
	C.resize(L + 1);
	return L;
}

void computeMinimumPolynomialForLinearlyRecurrentSequence(const vector<mint> &a, vector<mint> &phi) {
	int n2 = (int)a.size(), n = n2 / 2;
	assert(n2 % 2 == 0);
	int L = berlekampMassey(a, phi);
	reverse(phi.begin(), phi.begin() + (L + 1));
}

#pragma endregion

mint linearlyRecurrentSequenceValue(long long K, const vector<mint> &initValues, const vector<mint> &annPoly) {
	assert(K >= 0);
	if(K < (int)initValues.size())
		return initValues[(int)K];
	int d = (int)annPoly.size() - 1;
	assert(d >= 0);
	assert(annPoly[d].get() == 1);
	assert(d <= (int)initValues.size());
	if(d == 0)
		return mint();
	vector<mint> coeffs(d), square;
	coeffs[0] = 1;
	int l = 0;
	while((K >> l) > 1) ++ l;
	for(; l >= 0; -- l) {
		square.assign(d * 2 - 1, mint());
		for(int i = 0; i < d; ++ i)
			for(int j = 0; j < d; ++ j)
				square[i + j] += coeffs[i] * coeffs[j];
		for(int i = d * 2 - 2; i >= d; -- i) {
			mint c = square[i];
			if(c.x == 0) continue;
			for(int j = 0; j < d; ++ j)
				square[i - d + j] -= c * annPoly[j];
		}
		for(int i = 0; i < d; ++ i)
			coeffs[i] = square[i];
		if(K >> l & 1) {
			mint lc = coeffs[d - 1];
			for(int i = d - 1; i >= 1; -- i)
				coeffs[i] = coeffs[i - 1] - lc * annPoly[i];
			coeffs[0] = mint() - lc * annPoly[0];
		}
	}
	mint res;
	for(int i = 0; i < d; ++ i)
		res += coeffs[i] * initValues[i];
	return res;
}

mint linearlyRecurrentSequenceValue(long long K, const pair<vector<mint>, vector<mint> > &seqPair) {
	return linearlyRecurrentSequenceValue(K, seqPair.first, seqPair.second);
}
int main() {
	int C; int W; int H;
	while(~scanf("%d%d%d", &C, &W, &H)) {
		int N = W * 2 + 10;
		vector<mint> dp(N);
		dp[0] = 1;
		reu(i, 1, N) {
			mint x;
			mint y = 1;
			rer(j, 0, min(W, i)) {
				x += (i == j ? 1 : dp[i - 1 - j]) * y;
				y *= H;
			}
			dp[i] = x;
		}
		vector<mint> phi;
		computeMinimumPolynomialForLinearlyRecurrentSequence(dp, phi);
		mint ans = linearlyRecurrentSequenceValue(C, dp, phi);
		printf("%d\n", ans.get());
	}
	return 0;
}