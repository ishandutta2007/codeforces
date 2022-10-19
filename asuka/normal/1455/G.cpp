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

const int N = 200000, M = N * 20;

ll Min[M], tag[M];
int ls[M], rs[M], tot;

void down(int p, ll v) {
	Min[p] += v;
	tag[p] += v;
}

void pd(int p) {
	if (ls[p]) down(ls[p], tag[p]);

	if (rs[p]) down(rs[p], tag[p]);

	tag[p] = 0;
}

void pu(int p) {
	Min[p] = min(Min[ls[p]], Min[rs[p]]);
}

#define mid ((l + r) >> 1)

void upd(int &p, int l, int r, int x, ll v) {
	if (!p) p = ++tot;

	if (l == r) return void(Min[p] = v);

	pd(p);
	x <= mid ? upd(ls[p], l, mid, x, v) : upd(rs[p], mid + 1, r, x, v);
	pu(p);
}

void merge(int &u, int v, int l, int r) {
	if (!u || !v) return u |= v, void();

	Min[u] = min(Min[u], Min[v]);

	if (l == r) return;

	pd(u); pd(v);
	merge(ls[u], ls[v], l, mid);
	merge(rs[u], rs[v], mid + 1, r);
	// pu(u);
}

ll ask(int p, int l, int r, int x) {
	if (!p) return infll;

	if (l == r) return Min[p];

	pd(p);
	return x <= mid ? ask(ls[p], l, mid, x) : ask(rs[p], mid + 1, r, x);
}

int n, s;

int calc(int x, ll v) {
	int rt = 0;
	upd(rt, 0, N, x, v);
	string o;

	while (cin >> o) {
		if (o == "end") return rt;

		if (o == "set") {
			int y, c;
			ll u = Min[rt];
			cin >> y >> c;
			down(rt, c);

			if (y != s) upd(rt, 0, N, y, u);

		} else {
			int y;
			cin >> y;
			ll u = ask(rt, 0, N, y);
			upd(rt, 0, N, y, infll);
			merge(rt, calc(y, u), 0, N);
		}
	}

	return rt;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> s;
	memset(Min, 0x3f, sizeof Min);
	cout << Min[calc(0, 0)];
	return 0;
}