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
ll par[N][M],st[N],fn[N],ts=1;
ll hi[N];
vector <int> g[N];
void dfspar(ll v,ll p){
    par[v][0]=p;
    hi[v]=hi[p]+1;
    st[v]=ts;
    for (auto u : g[v]){
        if (u==p) continue;
        ts++;
        dfspar(u,v);
    }
    fn[v]=ts;
}
ll getpar(ll v,ll h){
    if (h<=0) return v;
    for (int i=0;i<M;i++){
        if ((h & (1<<i))) v=par[v][i];
    }
    return v;
}
ll lca(ll v,ll u){
    if (hi[u]<hi[v]) swap(u,v);
    u=getpar(u,hi[u]-hi[v]);
    if (u==v) return u;
    for (int i=M-1;i>-1;i--){
        if (par[v][i]!=par[u][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
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
vector <int> pr[N];
ll f[N];
ll val[N];
ll ra[N];
ll ans[N];
ll sz[N],dp[N];
vector <int> y[N];
void dfsd(ll v,ll p,ll gcd){
    if (val[v]%gcd==0){
        sz[v]=f[val[v]];
    }
    for (auto u : y[v]){
        if (u==p) continue;
        dfsd(u,v,gcd);
        dp[v]+=dp[u]+sz[u]*(hi[u]-hi[v])%mod;
        sz[v]+=sz[u];
        sz[v]%=mod;
        dp[v]%=mod;
    }
}
void dfsup(ll v,ll p,ll t){
    for (auto u : y[v]){
        if (u==p) continue;
        ll o=0;
        //if (val[u])
        dp[u]=dp[v]-(hi[u]-hi[v])*sz[u]%mod+((t-sz[u]+mod)%mod)*(hi[u]-hi[v])%mod;
        dp[u]+=mod;
        dp[u]%=mod;
        dfsup(u,v,t);
    }
}
int32_t main(){
    sync;
    for (int i=2;i<N;i++){
        if (pr[i].size()==0){
            for (int j=i;j<N;j+=i) pr[j].pb(i);
        }
    }
    for (int i=1;i<N;i++){
        f[i]=i;
        for (auto u : pr[i]){
            f[i]*=u-1;
            f[i]/=u;
        }
    }
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> val[i];
        ra[val[i]]=i;
    }
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfspar(1,1);
    for (int i=1;i<M;i++){
        for (int j=1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
 //   cout << "KIR" << endl;
 //   return 0;
    for (int gcd=1;gcd<=n;gcd++){
        vector <pii> rass;
        for (int j=gcd;j<=n;j+=gcd){
            rass.pb({st[ra[j]],ra[j]});
        }
        sort(rass.begin(),rass.end());
        vector <pii> ras;
        ras.pb(rass[0]);
        for (int i=1;i<rass.size();i++){
            ras.pb(rass[i]);
            ll v=lca(rass[i].S,rass[i-1].S);
            ras.pb({st[v],v});
        }
        sort(ras.begin(),ras.end());
        ras.resize(unique(ras.begin(),ras.end())-ras.begin());
        vector <int> bk;
        bk.pb(0);
        for (int i=1;i<ras.size();i++){
            while(fn[ras[bk.back()].S]<fn[ras[i].S]) bk.pop_back();
       //     cout << gcd << " " << ras[bk.back()].S << " " << ras[i].S << endl;
            y[ras[bk.back()].S].pb(ras[i].S);
            y[ras[i].S].pb(ras[bk.back()].S);
            bk.pb(i);
        }
    //    cout << gcd << " dc  " << ras.size() << endl;
        dfsd(ras[0].S,0,gcd);
        dfsup(ras[0].S,0,sz[ras[0].S]);

        for (auto U : ras){
            ll u=U.S;
            if (val[u]%gcd==0){
                ans[gcd]+=dp[u]*f[val[u]]%mod;
                ans[gcd]%=mod;
           //     cout << gcd << " " << ans[gcd] << endl;
            }
        }
        ///
        for (auto u : ras){
            sz[u.S]=0,dp[u.S]=0;
            y[u.S].clear();
        }
     //   for (int i=1;i<=3;i++) cout << dp[i] << " " << sz[i] << " " << y[i].size() << endl;
    }
    ll jav=0;
    for (int i=N-1;i;i--){
        for (int j=2*i;j<N;j+=i){
            ans[i]-=ans[j];
            ans[i]+=mod;
            ans[i]%=mod;
        }
        jav+=ans[i]*i%mod*power(f[i],mod-2)%mod;
    }
    cout << jav%mod*power(n*(n-1)%mod,mod-2)%mod << endl;

}