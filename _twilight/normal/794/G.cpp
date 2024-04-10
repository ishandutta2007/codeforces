#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

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

const int Mod = 1e9 + 7;

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

Z<> qpow(Z<> a, int p) {
	Z<> rt = Z<>(1), pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

typedef Z<> Zi;

const int N = 3e5 + 5;

int gcd(int a, int b) {
	return ((b) ? (gcd(b, a % b)) : (a));
}

Zi fac[N << 1], _fac[N << 1];
void init_fac(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i;
	_fac[n] = ~fac[n];
	for (int i = n; i; i--)
		_fac[i - 1] = _fac[i] * i;
}
Zi comb(int n, int m) {
	return (n < m) ? (0) : (fac[n] * _fac[m] * _fac[n - m]);
}

int n, c1, c2;
char A[N], B[N];
Zi mu[N], pw2[N];

int main() {
	scanf("%s%s%d", A + 1, B + 1, &n);
	mu[1] = 1;
	for (int i = 1; i < n; i++) {
		if (mu[i].v) {
			for (int j = i << 1; j <= n; j += i) {
				mu[j] -= mu[i];
			}
		}
	}
	pw2[0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		pw2[i] = pw2[i - 1] + pw2[i - 1];
	}
	int lena = strlen(A + 1);
	int lenb = strlen(B + 1);
	init_fac(lena + lenb + 1);
	Zi weq = 1;
	if (lena == lenb) {
		for (int i = 1; i <= lena; i++) {
			if (A[i] == '?') {
				if (B[i] == '?') {
					weq = weq + weq;
				}
			} else {
				if (A[i] != B[i] && B[i] != '?') {
					weq = 0;
					break;
				}
			}
		} 
	} else {
		weq = 0;
	}
	int d1 = 0, d2 = 0;
	for (char* x = A + 1; *x; x++) {
		c1 += (*x == '?');
		d1 += (*x == 'A');
		d2 += (*x == 'B');
	}
	for (char* x = B + 1; *x; x++) {
		c2 += (*x == '?');
		d1 -= (*x == 'A');
		d2 -= (*x == 'B');
	}
	Zi ans = 0, tmp = 0, coef = 0;
	for (int d = 1; d <= n; d++) {
		for (int e = 1, T = d; T <= n; T += d, e++) {
			int x = n / T;
			tmp += mu[e] * x * x * pw2[d];	
		}
	}
	for (int k = -c2, da, db; k <= c1; k++) {
		if (1ll * (da = d1 + k) * (db = d2 + c1 - c2 - k) < 0) {
			(da < 0) ? (da = -da) : (db = -db);
			ans += comb(c1 + c2, k + c2) * (pw2[n / (max(da, db) / gcd(da, db)) + 1] - 2);
		}
		if (!da && !db) {
			coef += comb(c1 + c2, k + c2);
		}
	}
	coef -= weq;
	ans += tmp * coef + (pw2[n + 1] - 2) * (pw2[n + 1] - 2) * weq;
	printf("%d\n", ans.v);
	return 0;
}