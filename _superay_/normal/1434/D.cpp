#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int N = 500005;
int n, Q, tot, dfn[N], dl[N], pp[N], dr[N], dfc, st[20][N * 2], lg2[N * 2], dep[N], dist[N];
vector<pair<int, int> > G[N];
inline int LCA(int l, int r) {
	l = dfn[l], r = dfn[r];
	if (l > r) swap(l, r);
	int i = lg2[r - l + 1];
	if (dep[st[i][l]] < dep[st[i][r - (1 << i) + 1]])
		return st[i][l];
	else
		return st[i][r - (1 << i) + 1];
}
inline int getdist(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}
struct Node {
	int u, v, d;
};
inline Node Merge(const Node &a, const Node &b) {
	if (a.d == -1) return b;
	if (b.d == -1) return a;
	Node ret;
	if (a.d > b.d) {
		ret = a;
	} else {
		ret = b;
	}
	int d1 = getdist(a.u, b.u), d2 = getdist(a.u, b.v), d3 = getdist(a.v, b.u), d4 = getdist(a.v, b.v);
	int md = max(max(d1, d2), max(d3, d4));
	if (md <= ret.d) return ret;
	ret.d = md;
	if (d1 == md) {
		ret.u = a.u;
		ret.v = b.u;
	} else if (d2 == md) {
		ret.u = a.u;
		ret.v = b.v;
	} else if (d3 == md) {
		ret.u = a.v;
		ret.v = b.u;
	} else {
		ret.u = a.v;
		ret.v = b.v;
	}
	return ret;
}
Node tr[N * 4][2];
int tag[N * 4];
void build(int i, int l, int r) {
	tag[i] = 0;
	if (l == r) {
		int u = pp[l];
		tr[i][dist[u]].u = tr[i][dist[u]].v = u;
		tr[i][dist[u]].d = 0;
		tr[i][dist[u] ^ 1].u = tr[i][dist[u] ^ 1].v = 0;
		tr[i][dist[u] ^ 1].d = -1;
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	tr[i][0] = Merge(tr[i << 1][0], tr[i << 1 | 1][0]);
	tr[i][1] = Merge(tr[i << 1][1], tr[i << 1 | 1][1]);
}
inline void pushdown(int i) {
	if (tag[i]) {
		swap(tr[i << 1][0], tr[i << 1][1]);
		swap(tr[i << 1 | 1][0], tr[i << 1 | 1][1]);
		tag[i << 1] ^= 1;
		tag[i << 1 | 1] ^= 1;
		tag[i] = 0;
	}
}
void modify(int i, int l, int r, int lf, int rg) {
	if (lf <= l && r <= rg) {
		swap(tr[i][0], tr[i][1]);
		tag[i] ^= 1;
		return;
	}
	pushdown(i);
	int mid = (l + r) >> 1;
	if (lf <= mid) modify(i << 1, l, mid, lf, rg);
	if (rg > mid) modify(i << 1 | 1, mid + 1, r, lf, rg);
	tr[i][0] = Merge(tr[i << 1][0], tr[i << 1 | 1][0]);
	tr[i][1] = Merge(tr[i << 1][1], tr[i << 1 | 1][1]);
}
void dfs(int u, int lst, int depth, int D) {
	dl[u] = ++dfc;
	pp[dfc] = u;
	st[0][dfn[u] = ++tot] = u;
	dep[u] = depth;
	dist[u] = D;
	for (auto &e : G[u]) {
		int v = e.first;
		if (v == lst) continue;
		dfs(v, u, depth + 1, D ^ e.second);
		st[0][++tot] = u;
	}
	dr[u] = dfc;
}
int eu[N], ev[N];
int main() {
	read_int(n);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		read_int(u);
		eu[i] = u;
		read_int(v);
		ev[i] = v;
		read_int(w);
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}
	tot = 0;
	dfs(1, 0, 0, 0);
	lg2[0] = -1;
	for (int i = 1; i <= tot; i++)
		lg2[i] = lg2[i - 1] + ((i & (i - 1)) ? 0 : 1);
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= tot - (1 << i) + 1; j++) {
			if (dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << (i - 1))]])
				st[i][j] = st[i - 1][j];
			else
				st[i][j] = st[i - 1][j + (1 << (i - 1))];
		}
	}
	build(1, 1, n);
	read_int(Q);
	for (int i = 1; i < n; i++) {
		if (dl[eu[i]] > dl[ev[i]]) swap(eu[i], ev[i]);
	}
	while (Q--) {
		int eid;
		read_int(eid);
		modify(1, 1, n, dl[ev[eid]], dr[ev[eid]]);
		print_int(max(tr[1][0].d, tr[1][1].d), '\n');
	}
	return 0;
}