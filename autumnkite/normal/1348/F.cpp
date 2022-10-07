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

const int N = 200005, LG = 18;

int n, l[N], r[N];
int p[N], a[N];
int Log[N], mn[N][LG];
std::vector<std::pair<int, int>> vec[N];

int my_min(int x, int y) {
	return l[p[x]] < l[p[y]] ? x : y;
}

void initST() {
	Log[1] = 0;
	for (int i = 2; i <= n; ++i) {
		Log[i] = Log[i >> 1] + 1;
	}
	for (int i = 1; i <= n; ++i) {
		mn[i][0] = i;
	}
	for (int j = 1; j < LG; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			mn[i][j] = my_min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int t = Log[r - l + 1];
	return my_min(mn[l][t], mn[r - (1 << t) + 1][t]);
}

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(l[i]), read(r[i]);
		vec[r[i]].push_back({l[i], i});
	}
	std::priority_queue<std::pair<int, int>> Q;
	for (int i = n; i; --i) {
		for (auto v : vec[i]) {
			Q.push(v);
		}
		p[i] = Q.top().second;
		Q.pop();
		a[p[i]] = i;
	}
	initST();
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == r[p[i]]) {
			continue;
		}
		int j = query(i + 1, r[p[i]]);
		if (l[p[j]] <= i) {
			x = i, y = j;
			break;
		}
	}
	if (!x) {
		printStr("YES");
		for (int i = 1; i <= n; ++i) {
			print(a[i], ' ');
		}
		putchar('\n');
	} else {
		printStr("NO");
		for (int i = 1; i <= n; ++i) {
			print(a[i], ' ');
		}
		putchar('\n');
		std::swap(a[p[x]], a[p[y]]);
		for (int i = 1; i <= n; ++i) {
			print(a[i], ' ');
		}
		putchar('\n');
	}
}