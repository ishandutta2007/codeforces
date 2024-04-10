#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5;

mt19937 rnd((unsigned long long)(new char));
int n, m, ans[N + 10];

struct Element {
	int p, c;
	bool operator < (const Element &rhs) const {
		if (p == rhs.p) return c < rhs.c;
		return p > rhs.p;
	}
} a[N + 10];

struct Node *null;
struct Node {
    int rndval, val, id, mey, vtag, mtag; Node *ch[2];
    void revisev(int v) { val += v, vtag += v; }
	void revisem(int v) { mey += v, mtag += v; }
	void revise(int v) { val -= v, vtag -= v, mey++, mtag++; }
	void pushdown() {
		if (vtag) ch[0]->revisev(vtag), ch[1]->revisev(vtag), vtag = 0;
		if (mtag) ch[0]->revisem(mtag), ch[1]->revisem(mtag), mtag = 0;
    }
} mem[N + 10], *atot = mem, *rt;
 
void Init() { null = atot, null->ch[0] = null->ch[1] = null, rt = null; }
Node* newNode(int val, int id) { return atot++, atot->rndval = rnd(), atot->val = val, atot->id = id, atot->ch[0] = atot->ch[1] = null, atot; }
 
void splitval(Node *u, int val, Node *&x, Node *&y) {
    if (u == null) return x = y = null, void();
	u->pushdown();
    if (u->val <= val) x = u, splitval(u->ch[1], val, u->ch[1], y);
    else y = u, splitval(u->ch[0], val, x, u->ch[0]);
}
Node* merge(Node *x, Node *y) {
    if (x == null || y == null) return (x == null) ? y : x;
    if (x->rndval < y->rndval) return x->pushdown(), x->ch[1] = merge(x->ch[1], y), x;
    return y->pushdown(), y->ch[0] = merge(x, y->ch[0]), y;
}
void insert(Node *&u, Node *v) {
	Node *x, *z;
	splitval(u, v->val, x, z), u = merge(merge(x, v), z);
}
void dfs(Node *u, Node *&p) {
	if (u == null) return;
	u->pushdown(), dfs(u->ch[0], p), dfs(u->ch[1], p), u->ch[0] = u->ch[1] = null, insert(p, u);
}
void solve(Node *u) {
	if (u == null) return;
	u->pushdown(), solve(u->ch[0]), solve(u->ch[1]), ans[u->id] = u->mey;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    Init(), fr(m);
	for (int i = 1; i <= m; i++) fr(a[i].c, a[i].p);
	sort(a + 1, a + 1 + m), fr(n);
	for (int i = 1; i <= n; i++) insert(rt, newNode(fr(), i));
	for (int i = 1; i <= m; i++) {
		int c = a[i].c;
		Node *x, *y, *z;
		splitval(rt, c - 1, x, y), splitval(y, 2 * c - 1, y, z);
		if (z != null) z->revise(c);
		if (y != null) y->revise(c), dfs(y, x);
		rt = merge(x, z);
	}
	solve(rt);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}