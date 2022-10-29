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

const int N = 5e3 + 5;

int n, k;
Zi a[N];
Zi f[N];

int main() {
	scanf("%d%d", &n, &k);
	Zi prod = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].v);
		prod = prod * a[i];
	}
	
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j; j--) {
			f[j] += f[j - 1] * a[i];
		}
	}
	
	Zi ans = 0, tmp, P = 1;
	for (int i = 0; i <= n && i <= k; i++) {
		tmp = qpow(n, k - i) * f[n - i] * P;
		if (i & 1)
			tmp = -tmp;
		ans += tmp;
		P = P * (k - i);
	}
	ans = prod - ans * ~qpow(n, k);
	printf("%d\n", ans.v);
	return 0;
}