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

const int P = 1000000007, PP = P - 1;

typedef std::vector<std::vector<int>> matrix;

long long n;
int f1, f2, f3, c;

matrix operator * (const matrix &a, const matrix &b) {
	matrix res(a.size(), std::vector<int>(b[0].size()));
	for (int i = 0; i < (int)a.size(); ++i) {
		for (int k = 0; k < (int)b.size(); ++k) {
			for (int j = 0; j < (int)b[0].size(); ++j) {
				res[i][j] = (res[i][j] + 1ll * a[i][k] * b[k][j]) % PP;
			}
		}
	}
	return res;
}

matrix qpow(matrix a, long long b) {
	matrix s(a.size(), std::vector<int>(a.size()));
	for (int i = 0; i < (int)s.size(); ++i) {
		s[i][i] = 1;
	}
	for (; b; b >>= 1) {
		if (b & 1) {
			s = s * a;
		}
		a = a * a;
	}
	return s;
}

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

void solve() {
	read(n), read(f1), read(f2), read(f3), read(c);
	c = 1ll * c * c % P;
	matrix A(5, std::vector<int>(5));
	A[1][0] = A[2][1] = 1;
	A[0][2] = A[1][2] = A[2][2] = A[3][2] = 1;
	A[3][3] = A[4][3] = A[4][4] = 1;
	A = qpow(A, n - 1);
	int ans = 1;
	ans = 1ll * ans * qpow(f1, A[0][0]) % P;
	ans = 1ll * ans * qpow(f2, A[1][0]) % P;
	ans = 1ll * ans * qpow(f3, A[2][0]) % P;
	ans = 1ll * ans * qpow(c, A[3][0]) % P;
	ans = 1ll * ans * qpow(c, A[4][0]) % P;
	print(ans);
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}