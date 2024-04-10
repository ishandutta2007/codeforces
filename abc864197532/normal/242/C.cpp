#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 50000, dx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
const double eps = 1e-6, Pi = 3.1415926535;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x0, y0, x1, y1, n, r, ll, rr, now = 0;
	cin >> x0 >> y0 >> x1 >> y1 >> n;
	map <pii, int> point;
	fop (i,0,n) {
		cin >> r >> ll >> rr;
		fop (j,ll,rr + 1) if (!point.count({r, j})) point[{r, j}] = now++;
	}
	vector <int> adj[now];
	for (auto A : point) {
		tie(ll, rr) = A.X;
		fop (k,0,8) {
			if (point.count({ll + dx[k], rr + dy[k]})) {
				adj[A.Y].pb(point[{ll + dx[k], rr + dy[k]}]);
			}
		}
	}
	vector <int> dis(now, -1);
	if (!point.count({x0, y0}) || !point.count({x1, y1})) {
		cout << -1 << endl;
	} else {
		int s = point[{x0, y0}], t = point[{x1, y1}];
		queue <int> q;
		q.push(s);
		dis[s] = 0;
		int v;
		while (q.size()) {
			v = q.front(); q.pop();
			for (int u : adj[v]) if (dis[u] == -1) {
				dis[u] = dis[v] + 1;
				q.push(u);
			}
		}
		cout << dis[t] << endl;
	}
}