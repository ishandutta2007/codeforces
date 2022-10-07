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

int n, m, a[300005][8];
int id[1 << 8];

std::pair<int, int> get(int md) {
	for (int S = 0; S < (1 << m); ++S) {
		id[S] = -1;
	}
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] >= md) {
				t |= 1 << j;
			}
		}
		id[t] = i;
	}
	for (int i = 0; i < m; ++i) {
		for (int S = 0; S < (1 << m); ++S) {
			if (!(S >> i & 1)) {
				id[S] = std::max(id[S], id[S ^ (1 << i)]);
			}
		}
	}
	int U = (1 << m) - 1;
	for (int S = 0; S < (1 << m); ++S) {
		if (~id[S] && ~id[U ^ S]) {
			return {id[S], id[U ^ S]};
		}
	}
	return {-1, -1};
}

void solve() {
	read(n), read(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			read(a[i][j]);
		}
	}
	int l = 0, r = 1000000000, ans = 0;
	while (l <= r) {
		int md = (l + r) >> 1;
		if (get(md).first != -1) {
			ans = md;
			l = md + 1;
		} else {
			r = md - 1;
		}
	}
	std::pair<int, int> p = get(ans);
	print(p.first + 1, ' '), print(p.second + 1);
	// debug("%d\n", ans);
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}