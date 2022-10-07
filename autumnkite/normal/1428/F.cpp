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

const int N = 500005, LG = 19;

int n;
char a[N];
int m;
int Log[N];
int bel[N];

struct Apple {
	int l, r;

	Apple() {}
	
	Apple(int _l, int _r) : l(_l), r(_r) {}

	bool operator < (const Apple &rhs) const {
		return r - l < rhs.r - rhs.l || (r - l == rhs.r - rhs.l && l > rhs.l);
	}

	bool operator == (const Apple &rhs) const {
		return l == rhs.l && r == rhs.r;
	}
} c[N][LG];

void init() {
	m = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == '1') {
			if (i == 1 || a[i - 1] == '0') {
				c[++m][0] = Apple(i, i);
			} else {
				c[m][0].r = i;
			}
		}
		bel[i] = m;
	}
	Log[1] = 0;
	for (int i = 2; i <= m; ++i) {
		Log[i] = Log[i >> 1] + 1;
	}
	for (int j = 1; j < LG; ++j) {
		for (int i = 1; i <= m - (1 << j) + 1; ++i) {
			c[i][j] = std::max(c[i][j - 1], c[i + (1 << (j - 1))][j - 1]);
		}
	}
}

Apple query(int l, int r) {
	int tl = bel[l] + 1;
	int tr = a[r] == '0' ? bel[r] : bel[r] - 1;
	if (a[l] == '1' && a[r] == '1' && bel[l] == bel[r]) {
		return Apple(l, r);
	}
	Apple cl = a[l] == '0' ? Apple(l + 1, l) : Apple(l, c[bel[l]][0].r);
	Apple cr = a[r] == '0' ? Apple(r, r - 1) : Apple(c[bel[r]][0].l, r);
	if (tl > tr) {
		return std::max(cl, cr);
	} else {
		int t = Log[tr - tl + 1];
		return std::max(std::max(c[tl][t], c[tr - (1 << t) + 1][t]), std::max(cl, cr));
	}
}

int findL(int x) {
	int l = 1, r = x, ans = x + 1;
	while (l <= r) {
		int md = (l + r) >> 1;
		if (query(md, x) == Apple(std::max(md, c[bel[x]][0].l), x)) {
			ans = md;
			r = md - 1;
		} else {
			l = md + 1;
		}
	}
	return ans;
}

int findR(int x) {
	int l = x, r = n, ans = x - 1;
	while (l <= r) {
		int md = (l + r) >> 1;
		if (query(x, md) == Apple(x, std::min(md, c[bel[x]][0].r))) {
			ans = md;
			l = md + 1;
		} else {
			r = md - 1;
		}
	}
	return ans;
}

long long calc(int n) {
	return 1ll * (n + 1) * (n + 1) * n / 2 - 1ll * n * (n + 1) * (2 * n + 1) / 6;
}

void solve() {
	read(n);
	readStr(a + 1);
	init();
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == '1') {
			ans += 1ll * (c[bel[i]][0].r - i + 1) * (findR(i) - c[bel[i]][0].r);
			ans += 1ll * (i - c[bel[i]][0].l + 1) * (c[bel[i]][0].l - findL(i));
		}
	}
	for (int i = 1; i <= m; ++i) {
		int L = findL(c[i][0].r), R = findR(c[i][0].l);
		ans += 1ll * (c[i][0].r - c[i][0].l + 1) * (c[i][0].l - L) * (R - c[i][0].r);
		ans += calc(c[i][0].r - c[i][0].l + 1);
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