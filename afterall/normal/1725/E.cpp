#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100,M=20;
vector <int> g[N];
ll par[N][M];
ll hi[N];
ll st[N],fn[N],ts=1;
void dfspar(ll v,ll p){
    par[v][0]=p;
    hi[v]=hi[p]+1;
    st[v]=ts;
    for (int i=1;i<M;i++){
        par[v][i]=par[par[v][i-1]][i-1];
    }
    for (auto u : g[v]){
        if (u==p) continue;
        ts++;
        dfspar(u,v);
    }
    fn[v]=ts;
}
ll getpar(ll v,ll h){
    for (int i=0;i<M;i++){
        if (h & (1<<i)) v=par[v][i];
    }
    return v;
}
ll lca(ll v,ll u){
    if (hi[v]<hi[u]) swap(u,v);
    v=getpar(v,hi[v]-hi[u]);
    if (u==v) return v;
    for (int i=M-1;i>-1;i--){
        if (par[v][i]!=par[u][i]){
            v=par[v][i];
            u=par[u][i];
        }
    }
    return par[v][0];
}
ll a[N];
vector <int> p[N];
vector <int> mol[N];
ll ans=0;
vector <int> y[N];
ll sz[N];
ll mod=998244353;
ll mark[N];
ll hal(ll x,ll y){
    return y*(y-1)/2%mod*x%mod+x*(x-1)/2%mod*y%mod;
}
void dfs(ll v,ll p,ll kol){
    sz[v]=mark[v];
    for (auto u : y[v]){
        dfs(u,v,kol);
        sz[v]+=sz[u];
    }
    ans+=(hi[v]-hi[p])*hal(sz[v],kol-sz[v])%mod;
    ans%=mod;

}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfspar(1,1);
    for (int i=2;i<N;i++){
        if (p[i].size()) continue;
        for (int j=i;j<N;j+=i){
            p[j].pb(i);
        }
    }
    for (int i=1;i<=n;i++){
        for (auto u : p[a[i]]){
            mol[u].pb(i);
        }
    }
    for (int i=2;i<N;i++){
        if (mol[i].size()==0) continue;
        vector <pii> ras;
        for (auto u : mol[i]){
            ras.pb({st[u],u});
        }
        sort(ras.begin(),ras.end());
        int szz=ras.size();
        for (int i=0;i<szz;i++) mark[ras[i].S]=1;
        for (int i=1;i<szz;i++){
            ll v=lca(ras[i-1].S,ras[i].S);
            ras.pb({st[v],v});
        }
        sort(ras.begin(),ras.end());
        ras.resize(unique(ras.begin(),ras.end())-ras.begin());
        /*
        cout << i << " i " << ras.size() << endl;
        for (auto u : ras){
            cout << u.S << ' ' ;
        }
        cout << endl;
        */
        vector <int> agh;
        agh.pb(0);
        for (int i=1;i<ras.size();i++){
            while(fn[ras[agh.back()].S]<fn[ras[i].S]) agh.pop_back();
            y[ras[agh.back()].S].pb(ras[i].S);
            agh.pb(i);
        }
        dfs(ras[0].S,ras[0].S,szz);
        for (auto U : ras) y[U.S].clear(),sz[U.S]=0,mark[U.S]=0;
    }
    cout << ans << endl;

}