#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

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

const int N = 1000005;

int n, a[N], b[N];

int edge, hd[1 << 20], to[N << 1], pr[N << 1], vis[N << 1], d[1 << 20];

void addEdge(int u, int v) {
	to[edge] = v, pr[edge] = hd[u], vis[edge] = 0, hd[u] = edge++;
}

int idx, ans[N];

void dfs(int u) {
	for (int &i = hd[u]; ~i; i = pr[i]) {
		if (!vis[i]) {
			vis[i] = vis[i ^ 1] = 1;
			int t = i;
			dfs(to[i]);
			ans[++idx] = t;
			if (i == -1) {
				break;
			}
		}
	}
}

bool check(int k) {
	int mask = (1 << k) - 1;
	edge = 0;
	for (int i = 0; i < (1 << k); ++i) {
		hd[i] = -1, d[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		int x = a[i] & mask, y = b[i] & mask;
		addEdge(x, y), addEdge(y, x);
		++d[x], ++d[y];
	}
	for (int i = 0; i < (1 << k); ++i) {
		if (d[i] & 1) {
			return 0;
		}
	}
	idx = 0;
	for (int i = 0; i < (1 << k); ++i) {
		if (d[i]) {
			dfs(i);
			break;
		}
	}
	if (idx < n) {
		return 0;
	}
	return 1;
}

void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(a[i]), read(b[i]);
	}
	int m = 0;
	for (int i = 20; ~i; --i) {
		if (check(i)) {
			m = i;
			break;
		}
	}
	print(m);
	for (int i = 1; i <= idx; ++i) {
		int id = ans[i] >> 1, op = ans[i] & 1;
		++id;
		if (!op) {
			print(id * 2, ' '), print(id * 2 - 1, ' ');
		} else {
			print(id * 2 - 1, ' '), print(id * 2, ' ');
		}
	}
	putchar('\n');
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}