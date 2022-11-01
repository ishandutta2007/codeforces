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
int n, q, a[N * N], ans[N];
bool vis[N * N];
vector<int> vec[2][N], vx[N], vy;
inline int D(int x, int y, int w) {
	return max(w / n - x, w % n - y);
}
vector<int> Merge(int x, int y, const vector<int> &v1, const vector<int> &v2) {
	int i = 0, j = 0;
	vector<int> ret;
	while ((i < (int)v1.size() || j < (int)v2.size()) && (int)ret.size() <= q) {
		if (i < (int)v1.size() && (j == (int)v2.size() || D(x, y, v1[i]) < D(x, y, v2[j]))) {
			if (!vis[a[v1[i]]]) {
				vis[a[v1[i]]] = 1;
				ret.push_back(v1[i]);
			}
			i++;
		} else {
			if (!vis[a[v2[j]]]) {
				vis[a[v2[j]]] = 1;
				ret.push_back(v2[j]);
			}
			j++;
		}
	}
	for (int w : ret) vis[a[w]] = 0;
	return ret;
}
int main() {
	read_int(n);
	read_int(q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			read_int(a[i * n + j]);
		}
	}
	int cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		cur ^= 1;
		vy.clear();
		for (int j = n - 1; j >= 0; j--) {
			vx[j] = Merge(i, j, vx[j], {i * n + j});
			vy = Merge(i, j, vy, {i * n + j});
			vec[cur][j] = Merge(i, j, vx[j], vy);
			vec[cur][j] = Merge(i, j, vec[cur][j], vec[!cur][j + 1]);
			int v = min(n - i, n - j);
			if ((int)vec[cur][j].size() > q) {
				v = min(v, D(i, j, vec[cur][j].back()));
			}
			ans[v]++;
		}
	}
	for (int i = n; i >= 1; i--) ans[i] += ans[i + 1];
	for (int i = 1; i <= n; i++) print_int(ans[i], '\n');
	return 0;
}