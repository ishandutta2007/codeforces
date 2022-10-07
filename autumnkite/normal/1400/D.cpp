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

int n, a[3005];
std::vector<int> p[3005];

void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		p[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		p[a[i]].push_back(i);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		int v = p[i].size();
		ans += 1ll * v * (v - 1) * (v - 2) * (v - 3) / 24;
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				std::vector<int> pos(p[i].size() + p[j].size());
				std::merge(p[i].begin(), p[i].end(), p[j].begin(), p[j].end(), pos.begin());
				std::vector<int> pre(pos.size()), suf(pos.size());
				for (int k = 0; k < (int)pos.size(); ++k) {
					pre[k] = (k > 0 ? pre[k - 1] : 0) + (a[pos[k]] == i);
				}
				for (int k = (int)pos.size() - 1; ~k; --k) {
					suf[k] = (k < (int)pos.size() - 1 ? suf[k + 1] : 0) + (a[pos[k]] == j);
				}
				int sum = 0;
				for (int k = 0; k < (int)pos.size(); ++k) {
					if (a[pos[k]] == i) {
						ans += 1ll * sum * suf[k];
					} else {
						sum += pre[k];
					}
				}
			}
		}
	}
	print(ans);
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}