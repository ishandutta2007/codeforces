#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;

struct edge{
    ll to, cap, flow, cost;
    edge(){

    }
    edge(int _to, int _cap, ll _cost) {
        to = _to;
        cap = _cap;
        flow = 0;
        cost = _cost;
    }
};
vector<edge> e;
vector<int> g[maxn];
void add_edge(int from, int to, int cap, ll cost) {
    g[from].push_back(e.size());
    e.push_back(edge(to, cap, cost));
    g[to].push_back(e.size());
    e.push_back(edge(from, 0, -cost));
}
int s, t;
ll dis[maxn];
int fr[maxn];
ll ans = 0;
int spfa() {
    for(int i = 0; i <= t; i++) {
        dis[i] = 1ll<<60;
        fr[i] = -1;
    }
    queue <int> q;
    dis[s] = 0;
    q.push(s);
    while(q.size() > 0) {
        int v = q.front();
        q.pop();
        for(int to: g[v]) {
            edge &o = e[to];
            if(o.cap - o.flow == 0) continue;
            if(dis[o.to] > dis[v] + o.cost) {
                dis[o.to] = dis[v] + o.cost;
                fr[o.to] = to;
                q.push(o.to);
            }
        }
    }
    if(fr[t] == -1) {
        return 0;
    }
    int v = t;
    vector<int> edges;
    while(fr[v] != -1) {
        edges.push_back(fr[v]);
        v = e[fr[v]^1].to;
    }
    ll mi = inf;
    for(int id: edges) {
        mi = min(mi, e[id].cap - e[id].flow);
    }
    ll cur = 0;
    for(int id: edges) {
        e[id].flow += mi;
        e[id ^ 1].flow -= mi;
        cur += e[id].cost * mi;
    }
    if(cur >= 0) return false;
    ans -= cur;
    return true;
}
int n, m;
int a[550], b[550], k[550];
int p[550];
int cmp(int i,int j) {
    return b[i] > b[j];
}
ll dp[550][550];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> k[i];
        p[i] = i;
    }
    sort(p, p+n, cmp);
    for(int pos = 0; pos < n; pos++) {
        int i = p[pos];
        for(int j = 0; j <= n; j++) {
            dp[pos + 1][j] = max(dp[pos][j], dp[pos+1][j]);
            dp[pos + 1][j + 1] = max(dp[pos+1][j+1], dp[pos][j] + a[i] - b[i] * 1ll * min(k[i], j));
            dp[pos + 1][j] = max(dp[pos][j]+ a[i] - b[i] * 1ll * k[i], dp[pos+1][j]);
        }
    }
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}