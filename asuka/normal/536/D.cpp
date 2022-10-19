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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
using pll = pair<ll, ll>;
const int N = 2015;
int n, m, s, t, p[N], x[N], y[N];
int pMax[N], pMin[N], nx[N][N], ny[N][N];
bool occ[N][N];
ll suf[N][N], Max[N], Min[N], dp[N][N][2];
vector<pii> e[N];

bool vis[N];
ll dis[N];
priority_queue<pll, vector<pll>, greater<pll>> q;

void dij(int st, int res[]) {
	fill(vis + 1, vis + n + 1, 0);
	fill(dis + 1, dis + n + 1, infll);
	q.emplace(0, st);
	dis[st] = 0;
	while (SZ(q)) {
		int u = q.top().se; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v, w] : e[u]) {
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.emplace(dis[v], v);
			}
		}
	}
	vector<ll> vec;
	rep(i, 1, n) vec.emplace_back(dis[i]);
	sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
	res[0] = SZ(vec);
	rep(i, 1, n) res[i] = lower_bound(all(vec), dis[i]) - vec.begin() + 1;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	rep(i, 1, n) scanf("%d", &p[i]);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}
	dij(s, x); dij(t, y);
	rep(i, 1, n) suf[x[i]][y[i]] += p[i], occ[x[i]][y[i]] = 1;

	memset(nx, 0x3f, sizeof nx);
	memset(ny, 0x3f, sizeof ny);
	per(i, 0, x[0]) per(j, 0, y[0]) {
		suf[i][j] += suf[i + 1][j] + suf[i][j + 1] - suf[i + 1][j + 1];
		nx[i][j] = min({nx[i + 1][j], nx[i][j + 1], occ[i + 1][j + 1] ? i + 1 : inf});
		ny[i][j] = min({ny[i + 1][j], ny[i][j + 1], occ[i + 1][j + 1] ? j + 1 : inf});
	}
	rep(i, 0, n) pMax[i] = x[0] + 1, pMin[i] = y[0] + 1;
	rep(i, 0, n) Max[i] = -1e14, Min[i] = 1e14;
	per(i, 0, x[0]) per(j, 0, y[0]) {
		if (nx[i][j] == inf && ny[i][j] == inf) dp[i][j][0] = dp[i][j][1] = 0;
		else {
			while (pMax[j] - 1 >= nx[i][j]) Max[j] = max(Max[j], dp[pMax[j] - 1][j][1] - suf[pMax[j]][j + 1]), pMax[j]--;
			while (pMin[i] - 1 >= ny[i][j]) Min[i] = min(Min[i], dp[i][pMin[i] - 1][0] + suf[i + 1][pMin[i]]), pMin[i]--;
			dp[i][j][0] = suf[i + 1][j + 1] + Max[j];
			dp[i][j][1] = - suf[i + 1][j + 1] + Min[i];
		}
	}
	if (dp[0][0][0] > 0) puts("Break a heart");
	else if (dp[0][0][0] == 0) puts("Flowers");
	else puts("Cry");
	return 0;
}