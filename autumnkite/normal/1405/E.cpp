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

const int N = 300005;

int n, q, a[N], vis[N];

std::vector<std::pair<int, int>> Q[N];

int ans[N];

struct SegmentTree {
	static const int N = ::N << 2, INF = 0x3f3f3f3f;

	int sum[N];
	int mn[N];
	int lz[N];

	void build(int u, int l, int r) {
		if (l == r) {
			if (vis[l]) {
				sum[u] = 1, mn[u] = vis[l] - a[l] - 1;
			} else {
				sum[u] = 0, mn[u] = INF;
			}
			return;
		}
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		sum[u] = sum[u << 1] + sum[u << 1 | 1];
		mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
	}

	void add(int u, int v) {
		mn[u] += v, lz[u] += v;
	}

	void down(int u) {
		add(u << 1, lz[u]), add(u << 1 | 1, lz[u]), lz[u] = 0;
	}

	void erase(int u, int l, int r, int x) {
		if (l == r) {
			sum[u] = 0;
			mn[u] = INF;
			return;
		}
		int md = (l + r) >> 1;
		down(u);
		if (x <= md) {
			erase(u << 1, l, md, x);
			add(u << 1 | 1, -1);
		} else {
			erase(u << 1 | 1, md + 1, r, x);
		}
		sum[u] = sum[u << 1] + sum[u << 1 | 1];
		mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
	}

	int find(int u, int l, int r) {
		if (l == r) {
			return l;
		}
		int md = (l + r) >> 1;
		down(u);
		if (mn[u << 1] < 0) {
			return find(u << 1, l, md);
		} else {
			return find(u << 1 | 1, md + 1, r);
		}
	}

	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return sum[u];
		}
		int md = (l + r) >> 1;
		down(u);
		if (R <= md) {
			return query(u << 1, l, md, L, R);
		} else if (L > md) {
			return query(u << 1 | 1, md + 1, r, L, R);
		} else {
			return query(u << 1, l, md, L, R) + query(u << 1 | 1, md + 1, r, L, R);
		}
	}
} T;

void solve() {
	read(n), read(q);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		a[i] = i - a[i];
	}
	for (int i = 1; i <= q; ++i) {
		int x, y;
		read(x), read(y);
		Q[x].push_back({y, i});
	}
	int now = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= 0 && a[i] <= now) {
			++now, vis[i] = now;
		}
	}
	T.build(1, 1, n);
	for (int i = 0; i <= n; ++i) {
		if (i && T.query(1, 1, n, i, i)) {
			T.erase(1, 1, n, i);
			while (T.mn[1] < 0) {
				int p = T.find(1, 1, n);
				T.erase(1, 1, n, p);
			}
		}
		for (auto qu : Q[i]) {
			ans[qu.second] = T.query(1, 1, n, i + 1, n - qu.first);
		}
	}
	for (int i = 1; i <= q; ++i) {
		print(ans[i]);
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}