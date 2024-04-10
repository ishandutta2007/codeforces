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

const int N = 300005;

int n, m, a[N], p[N], lst[N], mn[N], mx[N];

struct BIT {
	int n, c[N];

	void init(int _n) {
		n = _n;
		for (int i = 1; i <= n; ++i) {
			c[i] = 0;
		}
	}

	void add(int x) {
		for (; x <= n; x += x & -x) {
			++c[x];
		}
	}

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
} T1, T2;

void upd(int &a, int b) {
	a = std::max(a, b);
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= m; ++i) {
		read(a[i]);
		lst[i] = p[a[i]];
		p[a[i]] = i;
	}
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
			mn[i] = i;
		} else {
			mn[i] = 1;
			++s;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
			mx[i] = ++s;
		}
	}
	T1.init(n), T2.init(m);
	for (int i = 1; i <= m; ++i) {
		T2.add(lst[i] + 1);
		if (!lst[i]) {
			T1.add(a[i]);
			upd(mx[a[i]], T1.query(n) - T1.query(a[i]) + a[i]);
		} else {
			upd(mx[a[i]], T2.query(lst[i]) - lst[i] + 1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i]) {
			upd(mx[i], T2.query(p[i]) - p[i] + 1);
		}
		print(mn[i], ' '), print(mx[i]);
	}
}