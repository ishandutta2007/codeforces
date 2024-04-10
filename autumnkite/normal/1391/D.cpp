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

const int N = 1000005, INF = 0x3f3f3f3f;

int n, m, a[N], bitcnt[8], f[N][8];
char tmp[N];

int calc(int mask, int lst) {
	int res = lst;
	for (int i = 1; i < n; ++i) {
		int x = (mask >> i & 1) ^ (mask >> (i - 1) & 1) ^ lst ^ 1;
		res |= x << i;
		lst = x;
	}
	return res;
}

void solve() {
	read(n), read(m);
	if (n > 3) {
		print(-1);
		return;
	}
	for (int i = 0; i < n; ++i) {
		readStr(tmp);
		for (int j = 0; j < m; ++j) {
			a[j] |= (tmp[j] ^ '0') << i;
		}
	}
	bitcnt[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	}
	for (int S = 0; S < (1 << n); ++S) {
		f[0][S] = bitcnt[S ^ a[0]];
	}
	for (int i = 1; i < m; ++i) {
		for (int S = 0; S < (1 << n); ++S) {
			f[i][S] = std::min(f[i - 1][calc(S, 0)], f[i - 1][calc(S, 1)]) + bitcnt[S ^ a[i]];
		}
	}
	int ans = INF;
	for (int S = 0; S < (1 << n); ++S) {
		ans = std::min(ans, f[m - 1][S]);
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