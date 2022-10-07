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

const int N = 1005, INF = 0x3f3f3f3f;

int n, x;
char a[N];

struct AC_Automaton {
	static const int N = 100005;

	int rt, cnt;
	int in[N], go[N][10], fail[N];

	void init() {
		cnt = rt = 1;
	}

	void insert(int *a, int len) {
		int u = rt;
		for (int i = 1; i <= len; ++i) {
			if (!go[u][a[i]]) {
				go[u][a[i]] = ++cnt;
			}
			u = go[u][a[i]];
		}
		in[u] = 1;
	}

	void build() {
		std::vector<int> Q;
		for (int i = 0; i < 10; ++i) {
			if (go[rt][i]) {
				Q.push_back(go[rt][i]);
				fail[go[rt][i]] = rt;
			} else {
				go[rt][i] = rt;
			}
		}
		for (int k = 0; k < (int)Q.size(); ++k) {
			int u = Q[k];
			for (int i = 0; i < 10; ++i) {
				if (go[u][i]) {
					int v = go[u][i];
					fail[v] = go[fail[u]][i];
					Q.push_back(v);
				} else {
					go[u][i] = go[fail[u]][i];
				}
			}
		}
	}
} A;

int tmp[25];

bool check(int n) {
	for (int i = 1; i <= n; ++i) {
		int s = 0;
		for (int j = i; j <= n; ++j) {
			s += tmp[j];
			if (s != x && x % s == 0) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int k, int s) {
	if (s == x) {
		if (check(k - 1)) {
			A.insert(tmp, k - 1);
		}
		return;
	}
	for (int i = 1; i <= 9 && i <= x - s; ++i) {
		tmp[k] = i;
		dfs(k + 1, s + i);
	}
}

int f[2][A.N];

void upd(int &a, int b) {
	a = std::min(a, b);
}

void solve() {
	n = readStr(a + 1);
	read(x);
	A.init();
	dfs(1, 0);
	A.build();
	int u = 0;
	for (int i = 1; i <= A.cnt; ++i) {
		f[u][i] = INF;
	}
	f[u][A.rt] = 0;
	for (int i = 1; i <= n; ++i) {
		int c = a[i] - '0';
		for (int j = 1; j <= A.cnt; ++j) {
			f[u ^ 1][j] = INF;
		}
		for (int j = 1; j <= A.cnt; ++j) {
			if (!A.in[A.go[j][c]]) {
				upd(f[u ^ 1][A.go[j][c]], f[u][j]);
			}
			upd(f[u ^ 1][j], f[u][j] + 1);
		}
		u ^= 1;
	}
	int ans = INF;
	for (int i = 1; i <= A.cnt; ++i) {
		upd(ans, f[u][i]);
	}
	print(ans);
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}