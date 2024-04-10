#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
const int N = 200000;
vector <int> adj[N], weight;

vector <int> bfs(int v, int n) {
    vector <int> ans(n, -1);
    queue <pii> q;
    q.push({v, 0});
    ans[v] = 0;
    int u, d;
    while (q.size()) {
        tie(u, d) = q.front(); q.pop();
        for (int v : adj[u]) if (ans[v] == -1) {
            q.push({v, d + 1});
            ans[v] = d + 1;
        }
    }
    return ans;
}


void solve () {
    int n, m, a, b, c, u, v;
    cin >> n >> m >> a >> b >> c;
    a--; b--; c--;
    weight.resize(m);
    fop (i,0,m) cin >> weight[i];
    fop (i,0,n) adj[i].clear();
    fop (i,0,m) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sort(weight.begin(), weight.end());
    vector <lli> pre(m + 1, 0);
    fop (i,0,m) pre[i + 1] = pre[i] + weight[i];
    vector <int> dis[3];
    dis[0] = bfs(a, n);
    dis[1] = bfs(b, n);
    dis[2] = bfs(c, n);
    lli ans = 1ll << 60;
    fop (i,0,n) {
    	//cout << dis[1][i] << ' ' << min(dis[0][i] + dis[1][i] + dis[2][i], m) << endl;
    	if (dis[0][i] + dis[1][i] + dis[2][i] > m) continue;
        ans = min(ans, pre[dis[0][i] + dis[1][i] + dis[2][i]] + pre[dis[1][i]]);
    }
    cout << ans << '\n';
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}