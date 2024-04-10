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

const int N = 100005;

int n, x, y, a[N], b[N];
std::vector<int> p[N];

void solve() {
	read(n), read(x), read(y);
	for (int i = 1; i <= n + 1; ++i) {
		p[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		p[a[i]].push_back(i);
	}
	std::priority_queue<std::pair<int, int>> Q;
	int t = 0;
	for (int i = 1; i <= n + 1; ++i) {
		if (p[i].empty()) {
			t = i;
		}
		Q.push({(int)p[i].size(), i});
	}
	int now = n;
	for (int i = 1; i <= x; ++i) {
		int k = Q.top().second;
		Q.pop();
		b[p[k].back()] = k, --now;
		p[k].pop_back();
		Q.push({(int)p[k].size(), k});
	}
	for (int i = 1; i <= n - y && Q.top().first > now / 2; ++i) {
		int k = Q.top().second;
		Q.pop();
		b[p[k].back()] = t, --now;
		p[k].pop_back();
		Q.push({(int)p[k].size(), k});
	}
	int mx = Q.top().first;
	if (mx > now / 2) {
		printStr("NO");
		return;
	}
	std::vector<std::pair<int, int>> pos;
	for (int i = 1; i <= n + 1; ++i) {
		for (int v : p[i]) {
			pos.push_back({i, v});
		}
	}
	int d = pos.size();
	for (int i = 0; i < d; ++i) {
		b[pos[i].second] = pos[(i + mx) % d].first;
	}
	for (int i = 0; i < now - y + x; ++i) {
		b[pos[i].second] = t;
	}
	printStr("YES");
	for (int i = 1; i <= n; ++i) {
		print(b[i], " \n"[i == n]);
	}
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}