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

const int N = 1000005;

int n;
long long r1, r2, r3, d, a[N], f[N];

void solve() {
	read(n), read(r1), read(r2), read(r3), read(d);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	f[0] = -d;
	for (int i = 1; i <= n; ++i) {
		f[i] = f[i - 1] + d + std::min(r1 * a[i] + r3, std::min(r2, r1 * a[i] + r1) + r1 + d * 2);
		if (i > 1) {
			f[i] = std::min(f[i], f[i - 2] + 4 * d + std::min(r2, r1 * a[i - 1] + r1) + r1 + std::min(r2, r1 * a[i] + r1) + r1);
		}
	}
	long long sum = d + std::min(r1 * a[n] + r3, std::min(r2, r1 * a[n] + r1) + r1 + d * 2), ans = f[n];
	for (int i = n - 1; ~i; --i) {
		ans = std::min(ans, f[i] + sum);
		sum += 2 * d + std::min(r2, r1 * a[i] + r1) + r1;
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