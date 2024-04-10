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

const int N = 100005;

int n;
long long k, a[N], b[N];

long long calc(long long A) {
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		long long l = 0, r = a[i], ans = 0;
		while (l <= r) {
			long long md = (l + r) >> 1;
			if (-3ll * md * (md - 1) + a[i] - 1 >= A) {
				ans = md;
				l = md + 1;
			} else {
				r = md - 1;
			}
		}
		res += b[i] = ans;
	}
	return res;
}

int main() {
	read(n), read(k);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	long long l = -4000000000000000000ll, r = 2000000000ll, ans = 0;
	while (l <= r) {
		long long md = (l + r) >> 1;
		if (calc(md) >= k) {
			ans = md;
			l = md + 1;
		} else {
			r = md - 1;
		}
	}
	long long now = calc(ans);
	for (int i = 1; i <= n; ++i) {
		if (now == k) {
			break;
		}
		if (b[i] > 0 && -3ll * b[i] * (b[i] - 1) + a[i] - 1 == ans) {
			--b[i];
			--now;
		}
	}
	for (int i = 1; i <= n; ++i) {
		print(b[i], " \n"[i == n]);
	}
}