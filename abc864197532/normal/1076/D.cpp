#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 300000, logN = 17, K = 350;

vector <pair <int, lli>> adj[N];
vector <pii> adj2[N]; 
vector <lli> dis;
vector <int> path;

void run(int s, int n) {
	dis.assign(n, 1ll << 60);
	path.assign(n, -1);
	dis[s] = 0;
	int v;
	lli d;
	priority_queue <pair <lli, int>, vector <pair <lli, int>>, greater<pair <lli, int>>> pq;
	pq.push({dis[s], s});
	while (pq.size()) {
		tie(d, v) = pq.top(); pq.pop();
		if (dis[v] < d) continue;
		int u, w;
		for (pii A : adj[v]) {
			tie(u, w) = A;
			if (dis[u] > dis[v] + w) {
				dis[u] = dis[v] + w;
				path[u] = v;
				pq.push({dis[u], u});
			}
		}
	}
}

vector <int> ans;

void dfs(int v, int pa, int e) {
	if (~e) ans.pb(e);
	for (pii A : adj2[v]) if (A.X != pa) {
		dfs(A.X, v, A.Y);
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, w, c = 1, k;
    cin >> n >> m >> k;
    map <pii, int> edge;
    fop (i,0,m) {
    	cin >> u >> v >> w; u--; v--;
    	adj[u].eb(v, w);
    	adj[v].eb(u, w);
    	edge[{u, v}] = c;
    	edge[{v, u}] = c++;
	}
	run(0, n);
	fop (i,1,n) {
		tie(u, v) = mp(i, path[i]);
		c = edge[{u, v}];
		adj2[u].eb(v, c);
		adj2[v].eb(u, c);
	}
	dfs(0, -1, -1);
	while (ans.size() > k) ans.pop_back();
	cout << ans.size() << endl;
	printv(ans);
}