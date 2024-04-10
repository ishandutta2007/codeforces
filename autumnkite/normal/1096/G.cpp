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

const int N = 1000005, P = 998244353;

int n, k, mn, mx, p[10], a[N * 9], inv[N * 9];

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

int main() {
	read(n), read(k), n >>= 1;
	mn = 10, mx = 0;
	for (int i = 0; i < k; ++i) {
		int x;
		read(x);
		p[x] = 1;
		mn = std::min(mn, x);
		mx = std::max(mx, x + 1);
	}
	k = mx - mn;
	a[0] = qpow(p[mn], n);
	int p0_inv = qpow(p[mn], P - 2);
	for (int i = 0; i < n * 9; ++i) {
		if (i + 1 == 1) {
			inv[i + 1] = 1;
		} else {
			inv[i + 1] = 1ll * (P - P / (i + 1)) * inv[P % (i + 1)] % P;
		}
		int t = 0;
		for (int j = 0; j < k - 1 && j <= i; ++j) {
			t = (t + (1ll * n * a[i - j] % P) * (1ll * p[mn + j + 1] * (j + 1) % P)) % P;
		}
		for (int j = 1; j < k && j <= i + 1; ++j) {
			t = (t + 1ll * (P - p[mn + j]) * a[i - j + 1] % P * (i - j + 1)) % P;
		}
		a[i + 1] = 1ll * t * inv[i + 1] % P * p0_inv % P;
	}
	int ans = 0;
	for (int i = 0; i <= n * 9; ++i) {
		ans = (ans + 1ll * a[i] * a[i]) % P;
	}
	print(ans);
}