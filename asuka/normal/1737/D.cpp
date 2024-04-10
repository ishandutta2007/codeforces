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
int dis[505][505];

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		vector<tuple<int, int, int>> ed;
		cin >> n >> m;

		rep(i, 1, n) rep(j, 1, n) dis[i][j] = inf;
		rep(i, 1, n) dis[i][i] = 0;

		rep(i, 1, m) {
			int u, v, w;
			cin >> u >> v >> w;
			ed.eb(u, v, w);
			dis[u][v] = dis[v][u] = 1;
		}

		rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

		ll ans = infll;

		for (auto [u, v, w] : ed) {
			rep(_, 0, 1) {
				ans = min(ans, (ll) w * (1 + dis[1][u] + dis[v][n]));
				rep(i, 1, n)
					ans = min(ans, (ll) w * (2 + dis[1][i] + dis[i][u] + dis[i][n]));
				swap(u, v);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}