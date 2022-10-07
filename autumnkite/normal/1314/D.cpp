#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>

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

namespace myrnd {
	unsigned long long seed = 0x3C9FC1DA24BB75DFull;

	inline void srnd(unsigned long long _sd) {
		seed ^ _sd ? seed ^= _sd : 0;
	}

	inline unsigned long long rnd() {
		seed ^= seed << 13;
		seed ^= seed >> 7;
		seed ^= seed << 17;
		return seed + 0x764FF49E4F6C521Dull;
	}

	template<typename T>
	T rnd(T a, T b) {
		return rnd() % (unsigned long long)(b - a + 1) + a;
	}
}
using namespace myrnd;

const int INF = 0x3f3f3f3f;

int n, k, a[85][85], col[85];
int f[85][85];

void solve() {
	read(n), read(k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			read(a[i][j]);
		}
	}
	int ans = INF;
	while (1.0 * clock() / CLOCKS_PER_SEC < 2.5) {
		for (int i = 1; i <= n; ++i) {
			col[i] = rnd() & 1;
		}
		f[0][1] = 0;
		for (int i = 2; i <= n; ++i) {
			f[0][i] = INF;
		}
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[i][j] = INF;
				for (int p = 1; p <= n; ++p) {
					if (col[p] != col[j]) {
						f[i][j] = std::min(f[i][j], f[i - 1][p] + a[p][j]);
					}
				}
			}
		}
		ans = std::min(ans, f[k][1]);
	}
	print(ans);
}

int main() {
	srnd(time(0));
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}