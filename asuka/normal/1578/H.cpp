#include<bits/stdc++.h>
#define ll long long
#define MAXN 50015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int MOD = 998244353;
int inv[MAXN];
int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % MOD;
		a = (ll) a * a % MOD;
		b >>= 1;
	}
	return res;
}
namespace Poly {
	int mod = 998244353, grt = 3;
	class poly {
	private:
	    std::vector<int> data;
	    void out(void) {
	        for (int i = 0; i < (int)data.size(); ++i) printf("%d ", data[i]);
	        puts("");
	    }
	public:
	    poly(std::size_t len = std::size_t(0)) {data = std::vector<int>(len); }
	    poly(const std::vector<int> &b) {data = b; }
	    poly(const poly &b) {data = b.data; }
	    void resize(std::size_t len, int val = 0) {data.resize(len, val); }
	    std::size_t size(void)const {return data.size(); }
	    void clear(void) {data.clear(); }
	#if __cplusplus >= 201103L
	    void shrink_to_fit(void) {data.shrink_to_fit(); }
	#endif
	    int &operator[](std::size_t b) {return data[b]; }
	    const int &operator[](std::size_t b)const {return data[b]; }
	    poly operator*(const poly& h)const;
	    poly operator*=(const poly &h);
	    poly operator*(const int &h)const;
	    poly operator*=(const int &h);
	    poly operator+(const poly &h)const;
	    poly operator+=(const poly &h);
	    poly operator-(const poly &h)const;
	    poly operator-=(const poly &h);
	    poly operator<<(const std::size_t &b)const;
	    poly operator<<=(const std::size_t &b);
	    poly operator>>(const std::size_t &b)const;
	    poly operator>>=(const std::size_t &b);
	    poly operator/(const int &h)const;
	    poly operator/=(const int &h);
	    poly operator==(const poly &h)const;
	    poly operator!=(const poly &h)const;
	    poly operator+(const int &h)const;
	    poly operator+=(const int &h);
	    poly inv(void)const;
	    poly inv(const int &h)const;
	    friend poly sqrt(const poly &h);
	    friend poly log(const poly &h);
	    friend poly exp(const poly &h);
	};

	int qpow(int a, int b, int p = mod) {
	    int res = 1;
	    while (b) {if (b & 1) res = (ll)res * a % p; a = (ll)a * a % p, b >>= 1; }
	    return res;
	}

	std::vector<int> rev;
	void dft_for_module(std::vector<int> &f, int n, int b) {
	    static std::vector<int> w;
	    w.resize(n);
	    for (int i = 0; i < n; ++i) if (i < rev[i]) std::swap(f[i], f[rev[i]]);
	    for (int i = 2; i <= n; i <<= 1) {
	        w[0] = 1, w[1] = qpow(grt, (mod - 1) / i); if (b == -1) w[1] = qpow(w[1], mod - 2);
	        for (int j = 2; j < i / 2; ++j) w[j] = (ll)w[j - 1] * w[1] % mod;
	        for (int j = 0; j < n; j += i)
	            for (int k = 0; k < i / 2; ++k) {
	                int p = f[j + k], q = (ll)f[j + k + i / 2] * w[k] % mod;
	                f[j + k] = (p + q) % mod, f[j + k + i / 2] = (p - q + mod) % mod;
	            }
	    }
	}

	poly poly::operator*(const poly &h)const {
	    int N = 1; while (N < (int)(size() + h.size() - 1)) N <<= 1;
	    std::vector<int> f(this->data), g(h.data); f.resize(N), g.resize(N);
	    rev.resize(N);
	    for (int i = 0; i < N; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? N >> 1 : 0);
	    dft_for_module(f, N, 1), dft_for_module(g, N, 1);
	    for (int i = 0; i < N; ++i) f[i] = (ll)f[i] * g[i] % mod;
	    dft_for_module(f, N, -1), f.resize(size() + h.size() - 1);
	    for (int i = 0, inv = qpow(N, mod - 2); i < (int)f.size(); ++i) f[i] = (ll)f[i] * inv % mod;
	    return f;
	}

	poly poly::operator*=(const poly &h) {
	    return *this = *this * h;
	}

	poly poly::operator*(const int &h)const {
	    std::vector<int> f(this->data);
	    for (int i = 0; i < (int)f.size(); ++i) f[i] = (ll)f[i] * h % mod;
	    return f;
	}

	poly poly::operator*=(const int &h) {
	    for (int i = 0; i < (int)size(); ++i) data[i] = (ll)data[i] * h % mod;
	    return *this;
	}

	poly poly::operator+(const poly &h)const {
	    std::vector<int> f(this->data);
	    if (f.size() < h.size()) f.resize(h.size());
	    for (int i = 0; i < (int)h.size(); ++i) f[i] = (f[i] + h[i]) % mod;
	    return f;
	}

	poly poly::operator+=(const poly &h) {
	    std::vector<int> &f = this->data;
	    if (f.size() < h.size()) f.resize(h.size());
	    for (int i = 0; i < (int)h.size(); ++i) f[i] = (f[i] + h[i]) % mod;
	    return f;
	}

	poly poly::operator-(const poly &h)const {
	    std::vector<int> f(this->data);
	    if (f.size() < h.size()) f.resize(h.size());
	    for (int i = 0; i < (int)h.size(); ++i) f[i] = (f[i] - h[i] + mod) % mod;
	    return f;
	}

	poly poly::operator-=(const poly &h) {
	    std::vector<int> &f = this->data;
	    if (f.size() < h.size()) f.resize(h.size());
	    for (int i = 0; i < (int)h.size(); ++i) f[i] = (f[i] - h[i] + mod) % mod;
	    return f;
	}

