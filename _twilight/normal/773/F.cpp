#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

template <typename T, typename Tv>
void pcopy(T* pst, const T* ped, Tv* pval) {
	for ( ; pst != ped; *(pst++) = *(pval++));
}

const int N = 65536;
const int bzmax = 18;

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

template <const int Mod>
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
			return inv(v, Mod);
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
};

template <typename Zi>
Zi qpow(Zi a, int p, int Mod) {
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

template <typename Zi, const int Mod, const int g>
class NTT {
	private:
		Zi gn[bzmax + 4], _gn[bzmax + 4];
	public:

		NTT() {
			for (int i = 0; i <= bzmax; i++) {
				gn[i] = qpow(Zi(g), (Mod - 1) >> i, Mod);
				_gn[i] = qpow(Zi(g), -((Mod - 1) >> i), Mod);
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
};

const int Mod1 = 998244353, Mod2 = 1004535809;
const ll Mall = 1ll * Mod1 * Mod2;
typedef Z<Mod1> Zi;
typedef Z<Mod2> Zn;
NTT<Zi, Mod1, 3> NTT1;
NTT<Zn, Mod2, 3> NTT2;

int n, M, Mod;

typedef vector<int> Poly;

Poly operator + (Poly a, Poly b) {
	if (a.size() < b.size())
		a.resize(b.size());
	for (int i = 0; i < (signed) b.size(); i++) {
		a[i] += b[i];
		(a[i] >= Mod) && (a[i] -= Mod);
	}
	return a;
}

Poly operator * (Poly a, Poly b) {
	int n = a.size(), m = b.size();
	int k = n + m - 1;
	if (n < 40 || m < 40) {
		vector<ll> ret (k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ret[i + j] += a[i] * b[j];
			}
		}
		for (auto& x : ret)
			x %= Mod;
		vector<int> rt (k);
		pcopy(rt.data(), rt.data() + k, ret.data());
		return rt;
	}
	int t = NTT1.correct_len(k);
	vector<Zi> a1 (t), b1 (t);
	vector<Zn> a2 (t), b2 (t);
	pcopy(a1.data(), a1.data() + n, a.data());
	pcopy(a2.data(), a2.data() + n, a.data());
	pcopy(b1.data(), b1.data() + m, b.data());
	pcopy(b2.data(), b2.data() + m, b.data());
	NTT1(a1.data(), t, 1);
	NTT1(b1.data(), t, 1);
	NTT2(a2.data(), t, 1);
	NTT2(b2.data(), t, 1);
	for (int i = 0; i < t; i++)
		a1[i] = a1[i] * b1[i];
	for (int i = 0; i < t; i++)
		a2[i] = a2[i] * b2[i];
	NTT1(a1.data(), t, -1);
	NTT2(a2.data(), t, -1);
	a.resize(k);
	ll inv1 = inv(Mod1 % Mod2, Mod2), inv2 = inv(Mod2 % Mod1, Mod1);
	for (int i = 0; i < k; i++) {
		a[i] = ((1ll * a1[i].v * inv2 % Mod1 * Mod2 + 1ll * a2[i].v * inv1 % Mod2 * Mod1) % Mall) % Mod;
	}
	return a;
}

Poly& fix(Poly& p, int size) {
	p.resize(size);
	return p;
}

int main() {
	scanf("%d%d%d", &n, &M, &Mod);
	n++;
	Poly f0, f1, g0, g1, g;
	f0.resize(n), f1.resize(n);
	f0[0] = 1, f1[0] = 1;
	ll ans = 0;
	int q = 29;
	while (!(M >> q)) q--;
	for ( ; q; q--) {
		g0 = f0, g1 = f1, g = g0 + g1;
		g[0] = 1;
		if (!((M >> (q + 1)) & 1)) {
			f0 = f0 * g, f1 = f1 * g;
			fix(f0, n), fix(f1, n);
		} else {
			f0 = g1 * g, f1 = g0 * g;
			fix(f0, n), fix(f1, n);
		}
		for (int i = 1; i <= n; i++) {
			f0[i] -= g1[i];
			f1[i] -= g0[i];
			(f0[i] < 0) && (f0[i] += Mod);
			(f1[i] < 0) && (f1[i] += Mod);
		}
		if ((M >> q) & 1) {
			for (int i = n; i; i--) {
				f1[i] += f0[i - 1] + f1[i - 1] - (i == 1);
				f1[i] %= Mod;
			}
		}
/*		cerr << "\nf1: ";
		for (int i = 0; i < n; i++)
			cerr << f1[i] << " ";
		cerr << "\nf0: ";
		for (int i = 0; i < n; i++)
			cerr << f0[i] << " ";
		cerr << '\n'; */
		for (int i = 1; i < n; i += 2) {
			ans += f1[i];
		}
	}
	ans %= Mod;
	printf("%d\n", (int) ans);
	return 0;
}