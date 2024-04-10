#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#ifndef AT_HOME
#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)
#endif

namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}

	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
		x = 0;
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
		}
		if (op) {
			x = -x;
		}
		return true;
	}

	inline int readStr(char *s) {
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
		}
		s[n] = '\0';
		return n;
	}

	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}

	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		std::vector<int> num;
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (; x; x /= 10) {
			num.push_back(x % 10);
		}
		while (!num.empty()) {
			putchar(num.back() ^ '0');
			num.pop_back();
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}

	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
		putchar(ch);
	}
}
using namespace IO;

const int P = 998244353;

void inc(int &a, int b) {
	(a += b) >= P ? a -= P : 0;
}

void dec(int &a, int b) {
	a < b ? a += P - b : a -= b;
}

int plus(int a, int b) {
	return a + b >= P ? a + b - P : a + b;
}

int minus(int a, int b) {
	return a < b ? a + P - b : a - b;
}

int mul(int a, int b) {
	return 1ll * a * b % P;
}

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

namespace Polynomial {
	typedef std::vector<int> poly;

	const int MAX_LEN = 262144;
	const int G = 3;

	int omega[MAX_LEN];
	poly rev;

	void polyInit(){
		for (int m = 1; m < MAX_LEN; m <<= 1) {
			int _o = qpow(G, (P - 1) / (m << 1));
			omega[m] = 1;
			for (int i = 1; i < m; ++i) {
				omega[m + i] = mul(omega[m + i - 1], _o);
			}
		}
	}

	int get(int n) {
		int res = 1;
		while (res < n) {
			res <<= 1;
		}
		return res;
	}
	
	void init(int n) {
		int k = 0;
		while ((1 << k) < n) {
			++k;
		}
		rev.resize(n), rev[0] = 0, --k;
		for (int i = 1; i < n; ++i) {
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
		}
	}
	
	void DFT(poly &f, int n){
		f.resize(n);
		static unsigned long long ft[MAX_LEN];
		for (int i = 0; i < n; ++i) {
			ft[rev[i]] = f[i];
		}
		for (int m = 1; m < n; m <<= 1) {
			if (m & 262144) {
				for (int i = 0; i < n; ++i) {
					ft[i] %= P;
				}
			}
			int l = m << 1;
			for (int p = 0; p < n; p += l) {
				int *W = omega + m;
				unsigned long long *F0 = ft + p, *F1 = ft + p + m;
				for (int i = 0; i < m; ++i, ++W, ++F0, ++F1) {
					int t = (*F1) * (*W) % P;
					*F1 = (*F0) + P - t, *F0 += t;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			f[i] = ft[i] % P;
		}
	}

	void IDFT(poly &f, int n){
		DFT(f, n), std::reverse(f.begin() + 1, f.end());
		int t = qpow(n, P - 2);
		for (int i = 0; i < n; ++i) {
			f[i] = mul(f[i], t);
		}
	}

	poly Multiply(poly a, poly b, int _n = -1) {
		if (!a.size() || !b.size() || !_n) {
			return {};
		}
		if (_n == -1) {
			_n = a.size() + b.size() - 1;
		}
		if (a.size() <= 30 || b.size() <= 30) {
			poly res(a.size() + b.size() - 1);
			for (int i = 0; i < (int)a.size(); ++i) {
				for (int j = 0; j < (int)b.size(); ++j) {
					res[i + j] = (res[i + j] + 1ll * a[i] * b[j]) % P;
				}
			}
			res.resize(_n);
			return res;
		}
		int n = get(_n);
		init(n), DFT(a, n), DFT(b, n);
		for (int i = 0; i < n; ++i) {
			a[i] = mul(a[i], b[i]);
		}
		IDFT(a, n), a.resize(_n);
		return a;
	}
}
using Polynomial::poly;
using Polynomial::polyInit;
using Polynomial::Multiply;

const int N = 200005;

int m, n;
int fac[N], inv[N];
poly f, g;

int C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

void solve(int l, int r) {
	if (l + 1 == r) {
		if (l > 0) {
			f[l] = (qpow(l, m) + 1ll * (P - fac[l]) * f[l]) % P;
		} else {
			f[l] = 0;
		}
		return;
	}
	int md = (l + r + 1) >> 1;
	solve(l, md);
	poly tmp = poly(f.begin() + l, f.begin() + md);
	for (int i = 0; i < (int)tmp.size(); ++i) {
		tmp[i] = 1ll * tmp[i] * inv[i + l] % P;
	}
	tmp = Multiply(tmp, poly(g.begin(), g.begin() + r - l), r - l);
	for (int i = md; i < r; ++i) {
		inc(f[i], tmp[i - l]);
	}
	solve(md, r);
}

int main() {
	polyInit();
	long long t;
	read(m), read(t);
	if (t >= m) {
		print(0);
		return 0;
	}
	n = m - t;
	fac[0] = 1;
	for (int i = 1; i <= m; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	if (n == m) {
		print(fac[m]);
		return 0;
	}
	inv[m] = qpow(fac[m], P - 2);
	for (int i = m; i; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
	g.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		g[i] = inv[i];
	}
	f.resize(n + 1);
	solve(0, n + 1);
	print(2ll * C(m, n) * f[n] % P);
}