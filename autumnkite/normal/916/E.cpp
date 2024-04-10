#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)

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

class BIT {
	int n;
	std::vector<long long> c, ci;

	void add(int x, long long v) {
		long long t = v * x;
		for (++x; x <= n; x += x & -x) {
			c[x] += v;
			ci[x] += t;
		}
	}

	long long query(int x) {
		int t = x;
		long long s = 0, si = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
			si += ci[x];
		}
		return s * t - si;
	}

public:
	BIT(int _n) : n(_n), c(n + 1), ci(n + 1) {}

	void add(int l, int r, long long v) {
		add(l, v), add(r, -v);
	}

	long long query(int l, int r) {
		return query(r) - query(l);
	}
};

int main() {
	int n, q;
	read(n), read(q);
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		read(a[i]);
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		read(u), read(v);
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	std::vector<int> fa(n), sz(n), son(n), dep(n), dfn(n);
	int idx = 0;
	
	std::function<void(int)> dfs1 = [&](int u) {
		dfn[u] = idx++;
		sz[u] = 1;
		son[u] = -1;
		if (fa[u] != -1) {
			E[u].erase(std::find(E[u].begin(), E[u].end(), fa[u]));
		}
		for (int v : E[u]) {
			dep[v] = dep[u] + 1;
			fa[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if (son[u] == -1 || sz[v] > sz[son[u]]) {
				son[u] = v;
			}
		}
	};

	fa[0] = -1, dep[0] = 0, dfs1(0);
	
	std::vector<int> top(n);
	
	std::function<void(int, int)> dfs2 = [&](int u, int tp) {
		top[u] = tp;
		if (son[u] != -1) {
			dfs2(son[u], tp);
		}
		for (int v : E[u]) {
			if (v != son[u]) {
				dfs2(v, v);
			}
		}
	};

	dfs2(0, 0);
	
	auto LCA = [&](int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] > dep[top[v]]) {
				u = fa[top[u]];
			} else {
				v = fa[top[v]];
			}
		}
		return dep[u] < dep[v] ? u : v;
	};
	
	auto get_son = [&](int u, int v) {
		return *(--std::upper_bound(E[u].begin(), E[u].end(), v, [&](int x, int y) {
			return dfn[x] < dfn[y];
		}));
	};

	BIT T(n);
	for (int i = 0; i < n; ++i) {
		T.add(dfn[i], dfn[i] + 1, a[i]);
	}
	int rt = 0;	
	while (q--) {
		int op;
		read(op);
		if (op == 1) {
			read(rt);
			--rt;
		} else if (op == 2) {
			int u, v, w;
			read(u), read(v), read(w);
			--u, --v;
			int zuv = LCA(u, v), zur = LCA(u, rt), zvr = LCA(v, rt);
			int z;
			if (dep[zuv] >= dep[zur] && dep[zuv] >= dep[zvr]) {
				z = zuv;
			} else if (dep[zur] >= dep[zuv] && dep[zur] >= dep[zvr]) {
				z = zur;
			} else {
				z = zvr;
			}
			if (z == rt) {
				T.add(0, n, w);
			} else if (dfn[z] < dfn[rt] && dfn[rt] < dfn[z] + sz[z]) {
				int t = get_son(z, rt);
				T.add(0, n, w);
				T.add(dfn[t], dfn[t] + sz[t], -w);
			} else {
				T.add(dfn[z], dfn[z] + sz[z], w);
			}
		} else {
			int u;
			read(u);
			--u;
			if (u == rt) {
				print(T.query(0, n));
			} else if (dfn[u] < dfn[rt] && dfn[rt] < dfn[u] + sz[u]) {
				int t = get_son(u, rt);
				print(T.query(0, n) - T.query(dfn[t], dfn[t] + sz[t]));
			} else {
				print(T.query(dfn[u], dfn[u] + sz[u]));
			}
		}
	}
}