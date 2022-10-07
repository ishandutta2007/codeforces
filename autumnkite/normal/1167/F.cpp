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

const int N = 500005, P = 1000000007;

int n, a[N];

struct BIT {
	int c[N];
	
	void add(int x, int v) {
		for (; x <= n; x += x & -x) {
			c[x] = (c[x] + v) % P;
		}
	}
	
	void add(int l, int r, int v) {
		add(l, v), add(r + 1, -v);
	}
	
	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s = (s + c[x]) % P;
		}
		return s;
	}
} T, Tv;

void solve() {
	read(n);
	std::vector<std::pair<int, int>> vec;
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		vec.push_back({a[i], i});
	}
	std::sort(vec.begin(), vec.end());
	int ans = 0;
	for (auto p : vec) {
		int x = p.second;
		T.add(x, n, 1ll * x * (n + 1) % P);
		Tv.add(x, n, P - x);
		Tv.add(1, x - 1, n - x + 1);
		ans = (ans + (T.query(x) + 1ll * Tv.query(x) * x) % P * a[x]) % P;
//		debug("%d\n", ans);
	}
	print(ans);
}

int main() {
	int T = 1;
//	read(T);
	while (T--) {
		solve();
	}
}