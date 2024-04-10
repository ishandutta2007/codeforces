#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
using db = double;
const db INF = 1e7; 
const int N = 200015;
int n, q, X, Y;

struct mat {
	db a[3][3];

	mat operator * (const mat &o) const {
		mat r;
		rep(i, 0, 2) rep(j, 0, 2) r.a[i][j] = -INF;
		rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2)
			r.a[i][k] = max(r.a[i][k], a[i][j] + o.a[j][k]);
		return r;
	}
} t[N << 2];

#define mid ((l + r) >> 1)

void pull(int p) {
	t[p] = t[p << 1] * t[p << 1 | 1];
}

mat ask(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return t[p];
	if (y <= mid) return ask(p << 1, l, mid, x, y);
	if (mid < x) return ask(p << 1 | 1, mid + 1, r, x, y);
	return ask(p << 1, l, mid, x, y) * ask(p << 1 | 1, mid + 1, r, x, y);
}

void upd(int p, int l, int r, int x, int v) {
	if (l == r) {
		rep(i, 0, 2) rep(j, 0, 2) {
			if (i + j > 2)
				t[p].a[i][j] = -INF;
			else {
				if (j == 0) t[p].a[i][j] = 0;
				else if (j == 1) t[p].a[i][j] = db(v) / db(X + Y);
				else t[p].a[i][j] = db(v) / Y;
			}
		}

		return;
	}

	if (x <= mid) upd(p << 1, l, mid, x, v);
	else upd(p << 1 | 1, mid + 1, r, x, v);
	pull(p);
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q >> X >> Y;
	cout << fixed << setprecision(10);
	if (X > Y) swap(X, Y);

	rep(i, 1, n) { int v; cin >> v; upd(1, 1, n, i, v); }

	rep(i, 1, q) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) upd(1, 1, n, x, y);
		else {
			mat r = ask(1, 1, n, x, y);
			db ans = -INF;
			rep(i, 0, 2) rep(j, 0, 2) ans = max(ans, r.a[i][j]);
			cout << ans << '\n';
		}
	}
	return 0;
}