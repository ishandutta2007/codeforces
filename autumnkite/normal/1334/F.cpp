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

const int N = 500005;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, a[N], m, b[N];
long long w[N], sum, f[N];

struct BIT{
	long long c[N];
	
	void add(int x, long long v) {
		for (; x <= n; x += x & -x) {
			c[x] += v;
		}
	}

	long long query(int x) {
		long long s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
} T;

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		read(w[i]);
		sum += w[i];
	}
	read(m);
	for (int i = 1; i <= m; ++i) {
		read(b[i]);
	}
	T.add(1, -INF);
	for (int i = 1; i <= n; ++i) {
		int j = std::lower_bound(b + 1, b + 1 + m, a[i]) - b;
		if (j <= m && a[i] == b[j]) {
			if (j == 1) {
				f[i] = w[i];
			} else {
				f[i] = T.query(b[j - 1]) + w[i];
			}
		} else {
			f[i] = -INF;
		}
		if (w[i] > 0) {
			T.add(a[i], w[i]);
		}
		long long tmp = T.query(a[i]);
		if (f[i] > tmp) {
			T.add(a[i], f[i] - tmp);
			T.add(a[i] + 1, tmp - f[i]);
		}
	}
	long long ans = T.query(b[m]);
	if (ans > -1e15) {
		printStr("YES");
		print(sum - ans);
	} else {
		printStr("NO");
	}
}