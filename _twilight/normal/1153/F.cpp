#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

template <typename T>
void pcopy(T* pst, const T* ped, T* pval) {
	for ( ; pst != ped; *(pst++) = *(pval++));
}

const int N = 4096;
const int Mod = 998244353;
const int bzmax = 19;
const int g = 3;

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a) {
	int x, y;
	exgcd(a, Mod, x, y);
	return (x < 0) ? (x + Mod) : (x);
}

template <const int Mod = :: Mod>
class Z {
	public:
		int v;
		
		Z() : v(0) {	}
		Z(int v) : v(v) {	}
		Z(ll x) : v(x % Mod) {	}
		
		Z operator + (Z b) {
			int x = v + b.v;
			return Z((x >= Mod) ? (x - Mod) : (x));
		}
		Z operator - (Z b) {
			int x = v - b.v;
			return Z((x < 0) ? (x + Mod) : (x));
		}
		Z operator * (Z b) {
			return Z(1ll * v * b.v);
		}
		Z operator ~ () {
			return inv(v);
		}
		Z operator -() {
			return Z(0) - *this;
		}
		
		Z& operator += (Z b) {
			return *this = *this + b;
		}
		Z& operator -= (Z b) {
			return *this = *this - b;
		}
		Z& operator *= (Z b) {
			return *this = *this * b;
		}

//		constexpr operator int () const {
//			return v;
//		}
};

typedef Z<> Zi;

Zi qpow(Zi a, int p) {
	if (p < Mod - 1)
		p += Mod - 1;
	Zi rt = 1, pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

class NTT {
	private:
		Zi gn[bzmax + 4], _gn[bzmax + 4];
	public:
		
		NTT() {
			for (int i = 0; i <= bzmax; i++) {
				gn[i] = qpow(Zi(g), (Mod - 1) >> i);
				_gn[i] = qpow(Zi(g), -((Mod - 1) >> i));
			}
		}

		void operator () (Zi* f, int len, int sgn) {
			for (int i = 1, j = len >> 1, k; i < len - 1; i++, j += k) {
				if (i < j)
					swap(f[i], f[j]);
				for (k = len >> 1; k <= j; j -= k, k >>= 1);
			}
			
			Zi *wn = (sgn > 0) ? (gn + 1) : (_gn + 1), w, a, b;
			for (int l = 2, hl; l <= len; l <<= 1, wn++) {
				hl = l >> 1, w = 1;
				for (int i = 0; i < len; i += l, w = 1) {
					for (int j = 0; j < hl; j++, w *= *wn) {
						a = f[i + j], b = f[i + j + hl] * w;
						f[i + j] = a + b;
						f[i + j + hl] = a - b;
					}
				}
			}

			if (sgn < 0) {
				Zi invlen = ~Zi(len);
				for (int i = 0; i < len; i++) {
					f[i] *= invlen;
				}
			}
		}

		int correct_len(int len) {
			int m = 1;
			for ( ; m <= len; m <<= 1);
			return m;
		}
} NTT;

void pol_inverse(Zi* f, Zi* g, int n) {
	static Zi A[N];
	if (n == 1) {
		g[0] = ~f[0];
	} else {
		int hn = (n + 1) >> 1, t = NTT.correct_len(n << 1 | 1);
		pol_inverse(f, g, hn);
		
		pcopy(A, A + n, f);
		pfill(A + n, A + t, Zi(0));
		pfill(g + hn, g + t, Zi(0));
		NTT(A, t, 1);
		NTT(g, t, 1);
		for (int i = 0; i < t; i++) {
			g[i] = g[i] * (Zi(2) - g[i] * A[i]);
		}
		NTT(g, t, -1);
		pfill(g + n, g + t, Zi(0));
	}
}

typedef vector<Zi> Poly;

Poly operator * (Poly A, Poly B) {
	int n = A.size(), m = B.size();
	int k = NTT.correct_len(n + m - 1);
	if (n < 20 || m < 20) {
		Poly rt (n + m - 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				rt[i + j] += A[i] * B[j];
			}
		}
		return rt;
	}
	A.resize(k), B.resize(k);
	NTT(A.data(), k, 1);
	NTT(B.data(), k, 1);
	for (int i = 0; i < k; i++) {
		A[i] *= B[i];
	}
	NTT(A.data(), k, -1);
	A.resize(n + m - 1);
	return A;
}

Zi fac[N], _fac[N];
Zi binom(int n, int m) {
	return (n < m) ? (0) : (fac[n] * _fac[n - m] * _fac[m]);
}
void init_fac(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	_fac[n] = ~fac[n];
	for (int i = n; i; i--) {
		_fac[i - 1] = _fac[i] * i;
	}
}

int n, K, L;

int main() {
	scanf("%d%d%d", &n, &K, &L);
	L %= Mod;
	init_fac(n << 1 | 1);
	
	Poly f (n + 1), g (_fac, _fac + n + 1);
	for (int i = 0; i <= n; i++) {
		if (i < K) {
			f[i] = 0;
		} else {
			f[i] = binom(n, i) * fac[n - i];
		}
	}
	for (int i = 1; i <= n; g[i] = -g[i], i += 2);
	f = f * g;
	Zi ans = 0, pw2 = 1;
	for (int i = 0; i <= n; i++, pw2 = pw2 + pw2) {
		f[i] = f[i] * _fac[n - i] * pw2;
		ans += f[i] * fac[i] * fac[i] * _fac[2 * i + 1];
	}
	ans *= L;
	printf("%d\n", ans.v);
	return 0;
}