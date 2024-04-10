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
const int N=2e5+100;
vector <pii> g[N];
vector <pii> dp[N];
ll up[N];
ll par[N];
ll val[N];
ll bestdown[N];
ll bestup[N];
void dfsdown(ll v,ll p,ll k){
    vector <pii> a;
    a.pb({0,v});
    par[v]=p;
    val[v]=k;
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p) continue;
        dfsdown(u,v,U.S);
        a.pb({dp[u][0].F+U.S,u});
        bestdown[v]=max(bestdown[v],bestdown[u]);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for (int i=0;i<min((ll)a.size(),(ll)4);i++) dp[v].pb(a[i]);
    ll x=0;
    for (int i=0;i<min((ll)a.size(),(ll)2);i++) x+=a[i].F;
    bestdown[v]=max(bestdown[v],x);
}
void dfsup(ll v,ll p){
    bestup[v]=max(bestup[v],max(up[p],bestup[p]));
    ll best=0;
    if (v!=1){
        vector <pii> x;
        x=dp[p];
        x.pb({up[p],-1});
        sort(x.begin(),x.end());
        reverse(x.begin(),x.end());
        ll p2=2;
        ll cnt=0;
        for (int j=0;j<x.size();j++){
            if (x[j].S==v) continue;
            if (p2>0){
                p2--;
                cnt+=x[j].F;
      //  if (i==3) cout << cnt << " cnt " << endl;
            }
        }
        bestup[v]=max(bestup[v],cnt);
    }
    ll mamad=0;
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p) continue;
        up[u]=up[v]+U.S;
        up[u]=max(up[u],best+U.S);
        best=max(best,dp[u][0].F+U.S);
        bestup[u]=max(bestup[u],mamad);
        mamad=max(mamad,bestdown[u]);
    }
    reverse(g[v].begin(),g[v].end());
    best=0;
    mamad=0;
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p) continue;
        up[u]=max(up[u],up[v]+U.S);
        up[u]=max(up[u],best+U.S);
        best=max(best,dp[u][0].F+U.S);
        bestup[u]=max(bestup[u],mamad);
        mamad=max(mamad,bestdown[u]);
    }
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p) continue;
      //  cout << u << " jrfn " << up[u] << endl;
        dfsup(u,v);
    }
}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=0;i<n-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
        ans+=2*w;
    }
    dfsdown(1,0,0);
    dfsup(1,0);
    ll mn=ans;
    for (int i=1;i<=n;i++){
        vector <pii> x=dp[i];
        x.pb({up[i],-1});
        sort(x.begin(),x.end());
        reverse(x.begin(),x.end());
        ll cnt=0;
        for (int j=0;j<min((ll)x.size(),(ll)4);j++) cnt+=x[j].F;
     //   cout << cnt << " cnt"
        mn=min(mn,ans-cnt);
        mn=min(mn,ans-2*val[i]-bestup[i]-bestdown[i]);
    }
    cout << mn << endl;
}