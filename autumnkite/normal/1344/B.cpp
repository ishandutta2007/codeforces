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

const int N = 1005;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int n, m;
char a[N][N];
bool vis[N][N];

void bfs(int x, int y) {
	std::vector<std::pair<int, int>> Q;
	Q.push_back({x, y});
	vis[x][y] = 1;
	for (int i = 0; i < (int)Q.size(); ++i) {
		x = Q[i].first, y = Q[i].second;
		for (int j = 0; j < 4; ++j) {
			int nx = x + dx[j], ny = y + dy[j];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
				if (!vis[nx][ny] && a[nx][ny] == '#') {
					Q.push_back({nx, ny});
					vis[nx][ny] = 1;
				}
			}
		}
	}
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		readStr(a[i] + 1);
	}
	int rb = 0, cb = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '#' && (j == 1 || a[i][j - 1] == '.')) {
				++cnt;
			}
		}
		if (cnt > 1) {
			print(-1);
			return 0;
		}
		rb += cnt;
	}
	for (int j = 1; j <= m; ++j) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i][j] == '#' && (i == 1 || a[i - 1][j] == '.')) {
				++cnt;
			}
		}
		if (cnt > 1) {
			print(-1);
			return 0;
		}
		cb += cnt;
	}
	if ((rb == n) ^ (cb == m)) {
		print(-1);
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '#' && !vis[i][j]) {
				++ans;
				bfs(i, j);
			}
		}
	}
	print(ans);
}