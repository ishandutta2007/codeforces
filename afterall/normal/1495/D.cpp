#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<long double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=4e2+10;
ll dis[N][N];
ll par[N][N];
bool vis[N][N];
ll mod=998244353;
vector <int> g[N];
void bfs(ll vv){
    memset(dis[vv],63,sizeof dis[vv]);
    queue <int> q;
    q.push(vv);
    dis[vv][vv]=0;
    while(q.size()){
        ll v=q.front();
        q.pop();
        for (auto u : g[v]){
            if (dis[vv][u]==dis[vv][v]+1) vis[vv][u]=1;
            if (dis[vv][u]>dis[vv][v]+1){
                dis[vv][u]=dis[vv][v]+1;
                q.push(u);
                if (vis[vv][v]) vis[vv][u]=1;
                par[vv][u]=v;
            }
        }
    }
}
ll ans[N][N];
bool mark[N];
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i=1;i<=n;i++) bfs(i);
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (vis[i][j]) continue;
            ll u=j;
            memset(mark,0,sizeof mark);
            while(u!=0){
                mark[u]=1;
                u=par[i][u];
            }
            ans[i][j]=1;
            for (int v=1;v<=n;v++){
                if (mark[v]) continue;
                ll t=0;
                for (auto u : g[v]){
                    if (dis[i][u]==dis[i][v]-1 && dis[j][u]==dis[j][v]-1){
                        t++;

                    }
                }
                ans[i][j]*=t;
                ans[i][j]%=mod;
            }
            ans[j][i]=ans[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}