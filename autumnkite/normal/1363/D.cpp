#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#ifndef AT_HOME
// #define getchar() IO::myGetchar()
// #define putchar(x) IO::myPutchar(x)
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

int n, k, mx, ans[1005], vis[1005];
std::vector<int> S[1005];
char dfcmd[10005];

int Query(const std::vector<int> &id) {
	putchar('?'), putchar(' ');
	print((int)id.size(), ' ');
	for (int v : id) {
		print(v, ' ');
	}
	putchar('\n');
	fflush(stdout);
	int x;
	read(x);
	return x;
}

void Solve(int l, int r) {
	int md = (l + r) >> 1;
	for (int i = 1; i <= n; ++i) {
		vis[i] = 0;
	}
	for (int i = l; i <= md; ++i) {
		for (int v : S[i]) {
			vis[v] = 1;
		}
	}
	std::vector<int> t;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			t.push_back(i);
		}
	}
	int tmp = Query(t);
	if (l == r) {
		ans[l] = tmp;
		return;
	}
	if (tmp == mx) {
		for (int i = l; i <= md; ++i) {
			ans[i] = mx;
		}
		Solve(md + 1, r);
	} else {
		for (int i = md + 1; i <= r; ++i) {
			ans[i] = mx;
		}
		Solve(l, md);
	}
}

void solve() {
	read(n), read(k);
	for (int i = 1; i <= k; ++i) {
		int c;
		read(c);
		S[i].resize(c);
		for (int j = 0; j < c; ++j) {
			read(S[i][j]);
		}
	}
	std::vector<int> t;
	for (int i = 1; i <= n; ++i) {
		t.push_back(i);
	}
	mx = Query(t);
	Solve(1, k);
	putchar('!'), putchar(' ');
	for (int i = 1; i <= k; ++i) {
		print(ans[i], ' ');
	}
	putchar('\n');
	fflush(stdout);
	readStr(dfcmd);
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}