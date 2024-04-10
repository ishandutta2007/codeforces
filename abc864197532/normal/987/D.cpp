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
const int x = 864197532, N = 100087, logN = 18;

vector <int> adj[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s, k, u, v;
	cin >> n >> m >> k >> s;
	vector <int> color(n);
	fop (i,0,n) cin >> color[i], color[i]--;
	vector <vector <int>> dis(n, vector <int>(k, -1));
	fop (i,0,m) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fop (i,0,k) {
		queue <int> q;
		fop (j,0,n) if (color[j] == i) q.push(j), dis[j][i] = 0;
		while (q.size()) {
			int v = q.front(); q.pop();
			for (int u : adj[v]) if (dis[u][i] == -1) {
				dis[u][i] = dis[v][i] + 1;
				q.push(u);
			}
		}
	}
	fop (i,0,n) {
		sort(all(dis[i]));
		cout << accumulate(dis[i].begin(), dis[i].begin() + s, 0ll) << ' ';
	}
	cout << endl;
}