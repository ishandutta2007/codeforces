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

const int N = 3005;

int n, k, a[N];
char s[N];
std::set<int> S;
std::vector<std::pair<int, int>> move;

void solve() {
	read(n), read(k), readStr(s + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = (s[i] == 'R');
		if (i == 1 || a[i] != a[i - 1]) S.insert(i);
	}
	S.insert(n + 1);
	int cnt = 0;
	while (1) {
		std::vector<int> p;
		int x = 1;
		while (x <= n) {
			if (a[x] || x == 1) {
				x = *S.upper_bound(x);
				continue;
			}
			p.push_back(x - 1);
			std::swap(a[x], a[x - 1]);
			int tmp = *S.upper_bound(x);
			if (x > 2 && !a[x - 2]) {
				S.erase(x - 1);
			} else {
				S.insert(x - 1);
			}
			if (!a[x + 1]) {
				S.insert(x + 1);
			}
			x = tmp;
		}
		if (p.empty()) {
			break;
		}
		++cnt;
		for (int v : p) {
			move.push_back({v, cnt});
		}
	}
	if (k < cnt || k > (int)move.size()) {
		print(-1);
		return;
	}
	for (int i = (int)move.size() - 1; i >= 1; --i) {
		move[i].second -= move[i - 1].second;
	}
	for (int i = 0; i < (int)move.size(); ++i) {
		if (move[i].second) {
			continue;
		}
		if (cnt == k) {
			break;
		}
		move[i].second = 1;
		++cnt;
	}
	std::vector<std::vector<int>> ans(k);
	int now = 0;
	for (auto p : move) {
		now += p.second;
		// debug("%d %d\n", p.first, p.second);
		ans[now - 1].push_back(p.first);
	}
	for (auto p : ans) {
		print((int)p.size(), ' ');
		for (int v : p) {
			print(v, ' ');
		}
		putchar('\n');
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}