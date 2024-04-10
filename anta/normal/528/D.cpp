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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
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

typedef ModInt<998244353> fft_mint;
const int OmegaMax = 23;
fft_mint OmegaPrim = 31;
fft_mint Omega[OmegaMax+1];

void fft_init() {
	if(Omega[OmegaMax].get() != 0) return;
	fft_mint x = OmegaPrim;
	for(int i = OmegaMax; i >= 0; i --) {
		Omega[i] = x;
		x *= x;
	}
}
//a
void fft_main(int logn, const bool inv, fft_mint a[]) {
	fft_init();
	int n = 1 << logn;
	fft_mint ww = Omega[logn];
	if(inv) ww = ww.inverse();
	for(int m = n, mi = 0; m >= 2; m >>= 1, mi ++) {
		int mh = m >> 1;
		fft_mint w = 1;
		rep(i, mh) {
			for(int j = i; j < n; j += m) {
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
	reu(j, 1, n-1) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1) ;
		if(j < i) swap(a[i], a[j]);
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
	rep(i, 1<<logn) v[i] *= w[i];
	inverse_fft(logn, v);
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	char *S = new char[n+1], *T = new char[m+1];
	scanf("%s", S);
	scanf("%s", T);

	if(n < m) {
		puts("0");
		return 0;
	}
	
	vector<bool> match(n);
	rep(i, n)
		match[i] = i + m <= n;
	rep(ai, 4) {
		char a = "ATGC"[ai];
		vector<int> cnt(n+1, 0);
		rep(i, n) if(S[i] == a) {
			++ cnt[max(0, i - k)];
			-- cnt[min(n, i + k + 1)];
		}
		rep(i, n) cnt[i+1] += cnt[i];
		int P = 1, logP = 0;
		while(P < n + m) P <<= 1, logP ++;
		vector<fft_mint> A(P);
		rep(i, m) A[i] = T[i] == a ? 1 : 0;
		vector<fft_mint> B(P);
		rep(i, n) B[i] = cnt[i] > 0 ? 1 : 0;
//		cerr << "alpha = " << a << ":" << endl;
//		cerr << "A = "; rep(i, n) cerr << A[i].get() << ", "; cerr << endl;
//		cerr << "B = "; rep(i, m) cerr << B[i].get() << ", "; cerr << endl;
		reverse(B.begin(), B.begin() + n);
		convolution(&A[0], &B[0], logP);
		int c = count(T, T + m, a);
//		cerr << "C = "; rep(i, n) cerr << A[n-1-i].get() << ", "; cerr << endl;
//		cerr << "c = " << c << endl;
		rep(i, n) {
			//S[i]T = A'[n-1-i]
			bool b = A[n-1-i].get() == c;
			match[i] = match[i] && b;
		}
	}
	int ans = count(all(match), true);
	printf("%d\n", ans);
	return 0;
}