	poly poly::operator<<(const std::size_t &b)const {
	    std::vector<int> f(size() + b);
	    for (int i = 0; i < (int)size(); ++i) f[i + b] = data[i];
	    return f;
	}

	poly poly::operator<<=(const std::size_t &b) {
	    return *this = (*this) << b;
	}

	poly poly::operator>>(const std::size_t &b)const {
	    std::vector<int> f(size() - b);
	    for (int i = 0; i < (int)f.size(); ++i) f[i] = data[i + b];
	    return f;
	}

	poly poly::operator>>=(const std::size_t &b) {
	    return *this = (*this) >> b;
	}

	poly poly::operator/(const int &h)const {
	    std::vector<int> f(this->data); int inv = qpow(h, mod - 2);
	    for (int i = 0; i < (int)f.size(); ++i) f[i] = (ll)f[i] * inv % mod;
	    return f;
	}

	poly poly::operator/=(const int &h) {
	    int inv = qpow(h, mod - 2);
	    for (int i = 0; i < (int)data.size(); ++i) data[i] = (ll)data[i] * inv % mod;
	    return *this;
	}

	poly poly::inv(void)const {
	    int N = 1; while (N < (int)(size() + size() - 1)) N <<= 1;
	    std::vector<int> f(N), g(N), d(this->data);
	    d.resize(N), f[0] = qpow(d[0], mod - 2);
	    for (int w = 2; w < N; w <<= 1) {
	        for (int i = 0; i < w; ++i) g[i] = d[i];
	        rev.resize(w << 1);
	        for (int i = 0; i < w * 2; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? w : 0);
	        dft_for_module(f, w << 1, 1), dft_for_module(g, w << 1, 1);
	        for (int i = 0; i < w * 2; ++i) f[i] = (ll)f[i] * (2 + mod - (ll)f[i] * g[i] % mod) % mod;
	        dft_for_module(f, w << 1, -1);
	        for (int i = 0, inv = qpow(w << 1, mod - 2); i < w; ++i) f[i] = (ll)f[i] * inv % mod;
	        for (int i = w; i < w * 2; ++i) f[i] = 0;
	    }
	    f.resize(size());
	    return f;
	}

	poly poly::operator==(const poly &h)const {
	    if (size() != h.size()) return 0;
	    for (int i = 0; i < (int)size(); ++i) if (data[i] != h[i]) return 0;
	    return 1;
	}

	poly poly::operator!=(const poly &h)const {
	    if (size() != h.size()) return 1;
	    for (int i = 0; i < (int)size(); ++i) if (data[i] != h[i]) return 1;
	    return 0;
	}

	poly poly::operator+(const int &h)const {
	    poly f(this->data);
	    f[0] = (f[0] + h) % mod;
	    return f;
	}

	poly poly::operator+=(const int &h) {
	    return *this = (*this) + h;
	}

	poly poly::inv(const int &h)const {
	    poly f(*this);
	    f.resize(h);
	    return f.inv();
	}

	int modsqrt(int h, int p = mod) {
	    return 1;
	}

	poly sqrt(const poly &h) {
	    int N = 1; while (N < (int)(h.size() + h.size() - 1)) N <<= 1;
	    poly f(N), g(N), d(h); d.resize(N), f[0] = modsqrt(d[0]);
	    for (int w = 2; w < N; w <<= 1) {
	        g.resize(w);
	        for (int i = 0; i < w; ++i) g[i] = d[i];
	        f = (f + f.inv(w) * g) / 2;
	        f.resize(w);
	    }
	    f.resize(h.size());
	    return f;
	}

	poly log(const poly &h) {
	    poly f(h);
	    for (int i = 1; i < (int)f.size(); ++i) f[i - 1] = (ll)f[i] * i % mod;
	    f[f.size() - 1] = 0, f = f * h.inv(), f.resize(h.size());
	    for (int i = (int)f.size() - 1; i > 0; --i) f[i] = (ll)f[i - 1] * qpow(i, mod - 2) % mod;
	    f[0] = 0;
	    return f;
	}

	poly exp(const poly &h) {
	    int N = 1; while (N < (int)(h.size() + h.size() - 1)) N <<= 1;
	    poly f(N), g(N), d(h);
	    f[0] = 1, d.resize(N);
	    for (int w = 2; w < N; w <<= 1) {
	        f.resize(w), g.resize(w);
	        for (int i = 0; i < w; ++i) g[i] = d[i];
	        f = f * (g + 1 - log(f));
	        f.resize(w);
	    }
	    f.resize(h.size());
	    return f;
	}
}
using namespace Poly;
poly one, F, G, P;
poly circ(poly x) {
	poly y;
	y.resize(x.size(), 0);
	rep(i, 1, SZ(x) - 1) y[i] = (ll) x[i] * i % mod;
	return y * (one - x).inv();
}
int f[MAXN], n, m;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) inv[i] = power(i, MOD - 2);
	f[0] = 1;
	rep(i, 1, n) {
		int k = (m + i) / 2;
		if(k == (m + i - 1) / 2) f[i] = (ll) f[i - 1] * (k - i + 1) % MOD;
		else f[i] = (ll) f[i - 1] * k % MOD;
		f[i] = (ll) f[i] * inv[i] % MOD;
	}
	F.resize(n + 1);
	G.resize(n + 1);
	one.resize(1, 1);
	rep(i, 1, n) {
		if(i % 4 == 0) F[i] = (MOD - f[i]) % MOD;
		else if(i % 4 == 1) G[i] = f[i];
		else if(i % 4 == 2) F[i] = f[i];
		else G[i] = (MOD - f[i]) % MOD;
	}
	P = G * (one - F).inv();
	F = circ(F);
	P = circ(P);
	printf("%d\n", (P[n] + F[n]) % mod);
	return 0;
}