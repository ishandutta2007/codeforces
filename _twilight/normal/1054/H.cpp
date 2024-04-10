#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1 << 20;

typedef class Complex {
	public:
		double r, v;
		
		Complex() {	}
		Complex(double r, double v) : r(r), v(v) {	}

		friend Complex operator + (Complex a, Complex b) {
			return Complex(a.r + b.r, a.v + b.v);
		}
		friend Complex operator - (Complex a, Complex b) {
			return Complex(a.r - b.r, a.v - b.v);	
		}
		friend Complex operator * (Complex a, double k) {
			return Complex(a.r * k, a.v * k);
		}
		friend Complex operator * (Complex a, Complex b) {
			return Complex(a.r * b.r - a.v * b.v, a.r * b.v + a.v * b.r);
		}
		Complex& operator += (Complex b) {
			return *this = *this + b;
		}
} Complex;

const double pi = acos(-1);

class FFT {
	public:
		Complex gn[13], _gn[13];

		FFT() {
			double deg = 2 * pi;
			for (int i = 0; i < 13; i++) {
				deg /= 2;
				gn[i] = Complex(cos(deg), sin(deg));
				_gn[i] = Complex(gn[i].r, -gn[i].v);
			}
		}
			
		void operator () (Complex* f, int len, int sgn, int dlen = 1) {
			for (int i = 1, j = len >> 1, k; i < len - 1; i++, j += k) {
				if (i < j) {
					Complex *p1 = f + (i * dlen), *p2 = f + (j * dlen);
					for (int r = 0; r < dlen; r++) {
						swap(*(p1++), *(p2++));
					}
				}
				for (k = len >> 1; j >= k; j -= k, k >>= 1);
			}
			Complex* wn = (sgn == 1) ? gn : _gn;
			for (int l = 2; l <= len; l <<= 1, wn++) {
				int hl = l >> 1;
				for (int i = 0; i < len; i += l) {
					Complex w = Complex(1, 0);
					for (int j = 0; j < hl; j++, w = w * *wn) {
						Complex *x = f + ((i + j) * dlen), *y = f + ((i + j + hl) * dlen), u, v;
						for (int t = 0; t < dlen; t++, x++, y++) {
							u = *x, v = *y * w;
							*x = u + v, *y = u - v;
						}
					}
				}
			}
			if (sgn == -1) {
				double invlen = 1.0 / len;
				for (int i = 0, _ = len * dlen; i < _; i++)
					f[i] = f[i] * invlen;
			}
		}
} FFT;

typedef class Helper {
	public:
		int p;
		int g;
		int *x, *y;
		
		Helper(int p, int g) : p(p), g(g) {
			x = new int[p];
			y = new int[p];
			x[0] = 1;
			for (int i = 1; i < p - 1; i++)
				x[i] = x[i - 1] * g % p;
			for (int i = 0; i < p; i++)
				y[i] = -1;
			for (int i = 0; i < p - 1; i++)
				y[x[i]] = i;
		}
		int operator [] (int t) {
			return x[t % p];
		}
		int operator () (int t) {
			return y[t % p];
		}
} Helper;

void exgcd(int a, int b, int&x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) *x;
	}
}
int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : x;
}

int crt(vector<int> a, vector<int> m) {
	int M = 1, rt = 0;
	for (auto x : m)
		M *= x;
	int t = a.size();
	for (int i = 0; i < t; i++) {
		rt = rt + a[i] * inv(M / m[i] % m[i], m[i]) * (M / m[i]);
	}
	return rt % M;
}

const int Mod = 490019, Mod1 = 491, Mod2 = 499, Phi1 = Mod1 - 1, Phi2 = Mod2 - 1;

int crt(vector<int> a) {
	return crt(a, vector<int> {2, Mod1, Mod2});
}

Helper h1 (Mod1, 2), h2 (Mod2, 7);

int n, m, c;
int h[Mod];
Complex a[2][N], a1[2][2][1024], a2[2][2][1024];
Complex b[2][N], b1[2][2][1024], b2[2][2][1024];

int a3[8], b3[8];


void FFT2(Complex* f, int sgn) {
	for (int i = 0; i < 1024; i++)
		FFT(f + (i << 10), 1024, sgn);
	FFT(f, 1024, sgn, 1024);
}
#define DFT(_f) FFT((_f), 1024, 1)
#define IDFT(_f) FFT((_f), 1024, -1)
#define for2(x) for (int (x) = 0; (x) < 2; (x)++) 

