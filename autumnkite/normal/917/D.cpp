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

const int N = 105, P = 1000000007;

typedef std::vector<int> vector;
typedef std::vector<vector> matrix;

int n;

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

int det(matrix a) {
	int n = (int)a.size();
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		int p = -1;
		for (int j = i; j < n; ++j) {
			if (a[j][i]) {
				p = j;
				break;
			}
		}
		if (p == -1) {
			return 0;
		}
		if (p != i) {
			for (int j = i; j < n; ++j) {
				std::swap(a[i][j], a[p][j]);
			}
			ans = P - ans;
		}
		int inv = qpow(a[i][i], P - 2);
		for (int j = i + 1; j < n; ++j) {
			int t = 1ll * a[j][i] * inv % P;
			for (int k = i; k < n; ++k) {
				a[j][k] = (a[j][k] + 1ll * (P - t) * a[i][k]) % P;
			}
		}
		ans = 1ll * ans * a[i][i] % P;
	}
	return ans;
}

vector Gauss(matrix a, vector b) {
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		int p = -1;
		for (int j = i; j < n; ++j) {
			if (a[j][i]) {
				p = j;
				break;
			}
		}
		if (p == -1) {
			return {};
		}
		if (p != i) {
			for (int j = i; j < n; ++j) {
				std::swap(a[i][j], a[p][j]);
			}
			std::swap(b[i], b[p]);
		}
		int inv = qpow(a[i][i], P - 2);
		for (int j = 0; j < n; ++j) {
			if (j != i) {
				int t = 1ll * a[j][i] * inv % P;
				for (int k = i; k < n; ++k) {
					a[j][k] = (a[j][k] + 1ll * (P - t) * a[i][k]) % P;
				}
				b[j] = (b[j] + 1ll * (P - t) * b[i]) % P;
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		debug("%d ", a[i][j]);
	// 	}
	// 	debug("\n");
	// }
	for (int i = 0; i < n; ++i) {
		b[i] = 1ll * b[i] * qpow(a[i][i], P - 2) % P;
	}
	return b;
}

int main() {
	read(n);
	matrix D(n - 1, vector(n - 1, P - 1));
	for (int i = 0; i < n - 1; ++i) {
		D[i][i] = n - 1;
	}
	matrix E(n, vector(n, 0));
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		read(u), read(v), --u, --v;
		--E[u][v], --E[v][u], ++E[u][u], ++E[v][v];
	}
	matrix A(n, vector(n, 0));
	vector b(n);
	for (int k = 0; k < n; ++k) {
		int t = 1;
		for (int i = 0; i < n; ++i) {
			A[k][i] = t;
			t = 1ll * t * (k + 1) % P;
		}
		b[k] = det(D);
		// debug("%d\n", b[k]);
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				D[i][j] += E[i][j];
			}
		}
	}
	vector x(Gauss(A, b));
	for (int i = 0; i < n; ++i) {
		print(x[i], ' ');
	}
}