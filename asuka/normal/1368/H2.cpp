#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int SZ = 1 << 20;
struct IO {
	char buf[SZ], *p1, *p2;
	char fub[SZ], *pp;
	IO() : p1(buf), p2(buf), pp(fub) {}
	~IO() {fwrite(fub, 1, pp - fub, stdout);}
#ifdef Asuka
	char gc() { return getchar();}
	void pc(char c) { putchar(c);}
#else
	char gc() {
		if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, SZ, stdin);

		return p1 == p2 ? ' ' : *p1++;
	}
	void pc(char c) {
		if (pp - fub == SZ) fwrite(pp = fub, 1, SZ, stdout);

		*pp++ = c;
	}
#endif
	char readletter() {
		char ch = gc();

		while (ch < 'A' || ch > 'Z') ch = gc();

		return ch;
	}
	int read() {
		int x = 0;
		char ch = gc();

		while (!isdigit(ch)) ch = gc();

		while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch - '0'), ch = gc();

		return x;
	}
	void write(int x) {
		static int sta[25];

		if (x < 0) pc('-'), x = -x;

		int top = 0;

		do {
			sta[top++] = x % 10, x /= 10;
		} while (x);

		while (top) pc(sta[--top] + '0');
	}
} io;

const int N = 100015;

struct mat {
	int d[2][2];
	mat operator * (const mat &rhs) const {
		static mat res;
		res.d[0][0] = min(d[0][0] + rhs.d[0][0], d[0][1] + rhs.d[1][0]);
		res.d[0][1] = min(d[0][0] + rhs.d[0][1], d[0][1] + rhs.d[1][1]);
		res.d[1][0] = min(d[1][0] + rhs.d[0][0], d[1][1] + rhs.d[1][0]);
		res.d[1][1] = min(d[1][0] + rhs.d[0][1], d[1][1] + rhs.d[1][1]);
		return res;
	}
	void flip() {
		swap(d[0][0], d[1][1]);
		swap(d[0][1], d[1][0]);
	}
};

struct node {
	int l, r, mid, len, su, sd;
	char fl;
	mat c[2];
	node *ls, *rs;

	void init(int _l, int _r, int u, int d, int h) {
		l = _l; r = _r; mid = (l + r) >> 1; len = r - l + 1; su = u; sd = d;
		fl = 0;
		rep(p, 0, 1) memset(c[p].d, 0, sizeof c[p].d);
		rep(p, 0, 1) rep(q, 0, 1) c[p].d[q][!q] = h;
		rep(p, 0, 1) rep(q, 0, 1) {
			c[p].d[q][!u]++;
			c[p].d[q][!d ^ p]++;
		}
	}

	void pull() {
		su = ls -> su + rs -> su;
		sd = ls -> sd + rs -> sd;
		c[0] = ls -> c[0] * rs -> c[0];
		c[1] = ls -> c[1] * rs -> c[1];
	}

	void down(char f) {
		if (f & 1) {
			c[0].flip(); c[1].flip();
			swap(c[0], c[1]);
			su = len - su;
		}

		if (f & 2) {
			swap(c[0], c[1]);
			sd = len - sd;
		}

		fl ^= f;
	}

	void push() { if (fl) ls -> down(fl), rs -> down(fl), fl = 0; }

	void flip(int x, int y, char f) {
		if (x <= l && r <= y) return down(f);

		push();

		if (x <= mid) ls -> flip(x, y, f);

		if (y > mid) rs -> flip(x, y, f);

		pull();
	}
} Pool[N << 3], *ptr = Pool, *P, *Q;

node* build(int l, int r, int U[], int D[], int H) {
	node *p = ptr++;

	int mid = (l + r) >> 1;
	p -> init(l, r, U[l], D[l], H);

	if (l != r) {
		p -> ls = build(l, mid, U, D, H);
		p -> rs = build(mid + 1, r, U, D, H);
		p -> pull();
	}

	return p;
}

int n, m, q, S[4][N];

void solve() {
	int ans = inf;
	rep(p, 0, 1) rep(q, 0, 1) {
		ans = min(ans, (!p ? Q -> su : n - Q -> su) + (!q ? Q -> sd : n - Q -> sd) + P -> c[0].d[p][q]);
		ans = min(ans, (!p ? P -> su : m - P -> su) + (!q ? P -> sd : m - P -> sd) + Q -> c[0].d[p][q]);
	}
	io.write(ans); io.pc('\n');
}

int main() {
	// freopen("line.in", "r", stdin);
	// freopen("line.out", "w", stdout);
	n = io.read(); m = io.read(); q = io.read();
	rep(_, 0, 1) rep(i, 1, n) S[_][i] = io.readletter() == 'R';
	rep(_, 2, 3) rep(i, 1, m) S[_][i] = io.readletter() == 'R';
	P = build(1, m, S[2], S[3], n); Q = build(1, n, S[0], S[1], m);
	solve();
	rep(_, 1, q) {
		char opt = io.readletter();
		int l = io.read(), r = io.read();

		if (opt == 'U') P -> flip(l, r, 1);
		else if (opt == 'D') P -> flip(l, r, 2);
		else if (opt == 'L') Q -> flip(l, r, 1);
		else Q -> flip(l, r, 2);

		solve();
	}
	return 0;
}