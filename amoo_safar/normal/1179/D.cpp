#include <bits/stdc++.h>
/// 500 485 462 A4
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
const int N=5e5+100,inf=(ll)1e18;
vector <pair <int,pii> > line;
ll intersect(pii y,pii x){
    if (x.F==y.F){
        if (x.F<y.F) return -inf;
        else return inf;
    }
    if (x.F>y.F) cout << 1/0;
    return (x.S-y.S)/(y.F-x.F)+(x.S>y.S && (x.S-y.S)%(y.F-x.F)>0);
}
void add(pii x){
    while(line.size()){
        pii y=line.back().S;
        ll z=intersect(y,x);
        if (z>line.back().F){
            line.pb({z,x});
            return ;
        }
        else{
            line.pop_back();
        }
    }
    line.pb({-inf,x});
}
ll get(ll x){
    auto it=lower_bound(line.begin(),line.end(),pair <int,pii>(x,{inf,inf}));
    it--;
    pii ln=it->S;
    return ln.F*x+ln.S ;
}
ll dp[N];
ll n;
vector <int> g[N];
ll ans;
ll sz[N];
void dfs(ll v,ll p){
  //  cout << ans << " wjnrfn " << endl;
    vector <pii> a;
    sz[v]=1;
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v);
        sz[v]+=sz[u];
        a.pb({sz[u],-dp[u]});
    }
    for (int i=0;i<a.size();i++){
        a[i].S+=a[i].F*(2*n-1)-a[i].F*a[i].F;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(), a.end());
    dp[v]=n*(n-1);
    for (auto u : g[v]){
        if (u==p) continue;
        dp[v]=min(dp[v],dp[u]+(sz[v]-sz[u]-1)*(sz[v]-sz[u]));
    }
    if (dp[v]==n*(n-1)) dp[v]=0;
   // cout << v << " v " << dp[v]  << " " << n  << endl;
  //  ans=min(ans,dp[v]+(n-sz[v]+1)*(n-sz[v]));
    if (a.size()==0) return ;
  //  for (auto u : a){
    //    cout << u.F << " " << u.S << endl;
    //}
    line.clear();
    add(a[0]);
    for (int i=1;i<a.size();i++){
        ll z=get(-(2*a[i].F));
      //  cout << z << " zz " << endl;
        z+=a[i].S;
        ll cnt=(n)*(n-1)-z;
        ans=min(ans,cnt);
        //cout << ans << " ans " << endl;
        add(a[i]);
    }

}
int32_t main(){
    sync;
cin >> n;
    ans=n*(n-1);
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (n==2) kill(2);
    for (int i=1;i<=min((ll)4,n);i++){
        memset(dp,0,sizeof dp);
        memset(sz,0,sizeof sz);
        dfs(i,i);
    }
    cout << (n*(n-1)-ans/2) << endl;
}