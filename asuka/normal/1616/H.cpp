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
const int N = 150015, M = N * 30, mod = 998244353;

int n, a[N], x, ls[M], rs[M], cnt[M], pw[N], rt, tot, ans;

void ins(int &p, int d, int v) {
	if (!p) p = ++tot;

	cnt[p]++;

	if (d < 0) return;

	ins(v >> d & 1 ? rs[p] : ls[p], d - 1, v);
}

int g(int u) {
	return (ll) (pw[cnt[ls[u]]] - 1) * (pw[cnt[rs[u]]] - 1) % mod;
}

int f(int u, int v, int d) {
	if (!u || !v || d < 0) return (ll) pw[cnt[u]] * pw[cnt[v]] % mod;

	if (x >> d & 1) return (ll) f(ls[u], rs[v], d - 1) * f(rs[u], ls[v], d - 1) % mod;
	else return ((ll) f(ls[u], ls[v], d - 1) + f(rs[u], rs[v], d - 1) - 1 + g(u) + g(v)) % mod;
}

void solve(int p, int d) {
	if (!p) return;

	if (d < 0) return (ans += pw[cnt[p]] - 1) %= mod, void();

	if (x >> d & 1)(ans += f(ls[p], rs[p], d - 1) - 1) %= mod;
	else solve(ls[p], d - 1), solve(rs[p], d - 1);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &x);

	rep(i, 1, n) scanf("%d", a + i), ins(rt, 29, a[i]);

	pw[0] = 1;

	rep(i, 1, n) pw[i] = pw[i - 1] * 2 % mod;

	solve(1, 29);

	if (ans < 0) ans += mod;

	printf("%d\n", ans);
	return 0;
}