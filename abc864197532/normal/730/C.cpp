#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 5000, logN = 17;

vector <int> adj[N];
vector <pair<pii, int>> store;

vector <int> bfs(int v, int n) {
	vector <int> dis(n, -1);
	queue <int> q;
	q.push(v);
	dis[v] = 0;
	while (q.size()) {
		v = q.front(); q.pop();
		for (int u : adj[v]) if (dis[u] == -1) {
			dis[u] = dis[v] + 1;
			q.push(u);
		}
	}
	return dis;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, u, v, k, p;
    cin >> n >> m;
    fop (i,0,m) {
    	cin >> u >> v;
    	u--; v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	cin >> m;
	fop (i,0,m) {
		cin >> u; u--;
		store.pb({{0, 0}, u});
		cin >> store.back().X.Y >> store.back().X.X;
	}
	sort(all(store));
	cin >> q;
	while (q--) {
		cin >> v >> k >> p; v--;
		vector <int> dis = bfs(v, n);
		auto ask = [&](int d) {
			vector <pair<pii, int>> tmp;
			fop (i,0,m) {
				if (~dis[store[i].Y] && dis[store[i].Y] <= d) {
					tmp.pb(store[i]);
				}
			}
			lli ans = 0;
			int all = 0, now = 0;
			while (now < tmp.size() && all < k) {
				int need = min(k - all, tmp[now].X.Y);
				ans += 1ll * need * tmp[now].X.X;
				all += need;
				now++;
			}
			return (all == k && ans <= p);
		};
		int l = -1, r = n + 87;
		while (r - l > 1) {
			int mid = l + r >> 1;
			if (ask(mid)) r = mid;
			else l = mid;
		}
		if (r == n + 87) r = -1;
		cout << r << endl;
	}
}