#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
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

const int N = 100005, NN = 500005;

int n, m, c, q, idx;
int fa[NN];
std::vector<int> e[NN];
std::set<int> S[NN], E[NN];
std::map<int, int> mp[N];

int find(int x) {
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) {
		return false;
	}
	if (S[x].size() < S[y].size()) {
		std::swap(x, y);
	}
	for (int v : S[y]) {
		for (int u : e[v]) {
			E[u].erase(y), E[u].insert(x);
		}
		E[v].erase(y), E[v].insert(x);
		S[x].insert(v);
	}
	S[y].clear();
	fa[y] = x;
	return true;
}

void addOneEdge(int u, int v, int w) {
	if (!mp[u].count(w)) {
		mp[u][w] = ++idx;
		fa[idx] = idx, S[idx].insert(idx), E[idx].insert(idx);
	}
	merge(v, mp[u][w]);
}

void addEdge(int u, int v, int w) {
	addOneEdge(u, v, w), addOneEdge(v, u, w);
	E[u].insert(find(v)), E[v].insert(find(u));
	e[u].push_back(v), e[v].push_back(u);
}

void solve() {
	read(n), read(m), read(c), read(q);
	idx = n;
	for (int i = 1; i <= idx; ++i) {
		fa[i] = i, S[i].insert(i), E[i].insert(i);
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		read(u), read(v), read(w);
		addEdge(u, v, w);
	}
	while (q--) {
		char op[5];
		int u, v, w;
		readStr(op), read(u), read(v);
		if (*op == '+') {
			read(w);
			addEdge(u, v, w);
		} else {
			if (E[v].count(find(u))) {
				printStr("Yes");
			} else {
				printStr("No");
			}
		}
	}
}

int main() {
	int T = 1;
//	read(T);
	while (T--) {
		solve();
	}
}