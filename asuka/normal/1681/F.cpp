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

const int N = 500015;

int fa[N], siz[N];
vector<pii> s;

int find(int x) { return x == fa[x] ? x : find(fa[x]); }

void uni(int u, int v) {
	u = find(u); v = find(v);

	if (u == v) return;

	if (siz[u] < siz[v]) swap(u, v);

	fa[v] = u;
	siz[u] += siz[v];
	s.emplace_back(u, v);
}

void rollback() {
	auto [u, v] = s.back();
	fa[v] = v;
	siz[u] -= siz[v];
	s.pop_back();
}

ll ans;
vector<pii> t[N << 2];
#define mid ((l + r) >> 1)

void ins(int p, int l, int r, int x, int y, pii v) {
	if (x <= l && r <= y) return t[p].pb(v), void();

	if (x <= mid) ins(p << 1, l, mid, x, y, v);

	if (y > mid) ins(p << 1 | 1, mid + 1, r, x, y, v);
}

vector<pii> ed[N];

void dfs(int p, int l, int r) {
	int o = SZ(s);

	for (auto [u, v] : t[p]) uni(u, v);


	if (l == r) {
		for (auto [u, v] : ed[l]) {
			ans += (ll) siz[find(u)] * siz[find(v)];
		}

	} else {
		dfs(p << 1, l, mid);
		dfs(p << 1 | 1, mid + 1, r);
	}

	while (SZ(s) > o) rollback();
}

int n;

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);

	rep(i, 1, n) fa[i] = i, siz[i] = 1;

	rep(i, 2, n) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ed[w].emplace_back(u, v);
	}

	rep(i, 1, n) {
		for (auto [u, v] : ed[i]) {
			if (1 < i) ins(1, 1, n, 1, i - 1, mp(u, v));

			if (i < n) ins(1, 1, n, i + 1, n, mp(u, v));
		}
	}

	dfs(1, 1, n);
	printf("%lld\n", ans);
	return 0;
}