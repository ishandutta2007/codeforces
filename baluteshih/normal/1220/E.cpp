#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

const int N = 4e5;

int low[N], dfn[N], Time;// 1-base
vector<pii> G[N], edge;
vector<bool> is_bridge;

void init(int n) {
    Time = 0;
    for (int i = 1; i <= n; ++i)
        G[i].clear(), low[i] = dfn[i] = 0;
}

void add_edge(int a, int b) {
    G[a].pb(pii(b, SZ(edge))), G[b].pb(pii(a, SZ(edge)));
    edge.pb(pii(a, b));
}

void dfs(int u, int f) {
    dfn[u] = low[u] = ++Time;
    for (auto i : G[u])
        if (!dfn[i.X])
            dfs(i.X, i.Y), low[u] = min(low[u], low[i.X]);
        else if (i.Y != f)
            low[u] = min(low[u], dfn[i.X]);
    if (low[u] == dfn[u] && f != -1)
        is_bridge[f] = 1;
}

void solve(int n) {
    is_bridge.resize(SZ(edge));
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            dfs(i, -1);
}

ll w[N], cnt[N], nw[N], vis[N], vis2[N];
ll dp[N][2];
vector<int> nG[N];
int tp;

void dfs2(int u, int num) {
    //cerr << u << " " << num << endl;
    vis[u] = 1;
    nw[num] += w[u], ++cnt[num];
    for (auto i : G[u])
        if (!is_bridge[i.Y] && !vis[i.X])
            dfs2(i.X, num);
        else if (!vis[i.X])
            nG[num].pb(tp), nG[tp].pb(num), dfs2(i.X, tp++);
}

void dfs3(int u) {
    ll mx = 0, sum = 0, flag = 0;
    vis2[u] = 1;
    dp[u][0] = nw[u];
    for (int i : nG[u])
        if(!vis2[i]) {
            dfs3(i);
            if (~dp[i][1]) {
                sum += dp[i][1], flag = 1;
                dp[u][0] += dp[i][1];
                mx = max(mx, dp[i][0] - dp[i][1]);
            }
            else
                mx = max(mx, dp[i][0]);
        }
    dp[u][0] += mx;
    if (cnt[u] > 1 || flag)
        dp[u][1] = nw[u] + sum;
    else 
        dp[u][1] = -1;
   // cerr << u << " " << dp[u][0] << " " << dp[u][1] << endl; 
}

int main() {
    IOS();
    int n, m, a, b, s;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    while (m--)
        cin >> a >> b, add_edge(a, b);
    cin >> s, solve(n);
    dfs2(s, tp++), dfs3(0);
    cout << max(dp[0][0], dp[0][1]) << "\n";
}