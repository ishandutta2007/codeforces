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

const int N = 100005;

int n;
std::vector<int> E[N];

int dep[N];

namespace Checker {
	int lst[N];
	bool flag;

	void dfs(int u, int fa = 0) {
		dep[u] = dep[fa] + 1;
		if (~lst[dep[u]] && E[u].size() != E[lst[dep[u]]].size()) {
			flag = 0;
		}
		lst[dep[u]] = u;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
			}
		}
	}

	bool check(int rt) {
		for (int i = 1; i <= n; ++i) {
			dep[i] = 0, lst[i] = -1;
		}
		flag = 1, dfs(rt);
		return flag;
	}

	int find(int rt) {
		auto fd = [&](int x) {
			int lst = rt;
			while ((int)E[x].size() == 2) {
				int tmp = x;
				x = E[x][0] ^ E[x][1] ^ lst;
				lst = tmp;
			}
			if ((int)E[x].size() == 1 && check(x)) {
				return x;
			} else {
				return -1;
			}
		};
		int t = fd(E[rt][0]);
		if (t != -1) {
			return t;
		}
		for (int i = 1; i <= n; ++i) {
			dep[i] = 0, lst[i] = -1;
		}
		flag = 1, dep[rt] = 1;
		for (int i = 0; i < (int)E[rt].size(); ++i) {
			dfs(E[rt][i], rt);
			if (!flag) {
				return fd(E[rt][i]);
			}
		}
		return -1;
	}
}

namespace Diameter {
	int dep[N], fa[N];

	void dfs(int u) {
		dep[u] = dep[fa[u]] + 1;
		for (int v : E[u]) {
			if (v != fa[u]) {
				fa[v] = u, dfs(v);
			}
		}
	}

	std::vector<int> find() {
		fa[1] = 0, dfs(1);
		int u = std::max_element(dep + 1, dep + 1 + n) - dep;
		fa[u] = 0, dfs(u);
		std::vector<int> p;
		int v = std::max_element(dep + 1, dep + 1 + n) - dep;
		for (int i = v; i; i = fa[i]) {
			p.push_back(i);
		}
		return p;
	}
}

void solve() {
	read(n);
	for (int i = 1, u, v; i < n; ++i) {
		read(u), read(v);
		E[u].push_back(v), E[v].push_back(u);
	}
	std::vector<int> dm = Diameter::find();
	if (Checker::check(dm[0])) {
		print(dm[0]);
		return;
	}
	if (Checker::check(dm.back())) {
		print(dm.back());
		return;
	}
	if (!(dm.size() & 1)) {
		print(-1);
		return;
	}
	int x = (int)dm.size() / 2;
	if (Checker::check(dm[x])) {
		print(dm[x]);
		return;
	}
	print(Checker::find(dm[x]));
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}