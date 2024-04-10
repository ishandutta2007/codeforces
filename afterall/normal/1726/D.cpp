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
const int N=3e5+100;
vector <pii> g[N];
ll par[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
pii yal[N];
ll ans[N];
ll mark[N];
ll vis[N];
ll f=0;
void dfs(ll v,ll p){

    vis[v]=1;
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p) continue;
       // cout << v << " kgr " << u << endl;
        if (!vis[u]){
            dfs(u,v);
        }
        else if (f==0){
            f=1;
            ans[U.S]=0;
        }
    }
}
void Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        g[i].clear();
        par[i]=i;
        ans[i]=0;
        mark[i]=0;
        vis[i]=0;
        f=0;
    }
    vector <pii> ezafe;
    vector <int> s;
    for (int i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        yal[i]={u,v};
        if (getpar(u)==getpar(v)){
            ezafe.pb({u,v});
            s.pb(i);
            continue;
        }
        ans[i]=1;
        g[u].pb({v,i});
        g[v].pb({u,i});
        par[getpar(u)]=getpar(v);
    }
    if (ezafe.size()==3){
       //    cout << "mamlwedjoerjf " << endl;
        for (auto U : ezafe){
            mark[U.F]=1;
            mark[U.S]=1;
        }
        ll cnt=0;
        for (int i=1;i<=n;i++) cnt+=mark[i];
        if (cnt==3){
            g[ezafe[0].F].pb({ezafe[0].S,s[0]});
            g[ezafe[0].S].pb({ezafe[1].F,s[0]});
            reverse(g[ezafe[0].F].begin(),g[ezafe[0].F].end());
            dfs(ezafe[0].F,ezafe[0].F);
            ans[s[0]]=1;
        }
    }
    for (int i=1;i<=m;i++) cout << ans[i] ;
        cout << endl;


}
int32_t main(){
    sync;
    
    ll t=1;
    cin >> t;
    while(t--) Main();
}