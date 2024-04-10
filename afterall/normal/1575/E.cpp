#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100,inf=(ll)1e12;
vector <pii> g[N];
ll a[N];
ll sz[N];
ll vis[N];
ll n,k;
ll mod=1e9+7;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
void dfssz(ll v,ll p){
    sz[v]=1;
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p || vis[u]) continue;
        dfssz(u,v);
        sz[v]+=sz[u];
    }
}
ll findcen(ll v,ll p,ll tras){
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p || vis[u]) continue;
        if (sz[u]>=(tras+1)/2) return findcen(u,v,tras);
    }
    return v;
}
ll ans=0;
vector <pii> b[2];
void dfs(ll v,ll p,ll t,ll e,ll sig,ll FF){
    sig+=a[v];
    sig%=mod;
    b[FF].pb({t,sig});
    for (auto U : g[v]){
        ll u=U.F;
        if (vis[u] || u==p) continue;
        if (U.S!=e){
            dfs(u,v,t+1,U.S,sig,FF);
        }
        else dfs(u,v,t,e,sig,FF);
    }
}
ll parw[N];
ll parb[N];
ll shombol(ll cen,bool pp){
    ll jav=0;
    sort(b[0].begin(),b[0].end());
    sort(b[1].begin(),b[1].end());
    if (b[0].size()) parw[0]=b[0][0].S;
    if (b[1].size()) parb[0]=b[1][0].S;
    /*
    for (auto u : b[0]){
        cout << u.F << " " << u.S << "   ";
    }
    cout << endl;
    for (auto u : b[1]){
        cout << u.F << " " << u.S << "      ";
    }
    cout << endl;
    */
    for (int i=1;i<b[0].size();i++){
        parw[i]=parw[i-1]+b[0][i].S;
        parw[i]%=mod;
    }
    for (int i=1;i<b[1].size();i++){
        parb[i]=parb[i-1]+b[1][i].S;
        parb[i]%=mod;
    }
    for (auto u : b[0]){
        if (u.F<=k) jav+=2*(u.S+a[cen])*pp%mod;
        ll z=upper_bound(b[0].begin(),b[0].end(),pii({k-u.F,inf}))-b[0].begin();
        z--;
        if (z>=0){
            jav+=(u.S+a[cen])*(z+1)%mod+parw[z];
        }
        z=upper_bound(b[1].begin(),b[1].end(),pii({k-u.F-1,inf}))-b[1].begin();
        z--;
        if (z>=0){
            jav+=(u.S+a[cen])*(z+1)%mod+parb[z];
        }
        jav%=mod;
    }
    for (auto u : b[1]){
        if (u.F<=k) jav+=2*(u.S+a[cen])*pp%mod;
        ll z=upper_bound(b[1].begin(),b[1].end(),pii({k-u.F,inf}))-b[1].begin();
        z--;
        if (z>=0){
            jav+=(u.S+a[cen])*(z+1)%mod+parb[z];
        }
        z=upper_bound(b[0].begin(),b[0].end(),pii({k-u.F-1,inf}))-b[0].begin();
        z--;
        if (z>=0){
            jav+=(u.S+a[cen])*(z+1)%mod+parw[z];
        }
        jav%=mod;
    }
   // cout << " jav " << jav << endl;
    return jav;
}
ll W=0;
void dd(ll v,ll p,ll m,ll sig,ll t,ll e){
    sig+=a[v];
    if (t<=k && v>=m) W+=sig;
    sig%=mod;
    W%=mod;
    for (auto U: g[v]){
        ll u=U.F;
        if (u==p) continue;
        dd(u,v,m,sig,t+(e!=U.S && e!=-1),U.S);
    }
}
void solve(){
    queue <int> q;
    q.push(1);
    while(q.size()){
        ll v=q.front();
        q.pop();
        dfssz(v,v);
        ll cen=findcen(v,v,sz[v]);
     //   cout << cen << endl;
        b[0].clear();
        b[1].clear();
        for (auto U : g[cen]){
            ll u=U.F;
            if (vis[u]) continue;
            dfs(u,cen,0,U.S,0,U.S);
        }

        ans+=shombol(cen,1);
     //   cout << "ans " << ans << endl;
        for (auto U : g[cen]){
            ll u=U.F;
            if (vis[u]) continue;
            b[0].clear();
            b[1].clear();
            dfs(u,cen,0,U.S,0,U.S);
            ans-=shombol(cen,0);
        }
        ans%=mod;
        ans+=mod;
        ans%=mod;
        vis[cen]=1;
        for (auto U : g[cen]){
            ll u=U.F;
            if (vis[u]==0) q.push(u);
        }
    }
}
int32_t main(){
    sync;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        ans+=2*a[i];
        ans%=mod;
    }
    for (int i=0;i<n-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    solve();
    cout << ans*power(2,mod-2)%mod << endl;
    /*
    W=0;
    for (int i=1;i<=n;i++){
        dd(i,i,i,0,0,-1);
    }
    cout << W << endl;
    */
}
/*
4 1
0 0 0 1
1 2 1
1 4 0
2 3 1
*/