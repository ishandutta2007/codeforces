#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned &out_m) {
	unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
#ifdef __GNUC__
	asm(
		"divl %4; \n\t"
		: "=a" (d), "=d" (m)
		: "d" (xh), "a" (xl), "r" (y)
	);
#else
	__asm {
		mov edx, dword ptr[xh];
		mov eax, dword ptr[xl];
		div dword ptr[y];
		mov dword ptr[d], eax;
		mov dword ptr[m], edx;
	};
#endif
	out_d = d; out_m = m;
}

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
	ModInt &operator*=(ModInt that) {
		unsigned dummy;
		fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, x);
		return *this;
	}
	ModInt operator*(ModInt that) const {
		ModInt res;
		unsigned dummy;
		fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, res.x);
		return res;
	}
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
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

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<998244353> mint;


typedef ModInt<998244353> fft_mint;
const int OmegaMax = 23;
fft_mint OmegaPrim = 31;
fft_mint Omega[OmegaMax + 1];

void fft_init() {
	if (Omega[OmegaMax].get() != 0) return;
	fft_mint x = OmegaPrim;
	for (int i = OmegaMax; i >= 0; i --) {
		Omega[i] = x;
		x *= x;
	}
}
//a
void fft_main(int logn, const bool inv, fft_mint a[]) {
	fft_init();
	int n = 1 << logn;
	fft_mint ww = Omega[logn];
	if (inv) ww = ww.inverse();
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

void fft(int logn, fft_mint a[]) { fft_main(logn, false, a); }
void inverse_fft(int logn, fft_mint a[]) {
	fft_main(logn, true, a);
	int n = 1 << logn;
	fft_mint invn = fft_mint(n).inverse();
	rep(i, n) a[i] *= invn;
}

//v, wv
//v, w 2^logn, lognceil(log_2(size(v) + size(w)))
void convolution(fft_mint v[], fft_mint w[], int logn) {
	fft(logn, v); fft(logn, w);
	rep(i, 1 << logn) v[i] *= w[i];
	inverse_fft(logn, v);
}

template<typename Mat>
Mat operator^(const Mat& t, ll k) {
	Mat A = t, B = Mat::identity(t);
	while (k) {
		if (k & 1) {
			B *= A;
		}
		A *= A;
		k >>= 1;
	}
	return B;
}

struct UTToeplitzMatrix {
	using Num = mint;
	vector<Num> v;
	mint coeffs[1 << 16];
	UTToeplitzMatrix() {}
	UTToeplitzMatrix(int n, int m) : v(n, 0) {
		(void)m; assert(n == m); assert(n > 0);
	}
	inline int size() const { return (int)v.size(); }
	inline int height() const { return size(); }
	inline int width() const { return size(); }
	inline Num& at(int i) { assert(0 <= i && i < size()); return v[i]; }
	inline const Num& at(int i) const { assert(0 <= i && i < size()); return v[i]; }
	inline Num& at(int i, int j) {
		assert(0 <= i && i < size() && 0 <= j && j < size());
		assert(i <= j);	
		return v[j - i];
	}
	inline const Num& at(int i, int j) const {
		assert(0 <= i && i < size() && 0 <= j && j < size());
		if (i > j) return mint();	
		return v[j - i];
	}
	static UTToeplitzMatrix identity(int n) {
		UTToeplitzMatrix A(n, n);
		A.at(0) = 1;
		return A;
	}
	inline static UTToeplitzMatrix identity(const UTToeplitzMatrix& A) { return identity(A.size()); }
};

struct BlockMatrix {
	typedef UTToeplitzMatrix Block;
	vector<vector<Block> > blocks;
	vector<int> heights, widths;
	BlockMatrix(const vector<int>& hs, const vector<int>& ws)
		: heights(hs), widths(ws) {
		int n = heights.size(), m = widths.size();
		assert(n > 0 && m > 0);
		blocks.resize(n);
		rep(i, n) rep(j, m)
			blocks[i].push_back(Block(heights[i], widths[j]));
	}
	inline int height() const { return heights.size(); }
	inline int width() const { return widths.size(); }
	inline int blockHeight(int i) const { assert(0 <= i && i < height()); return blocks[i][0].height(); }
	inline int blockWidth(int j) const { assert(0 <= j && j < width()); return blocks[0][j].width(); }
	inline Block& at(int i, int j) { assert(0 <= i && i < height() && 0 <= j && j < width()); return blocks[i][j]; }
	inline const Block& at(int i, int j) const { assert(0 <= i && i < height() && 0 <= j && j < width()); return blocks[i][j]; }
	static BlockMatrix identity(int n, int m) {
		vector<int> v;
		rep(i, n) v.push_back(m);
		BlockMatrix A(v, v);
		rep(i, n) A.at(i, i) = Block::identity(m);
		return A;
	}
	inline static BlockMatrix identity(const BlockMatrix& A) {
		int n = A.height(); assert(n == A.width());
		int m = A.heights[0];
		assert(count(A.heights.begin(), A.heights.end(), m) == n);
		assert(count(A.widths.begin(), A.widths.end(), m) == n);
		return identity(n, m);
	}
	BlockMatrix& operator*=(const BlockMatrix& B) {
		int n = (int)at(0, 0).v.size();
		int logn = 1;
		while (1 << logn < n * 2) ++ logn;
		static mint coeffs[2][2][2][1 << 16];
		memset(coeffs, 0, sizeof(coeffs));
		rep(a, 2) rep(b, 2) {
			rep(i, n)
				coeffs[0][a][b][i] = at(a, b).v[i];
			fft(logn, coeffs[0][a][b]);
			rep(i, n)
				coeffs[1][a][b][i] = B.at(a, b).v[i];
			fft(logn, coeffs[1][a][b]);
		}
		static mint sum[2][2][1 << 16];
		memset(sum, 0, sizeof(sum));
		rep(a, 2) rep(b, 2) {
			rep(c, 2) {
				mint *x = coeffs[0][a][c], *y = coeffs[1][c][b];
				rep(i, 1 << logn)
					sum[a][b][i] += x[i] * y[i];
			}
		};
		rep(a, 2) rep(b, 2) {
			inverse_fft(logn, sum[a][b]);
			rep(i, n)
				at(a, b).v[i] = sum[a][b][i];
		}
		return *this;
	}
};

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		int K = max(k + 1, 2);
		BlockMatrix A({ K, K }, { K, K });
		A.at(0, 0).at(0) = 1;
		A.at(0, 0).at(1) = 1;
		A.at(0, 1).at(0) = 1;
		A.at(1, 0).at(1) = 1;
		A = A ^ n;
		rer(j, 1, k) {
			if (j != 1) putchar(' ');
			mint x = A.at(0, 0).at(j);
			printf("%d", x.get());
		}
		puts("");
	}
	return 0;
}