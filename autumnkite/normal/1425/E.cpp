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

const int N = 100005;

int n, k;
int a[N], d[N];
long long suf[N];

int main() {
	read(n), read(k);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		read(d[i]);
	}
	long long sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
	}
	if (k > 1) {
		print(std::max(std::max(0ll + a[n] - d[n], sum - *std::min_element(d + 1, d + n)), 0ll));
		return 0;
	}
	long long ans = 0;
	suf[n + 1] = 0;
	for (int i = n; i; --i) {
		suf[i] = suf[i + 1] + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		suf[i] -= d[i];
	}
	long long mx = 0;
	for (int i = 1; i < n - 1; ++i) {
		mx = std::max(mx, suf[i]);
		ans = std::max(ans, mx - a[i + 1]);
		ans = std::max(ans, mx - d[i + 1]);
		ans = std::max(ans, suf[i + 1]);
	}
	for (int i = n; i; --i) {
		suf[i] = std::max(suf[i], suf[i + 1]);
	}
	if (k == 0) {
		print(std::max(0ll, suf[1]));
		return 0;
	}
	ans = std::max(ans, suf[2]);
	long long presum = 0;
	int premin = 0x3f3f3f3f;
	for (int i = 1; i < n; ++i) {
		presum += a[i];
		premin = std::min(premin, d[i]);
		if (i > 1) {
			ans = std::max(ans, std::max(0ll, presum - premin) + std::max(0ll, suf[i + 1]));
		}
	}
	print(ans);
}