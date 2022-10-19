#include <bits/stdc++.h>
/// 500 485 462 A4
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=610,inf=(ll)1e9+1000;
vector <pii> g[N];
ll dis[N];
ll vis[N];
ll par[N];
ll ans[N][N];
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
    }
    for (int i=0;i<n;i++){
        memset(vis,0,sizeof vis);
        for (int j=0;j<n;j++) dis[j]=inf;
        dis[i]=0;
        for (int jj=0;jj<n;jj++){
            ll mn=-1;
            for (int k=0;k<n;k++){
                par[k]=inf;
                if (vis[k]) continue;
                if (mn==-1 || dis[k]<dis[mn]) mn=k;
            }
            ans[i][mn]=dis[mn];
            vector <pii> y=g[mn];
            for (int j=0;j<g[mn].size();j++){
                y[j].F+=dis[mn];
                y[j].F%=n;
                par[y[j].F]=y[j].S+dis[mn];
            }
            for (int j=0;j<n;j++){
                ll z=j-1+n;
                z%=n;
                par[j]=min(par[j],par[z]+1);
            }
            for (int j=0;j<n;j++){
                ll z=j-1+n;
                z%=n;
                par[j]=min(par[j],par[z]+1);
                dis[j]=min(dis[j],par[j]);
            }
            vis[mn]=1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}