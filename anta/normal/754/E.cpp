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
typedef ModInt<2130706433> fft_mint;
const int OmegaMax = 23;
fft_mint OmegaPrim = 183;
fft_mint Omega[OmegaMax + 1];

void fft_init() {
	if (Omega[OmegaMax].get() != 0) return;
	fft_mint x = OmegaPrim;
	for (int i = OmegaMax; i >= 0; i --) {
		Omega[i] = x;
		x *= x;
	}
}
void fft_core(fft_mint a[], int logn, int sign) {
	fft_init();
	int n = 1 << logn;
	fft_mint ww = Omega[logn];
	if (sign == -1) ww = ww.inverse();
	for (int m = n, mi = 0; m >= 2; m >>= 1, mi ++) {
		int mh = m >> 1;
		fft_mint w = 1;
		rep(i, mh) {
			for (int j = i; j < n; j += m) {
				int k = j + mh;
				fft_mint x = a[j] - a[k];
				a[j] += a[k];
				a[k] = w * x;
			}
			w *= ww;
		}
		ww *= ww;
	}
	int i = 0;
	reu(j, 1, n - 1) {
		for (int k = n >> 1; k > (i ^= k); k >>= 1);
		if (j < i) swap(a[i], a[j]);
	}
}
using Ring = fft_mint;

void fft(int logn, Ring a[]) {
	fft_core(a, logn, +1);
}

void inverse_fft(int logn, Ring a[]) {
	fft_core(a, logn, -1);
	Ring inv = fft_mint(1 << logn).inverse();
	rep(i, 1 << logn)
		a[i] *= inv;
}

void FFT2D(int logh, int H, int logw, int W, vector<vector<Ring>> &A) {
	assert(A.size() == 1 << logh);
	rep(i, H) {
		assert(A[i].size() == 1 << logw);
		fft(logw, A[i].data());
	}
	vector<Ring> tmp(1 << logh);
	rep(j, 1 << logw) {
		rep(i, 1 << logh)
			tmp[i] = A[i][j];
		fft(logh, tmp.data());
		rep(i, 1 << logh)
			A[i][j] = tmp[i];
	}
}

void FFT2Dinv(int logh, int H, int logw, int W, vector<vector<Ring>> &A) {
	vector<Ring> tmp(1 << logh);
	rep(j, 1 << logw) {
		rep(i, 1 << logh)
			tmp[i] = A[i][j];
		inverse_fft(logh, tmp.data());
		rep(i, 1 << logh)
			A[i][j] = tmp[i];
	}
	rep(i, H)
		inverse_fft(logw, A[i].data());
}

int main() {
	int tH; int tW;
	while (~scanf("%d%d", &tH, &tW)) {
		vector<string> table(tH);
		rep(i, tH) {
			char buf[401];
			scanf("%s", buf);
			table[i] = buf;
		}
		int pH; int pW;
		scanf("%d%d", &pH, &pW);
		vector<string> pattern(pH);
		rep(i, pH) {
			char buf[401];
			scanf("%s", buf);
			pattern[i] = buf;
		}
		fft_init();
		vector<Ring> vec(26), invVec(26);
		rep(i, 26) {
			vec[i] = i + 1;
			invVec[i] = vec[i].inverse();
		}
		int H = tH + pH, W = tW + pW;
		int logh = 1, logw = 1;
		while (1 << logh < H) ++logh;
		while (1 << logw < W) ++logw;
		vector<vector<Ring>> A(1 << logh, vector<Ring>(1 << logw)), B = A;
		rep(i, tH + pH) rep(j, tW + pW) {
			char c = table[i % tH][j % tW];
			A[tH + pH - 1 - i][tW + pW - 1 - j] = vec[c - 'a'];
		}
		vector<vector<fft_mint>> randomCoeffs(pH, vector<fft_mint>(pW));
		{
			mt19937 rng{ random_device{}() };
			uniform_int_distribution<int> dist(1, fft_mint::Mod - 1);
			rep(i, pH) rep(j, pW)
				randomCoeffs[i][j] = dist(rng);
		}
		fft_mint expectedSum;
		rep(i, pH) rep(j, pW) {
			char c = pattern[i][j];
			if (c == '?') continue;
			fft_mint a = randomCoeffs[i][j];
			expectedSum += a;
			B[i][j] = a * invVec[c - 'a'];
		}
		FFT2D(logh, H, logw, W, A);
		FFT2D(logh, H, logw, W, B);
		rep(i, 1 << logh) rep(j, 1 << logw)
			A[i][j] *= B[i][j];
		FFT2Dinv(logh, H, logw, W, A);
		int qs = 0;
		rep(i, pH) rep(j, pW)
			qs += pattern[i][j] == '?';
		vector<string> ans(tH, string(tW, '?'));
		rep(i, tH) rep(j, tW) {
			Ring r = A[tH + pH - 1 - i][tW + pW - 1 - j];
			ans[i][j] = r.get() == expectedSum.get() ? '1' : '0';
		}
		rep(i, tH)
			puts(ans[i].c_str());
	}
	return 0;
}