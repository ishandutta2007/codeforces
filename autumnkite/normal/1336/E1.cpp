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

const int P = 998244353, I2 = (P + 1) >> 1;

int n, m;
std::vector<long long> a;
std::vector<int> bitcnt;
std::vector<int> f;
std::vector<std::vector<int>> g;

void inc(int &a, int b) {
	(a += b) >= P ? a -= P : 0;
}

void dec(int &a, int b) {
	a < b ? a += P - b : a -= b;
}

int plus(int a, int b) {
	return a + b >= P ? a + b - P : a + b;
}

int minus(int a, int b) {
	return a < b ? a + P - b : a - b;
}

bool insert(long long x) {
	for (int i = (int)a.size() - 1; ~i; --i) {
		if (x >> i & 1) {
			if (!a[i]) {
				a[i] = x;
				return 1;
			} else {
				x ^= a[i];
			}
		}
	}
	return 0;
}

void FWTxor(std::vector<int> &a, int op) {
	int n = (int)a.size();
	for (int m = 1; m < n; m <<= 1) {
		for (int p = 0; p < n; p += m << 1) {
			for (int i = p; i < p + m; ++i) {
				int t0 = plus(a[i], a[i + m]), t1 = minus(a[i], a[i + m]);
				if (op == -1) {
					t0 = 1ll * t0 * I2 % P, t1 = 1ll * t1 * I2 % P;
				}
				a[i] = t0, a[i + m] = t1;
			}
		}
	}
}

void getBitcnt(int n) {
	bitcnt.resize(1 << n);
	bitcnt[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	}
}

void solve() {
	read(n), read(m);
	a.resize(m);
	int pw = 1;
	for (int i = 1; i <= n; ++i) {
		long long x;
		read(x);
		if (!insert(x)) {
			pw = 2ll * pw % P;
		}
	}
	int B = m >> 1, mask = (1 << B) - 1;
	getBitcnt(std::max(B, m - B));
	f.resize(1 << B);
	g.resize(m - B + 1, std::vector<int>(1 << B));
	for (int p = 0; p < (1 << B); ++p) {
		bool flag = 1;
		long long sum = 0;
		for (int i = 0; i < B; ++i) {
			if (p >> i & 1) {
				if (!a[i]) {
					flag = 0;
					break;
				}
				sum ^= a[i];
			}
		}
		if (flag) {
			++f[sum];
		}
	}
	for (int p = 0; p < (1 << (m - B)); ++p) {
		bool flag = 1;
		long long sum = 0;
		for (int i = B; i < m; ++i) {
			if (p >> (i - B) & 1) {
				if (!a[i]) {
					flag = 0;
					break;
				}
				sum ^= a[i];
			}
		}
		if (flag) {
			int cnt = bitcnt[sum >> B];
			++g[cnt][sum & mask];
		}
	}
	std::vector<int> ans(m + 1);
	FWTxor(f, 1);
	for (int k = 0; k <= m - B; ++k) {
		FWTxor(g[k], 1);
		for (int i = 0; i < (1 << B); ++i) {
			g[k][i] = 1ll * g[k][i] * f[i] % P;
		}
		FWTxor(g[k], -1);
		for (int i = 0; i < (1 << B); ++i) {
			inc(ans[k + bitcnt[i]], g[k][i]);
		}
	}
	for (int i = 0; i <= m; ++i) {
		print(1ll * ans[i] * pw % P, ' ');
	}
	putchar('\n');
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}