int main() {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		int p1 = h1(i), p2 = h2(i);
		p1 = (p1 + p1) % Phi1;
		p2 = (p2 + p2) % Phi2;
		if (p1 >= 0 && p2 >= 0)
			a[i & 1][p1 << 10 | p2].r += x;
		if (p1 >= 0)
			a1[i & 1][p2 < 0][p1].r += x;
		if (p2 >= 0)
			a2[i & 1][p1 < 0][p2].r += x;
		a3[((~i & 1) << 2) | ((p1 < 0) << 1) | (p2 < 0)] += x;
	}
	for (int i = 0, x; i < m; i++) {
		scanf("%d", &x);
		int p1 = h1(i), p2 = h2(i);
		p1 = (p1 + p1 + p1) % Phi1;
		p2 = (p2 + p2 + p2) % Phi2;
		if (p1 >= 0 && p2 >= 0)
			b[i & 1][p1 << 10 | p2].r += x;
		if (p1 >= 0)
			b1[i & 1][p2 < 0][p1].r += x;
		if (p2 >= 0)
			b2[i & 1][p1 < 0][p2].r += x;
		b3[((~i & 1) << 2) | ((p1 < 0) << 1) | (p2 < 0)] += x;
	}
	FFT2(a[0], 1), FFT2(a[1], 1), FFT2(b[0], 1), FFT2(b[1], 1);
	for (int i = 0; i < N; i++) {
		Complex pd = (a[0][i] + a[1][i]) * (b[0][i] + b[1][i]);
		a[1][i] = a[1][i] * b[1][i];
		a[0][i] = pd - a[1][i];
	}
	FFT2(a[0], -1), FFT2(a[1], -1);
	for2 (t) {
		for (int i = 0; i < Phi1; i++)
			for (int j = Phi2, __ = Phi2 << 1; j < __; j++)
				a[t][(i << 10) | (j - Phi2)].r += a[t][i << 10 | j].r;
		for (int i = Phi1, _ = Phi1 << 1; i < _; i++)
			for (int j = 0; j < Phi2; j++)
				a[t][(i - Phi1) << 10 | j].r += a[t][i << 10 | j].r;
		for (int i = Phi1, _ = Phi1 << 1; i < _; i++)
			for (int j = Phi2, __ = Phi2 << 1; j < __; j++)
				a[t][(i - Phi1) << 10 | (j - Phi2)].r += a[t][i << 10 | j].r;
		for (int i = 0; i < Phi1; i++)
			for (int j = 0; j < Phi2; j++)
				h[crt({t, h1[i], h2[j]})] += ((long long) (a[t][i << 10 | j].r + 0.5)) % Mod;
	}

	for2 (x) for2 (y) DFT(a1[x][y]);
	for2 (x) for2 (y) DFT(b1[x][y]);
	Complex _c[2][2];
	for (int i = 0; i < 1024; i++) {
		_c[0][0] = _c[0][1] = _c[1][0] = _c[1][1] = Complex(0, 0);
		for2(f0) for2(f1) for2(f2) for2(f3)
			_c[f0 & f2][f1 | f3] += a1[f0][f1][i] * b1[f2][f3][i];
		for2(x) for2(y)
			a1[x][y][i] = _c[x][y];
	}
	for2 (x) IDFT(a1[x][1]);
	for2 (t) {
		for (int i = Phi1, _ = Phi1 << 1; i <_; i++)
			a1[t][1][i - Phi1].r += a1[t][1][i].r;
		for (int i = 0; i < Phi1; i++)
			h[crt({t, h1[i], 0})] += ((long long) (a1[t][1][i].r + 0.5)) % Mod;
	}

	for2 (x) for2 (y) DFT(a2[x][y]);
	for2 (x) for2 (y) DFT(b2[x][y]);
	for (int i = 0; i < 1024; i++) {
		_c[0][0] = _c[0][1] = _c[1][0] = _c[1][1] = Complex(0, 0);
		for2(f0) for2(f1) for2(f2) for2(f3)
			_c[f0 & f2][f1 | f3] += a2[f0][f1][i] * b2[f2][f3][i];
		for2(x) for2(y)
			a2[x][y][i] = _c[x][y];
	}
	for2 (x) IDFT(a2[x][1]);
	for2 (t) {
		for (int i = Phi2, _ = Phi2 << 1; i <_; i++)
			a2[t][1][i - Phi2].r += a2[t][1][i].r;
		for (int i = 0; i < Phi2; i++)
			h[crt({t, 0, h2[i]})] += ((long long) (a2[t][1][i].r + 0.5)) % Mod;
	}

	int _d[8];
	memset(_d, 0, sizeof(_d));
	for (int i = 0; i < 8; i++) 
		for (int j = 0; j < 8; j++)
			_d[i | j] = (_d[i | j] + 1ll * a3[i] * b3[j]) % Mod;
	for2 (t)
		h[crt({!t, 0, 0})] += _d[(t << 2) | 3];

	int pwc = 1, ans = 0;
	for (int i = 0; i < Mod - 1; i++, pwc = 1ll * pwc * c % Mod)
		ans = (ans + 1ll * h[i] * pwc) % Mod;
	printf("%d\n", ans);
	return 0;
}