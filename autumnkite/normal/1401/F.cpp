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

const int N = 1 << 18;

int n, q, a[N];

struct BIT {
	static const int N = 1 << 19;

	int n;
	int c[N];

	void init(int _n) {
		n = _n;
		for (int i = 1; i <= n; ++i) {
			c[i] = 0;
		}
	}

	void flip(int x) {
		for (; x <= n; x += x & -x) {
			c[x] ^= 1;
		}
	}

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s ^= c[x];
		}
		return s;
	}
} TT;

struct SegmentTree {
	static const int N = 1 << 19;

	int ls[N], rs[N];
	long long sum[N];

	void build(int u, int l, int r) {
		if (l == r) {
			sum[u] = a[l];
			return;
		}
		int md = (l + r) >> 1;
		ls[u] = u << 1, rs[u] = u << 1 | 1;
		build(ls[u], l, md), build(rs[u], md + 1, r);
		sum[u] = sum[ls[u]] + sum[rs[u]];
	}

	void modify(int u, int l, int r, int x, int v) {
		if (l == r) {
			sum[u] = v;
			return;
		}
		int md = (l + r) >> 1;
		if (TT.query(u)) {
			std::swap(ls[u], rs[u]);
			TT.flip(u), TT.flip(u + 1);
		}
		if (x <= md) {
			modify(ls[u], l, md, x, v);
		} else {
			modify(rs[u], md + 1, r, x, v);
		}
		sum[u] = sum[ls[u]] + sum[rs[u]];
	}

	long long query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return sum[u];
		}
		int md = (l + r) >> 1;
		if (TT.query(u)) {
			std::swap(ls[u], rs[u]);
			TT.flip(u), TT.flip(u + 1);
		}
		if (R <= md) {
			return query(ls[u], l, md, L, R);
		} else if (L > md) {
			return query(rs[u], md + 1, r, L, R);
		} else {
			return query(ls[u], l, md, L, R) + query(rs[u], md + 1, r, L, R);
		}
	}
} T;

int main() {
	read(n), read(q);
	for (int i = 0; i < (1 << n); ++i) {
		read(a[i]);
	}
	TT.init((1 << (n + 1)) - 1);
	T.build(1, 0, (1 << n) - 1);
	while (q--) {
		int op, x, y;
		read(op);
		if (op == 1) {
			read(x), read(y);
			--x;
			T.modify(1, 0, (1 << n) - 1, x, y);
		} else if (op == 2) {
			read(x);
			TT.flip(1 << (n - x));
		} else if (op == 3) {
			read(x);
			TT.flip(1 << (n - x - 1));
			TT.flip(1 << (n - x));
		} else {
			read(x), read(y);
			--x, --y;
			print(T.query(1, 0, (1 << n) - 1, x, y));
		}
	}
}
/*
2 2
7 4 9 9
1 2 8
4 2 4
*/