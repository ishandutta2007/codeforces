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

const int N = 200005;

int n;
long long a[N], b[N];
int m;
char op[10000005];

namespace n2 {
	long long ta, tb;

	long long calc(long long a, long long b) {
		if (a > b) {
			std::swap(a, b);
		}
		if (a < ta || b < tb) {
			return -1;
		}
		if (a == ta) {
			if ((b - tb) % a == 0) {
				return (b - tb) / a;
			} else {
				return -1;
			}
		}
		long long res = calc(a, b % a);
		if (res == -1) {
			return -1;
		} else {
			return res + b / a;
		}
	}

	void getAns(long long a, long long b) {
		if (a > b) {
			getAns(b, a);
			op[++m] = 'R';
			return;
		}
		if (a == ta && b == tb) {
			return;
		}
		getAns(a, b - a);
		op[++m] = 'P';
	}

	void solve() {
		m = 0;
		ta = a[1], tb = a[2];
		if (ta > tb) {
			std::swap(ta, tb);
			op[++m] = 'R';
		}
		long long res = calc(b[1], b[2]);
		if (res == -1) {
			printStr("IMPOSSIBLE");
			return;
		}
		if (res > 200000) {
			printStr("BIG");
			print(res);
			return;
		}
		printStr("SMALL");
		getAns(b[1], b[2]);
		print(m);
		printStr(op + 1, m);
	}
}

bool check() {
	for (int i = 1; i <= n; ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool checkRev() {
	for (int i = 1; i <= n; ++i) {
		if (a[i] != b[n - i + 1]) {
			return false;
		}
	}
	return true;
}

void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		read(b[i]);
	}
	if (n == 1) {
		if (a[1] == b[1]) {
			printStr("SMALL");
			print(0);
			printStr("");
			return;
		} else {
			printStr("IMPOSSIBLE");
			return;
		}
	}
	if (n == 2) {
		n2::solve();
		return;
	}
	int cnt = 0;
	m = 0;
	while (!check() && !checkRev()) {
		bool flag0 = 1, flag1 = 1;
		for (int i = 2; i <= n; ++i) {
			flag0 &= b[i] > b[i - 1];
			flag1 &= b[i] < b[i - 1];
		}
		if (!flag0 && !flag1) {
			printStr("IMPOSSIBLE");
			return;
		}
		if (flag1) {
			std::reverse(b + 1, b + 1 + n);
			op[++m] = 'R';
		}
		for (int i = n; i >= 2; --i) {
			b[i] -= b[i - 1];
		}
		op[++m] = 'P';
		++cnt;
	}
	if (!check()) {
		std::reverse(b + 1, b + 1 + n);
		op[++m] = 'R';
	}
	if (cnt > 200000) {
		printStr("BIG");
		print(cnt);
	} else {
		printStr("SMALL");
		print(m);
		for (int i = m; i; --i) {
			putchar(op[i]);
		}
		putchar('\n');
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}