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

const int N = 205, INF = 0x3f3f3f3f;

int n, m;
char s[N], t[5];

int f[N][N][N];

void solve() {
	read(n), read(m);
	readStr(s + 1), readStr(t + 1);
	if (t[1] == t[2]) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == t[1]) {
				++cnt;
			}
		}
		cnt = std::min(n, cnt + m);
		print(1ll * cnt * (cnt - 1) / 2);
		return;
	}
	for (int j = 0; j <= m; ++j) {
		for (int k = 0; k <= n; ++k) {
			f[0][j][k] = -INF;
		}
	}
	f[0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= n; ++k) {
				f[i][j][k] = f[i - 1][j][k];
				if (k && j >= (s[i] != t[1])) {
					f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - (s[i] != t[1])][k - 1]);
				}
				if (j >= (s[i] != t[2])) {
					f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - (s[i] != t[2])][k] + k);
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= m; ++j) {
		for (int k = 0; k <= n; ++k) {
			ans = std::max(ans, f[n][j][k]);
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