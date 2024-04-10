#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

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

int n, A, R, M;
int a[N];

long long get(long long s1, long long s2) {
	if (A + R <= M) {
		return s1 * R + s2 * A;
	} else if (s1 <= s2) {
		return s1 * (M - A) + s2 * A;
	} else {
		return s1 * R + s2 * (M - R);
	}
}

long long calc(long long h) {
	long long s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > h) {
			s1 += a[i] - h;
		} else {
			s2 += h - a[i];
		}
	}
	return get(s1, s2);
}

int main() {
	read(n), read(A), read(R), read(M);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	std::sort(a + 1, a + 1 + n);
	int l = 0, r = 1000000000, md, ans = 0;
	while (l <= r) {
		md = (l + r) >> 1;
		if (calc(md + 1) - calc(md) >= 0) {
			ans = md, r = md - 1;
		} else {
			l = md + 1;
		}
	}
	print(calc(ans));
//	long long s1 = 0, s2 = 0;
//	for (int i = 1; i <= n; ++i) {
//		s1 += a[i];
//	}
//	long long lst = calc(0);
//	for (int i = 1; i <= 100; ++i) {
//		long long now = calc(i);
//		debug("%lld\n", now - lst);
//		lst = now;
//	}
//	long long ans = std::min(calc(s1 / n), calc((s1 + n - 1) / n));
//	for (int i = 1; i <= n; ++i) {
//		long long h = a[i];
//		s2 += h, s1 -= h;
//		ans = std::min(ans, get(s1 - 1ll * h * (n - i), 1ll * h * i - s2));
//	}
//	print(ans);
}
/*
10 3 5 10
1 3 4 9 10 12 20 50 51 60
*/