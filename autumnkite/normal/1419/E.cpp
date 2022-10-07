#include <bits/stdc++.h>

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
		static int num[40];
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (*num = 0; x; x /= 10) {
			num[++*num] = x % 10;
		}
		while (*num){
			putchar(num[*num] ^ '0');
			--*num;
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

int n;

void solve() {
	read(n);
	int x = n;
	std::vector<int> p;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			p.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		p.push_back(x);
	}
	std::set<int> d;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i > 1) {
				d.insert(i);
			}
			if (i * i < n) {
				d.insert(n / i);
			}
		}
	}
	std::vector<std::vector<int>> res(p.size());
	int ans = 0;
	if ((int)p.size() == 2) {
		res[0].push_back(n);
		d.erase(n);
		if (p[0] * p[1] == n) {
			ans = 1;
		} else {
			res[1].push_back(p[0] * p[1]);
			d.erase(p[0] * p[1]);
		}
	} else {
		for (int i = 0; i < (int)p.size(); ++i) {
			int nx = (i + 1) % (int)p.size();
			res[nx].push_back(p[i] * p[nx]);
			d.erase(p[i] * p[nx]);
		}
	}
	for (int v : d) {
		for (int i = 0; i < (int)p.size(); ++i) {
			if (v % p[i] == 0) {
				res[i].push_back(v);
				break;
			}
		}
	}
	for (int i = 0; i < (int)p.size(); ++i) {
		for (int v : res[i]) {
			print(v, ' ');
		}
	}
	putchar('\n');
	print(ans);
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}