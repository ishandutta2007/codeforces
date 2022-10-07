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

const int N = 1000005;

int n, m;
int a[N], b[N];
std::vector<int> c[N], d[N];

struct BIT {
	int c[N];

	void add(int x, int v) {
		for (; x < N; x += x & -x) {
			c[x] += v;
		}
	}

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
} T;

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		int x, l, r;
		read(x), read(l), read(r);
		if (l == 0) {
			a[x] = r;
		} else {
			b[x] = l;
		}
	}
	a[1000000] = 1000000;
	for (int i = 1; i <= m; ++i) {
		int x, l, r;
		read(x), read(l), read(r);
		if (l == 0) {
			c[r].push_back(x);
		} else {
			d[l].push_back(x);
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i]) {
			T.add(1, 1);
			T.add(a[i] + 1, -1);
		}
		if (b[i]) {
			T.add(b[i], 1);
		}
		for (int v : c[i]) {
			ans += T.query(v);
		}
		if (a[i] == 1000000) {
			++ans;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int v : d[i]) {
			ans += std::max(0, T.query(v) - 1);
		}
		if (a[i]) {
			T.add(1, -1);
			T.add(a[i] + 1, 1);
		}
		if (b[i]) {
			T.add(b[i], -1);
		}
	}
	print(ans);
}
/*
3 3
4 0 1
2 0 5
3 1 1000000
2 3 1000000
4 0 4
3 0 1000000
*/