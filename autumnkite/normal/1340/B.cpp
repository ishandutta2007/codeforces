#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>

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

const int N = 2005;
const int mask[] = {0x77, 0x12, 0x5D, 0x5B, 0x3A, 0x6B, 0x6F, 0x52, 0x7F, 0x7B};

int n, m, a[N];
std::bitset<N> f[N];
char s[10];

int bitcnt(int x) {
	int s = 0;
	while (x) {
		x &= x - 1;
		++s;
	}
	return s;
}

void printAns(int n, int m) {
	if (!n) {
		return;
	}
	for (int k = 9; ~k; --k) {
		if ((a[n] & mask[k]) == a[n]) {
			int v = bitcnt(a[n] ^ mask[k]);
			if (m >= v && f[n - 1][m - v]) {
				putchar(k ^ '0');
				printAns(n - 1, m - v);
				return;
			}
		}
	}
}

void solve() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		readStr(s), a[i] = 0;
		for (int j = 0; j < 7; ++j) {
			a[i] |= (s[6 - j] ^ '0') << j;
		}
	}
	std::reverse(a + 1, a + 1 + n);
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		f[i] = 0;
		for (int k = 0; k <= 9; ++k) {
			if ((a[i] & mask[k]) == a[i]) {
				int v = bitcnt(a[i] ^ mask[k]);
				f[i] |= f[i - 1] << v;
			}
		}
	}
	if (f[n][m]) {
		printAns(n, m);
		putchar('\n');
	} else {
		print(-1);
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}

/*
10 19
1101010
0101110
1010100
0111101
1111111
1000110
0001101
0000000
1110010
0101100
*/

/*
10 0
1110111
0010010
1011101
1011011
0111010
1101011
1101111
1010010
1111111
1111011
*/