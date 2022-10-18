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

const int INF = 2e9;
vector<pii> G[500005];
int pa[20][500005], boss[500005], in[500005], out[500005], dft, dp[20][500005], L, tag[500005];

int finds(int u) {
    if (u == boss[u])
        return u;
    return boss[u] = finds(boss[u]);
}

void dfs(int u, int f, int tg) {
    pa[0][u] = f, in[u] = ++dft, dp[0][u] = INF, tag[u] = tg;
    for (int i = 1; i <= L; ++i)
        pa[i][u] = pa[i - 1][pa[i - 1][u]], dp[i][u] = INF;
    for (pii i : G[u])
        if (i.X != f)
            dfs(i.X, u, i.Y);
    out[u] = dft;
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

void mdfy(int u, int v, int w) {
    if (anc(u, v)) return;
    for (int i = L; i >= 0; --i)
        if (!anc(pa[i][u], v))
            dp[i][u] = min(dp[i][u], w), u = pa[i][u];
    dp[0][u] = min(dp[0][u], w);
}

struct Edge {
    int a, b, w;
    bool operator<(const Edge &x) const{
        return w < x.w;
    }
}edge[500005];

int main() {
    IOS();
    int n, k, m, a, b;
    ll ans = 0;
    cin >> n >> k >> m, L = __lg(n);
    for (int i = 1; i <= n; ++i)
        boss[i] = i;
    for (int i = 1; i <= k; ++i)
        cin >> a >> b, G[a].pb(pii(b, 1)), G[b].pb(pii(a, 1)), boss[finds(a)] = finds(b);
    for (int i = 1; i <= m; ++i)
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m; ++i)
        if (finds(edge[i].a) != finds(edge[i].b))
            boss[finds(edge[i].a)] = finds(edge[i].b), G[edge[i].a].pb(pii(edge[i].b, 0)), G[edge[i].b].pb(pii(edge[i].a, 0));
    dfs(1, 1, 0);
    for (int i = 1; i <= m; ++i)
        mdfy(edge[i].a, edge[i].b, edge[i].w), mdfy(edge[i].b, edge[i].a, edge[i].w);
    for (int i = L; i > 0; --i)
        for (int u = 1; u <= n; ++u)
            dp[i - 1][u] = min(dp[i - 1][u], dp[i][u]), dp[i - 1][pa[i - 1][u]] = min(dp[i - 1][pa[i - 1][u]], dp[i][u]);
    for (int i = 1; i <= n; ++i)
        if (tag[i]) {
            if (dp[0][i] == INF)
                return cout << "-1\n", 0;
            else
                ans += dp[0][i];
        }
    cout << ans << "\n";
}