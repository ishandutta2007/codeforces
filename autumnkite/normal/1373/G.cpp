#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

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

const int N = 600005;

int nn, n, m, k;
std::set<std::pair<int, int>> S;

struct SegmentTree {
	int mn[N << 2];
	int lz[N << 2];

	void add(int u, int v) {
		mn[u] += v;
		lz[u] += v;
	}

	void down(int u) {
		add(u << 1, lz[u]), add(u << 1 | 1, lz[u]);
		lz[u] = 0;
	}

	void modify(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			add(u, v);
			return;
		}
		int md = (l + r) >> 1;
		down(u);
		if (L <= md) {
			modify(u << 1, l, md, L, R, v);
		}
		if (R > md) {
			modify(u << 1 | 1, md + 1, r, L, R, v);
		}
		mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
	}

	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return mn[u];
		}
		int md = (l + r) >> 1;
		down(u);
		if (R <= md) {
			return query(u << 1, l, md, L, R);
		} else if (L > md) {
			return query(u << 1 | 1, md + 1, r, L, R);
		} else {
			return std::min(query(u << 1, l, md, L, R), 
			  query(u << 1 | 1, md + 1, r, L, R));
		}
	}
} Tf;

struct BIT {
	int c[N];

	void add(int x, int v) {
		for (; x <= n; x += x & -x) {
			c[x] += v;
		}
	}

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
} Tg;

int findf(int x) {
	int l = x, r = n, md, ans = 0;
	while (l <= r) {
		md = (l + r) >> 1;
		if (Tf.query(1, 1, n, x, md) == 0) {
			ans = md;
			r = md - 1;
		} else {
			l = md + 1;
		}
	}
	return ans;
}

int findg(int x) {
	int tmp = Tg.query(x - 1);
	int l = x, r = n, md, ans = 0;
	while (l <= r) {
		md = (l + r) >> 1;
		if (Tg.query(md) - tmp <= md - x) {
			ans = md;
			r = md - 1;
		} else {
			l = md + 1;
		}
	}
	return ans;
}

int findn(int cnt) {
	int l = 1, r = n, md, ans = 0;
	while (l <= r) {
		md = (l + r) >> 1;
		if (Tg.query(md) == cnt) {
			ans = md;
			r = md - 1;
		} else {
			l = md + 1;
		}
	}
	return ans;
}

void solve() {
	read(n), read(k), read(m);
	int nn = n;
	n = 2 * n + m;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		read(x), read(y);
		int t = y + std::max(x - k, k - x);
		if (!S.count({x, y})) {
			S.insert({x, y});
			int p = findg(t);
			Tg.add(p, 1);
			if (t < p) {
				Tf.modify(1, 1, n, t, p - 1, 1);
			}
		} else {
			S.erase({x, y});
			int p = findf(t);
			Tg.add(p, -1);
			if (t < p) {
				Tf.modify(1, 1, n, t, p - 1, -1);
			}
		}
		print(std::max(0, findn(S.size()) - nn));
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}

/*
4 1 20
1 1
1 2
1 1
1 3
1 1
1 2
1 1
1 4
1 1
1 2
1 1
1 3
1 1
1 2
1 1
2 1
1 1
1 2
1 1
1 3
*/

/*
4 1 4
1 4
2 1
1 2
1 3
*/