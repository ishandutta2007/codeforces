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
const int N = 100015, K = 515;
int T, n, k, eid[K][K][2], nid[K][K], val[K * K * 2];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
vector<pii> e[K * K];
bool valid(int x, int y) {return 1 <= min(x, y) && max(x, y) <= k;}
void add(int u, int v, int w) {e[u].emplace_back(v, w); e[v].emplace_back(u, w);}
int dis[K * K];
bool vis[K * K];
priority_queue<pii, vector<pii>, greater<pii>> q;
void dij(int s, int m) {
	rep(i, 1, m) dis[i] = inf, vis[i] = 0;
	q.push(mp(0, s));
	dis[s] = 0;
	while(SZ(q)) {
		int u = q.top().se; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto [v, w] : e[u]) {
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(mp(dis[v], v));
			}
		}
	}
}
void solve() {
	scanf("%d%d", &n, &k);
	int te = 0, tn = 0;
	rep(i, 0, k) rep(j, 0, k) nid[i][j] = ++tn;
	rep(i, 1, k) rep(j, 1, k) {
		rep(d, 0, 1) {
			int ni = i + dx[d], nj = j + dy[d];
			if (!valid(ni, nj)) continue;
			eid[i][j][d] = ++te;
		}
	}
	fill(val + 1, val + te + 1, 0);
	rep(i, 1, tn) e[i].clear();
	rep(i, 1, n) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		rep(_, 0, 1) {
			if (r1 > r2 || c1 > c2) swap(r1, r2), swap(c1, c2);
			rep(d, 0, 1) {
				if (r1 + dx[d] == r2 && c1 + dy[d] == c2) {
					val[eid[r1][c1][d]]++;
				}
			}
			r1 = k - r1 + 1;
			r2 = k - r2 + 1;
			c1 = k - c1 + 1;
			c2 = k - c2 + 1;
		}
	}
	rep(i, 1, k) rep(j, 1, k) {
		rep(d, 0, 1) {
			int ni = i + dx[d], nj = j + dy[d];
			if (!valid(ni, nj)) continue;
			add(nid[i][j], nid[i - dx[d ^ 1]][j - dy[d ^ 1]], val[eid[i][j][d]]);
		}
	}
	dij(nid[k / 2][k / 2], tn);
	int ans = inf;
	rep(i, 0, k) rep(j, 0, k) {
		if(min(i, j) == 0 || max(i, j) == k) {
			ans = min(ans, dis[nid[i][j]]);
		}
	}
	printf("%d\n", n - ans);
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}