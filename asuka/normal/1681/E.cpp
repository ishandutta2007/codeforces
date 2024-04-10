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
const int N = 100015;

struct mat {
	ll d[2][2];
	mat() { memset(d, 0x3f, sizeof d); }
	ll *operator[](int i) { return d[i]; }
	mat operator * (mat o) const {
		mat res;

		rep(i, 0, 1) rep(j, 0, 1) rep(k, 0, 1) res[i][k] = min(res[i][k], d[i][j] + o[j][k]);

		return res;
	}
} a[N];

int lev(int x, int y) { return max(x, y); }
int id(int x, int y) { return x >= y ? y : y + y - x; }

struct node {
	int l, mid, r;
	mat s;
	node *ls, *rs;

	void pull() { s = ls -> s * rs -> s; }

	mat ask(int x, int y) {
		if (x <= l && r <= y) return s;

		if (y <= mid) return ls -> ask(x, y);

		if (x > mid) return rs -> ask(x, y);

		return ls -> ask(x, y) * rs -> ask(x, y);
	}
} Pool[N << 1], *ptr = Pool, *rt;

node *build(int l, int r) {
	int mid = (l + r) >> 1;
	node *p = ptr++;
	p -> l = l; p -> r = r; p -> mid = mid;

	if (l == r) p -> s = a[l];
	else p -> ls = build(l, mid),  p -> rs = build(mid + 1, r), p -> pull();

	return p;
}

int n, m, ux[N], uy[N], rx[N], ry[N];


int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);

	rep(i, 1, n - 1) scanf("%d%d%d%d", &ux[i], &uy[i], &rx[i], &ry[i]);

	rep(i, 1, n - 2) {
		rep(p, 0, 1) rep(q, 0, 1) {
			a[i][p][q] = 1 + abs((p ? id(ux[i] + 1, uy[i]) : id(rx[i], ry[i] + 1)) - (q ? id(ux[i + 1], uy[i + 1]) : id(rx[i + 1], ry[i + 1])));
		}
	}

	if (1 <= n - 2) rt = build(1, n - 2);
	scanf("%d", &m);

	rep(i, 1, m) {
		int sx, sy, tx, ty, l, r;
		scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
		l = lev(sx, sy);
		r = lev(tx, ty);

		if (l > r)
			swap(sx, tx), swap(sy, ty), swap(l, r);

		if (l == r)
			printf("%d\n", abs(id(sx, sy) - id(tx, ty)));
		else if (l + 1 == r) {
			ll ans = infll;

			rep(p, 0, 1) {
				ans = min(ans, 1ll + abs(id(sx, sy) - (p ? id(ux[l], uy[l]) : id(rx[l], ry[l]))) +
				          abs(id(tx, ty) - (p ? id(ux[l] + 1, uy[l]) : id(rx[l], ry[l] + 1))));
			}

			printf("%lld\n", ans);

		} else {
			ll ans = infll;
			mat u = rt -> ask(l, r - 2);

			rep(p, 0, 1) rep(q, 0, 1) {
				ans = min(ans, 1 + u[p][q] + abs(id(sx, sy) - (p ? id(ux[l], uy[l]) : id(rx[l], ry[l])))
				          + abs(id(tx, ty) - (q ? id(ux[r - 1] + 1, uy[r - 1]) : id(rx[r - 1], ry[r - 1] + 1))));
			}

			printf("%lld\n", ans);
		}
	}

	return 0;
}