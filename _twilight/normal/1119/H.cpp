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

const int Mod = 998244353;

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		Z operator + (Z b) {
			int x;
			return Z(((x = v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		Z operator - (Z b) {
			int x;
			return Z(((x = v - b.v) < 0) ? (x + Mod) : (x));
		}
		Z operator * (Z b) {
			return Z(v * 1ll * b.v);
		}
		Z operator ~() {
			return inv(v, Mod);
		}
		Z operator - () {
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

template <typename T>
void fwt(T* f, int n) {
	int N = 1 << n;
	for (int i = 0; i < n; i++) {
		int hn = 1 << i, len = hn << 1;
		for (int j = 0; j < N; j += len) {
			for (int k = 0; k < hn; k++) {
				T a = f[j + k], b = f[j + k + hn];
				f[j + k] = a + b;
				f[j + k + hn] = a - b;
			}
		}
	}
}

const int N = 1 << 17;

namespace Main {

int n, m;
Zi ans[N];
int x, y, z;
int X[N], Y[N], Z[N];

int __main__() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &x, &y, &z);
	int xor_sum = 0;
	for (int i = 1, a, b, c; i <= n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		b ^= a, c ^= a, xor_sum ^= a;
		X[c]++, Y[b]++, Z[b ^ c]++;
	}
	fwt(X, m);
	fwt(Y, m);
	fwt(Z, m);
	int M = 1 << m;
	for (int i = 0; i < M; i++) {
		int ab = (X[i] + n) >> 1;
		int ac = (Y[i] + n) >> 1;
		int ad = (Z[i] + n) >> 1;
		int a = (ab + ac + ad - n) >> 1;
		int b = ab - a, c = ac - a, d = ad - a;
		ans[i] = qpow(Zi(x) + Zi(y) + Zi(z), a);
		ans[i] *= qpow(Zi(x) - Zi(y) + Zi(z), b);
		ans[i] *= qpow(Zi(x) + Zi(y) - Zi(z), c);
		ans[i] *= qpow(Zi(x) - Zi(y) - Zi(z), d);
	}
	fwt(ans, m);
	Zi inv_len = ~Zi(M);
	for (int i = 0; i < M; i++) {
		printf("%d ", (ans[i ^ xor_sum] * inv_len).v);
	}
	return 0;
}

}

int main() {
	return Main :: __main__();
}