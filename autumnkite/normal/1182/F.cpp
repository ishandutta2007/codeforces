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

int l, r, a, P;
int B;
std::pair<int, int> b[50005];
int mn, ans;

void upd(int x) {
	int w = 1ll * a * x % P;
	if (w < P / 2) {
		w = P / 2 - w;
	} else {
		w = w - P / 2;
	}
	if (w < mn) {
		mn = w, ans = x;
	} else if (w == mn && x < ans) {
		ans = x;
	}
}

void solve() {
	read(l), read(r), read(a), read(P);
	P *= 2, a = 2ll * a % P;
	r = std::min(0ll + r, 0ll + l + P - 1);
	B = std::sqrt(P) + 0.5;
	for (int i = 1; i <= B; ++i) {
		b[i].first = (P / 2 + 1ll * a * i) % P;
		b[i].second = i;
	}
	std::sort(b + 1, b + 1 + B);
	mn = P, ans = 0;
	for (int i = 1; i <= (r - l) / B; ++i) {
		int w = 1ll * (i * B + l) * a % P;
		int nx = std::lower_bound(b + 1, b + B + 1, std::make_pair(w, 0)) - b;
		int pr = nx - 1;
		if (nx > B) {
			nx = 1;
		}
		if (pr < 1) {
			pr = B;
		}
		upd(i * B + l - b[nx].second);
		upd(i * B + l - b[pr].second);
	}
	int tmp = (r - l) / B + 1;
	for (int i = tmp * B - r + l; i <= B; ++i) {
		upd(tmp * B + l - i);
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
/*
1
356325 912953 399965 269

356379
*/