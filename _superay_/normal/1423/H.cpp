#include <bits/stdc++.h>
using namespace std;
//Fast IO start
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE - 1;
	inline void read_char(char &c) {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) *it++ = EOF;
		}
		c = *is++;
	}
	template <class T>
	inline void read_int(T &x) {
		T f = 1;
		char c;
		read_char(c);
		while (!isdigit(c)) {
			if (c == '-') {
				f = -1;
			}
			read_char(c);
		}
		x = 0;
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			read_char(c);
		}
		x *= f;
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
	inline void print_int(T x) {
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
	}
	struct flusher_t {
		inline ~flusher_t() {
			flush();
		}
	} flusher;
}
using io::read_char;
using io::read_int;
using io::print_char;
using io::print_int;
//Fast IO end
const int N = 100005;
const int Q = 500005;
struct Query {
	int t, x, y;
} a[Q];
int n, q, k, fa[N], sz[N];
vector<int> stk;
vector<int> st[Q * 4];
void Ins(int i, int l, int r, int lf, int rg, int id) {
	if (lf <= l && r <= rg) {
		st[i].push_back(id);
		return;
	}
	int mid = (l + r) >> 1;
	if (lf <= mid) Ins(i << 1, l, mid, lf, rg, id);
	if (rg > mid) Ins(i << 1 | 1, mid + 1, r, lf, rg, id);
}
int Find(int x) {
	return fa[x] == x ? x : Find(fa[x]);
}
void Union(int x, int y) {
	int rx = Find(x), ry = Find(y);
	if (rx == ry) return;
	if (sz[rx] < sz[ry]) swap(rx, ry);
	stk.push_back(ry);
	fa[ry] = rx;
	sz[rx] += sz[ry];
}
int ans[Q];
void Gao(int i, int l, int r) {
	int lim = stk.size();
	for (int id : st[i]) {
		Union(a[id].x, a[id].y);
	}
	if (l == r) {
		if (a[l].t == 2) ans[l] = sz[Find(a[l].x)];
	} else {
		int mid = (l + r) >> 1;
		Gao(i << 1, l, mid);
		Gao(i << 1 | 1, mid + 1, r);
	}
	while ((int)stk.size() > lim) {
		int ry = stk.back(); stk.pop_back();
		int rx = fa[ry];
		fa[ry] = ry;
		sz[rx] -= sz[ry];
	}
}
int main() {
	read_int(n);
	read_int(q);
	read_int(k);
	for (int i = 1; i <= q; i++) {
		read_int(a[i].t);
		if (a[i].t == 1) read_int(a[i].x), read_int(a[i].y);
		else if (a[i].t == 2) read_int(a[i].x);
	}
	set<int> st;
	for (int i = q; i >= 1; i--) {
		if (a[i].t == 3) {
			st.insert(i);
			if ((int)st.size() > k) st.erase(--st.end());
		}
		if (a[i].t == 1) {
			int rr;
			if ((int)st.size() == k) rr = *st.rbegin() - 1;
			else rr = q;
			Ins(1, 1, q, i, rr, i);
		}
	}
	for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	Gao(1, 1, q);
	for (int i = 1; i <= q; i++) if (a[i].t == 2) print_int(ans[i]), print_char('\n');
	return 0;
}