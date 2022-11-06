#include <bits/stdc++.h>
#define IT set<node>::iterator
using std::set; using std::swap; using std::sort;
typedef long long LL;
const int N = 100005;
int n, m, seed, vmax;
int rnd() {
	int ret = seed;
	seed = (seed * 7LL + 13) % 1000000007;
	return ret;
}
int qpow(int a, int b, int mod) {
	int t = 1;
	for (; b; b >>= 1, a = 1LL * a * a % mod)
		if (b & 1) t = 1LL * t * a % mod;
	return t;
}
struct node {
	int l, r;
	mutable LL v;
	node(int l, int r = -1, LL v = 0) : l(l), r(r), v(v) {}
	bool operator < (const node &o) const { return l < o.l; }
};
set<node> S;
IT split(int pos) {
	IT it = S.lower_bound(node(pos));
	if (it != S.end() && it->l == pos) return it;
	--it;
	int l = it->l, r = it->r; LL val = it->v;
	S.erase(it); S.insert(node(l, pos - 1, val));
	return S.insert(node(pos, r, val)).first;
}
void assign(int l, int r, int val) {
	IT itr = split(r + 1), itl = split(l);
	S.erase(itl, itr), S.insert(node(l, r, val));
}
void add(int l, int r, int val) {
	IT itr = split(r + 1), itl = split(l);
	for (IT it = itl; it != itr; it++)
		it->v += val;
}
struct pair { LL x; int y; };
bool cmp(pair a, pair b) { return a.x < b.x; }
LL kth(int l, int r, int rk) {
	static pair a[N]; int tot = 0;
	IT itr = split(r + 1), itl = split(l);
	for (IT it = itl; it != itr; it++)
		a[tot++] = (pair){it->v, it->r - it->l + 1};
	sort(a, a + tot, cmp);
	for (int i = 0; i < tot; i++) {
		rk -= a[i].y;
		if (rk <= 0) return a[i].x;
	}
	return -1;
}
int calc(int l, int r, int x, int y) {
	int ans = 0; IT itr = split(r + 1), itl = split(l);
	for (IT it = itl; it != itr; it++)
		ans = (ans + 1LL * (it->r - it->l + 1) * qpow(it->v % y, x, y)) % y;
	return ans;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	for (int i = 1; i <= n; i++)
		S.insert(node(i, i, rnd() % vmax + 1));
	for (int i = 1; i <= m; i++) {
		int op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1, x, y;
		if (l > r) swap(l, r);
		if (op == 3) x = rnd() % (r - l + 1) + 1;
		else x = rnd() % vmax + 1;
		if (op == 4) y = rnd() % vmax + 1;
		if (op == 1) add(l, r, x);
		if (op == 2) assign(l, r, x);
		if (op == 3) printf("%lld\n", kth(l, r, x));
		if (op == 4) printf("%d\n", calc(l, r, x, y));
	}
	return 0;
}