#include <bits/stdc++.h>
using namespace std;
//Fast IO start
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE + 1], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE + 1], *os = obuf, *ot = obuf + BUFSIZE;
	inline char read_char() {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) *it++ = EOF;
		}
		return *is++;
	}
	template <class T>
	inline void read_int(T &x) {
		T f = 1;
		char c = read_char();
		while (!isdigit(c)) {
			if (c == '-') f = -1;
			c = read_char();
		}
		x = 0;
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			c = read_char();
		}
		x *= f;
	}
	inline void read_str(char *s) {
		char c = read_char();
		while (c <= ' ') {
			c = read_char();
		}
		while (c > ' ') {
			*s++ = c;
			c = read_char();
		}
		*s = 0;
	}
	inline void flush() {
		fwrite(obuf, 1, os - obuf, stdout);
		os = obuf;
	}
	inline void print_char(char c) {
		*os++ = c;
		if (os == ot) {
			flush();
		}
	}
	template <class T>
	inline void print_int(T x, char c = 0) {
		static char q[40];
		if (!x) {
			print_char('0');
		} else {
			if (x < 0) {
				print_char('-');
				x = -x;
			}
			int top = 0;
			while (x) {
				q[top++] = x % 10 + '0';
				x /= 10;
			}
			while (top--) {
				print_char(q[top]);
			}
		}
		if (c) print_char(c);
	}
	inline void print_str(char *s, char c = 0) {
		while (*s) {
			print_char(*s++);
		}
		if (c) print_char(c);
	}
	struct flusher_t {
		inline ~flusher_t() {
			flush();
		}
	} flusher;
}
using io::read_char;
using io::read_int;
using io::read_str;
using io::print_char;
using io::print_int;
using io::print_str;
//Fast IO end
const int N = 1505;
int n, m, a[N][N], b[N][N], pos[N], cb[N], vis[N], cut[N];
vector<vector<int> > va, vb;
vector<int> ans;
void gao() {
	for (int j = 1; j <= m; j++) if (!vis[j] && !cb[j]) {
		vis[j] = 1;
		ans.push_back(j);
		for (int i = 1; i < n; i++) if (!cut[i] && b[i][j] < b[i + 1][j]) {
			cut[i] = 1;
			for (int k = 1; k <= m; k++) if (!vis[k] && b[i][k] > b[i + 1][k]) cb[k]--;
		}
		gao();
		return;
	}
	for (int i = 1; i < n; i++) if (!cut[i]) {
		if (pos[i] > pos[i + 1]) {
			puts("-1");
			exit(0);
		}
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int x : ans) printf("%d ", x);
	exit(0);
}
int main() {
	read_int(n);
	read_int(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) read_int(a[i][j]);
		va.push_back(vector<int>(a[i] + 1, a[i] + 1 + m));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) read_int(b[i][j]);
		vb.push_back(vector<int>(b[i] + 1, b[i] + 1 + m));
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	if (va != vb) { puts("-1"); return 0; }
	va.clear();
	vb.clear();
	for (int i = 1; i <= n; i++) {
		a[i][m + 1] = i;
		va.push_back(vector<int>(a[i] + 1, a[i] + 2 + m));
	}
	for (int i = 1; i <= n; i++) {
		b[i][m + 1] = i;
		vb.push_back(vector<int>(b[i] + 1, b[i] + 2 + m));
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	for (int i = 0; i < n; i++) pos[vb[i].back()] = va[i].back();
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cb[j] += (b[i][j] > b[i + 1][j]);
		}
	}
	gao();
	puts("-1");
	return 0;
}