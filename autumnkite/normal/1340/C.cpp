#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

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

const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3fll;

int n, m, p[10005], g, r, f[10005][1005];

void solve() {
	read(n), read(m);
	for (int i = 1; i <= m; ++i) {
		read(p[i]);
	}
	std::sort(p + 1, p + 1 + m);
	read(g), read(r);
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < g; ++j) {
			f[i][j] = INF;
		}
	}
	f[1][0] = 0;
	std::deque<std::pair<int, int>> Q;
	Q.push_back({1, 0});
	while (!Q.empty()) {
		int u = Q.front().first, t = Q.front().second;
		Q.pop_front();
		// debug("%d %d %d\n", u, t, f[u][t]);
		if (u > 1 && t + p[u] - p[u - 1] <= g) {
			int nt = t + p[u] - p[u - 1], w = 0;
			if (nt == g) {
				nt = 0, w = 1;
			}
			if (f[u - 1][nt] == INF) {
				f[u - 1][nt] = f[u][t] + w;
				if (w == 0) {
					Q.push_front({u - 1, nt});
				} else {
					Q.push_back({u - 1, nt});
				}
			}
		}
		if (u < m && t + p[u + 1] - p[u] <= g) {
			int nt = t + p[u + 1] - p[u], w = 0;
			if (nt == g) {
				nt = 0, w = 1;
			}
			if (f[u + 1][nt] == INF) {
				f[u + 1][nt] = f[u][t] + w;
				if (w == 0) {
					Q.push_front({u + 1, nt});
				} else {
					Q.push_back({u + 1, nt});
				}
			}
		}
	}
	long long ans = INFll;
	if (f[m][0] < INF) {
		ans = 1ll * f[m][0] * (g + r) - r;
	}
	for (int i = 1; i < g; ++i) {
		if (f[m][i] < INF) {
			ans = std::min(ans, 1ll * f[m][i] * (g + r) + i);
		}
	}
	if (ans == INFll) {
		print(-1);
	} else {
		print(ans);
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}