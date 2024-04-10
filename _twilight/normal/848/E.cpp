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

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}

const int N = 131072;
const int Mod = 998244353;
const int bzmax = 19;
const int g = 3;

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
		friend Z operator ~(const Z& a) {
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

		template <typename T>
		void operator () (T* f, int len, int sgn) {
			for (int i = 1, j = len >> 1, k; i < len - 1; i++, j += k) {
				if (i < j)
					swap(f[i], f[j]);
				for (k = len >> 1; k <= j; j -= k, k >>= 1);
			}
			
			Zi *wn = (sgn > 0) ? (gn + 1) : (_gn + 1), w;
			T a, b;
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
					f[i] = f[i] * invlen;
				}
			}
		}

		int correct_len(int len) {
			int m = 1;
			for ( ; m <= len; m <<= 1);
			return m;
		}
} NTT;

template <typename T>
void pol_inverse(T* f, T* g, int n) {
	static T A[N];
	if (n == 1) {
		g[0] = ~f[0];
	} else {
		int hn = (n + 1) >> 1, t = NTT.correct_len(n << 1 | 1);
		pol_inverse(f, g, hn);
		
		pcopy(A, A + n, f);
		pfill(A + n, A + t, T(0));
		pfill(g + hn, g + t, T(0));
		NTT(A, t, 1);
		NTT(g, t, 1);
		for (int i = 0; i < t; i++) {
			g[i] = g[i] * (T(2) - g[i] * A[i]);
		}
		NTT(g, t, -1);
		pfill(g + n, g + t, T(0));
	}
}

typedef vector<Zi> Poly;

Poly operator + (Poly A, Poly B) {
	int n = A.size(), m = B.size();
	int t = max(n, m);
	A.resize(t), B.resize(t);
	for (int i = 0; i < t; i++) {
		A[i] += B[i];
	}
	return A;
}

Poly operator - (Poly A, Poly B) {
	int n = A.size(), m = B.size();
	int t = max(n, m);
	A.resize(t), B.resize(t);
	for (int i = 0; i < t; i++) {
		A[i] -= B[i];
	}
	return A;
}

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

Poly operator ~ (Poly f) {
	int n = f.size(), t = NTT.correct_len((n << 1) | 1);
	Poly rt (t);
	f.resize(t);
	pol_inverse(f.data(), rt.data(), n);
	rt.resize(n);
	return rt;
}

typedef class Matrix {
	public:
		Zi a[2][2];

		Matrix() {	}
		Matrix(int x) {
			a[0][0] = a[1][1] = x;
			a[0][1] = a[1][0] = 0;
		}
		
		Zi* operator [] (int p) {
			return a[p];
		}
		Matrix operator * (Matrix b) {
			Matrix rt;
			rt[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
			rt[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
			rt[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
			rt[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
			return rt;
		}
		Matrix operator - (Matrix b) {
			Matrix rt;
			rt[0][0] = a[0][0] - b[0][0];
			rt[0][1] = a[0][1] - b[0][1];
			rt[1][0] = a[1][0] - b[1][0];
			rt[1][1] = a[1][1] - b[1][1];
			return rt;
		}
		Matrix operator + (Matrix b) {
			Matrix rt;
			rt[0][0] = a[0][0] + b[0][0];
			rt[0][1] = a[0][1] + b[0][1];
			rt[1][0] = a[1][0] + b[1][0];
			rt[1][1] = a[1][1] + b[1][1];
			return rt;
		}
		Matrix operator * (Zi x) {
			Matrix rt;
			rt[0][0] = a[0][0] * x;
			rt[0][1] = a[0][1] * x;
			rt[1][0] = a[1][0] * x;
			rt[1][1] = a[1][1] * x;
			return rt;
		}
} Matrix;

#define g _g

int n;
Zi dp[N][2][2];
Matrix f[N], g[N], G[N];

int main() {

	scanf("%d", &n);
	for (int s = 0; s < 2; s++) {
		memset(dp, 0, sizeof(dp));
		dp[1][0][0] = g[1][s][0] = (s == 1);
		dp[1][0][1] = g[1][s][1] = (s == 0);
		for (int i = 2; i < n; i++) {
			dp[i][0][0] = dp[i - 1][0][1] + dp[i - 1][1][0];
			dp[i][0][1] = dp[i - 1][0][0];
			dp[i][1][0] = dp[i - 1][1][1];
			dp[i][1][1] = dp[i - 1][0][1];
			g[i][s][0] = dp[i][0][0] * i * i;
			g[i][s][1] = dp[i][0][1] * i * i;
		}
	}
	
	Zi ans = 0;
	/* for (int s = 0; s < 2; s++) {
		f[1][s][s] = 1;
		for (int i = 2; i < n; i++) {
			for (int j = 0; j < i; j++) {
				f[i][s][0] += f[i - j - 1][s][1] * g[j][1][0];
				f[i][s][0] += f[i - j - 1][s][0] * g[j][0][0];
				f[i][s][1] += f[i - j - 1][s][1] * g[j][1][1];
				f[i][s][1] += f[i - j - 1][s][0] * g[j][0][1];
			}
		}
	} */

	for (int i = 1; i <= n; i++) {
		G[i] = g[i - 1] * Zi(Mod - 1);
	}
	G[0] = Matrix(1);
//	pol_inverse(G, f, n + 1);
	Poly A (n + 1), B(n + 1), C(n + 1), D(n + 1);
	for (int i = 0; i <= n; i++) {
		A[i] = G[i][0][0];
		B[i] = G[i][0][1];
		C[i] = G[i][1][0];
		D[i] = G[i][1][1];
	}
	Poly _A = D, _B = B * Poly {Mod - 1}, _C = C * Poly {Mod - 1}, _D = A;
	Poly E = A * D - B * C;
	E.resize(n + 1);
	E = ~E;
	_A = _A * E;
	_B = _B * E;
	_C = _C * E;
	_D = _D * E;
	for (int i = 1; i <= n; i++) {
		f[i][0][0] = _A[i - 1];
		f[i][0][1] = _B[i - 1];
		f[i][1][0] = _C[i - 1];
		f[i][1][1] = _D[i - 1];
	}

	for (int i = 1; i < n; i++) {
		if (i != n - 1) {
			ans += f[n - i][0][0] * g[i][0][0] * (i + 1);
			ans += f[n - i][0][1] * g[i][1][0] * (i + 1);
			ans += f[n - i][1][0] * g[i][0][1] * (i + 1);
			ans += f[n - i][1][1] * g[i][1][1] * (i + 1);
		} else {
			ans += g[i][0][0] * (i + 1);
			ans += g[i][1][1] * (i + 1);
		}
	}
	printf("%d\n", ans.v);
	return 0;
}