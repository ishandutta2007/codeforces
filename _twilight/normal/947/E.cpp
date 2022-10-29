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

const int N = 262144;
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

int inv(int a, int Mod) {
	int x, y;
	exgcd(a, Mod, x, y);
	return (x < 0) ? (x + Mod) : (x);
}

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		friend Z operator + (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		friend Z operator - (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
		}
		friend Z operator * (const Z& a, const Z& b) {
			return Z(a.v * 1ll * b.v);
		}
		friend Z operator ~ (const Z& a) {
			return inv(a.v, Mod);
		}
		friend Z operator - (const Z& a) {
			return Z(0) - a;
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
		friend boolean operator == (const Z& a, const Z& b) {
			return a.v == b.v;
		} 
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

const Zi inv2 ((Mod + 1) >> 1);

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

typedef class Poly : public vector<Zi> {
	public:
		using vector<Zi>::vector;

		Poly& fix(int sz) {
			resize(sz);
			return *this;
		}
} Poly;

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
void init_fac(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i;
	_fac[n] = ~fac[n];
	for (int i = n; ~i; i--)
		_fac[i - 1] = _fac[i] * i;
}

// G(x) = F(x + d)
Poly pol_mov(Poly f, Zi d) {
	int n = f.size();
	Poly a (n);
	Zi pw = 1;
	for (int i = 0; i < n; i++, pw *= d)
		a[i] = pw * _fac[i];
	for (int i = 0; i < n; i++) {
		f[i] = f[i] * fac[i];
	}
	reverse(a.begin(), a.end());
	f = a * f;
	for (int i = 0; i < n; i++) {
		a[i] = f[i + n - 1] * _fac[i];
	}
	return a;
}

int n;
ll M;

int main() {
	scanf("%d%lld", &n, &M);
	M %= Mod - 1;
	Poly f (++n);
	init_fac(n + 1);
	for (auto &x : f)
		scanf("%d", &x.v);
	f = pol_mov(f, 1);
	for (int i = 0; i < n; i++)
		f[i] *= qpow(~Zi(i + 1), M);
	f = pol_mov(f, Mod - 1);
	for (auto x : f)
		printf("%d ", x.v);
	return 0;
}