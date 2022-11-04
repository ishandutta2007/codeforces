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
const int N = 400005;
const int LOGN = 20;
struct SAM {
	int go[N][26], len[N], pre[N], ep[N], lp[N], tot, last;
	inline void Init() {
		tot = last = 1;
		memset(go[1], 0, sizeof(go[1]));
		len[1] = pre[1] = pre[0] = 0;
	}
	inline int newstate(int l) {
		len[++tot] = l;
		ep[tot] = 0;
		return tot;
	}
	inline void extend(int x) {
		int p = last, np = newstate(len[p] + 1);
		memset(go[np], 0, sizeof(go[np]));
		lp[len[np]] = np;
		ep[np] = len[np];
		while (p && !go[p][x]) {
			go[p][x] = np;
			p = pre[p];
		}
		if (!p) pre[np] = 1;
		else {
			int q = go[p][x];
			if (len[q] == len[p] + 1) pre[np] = q;
			else {
				int nq = newstate(len[p] + 1);
				memcpy(go[nq], go[q], sizeof(go[q]));
				pre[nq] = pre[q];
				pre[q] = pre[np] = nq;
				while (p && go[p][x] == q) {
					go[p][x] = nq;
					p = pre[p];
				}
			}
		}
		last = np;
	}
} sam1, sam2;
namespace Tree2 {
int n, wi[N], dfc, dfn[N], pos[N], st_dfc, st_dfn[N], st[LOGN][N * 2], lg2[N * 2], dep[N];
vector<int> G[N];
void dfs(int u, int depth) {
	dep[u] = depth;
	pos[dfn[u] = ++dfc] = u;
	st[0][st_dfn[u] = ++st_dfc] = u;
	for (int v : G[u]) {
		dfs(v, depth + 1);
		st[0][++st_dfc] = u;
	}
}
inline int LCA(int l, int r) {
	l = st_dfn[l], r = st_dfn[r];
	if (l > r) swap(l, r);
	int i = lg2[r - l + 1];
	if (dep[st[i][l]] < dep[st[i][r - (1 << i) + 1]])
		return st[i][l];
	else
		return st[i][r - (1 << i) + 1];
}
inline void Build() {
	n = sam2.tot;
	for (int i = 1; i <= n; i++) wi[i] = sam2.len[i];
	for (int i = 2; i <= n; i++) G[sam2.pre[i]].push_back(i);
	dfc = st_dfc = 0;
	dfs(1, 0);
	lg2[0] = -1;
	for (int i = 1; i <= st_dfc; i++) lg2[i] = lg2[i - 1] + ((i & (i - 1)) ? 0 : 1);
	for (int i = 1; i <= lg2[st_dfc]; i++)
		for (int j = 1; j <= st_dfc - (1 << i) + 1; j++)
			if (dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << (i - 1))]])
				st[i][j] = st[i - 1][j];
			else
				st[i][j] = st[i - 1][j + (1 << (i - 1))];
}
}
long long ans;
namespace Tree1 {
const int V = 4000005;
const int INF = 0x3f3f3f3f;
int n, ls, wi[N], rt[N], lson[V], rson[V], mn[V], mx[V], tot;
long long val[V];
vector<int> G[N];
inline void pushup(int x) {
	mn[x] = min(mn[lson[x]], mn[rson[x]]);
	mx[x] = max(mx[lson[x]], mx[rson[x]]);
	val[x] = val[lson[x]] + val[rson[x]];
	if (mx[lson[x]] != -INF && mn[rson[x]] != INF) {
		val[x] -= Tree2::wi[Tree2::LCA(Tree2::pos[mx[lson[x]]], Tree2::pos[mn[rson[x]]])];
	}
}
void Ins(int &x, int l, int r, int p) {
	if (!x) x = ++tot;
	if (l == r) {
		mn[x] = mx[x] = p;
		val[x] = Tree2::wi[Tree2::pos[p]];
		return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid) Ins(lson[x], l, mid, p);
	else Ins(rson[x], mid + 1, r, p);
	pushup(x);
}
int Merge(int x, int y, int l, int r) {
	if (!x || !y) return x | y;
	int mid = (l + r) >> 1;
	lson[x] = Merge(lson[x], lson[y], l, mid);
	rson[x] = Merge(rson[x], rson[y], mid + 1, r);
	pushup(x);
	return x;
}
void dfs(int u, int lst) {
	rt[u] = 0;
	if (sam1.ep[u] && sam1.ep[u] <= ls - 2) Ins(rt[u], 1, Tree2::dfc, Tree2::dfn[sam2.lp[ls - sam1.ep[u] - 1]]);
	for (int v : G[u]) {
		dfs(v, u);
		rt[u] = Merge(rt[u], rt[v], 1, Tree2::dfc);
	}
	ans += val[rt[u]] * (wi[u] - wi[lst]);
}
inline void Build() {
	n = sam1.tot;
	for (int i = 1; i <= n; i++) wi[i] = sam1.len[i];
	for (int i = 2; i <= n; i++) G[sam1.pre[i]].push_back(i);
	tot = 0;
	lson[0] = rson[0] = val[0] = 0;
	mn[0] = INF, mx[0] = -INF;
	dfs(1, 0);
}
}
int n;
char S[N];
int main() {
	read_str(S + 1);
	n = strlen(S + 1);
	sam1.Init();
	for (int i = 1; i <= n; i++) sam1.extend(S[i] - 'a');
	sam2.Init();
	for (int i = n; i >= 1; i--) sam2.extend(S[i] - 'a');
	ans = 0;
	for (int i = 2; i <= sam1.tot; i++) ans += sam1.len[i] - sam1.len[sam1.pre[i]];
	ans *= 3;
	ans -= sam1.len[sam1.lp[n]] - sam1.len[sam1.pre[sam1.lp[n]]];
	ans -= sam2.len[sam2.lp[n]] - sam2.len[sam2.pre[sam2.lp[n]]];
	ans += 2;
	Tree2::Build();
	Tree1::ls = n;
	Tree1::Build();
	print_int(ans, '\n');
	return 0;
}