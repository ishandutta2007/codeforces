#include <bits/stdc++.h>
typedef long long int ll;
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
using namespace std;
const int N=3e5+100;
ll dis[N];
vector <int> g[N];
ll par[N];
ll vis[N];
ll mark[N];
ll o=0;
vector <int> sar;
ll dfs(ll v){
    o++;
    sar.pb(v);
    mark[v]=1;
    for (auto u : g[v]){
        if (mark[u]==0) dfs(u);
    }
}
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
    memset(dis,63,sizeof dis);
    ll tr=0;
    queue <int> q;
    dis[1]=0;
    q.push(1);
    while(q.size()){
        ll v=q.front();
        q.pop();
        tr++;
        for (auto u : g[v]){
            if (dis[u]>dis[v]+1){
                par[u]=v;
                dis[u]=dis[v]+1;
                q.push(u);
            }
        }
    }
    ll v=0;
    ll mx=1e9;
    mark[1]=1;
    for (auto u : g[1]){
        if (mark[u]) continue;
        sar.clear();
        o=0;
        dfs(u);
        for (auto z : sar){
            if (g[z].size()!=o) mark[z]=2;
        }
    }
    if (g[1].size()!=tr-1) mark[1]=2;
    for (int i=1;i<=n;i++){
        if (dis[i]<N && mark[i]==2){
            if (mx>dis[i]+4){
                mx=dis[i]+4;
                v=i;
            }
        }
    }
    if (v==0 && dis[n]>N) kill(-1);
    ll p1=0;
    if (dis[n]<mx){
        vector <int> ras;
        ll z=n;
        while(z!=1){
            ras.pb(z);
            z=par[z];
        }
        ras.pb(1);
        reverse(ras.begin(),ras.end());
        cout << ras.size()-1 << endl;
        for (auto u : ras){
            cout << u << " ";
        }
        return 0;
    }
    ll z=v;
    if (z!=1 && dis[z]!=1) cout << "KIRSHOTOR" << endl;
    vector <int> ans;
    while(z!=1){
        ans.pb(z);
        z=par[z];
    }
    ans.pb(1);
    reverse(ans.begin(),ans.end());
    for (auto u : g[v]){
        vis[u]=1;
    }
    vis[v]=1;
    for (auto u : g[v]){
        if (u==1) continue;
        for (auto y : g[u]){
            if (vis[y]==0){
                ans.pb(u);
                ans.pb(y);
                ans.pb(v);
                ans.pb(n);
                cout << ans.size()-1 << endl;
                for (auto u : ans){
                    cout << u << " ";
                }
                return 0;
            }
        }
    }
}