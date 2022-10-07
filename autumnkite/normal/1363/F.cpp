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

const int N = 2005, INF = 0x3f3f3f3f;

int n, ca[N][26], cb[N][26], nx[N][26];
char a[N], b[N];
int f[N][N];

void solve() {
	read(n);
	readStr(a + 1), readStr(b + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j) {
			ca[i][j] = ca[i - 1][j], cb[i][j] = cb[i - 1][j];
		}
		++ca[i][a[i] - 'a'];
		++cb[i][b[i] - 'a'];
	}
	for (int i = 0; i < 26; ++i) {
		nx[n + 1][i] = n + 1;
	}
	for (int i = n; i; --i) {
		for (int j = 0; j < 26; ++j) {
			nx[i][j] = nx[i + 1][j];
		}
		nx[i][b[i] - 'a'] = i;
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			f[i][j] = INF;
		}
	}
	f[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			int c = a[i + 1] - 'a';
			int p = nx[j + 1][c];
			if (p <= n) {
				f[i + 1][p] = std::min(f[i + 1][p], f[i][j] + p - j - 1);
			}
			if (cb[j][c] > ca[i][c]) {
				f[i + 1][j] = std::min(f[i + 1][j], f[i][j]);
			}
		}
	}
	if (f[n][n] == INF) {
		print(-1);
	} else {
		print(f[n][n]);
	}
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}