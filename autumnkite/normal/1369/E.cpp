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

const int N = 100005, M = 200005;

int n, m;
int a[N];

struct Edge {
	int u, v;
} edge[M];

std::vector<int> E[N];

bool edge_added[M], node_added[N];
std::vector<int> now;

void addNode(int u) {
	if (node_added[u]) {
		return;
	}
	node_added[u] = 1;
	for (int id : E[u]) {
		if (!edge_added[id]) {
			edge_added[id] = 1;
			now.push_back(id);
		}
	}
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		read(edge[i].u), read(edge[i].v);
		E[edge[i].u].push_back(i), E[edge[i].v].push_back(i);
		--a[edge[i].u], --a[edge[i].v];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= 0) {
			addNode(i);
		}
	}
	for (int i = 0; i < (int)now.size(); ++i) {
		int id = now[i];
		++a[edge[id].u], ++a[edge[id].v];
		if (a[edge[id].u] >= 0) {
			addNode(edge[id].u);
		}
		if (a[edge[id].v] >= 0) {
			addNode(edge[id].v);
		}
	}
	if ((int)now.size() < m) {
		printStr("DEAD");
		return 0;
	}
	std::reverse(now.begin(), now.end());
	printStr("ALIVE");
	for (int id : now) {
		print(id, ' ');
	}
}