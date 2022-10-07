#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

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

int n, m, x, k, y, a[N], b[N];

void solve() {
	read(n), read(m);
	read(x), read(k), read(y);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		read(b[i]);
	}
	std::vector<int> pos;
	pos.push_back(0);
	int j = 1;
	for (int i = 1; i <= m; ++i) {
		while (j <= n && a[j] != b[i]) {
			++j;
		}
		if (j > n) {
			print(-1);
			return;
		}
		pos.push_back(j);
	}
	pos.push_back(n + 1);
	long long tmp = std::min(1ll * x, 1ll * k * y), ans = 0;
	a[0] = a[n + 1] = 0;
	for (int i = 1; i < (int)pos.size(); ++i) {
		int mx = std::max_element(a + pos[i - 1], a + pos[i] + 1) - a;
		bool flag = pos[i - 1] < mx && mx < pos[i];
		int len = pos[i] - pos[i - 1] - 1;
		if (flag && len < k) {
			print(-1);
			return;
		}
		ans += 1ll * (len / k) * tmp + 1ll * (len % k) * y;
		if (flag) {
			ans += x - tmp;
		}
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