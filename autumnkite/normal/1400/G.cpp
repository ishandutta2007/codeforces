#include <bits/stdc++.h>

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
		static int num[40];
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (*num = 0; x; x /= 10) {
			num[++*num] = x % 10;
		}
		while (*num){
			putchar(num[*num] ^ '0');
			--*num;
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

const int N = 300005, P = 998244353;

int n, m, l[N], r[N];
int cnt[N];
int a[20], b[20];
int sum[45][N];

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

int fac[N], inv[N];

void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[n] = qpow(fac[n], P - 2);
	for (int i = n; i; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
}

int C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

void solve() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		read(l[i]), read(r[i]);
		++cnt[l[i]], --cnt[r[i] + 1];
	}
	for (int i = 1; i <= n; ++i) {
		cnt[i] += cnt[i - 1];
	}
	init(n);
	for (int t = 0; t <= 2 * m; ++t) {
		for (int i = 1; i <= n; ++i) {
			sum[t][i] = (sum[t][i - 1] + C(cnt[i] - t, i - t)) % P;
		}
	}
	for (int i = 0; i < m; ++i) {
		read(a[i]), read(b[i]);
	}
	int ans = 0;
	for (int S = 0; S < (1 << m); ++S) {
		static bool vis[N];
		int L = 1, R = n, sz = 0, s = 1;
		for (int i = 0; i < m; ++i) {
			if (S >> i & 1) {
				s *= -1;
				L = std::max(L, l[a[i]]), R = std::min(R, r[a[i]]), sz += !vis[a[i]], vis[a[i]] = 1;
				L = std::max(L, l[b[i]]), R = std::min(R, r[b[i]]), sz += !vis[b[i]], vis[b[i]] = 1;
			}
		}
		if (L <= R) {
			s *= sum[sz][R] - sum[sz][L - 1];
		} else {
			s = 0;
		}
		s = (s + P) % P;
		ans = (ans + s) % P;
		for (int i = 0; i < m; ++i) {
			if (S >> i & 1) {
				vis[a[i]] = vis[b[i]] = 0;
			}
		}
	}
	print(ans);
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}