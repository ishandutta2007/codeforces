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

const int bzmax = 60;

int n, m;

typedef class LinearBasis {
	public:
		ll a[bzmax];

		LinearBasis() {
			memset(a, 0, sizeof(a));
		}

		bool insert(ll x) {
			for (int i = m; i-- && x; ) {
				if ((x >> i) & 1) {
					x ^= a[i];
				}
				if ((x >> i) & 1) {
					a[i] = x;
					for (int j = i - 1; ~j; j--) {
						if ((a[i] >> j) & 1) {
							a[i] ^= a[j];
						}
					}
					for (int j = i + 1; j < m; j++) {
						if ((a[j] >> i) & 1) {
							a[j] ^= a[i];
						}
					}
					return true;
				}
			}
			return false;
		}

		LinearBasis dual() {
			LinearBasis rt;
			for (int i = m; i--; ) {
				if (!a[i]) {
					ll x = 1ll << i;
					for (int j = i + 1; j < m; j++) {
						if ((a[j] >> i) & 1) {
							x |= 1ll << j;
						}
					}
					rt.insert(x);
				}
			}
			return rt;
		}
} LinearBasis;

LinearBasis lb;

vector<Zi> calc(LinearBasis& lb) {
	vector<ll> a;
	for (int i = 0; i < m; i++) {
		if (lb.a[i]) {
			a.push_back(lb.a[i]);
		}
	}
	int sz = a.size();
	int half = sz >> 1;
	vector<ll> vl (1 << half, 0ll), vr (1 << (sz - half), 0ll);
	for (int s = 0, _ = 1 << half; s < _; s++) {
		for (int i = 0; i < half; i++) {
			if ((s >> i) & 1) {
				vl[s] ^= a[i];
			}
		}
	}
	for (int s = 0, _ = 1 << (sz - half); s < _; s++) {
		for (int i = 0; i < sz - half; i++) {
			if ((s >> i) & 1) {
				vr[s] ^= a[i + half];
			}
		}
	}
	vector<int> rt (m + 1, 0);
	int msk = (1 << half) - 1;
	for (int s = 0, _ = 1 << sz; s < _; s++) {
		rt[__builtin_popcountll(vl[s & msk] ^ vr[s >> half])]++;
	}
	vector<Zi> _rt (m + 1);
	for (int i = 0; i <= m; i++) {
		_rt[i] = rt[i];
	}
	return _rt;
}

Zi f[60][60];

int main() {
	scanf("%d%d", &n, &m);
	int rk = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		rk += lb.insert(x);
	}
	vector<Zi> ans;
	if (rk * 2 <= m) {
		ans = calc(lb);	
	} else {
		lb = lb.dual();
		auto v = calc(lb);
		f[0][0] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = i; j; j--) {
				f[0][j] += f[0][j - 1];
			}
		}
		for (int i = 1; i <= m; i++) {
			memcpy(f[i], f[i - 1], sizeof(Zi) * (m + 1));
			for (int j = 1; j <= m; j++) {
				f[i][j] -= f[i][j - 1];
			}
			for (int j = m; j; j--) {
				f[i][j] -= f[i][j - 1];
			}
		}
		ans.resize(m + 1, Zi(0));
		for (int k = 0; k <= m; k++) {
			for (int c = 0; c <= m; c++) {
				ans[k] += f[c][k] * v[c];
			}
		}
		Zi coef = ~qpow(2, m - rk);
		for (auto& x : ans) {
			x *= coef;
		}
	}
	Zi coef = qpow(2, n - rk);
	for (auto x : ans) {
		x *= coef;
		printf("%d ", x.v);
	}
	return 0;
}