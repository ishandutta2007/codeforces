#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

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

const char vowels[] = "aeiou";

const int N = 100005;

int n;
char tmp[1000005];
std::string str[N];
std::vector<int> id[1000005][5];
std::vector<std::pair<int, int>> S[2];

int check(char c) {
	for (int i = 0; i < 5; ++i) {
		if (c == vowels[i]) {
			return i;
		}
	}
	return -1;
}

void print_string(const std::string &s, char ch) {
	printStr(s.c_str(), s.size(), ch);
}

void solve() {
	read(n);
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		readStr(tmp);
		str[i] = tmp;
		int cnt = 0, lst = 0;
		for (int j = 0; j < (int)str[i].size(); ++j) {
			int t = check(str[i][j]);
			if (t != -1) {
				++cnt, lst = t;
			}
		}
		id[cnt][lst].push_back(i);
		mx = std::max(mx, cnt);
	}
	for (int i = 1; i <= mx; ++i) {
		int lst = -1;
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k + 1 < (int)id[i][j].size(); k += 2) {
				S[1].push_back({id[i][j][k], id[i][j][k + 1]});
			}
			if (id[i][j].size() & 1) {
				int t = id[i][j].back();
				if (lst == -1) {
					lst = t;
				} else {
					S[0].push_back({lst, t});
					lst = -1;
				}
			}
		}
	}
	int n0 = S[0].size(), n1 = S[1].size(), m;
	std::vector<std::pair<int, int>> ans0, ans1;
	if (n0 < n1) {
		m = (n0 + n1) / 2;
		for (int i = 0; i < n0; ++i) {
			ans0.push_back(S[0][i]);
		}
		for (int i = n0; i < m; ++i) {
			ans0.push_back(S[1][i - n0]);
		}
		for (int i = m; i < 2 * m; ++i) {
			ans1.push_back(S[1][i - n0]);
		}
	} else {
		m = n1;
		for (int i = 0; i < m; ++i) {
			ans0.push_back(S[0][i]);
		}
		for (int i = 0; i < m; ++i) {
			ans1.push_back(S[1][i]);
		}
	}
	print(m);
	for (int i = 0; i < m; ++i) {
		print_string(str[ans0[i].first], ' ');
		print_string(str[ans1[i].first], '\n');
		print_string(str[ans0[i].second], ' ');
		print_string(str[ans1[i].second], '\n');
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}