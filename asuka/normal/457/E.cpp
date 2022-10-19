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

const int N = 200015;

int n, m, anc[N], Max[N], Min[N], d[N];
tuple<int, int, int> e[N];
vector<pii> g[N];
bool vis[N];

bool dfs(int u, int r) {
	anc[u] = r;
	Max[r] = max(Max[r], d[u]);
	Min[r] = min(Min[r], d[u]);
	vis[u] = 1;

	for (auto [v, w] : g[u]) {
		if (vis[v]) {
			if (d[v] != d[u] + w) return 0;

		} else {
			d[v] = d[u] + w;

			if (!dfs(v, r)) return 0;
		}
	}

	return 1;
}

int check(int x) {
	rep(i, 1, n) g[i].clear(), vis[i] = 0, Max[i] = -inf, Min[i] = inf;
	rep(i, 1, x) {
		auto [u, v, w] = e[i];
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, -w);
	}

	rep(i, 1, n) {
		if (vis[i]) continue;

		d[i] = 0;

		if (!dfs(i, i)) return -1;
	}

	rep(i, 2, n) if (anc[i] == anc[1] && d[i] <= d[1]) return -2;

	rep(i, 1, n - 1) if (anc[i] == anc[n] && d[i] >= d[n]) return -3;

	if (anc[1] == anc[n]) {

		rep(i, 1, n) if (i == anc[i] && anc[i] != anc[1]) {
			if (Max[i] - Min[i] >= d[n] - d[1])
				return -4;
		}

		return d[n] - d[1];
	}

	return 0;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);

	rep(i, 1, m) {
		int u, v, w, f;
		scanf("%d%d%d%d", &u, &v, &w, &f);
		e[i] = {u, v, w * f};
	}

	int l = 1, r = m, ans = -1;

	while (l <= r) {
		int mid = (l + r) >> 1;

		if (check(mid) < 0) ans = mid, r = mid - 1;
		else l = mid + 1;
	}

	if (ans > 0) {
		printf("BAD %d\n", ans);
		return 0;
	}

	int o = check(m);

	if (o == 0) puts("UNKNOWN");
	else printf("%d\n", o);

	return 0;
}