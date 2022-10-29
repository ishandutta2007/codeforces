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

const Zi inv2 ((Mod + 1) >> 1);

const int N = 5005;

int n, K;
Zi zn;
Zi pw2[N], F[N];
Zi fac[N], _fac[N], facn[N];

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

int main() {
	scanf("%d%d", &n, &K);
	init_fac(K);
	if (n <= K) {
		Zi ans = 0, Cn = 1;
		for (int i = 1; i <= n; i++) {
			ans += (Cn *= (n - i + 1)) * _fac[i] * qpow(i, K);
		}
		printf("%d\n", ans.v);
		return 0;
	}
	zn = n % Mod;
	facn[0] = zn - K;
	for (int i = 1; i <= K; i++)
		facn[i] = facn[i - 1] * (n - K + i);
	pw2[0] = 1, pw2[1] = -inv2;
	for (int i = 2; i <= K; i++)
		pw2[i] = pw2[i - 1] * pw2[1];
	F[K] = 1;
	for (int i = K; i; i--)
		F[i - 1] = F[i] * inv2 + facn[K - i] * _fac[K - i + 1] * pw2[K - i + 1];
	Zi ans = 0, Cn = 1;
	for (int i = 0; i <= K; i++) {
		ans += Cn * _fac[i] * ((i & 1) ? (-pw2[i]) : (pw2[i])) * qpow(i, K) * F[i];
		Cn *= (n - i);
	}
	ans *= qpow(2, n);
	printf("%d\n", ans.v);
	return 0;
}