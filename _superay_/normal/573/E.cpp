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
const int N = 100005;
struct Node {
	int lson, rson, sz;
	long long tag, val;
} tr[N];
inline void Cov(int p, long long x) {
	if (!p) return;
	tr[p].tag += x;
	tr[p].val += x;
}
inline void pushdown(int p) {
	if (tr[p].tag) {
		Cov(tr[p].lson, tr[p].tag);
		Cov(tr[p].rson, tr[p].tag);
		tr[p].tag = 0;
	}
}
inline void pushup(int p) {
	tr[p].sz = tr[tr[p].lson].sz + tr[tr[p].rson].sz + 1;
}
void Split(int p, long long b, long long k, int &r1, int &r2, long long &rv) {
	if (!p) {
		r1 = r2 = 0;
		rv = b;
		return;
	}
	pushdown(p);
	if (tr[p].val < b + k * (tr[tr[p].lson].sz + 1)) {
		r2 = p;
		Split(tr[p].lson, b, k, r1, tr[p].lson, rv);
	} else {
		r1 = p;
		Split(tr[p].rson, b + k * (tr[tr[p].lson].sz + 1), k, tr[p].rson, r2, rv);
	}
	pushup(p);
}
mt19937 rng(123321);
int Merge(int p, int q) {
	if (!p || !q) return p | q;
	if (uniform_int_distribution<int>(1, tr[p].sz + tr[q].sz)(rng) <= tr[p].sz) {
		pushdown(p);
		tr[p].rson = Merge(tr[p].rson, q);
		pushup(p);
		return p;
	} else {
		pushdown(q);
		tr[q].lson = Merge(p, tr[q].lson);
		pushup(q);
		return q;
	}
}
long long ans, sum;
void dfs(int p) {
	if (!p) return;
	pushdown(p);
	dfs(tr[p].lson);
	sum += tr[p].val;
	ans = max(ans, sum);
	dfs(tr[p].rson);
}
int n;
int main() {
	read_int(n);
	int rt = 0;
	for (int i = 1; i <= n; i++) {
		int x, p, q;
		read_int(x);
		Split(rt, 0, x, p, q, tr[i].val);
		tr[i].sz = 1;
		q = Merge(i, q);
		Cov(q, x);
		rt = Merge(p, q);
	}
	dfs(rt);
	print_int(ans, '\n');
	return 0;
}