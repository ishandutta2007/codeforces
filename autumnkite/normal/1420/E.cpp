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

const int N = 85;

int n, a[N], m, b[N], f[N][N * N / 2][N << 1];

int myabs(int a) {
	return a > 0 ? a : -a;
}

void upd(int &a, int b) {
	a = std::max(a, b);
}

void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	int lst = 0;
	int sum = 0;
	for (int i = 1; i <= n + 1; ++i) {
		if (i == n + 1 || a[i]) {
			b[++m] = i - lst - 1;
			sum += b[m];
			lst = i;
		}
	}
	f[0][0][N] = sum * sum;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n * (n - 1) / 2; ++j) {
			for (int k = std::max(-n, -j); k <= n && k <= j; ++k) {
				if (f[i][j][k + N]) {
					for (int l = std::max(k - b[i + 1], -n); l <= n && l <= n * (n - 1) / 2 - j; ++l) {
						int t = b[i + 1] - k + l;
						upd(f[i + 1][j + myabs(l)][l + N], f[i][j][k + N] - t * t);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= n * (n - 1) / 2; ++j) {
		ans = std::max(ans, f[m][j][N]);
		print(ans / 2, ' ');
	}
	putchar('\n');
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}