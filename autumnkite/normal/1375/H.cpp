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

const int N = 5005;

int n, q;
int a[N], p[N], f[100005];

std::vector<std::pair<int, int>> ans;

struct SegmentTree {
	std::vector<int> pos[N << 2];
	std::map<std::pair<int, int>, int> mp[N << 2];

	void build(int u, int l, int r) {
		for (int i = l; i <= r; ++i) {
			pos[u].push_back(p[i]);
		}
		std::sort(pos[u].begin(), pos[u].end());
		if (l == r) {
			return;
		}
		int md = (l + r) >> 1;
		build(u << 1, l, md);
		build(u << 1 | 1, md + 1, r);
	}

	int solve(int u, int L, int R) {
		int l = std::lower_bound(pos[u].begin(), pos[u].end(), L) - pos[u].begin();
		int r = std::upper_bound(pos[u].begin(), pos[u].end(), R) - pos[u].begin() - 1;
		if (l > r) {
			return 0;
		}
		if (l == r) {
			return pos[u][l];
		}
		if (mp[u].count({l, r})) {
			return mp[u][{l, r}];
		}
		int x = solve(u << 1, L, R), y = solve(u << 1 | 1, L, R);
		if (!x || !y) {
			return mp[u][{l, r}] = x | y;
		} else {
			ans.push_back({x, y});
			return mp[u][{l, r}] = n + (int)ans.size();
		}
	}
} T;

void solve() {
	read(n), read(q);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		p[a[i]] = i;
	}
	T.build(1, 1, n);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		read(l), read(r);
		f[i] = T.solve(1, l, r);
	}
	print((int)ans.size() + n);
	for (auto v : ans) {
		print(v.first, ' '), print(v.second);
	}
	for (int i = 1; i <= q; ++i) {
		print(f[i], " \n"[i == q]);
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}