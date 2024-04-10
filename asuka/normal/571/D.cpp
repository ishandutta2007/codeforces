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
const int N = 500015;
vector<pair<int, ll>> a[N];
vector<int> U[N], M[N];
int n, q, t[N], fau[N], fam[N];
pair<int, ll> d[N];

int find(int fa[], int x) { return x == fa[x] ? x : fa[x] = find(fa, fa[x]); }

ll ask(int x) {
	int u = find(fau, x), m = find(fam, x);
	if (t[m] > d[x].fi) d[x] = mp(t[m], 0);
	int o = lower_bound(all(a[u]), mp(d[x].fi, 0ll)) - a[u].begin();
	return d[x].se + (a[u].empty() ? 0 : (a[u].back().se - (o ? a[u][o - 1].se : 0)));
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d", &n, &q);
	rep(i, 1, n) fau[i] = fam[i] = i, U[i].pb(i), M[i].pb(i);

	rep(_, 1, q) {
		char op[3];
		int x, y;
		scanf("%s%d", op, &x);
		if (op[0] == 'U' || op[0] == 'M') scanf("%d", &y);

		if (op[0] == 'U') {
			bool fl = 0;
			if (SZ(U[x]) < SZ(U[y]))
				swap(x, y), fl = 1;

			for (int o : U[y]) {
				d[o] = mp(_, ask(o));
				U[x].pb(o);
			}

			if (!fl) {
				fau[y] = x;
			} else {
				fau[x] = y;
				swap(U[x], U[y]);
				swap(a[x], a[y]);
			}
		} else if (op[0] == 'M') {
			bool fl = 0;
			if (SZ(M[x]) < SZ(M[y])) 
				swap(x, y), fl = 1;

			for (int o : M[y]) {
				d[o] = mp(_, ask(o));
				M[x].pb(o);
			}

			if (!fl) {
				fam[y] = x;
			} else {
				fam[x] = y;
				swap(M[x], M[y]);
				swap(t[x], t[y]);
			}
		} else if (op[0] == 'A') {
			int k = SZ(U[x]);
			a[x].eb(_, k + (a[x].empty() ? 0 : a[x].back().se));
		} else if (op[0] == 'Z') {
			t[x] = _;
		} else printf("%lld\n", ask(x));
	}
	return 0;
}