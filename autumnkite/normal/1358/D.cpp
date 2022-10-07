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

int n, a[400005];
long long x, s[400005], si[400005];

void solve() {
	read(n), read(x);
	for (int i = 1; i <= n; ++i) {
		read(a[i]), a[n + i] = a[i];
	}
	n *= 2;
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
		si[i] = si[i - 1] + 1ll * a[i] * (a[i] + 1) / 2;
	}
	long long ans = 0;
	int l = 1;
	for (int i = 1; i <= n; ++i) {
		while (l < i && s[i] - s[l] > x) {
			++l;
		}
		long long t = x - (s[i] - s[l]);
		if (t > a[l]) {
			continue;
		}
		t = si[i] - si[l] + (a[l] - t + 1 + a[l]) * t / 2;
		// debug("%d %d %lld\n", l, i, t);
		ans = std::max(ans, t);
	}
	// debug("\n");
	int r = n;
	for (int i = n; i; --i) {
		while (i < r && s[r - 1] - s[i - 1] > x) {
			--r;
		}
		long long t = x - (s[r - 1] - s[i - 1]);
		if (t > a[r]) {
			continue;
		}
		t = si[r - 1] - si[i - 1] + 1ll * (1 + t) * t / 2;
		// debug("%d %d %lld\n", i, r, t);
		ans = std::max(ans, t);
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