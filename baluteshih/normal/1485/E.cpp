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

vector<int> G[200005];
int a[200005], pa[200005], dis[200005], mi[200005], mx[200005];
ll dp[200005], mxdp[200005], mxdp2[200005];

void update(int u, int p) {
    pa[u] = p;
    dis[u] = dis[p] + 1;
    mi[dis[u]] = min(mi[dis[u]], a[u]);
    mx[dis[u]] = max(mx[dis[u]], a[u]);
    if (p != 1) {
        dp[u] = dp[p] + max(abs(a[p] - mi[dis[p]]), abs(a[p] - mx[dis[p]]));
        dp[u] = max({dp[u], mxdp[dis[p]] - a[p], mxdp2[dis[p]] + a[p]});
        mxdp[dis[u]] = max(mxdp[dis[u]], dp[u] + a[u]);
        mxdp2[dis[u]] = max(mxdp2[dis[u]], dp[u] - a[u]);
    }
}

int main() {
    IOS();
    const int INF = 1e9;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        ll ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            G[i].clear();
        for (int i = 2; i <= n; ++i)
            cin >> x, G[i].pb(x), G[x].pb(i), dp[i] = 0;
        for (int i = 2; i <= n; ++i)
            cin >> a[i], mi[i] = INF, mxdp[i] = mxdp2[i] = mx[i] = -INF;
        queue<int> q;
        dis[1] = 1;
        for (int i : G[1])
            q.push(i),  update(i, 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : G[u])
                if (i != pa[u])
                    update(i, u), q.push(i);
        }
        for (int i = 2; i <= n; ++i)
            ans = max(ans, dp[i] + max(abs(a[i] - mi[dis[i]]), abs(a[i] - mx[dis[i]])));
        cout << ans << "\n";
    }
}