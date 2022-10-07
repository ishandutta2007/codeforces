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

const int N = 15;

int n;

void solve() {
	read(n);
	std::vector<int> sum(1 << n);
	for (int i = 0; i < n; ++i) {
		read(sum[1 << i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int S = 0; S < (1 << n); ++S) {
			if (S >> i & 1) {
				sum[S] += sum[S ^ (1 << i)];
			}
		}
	}
	std::vector<std::vector<int>> pos(n + 1, std::vector<int>(1 << n));
	for (int i = 0; i <= n; ++i) {
		for (int S = 0; S < (1 << n); ++S) {
			int p = i;
			while (p < n && (S >> p & 1) == 0) {
				++p;
			}
			pos[i][S] = p;
		}
	}
	std::vector<std::vector<std::vector<int>>> f(n + 1, 
	  std::vector<std::vector<int>>(1 << n, std::vector<int>(n + 1, -1)));
	auto cmp = [&](int a, int b) {
		if (a == -1 || b == -1) {
			return a != -1;
		}
		return sum[a] < sum[b];
	};
	auto upd = [&](int &a, int b) {
		if (cmp(b, a)) {
			a = b;
		}
	};
	f[0][0][0] = 0;
	int U = (1 << n) - 1;
	for (int k = 0; k < n; ++k) {
		for (int S = 0; S < (1 << n); ++S) {
			for (int i = 0; i < n; ++i) {
				if (f[k][S][i] != -1) {
					int _S = U ^ S;
					for (int mask = _S; mask; mask = (mask - 1) & _S) {
						int p = pos[i][mask];
						if (cmp(f[k][S][i], mask) && p < n) {
							upd(f[k + 1][S ^ mask][p + 1], mask);
						}
					}
				}
			}
		}
	}
	int c = n;
	while (1) {
		bool flag = 0;
		for (int i = 0; i <= n; ++i) {
			if (f[c][U][i] != -1) {
				flag = 1;
			}
		}
		if (flag) {
			break;
		}
		--c;
	}
	auto calc = [&](int S, int p) {
		int res = 0;
		for (int i = 0; i < p; ++i) {
			res += S >> i & 1;
		}
		return res;
	};
	print(n - c);
	int now = U, ex = U;
	int p = 0;
	while (f[c][U][p] == -1) {
		++p;
	}
	while (c > 0) {
		int mask = f[c][now][p];
		--p;
		for (int i = 0; i < n; ++i) {
			if (p != i && (mask >> i & 1)) {
				print(calc(ex, i) + 1, ' ');
				print(calc(ex, p) + 1);
				ex ^= 1 << i;
			}
		}
		--c, now ^= mask;
		for (int i = 0; i < n; ++i) {
			if (cmp(f[c][now][i], mask) && pos[i][mask] == p) {
				p = i;
				break;
			}
		}
	}
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}