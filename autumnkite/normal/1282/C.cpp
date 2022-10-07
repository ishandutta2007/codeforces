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

int n, T, c[2];
std::pair<int, int> a[N];
int suf[N];

void solve() {
	read(n), read(T), read(c[0]), read(c[1]);
	for (int i = 1; i <= n; ++i) {
		read(a[i].second);
	}
	for (int i = 1; i <= n; ++i) {
		read(a[i].first);
	}
	std::sort(a + 1, a + 1 + n);
	a[n + 1].first = T + 1;
	suf[n + 1] = 0;
	for (int i = n; i; --i) {
		suf[i] = suf[i + 1] + (a[i].second == 0);
	}
	long long sum = 0, ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (i > 0) {
			sum += c[a[i].second];
		}
		if (sum < a[i + 1].first) {
			long long t = a[i + 1].first - sum - 1, s = 0;
			if (t < 1ll * suf[i + 1] * c[0]) {
				s = t / c[0];
			} else {
				s = suf[i + 1] + (t - 1ll * suf[i + 1] * c[0]) / c[1];
			}
			s = std::min<long long>(s, n - i);
			ans = std::max(ans, i + s);
		}
	}
	print(ans);
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}