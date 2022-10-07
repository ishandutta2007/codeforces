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

const int N = 505;

int n, m, a[N][N], vis[N][N];
char tmp[N];

std::pair<int, int> findCenter() {
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j < m; ++j) {
			if (a[i][j] && a[i - 1][j] && a[i][j - 1] && a[i][j + 1] && a[i + 1][j]) {
				return {i, j};
			}
		}
	}
	return {0, 0};
}

void solve() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		readStr(tmp + 1);
		for (int j = 1; j <= m; ++j) {
			a[i][j] = (tmp[j] == '*');
		}
	}
	std::pair<int, int> tmp = findCenter();
	if (!tmp.first) {
		printStr("NO");
		return;
	}
	int x = tmp.first, y = tmp.second;
	for (int i = x; i; --i) {
		if (a[i][y]) {
			vis[i][y] = 1;
		} else {
			break;
		}
	}
	for (int i = x; i <= n; ++i) {
		if (a[i][y]) {
			vis[i][y] = 1;
		} else {
			break;
		}
	}
	for (int i = y; i; --i) {
		if (a[x][i]) {
			vis[x][i] = 1;
		} else {
			break;
		}
	}
	for (int i = y; i <= m; ++i) {
		if (a[x][i]) {
			vis[x][i] = 1;
		} else {
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!vis[i][j] && a[i][j]) {
				printStr("NO");
				return;
			}
		}
	}
	printStr("YES");
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}