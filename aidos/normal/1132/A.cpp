#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
pair <int, pii> e[maxn];
int p[maxn];
vector<pii> g[maxn];
vector<pii> G[maxn];
ll dp[25][maxn];
int get(int v) {
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
void dijkstra(int v, int id) {
    priority_queue< pair<ll, int> > pq;
    for(int i = 1; i <= n; i++) dp[id][i] = 1ll<<50;
    dp[id][v] = 0;
    pq.push(make_pair(0, v));
    while(pq.size() > 0) {
        ll val = -pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(val > dp[id][v]) continue;
        for(const pii &to: G[v]) {
            int u = to.first;
            int w = to.second;
            if(dp[id][u] > val + w) {
                dp[id][u] = val + w;
                pq.push(make_pair(-dp[id][u], u));
            }
        }
    }
}
int lev[maxn];
int par[20][maxn];
ll d[maxn];
void dfs(int v, int P) {
    par[0][v] = P;
    for(int i = 1; i < 20; i++) {
        par[i][v] = par[i-1][par[i-1][v]];
    }
    for(const pii &to: g[v]) {
        int u = to.first;
        int w = to.second;
        if(u == P) continue;
        d[u] = d[v] + w;
        lev[u] = lev[v] + 1;
        dfs(u, v);
    }
}
int lca(int u, int v) {
    if(lev[u] > lev[v]) swap(u, v);
    for(int i = 19; i >= 0; i--) {
        if(lev[v] - (1<<i) >= lev[u]) {
            v = par[i][v];
        }
    }
    if(u == v) return v;
    for(int i = 19; i >= 0; i--) {
        if(par[i][v] != par[i][u]) {
            v = par[i][v];
            u = par[i][u];
        }
    }
    return par[0][v];
}
void solve() {
    int cnt1, cnt2, cnt3, cnt4;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
    if(cnt1 != cnt4 || (cnt3 > 0 && cnt1 == 0)) cout << 0;
    else cout << 1;
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
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