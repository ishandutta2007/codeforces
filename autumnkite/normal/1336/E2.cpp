#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

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

const int P = 998244353, I2 = (P + 1) >> 1;

int n, m, fac[55], inv[55];
std::vector<long long> a, b, c;
std::vector<int> id;
std::vector<int> f, g;

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

bool insert(long long x) {
	for (int i = m - 1; ~i; --i) {
		if (x >> i & 1) {
			if (!a[i]) {
				a[i] = x;
				return true;
			} else {
				x ^= a[i];
			}
		}
	}
	return false;
}

namespace BF {
	void dfs(int k, long long now) {
		if (k == (int)b.size()) {
			++f[__builtin_popcountll(now)];
			return;
		}
		dfs(k + 1, now);
		dfs(k + 1, now ^ b[k]);
	}
}

void dfs(int k, long long now) {
	if (k == (int)id.size()) {
		++g[__builtin_popcountll(now)];
		return;
	}
	dfs(k + 1, now);
	dfs(k + 1, now ^ (1ll << id[k]) ^ c[id[k]]);
}

int C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

int main() {
	read(n), read(m);
	a.resize(m);
	for (int i = 0; i < n; ++i) {
		long long x;
		read(x);
		insert(x);
	}
	for (int i = m - 1; ~i; --i) {
		if (a[i]) {
			for (int j = m - 1; j > i; --j) {
				if (a[j] >> i & 1) {
					a[j] ^= a[i];
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		if (a[i]) {
			b.push_back(a[i]);
		} else {
			id.push_back(i);
		}
	}
	if ((int)b.size() < m / 2) {
		f.resize(m + 1);
		BF::dfs(0, 0);
		for (int i = 0; i <= m; ++i) {
			f[i] = 1ll * f[i] * qpow(2, n - (int)b.size()) % P;
			print(f[i], ' ');
		}
		return 0;
	}
	c.resize(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			c[j] |= (long long)(a[i] >> j & 1) << i;
		}
	}
	g.resize(m + 1);
	dfs(0, 0);
	fac[0] = 1;
	for (int i = 1; i <= m; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[m] = qpow(fac[m], P - 2);
	for (int i = m; i; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
	std::vector<std::vector<int>> F(m + 1, std::vector<int>(m + 1));
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= m; ++k) {
				int t = 1ll * C(i, k) * C(m - i, j - k) % P;
				if (k & 1) {
					F[j][i] = (F[j][i] + P - t) % P;
				} else {
					F[j][i] = (F[j][i] + t) % P;
				}
			}
		}
	}
	f.resize(m + 1);
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			f[i] = (f[i] + 1ll * F[i][j] * g[j]) % P;
		}
		f[i] = 1ll * f[i] * qpow(I2, m - (int)b.size()) % P;
		f[i] = 1ll * f[i] * qpow(2, n - (int)b.size()) % P;
		print(f[i], ' ');
	}
}