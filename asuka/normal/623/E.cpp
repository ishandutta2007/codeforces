#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int r = 1;
	for (; b; b >>= 1, a = (ll) a * a % mod)
		if (b & 1) r = (ll) r * a % mod;
	return r;
}

namespace Conv {
	using db = double;
	const db PI = acos(-1);

	struct cp {
		db x, y;
		cp(db _x = 0, db _y = 0) { x = _x, y = _y; }
		cp operator + (const cp &o) const { return cp(x + o.x, y + o.y); }
		cp operator - (const cp &o) const { return cp(x - o.x, y - o.y); }
		cp operator * (const cp &o) const { return cp(x * o.x - y * o.y, x * o.y + y * o.x); }
		cp conj() const { return cp(x, -y); }
	};

	int rev[1 << 16], lim;
	cp A[1 << 16], B[1 << 16], w[1 << 16];

	void init(int n, int m) {
		lim = 1;
		int k = 0; while (lim < n + m - 1) lim <<= 1, k++;
		rep(i, 1, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));

		for (int i = 1; i < lim; i <<= 1) {
			rep(j, 0, i - 1) w[i + j] = cp(cos(PI / i * j), sin(PI / i * j));
		}
	}

	void DFT(cp a[], bool f) {
		rep(i, 0, lim - 1) if (i < rev[i]) swap(a[i], a[rev[i]]);

		for (int i = 1; i < lim; i <<= 1) {
			for (int j = 0; j < lim; j += (i << 1)) {
				rep(k, 0, i - 1) {
					cp x = a[j + k], y = a[j + k + i] * w[i + k];
					a[j + k] = x + y;
					a[j + k + i] = x - y;
				}
			}
		}

		if (f) return;
		reverse(a + 1, a + lim);
		db div = 1.0 / lim;
		rep(i, 0, lim - 1) a[i].x *= div, a[i].y *= div;
	}

	const int O = (1 << 15) - 1;
	const cp dr = cp(0.5, 0), di = cp(0, -0.5);

	cp Mem[1 << 16];

	void GetMem(int *a, int n) {
		rep(i, 0, lim - 1) Mem[i] = i < n ? cp(a[i] >> 15, a[i] & O) : cp();
		DFT(Mem, 1);
	}

	void Mul(int *a, int n, int *b, int m, int *c, int l, bool fl) {
		static cp AC[1 << 16], AD[1 << 16], BC[1 << 16], BD[1 << 16];

		rep(i, 0, lim - 1) {
			A[i] = i < n ? cp(a[i] >> 15, a[i] & O) : cp();
			if (!fl) B[i] = i < m ? cp(b[i] >> 15, b[i] & O) : cp();
		}

		DFT(A, 1);
		if (!fl) DFT(B, 1);
		else rep(i, 0, lim - 1) B[i] = Mem[i];

		rep(i, 0, lim - 1) {
			int j = i ? lim - i : 0;
			cp va, vb, vc, vd;
			va = (A[i] + A[j].conj()) * dr, vb = (A[i] - A[j].conj()) * di;
			vc = (B[i] + B[j].conj()) * dr, vd = (B[i] - B[j].conj()) * di;
			AC[i] = va * vc, AD[i] = va * vd;
			BC[i] = vb * vc, BD[i] = vb * vd;
		}

		rep(i, 0, lim - 1) {
			A[i] = AC[i] + AD[i] * cp(0, 1);
			B[i] = BC[i] + BD[i] * cp(0, 1);
		}

		DFT(A, 0), DFT(B, 0);
			
		rep(i, 0, l - 1) {
			int vac = (static_cast<ll>(A[i].x + 0.5) % mod + mod) % mod;
			int vad = (static_cast<ll>(A[i].y + 0.5) % mod + mod) % mod;
			int vbc = (static_cast<ll>(B[i].x + 0.5) % mod + mod) % mod;
			int vbd = (static_cast<ll>(B[i].y + 0.5) % mod + mod) % mod;
			c[i] = (((ll) vac << 30) + ((ll) (vad + vbc) << 15) + vbd) % mod;
		}
	}
}

const int N = 30015;
int k, a[N], b[N], fac[N], ifac[N];

void calc(int n) {
	if (n == 1) {
		rep(i, 1, k) a[i] = ifac[i];
		Conv::GetMem(a + 1, k);
		return;
	}

	calc(n >> 1);
	auto gao = [&](int t[], int v[], int o, bool fl = 0) {
		for (int i = 1, pw = o; i <= k; i++, pw = (ll) pw * o % mod)
			t[i] = (ll) v[i] * pw % mod;
		Conv::Mul(a + 1, k, b + 1, k, a + 2, k - 1, fl), a[1] = 0;
	};

	gao(b, a, qpow(2, n >> 1));
	if (n & 1) gao(a, a, 2, 1);
}

ll n;

int main() {
	cin >> n >> k;
	if (n > k) return puts("0"), 0;
	fac[0] = 1;
	rep(i, 1, k) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[k] = qpow(fac[k], mod - 2);
	per(i, 0, k - 1) ifac[i] = (ll) ifac[i + 1] * (i + 1) % mod;
	Conv::init(k, k);
	calc(n);
	int ans = 0;
	rep(i, 1, k) ans = (ans + (ll) a[i] * ifac[k - i]) % mod;
	ans = (ll) ans * fac[k] % mod;
	printf("%d\n", ans);
	return 0;
}