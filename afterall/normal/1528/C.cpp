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
const int N=3e5+100;
vector <int> g[N];
vector <int> y[N];
ll vis[N];
ll hi[N],st[N],fn[N],ts=1;
set <pii> seg[N*4];
ll n;
void upd(ll nod,ll l,ll r,ll L,ll R,pii val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].insert(val);
        return ;
    }
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
}
void hazf(ll nod,ll l,ll r,ll L,ll R,pii val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].erase(val);
        return ;
    }
    ll mid=(r+l)/2;
    hazf(nod*2,l,mid,L,R,val);
    hazf(nod*2+1,mid,r,L,R,val);
}
pii get(ll nod,ll l,ll r,ll id){
    pii a={N,N};
    if (seg[nod].size()!=0) a=*seg[nod].begin();
    if (r-l==1) return a;
    ll mid=(r+l)/2;
    pii b;
    if (mid>id) b=get(nod*2,l,mid,id);
    else b=get(nod*2+1,mid,r,id);
    if (a.F<b.F) return a;
    return b;
}
ll fen[N];
void add(ll idx,ll val){
    for (;idx<N;idx+=idx & (-idx)) fen[idx]+=val;
}
ll getfen(ll idx){
    ll s=0;
    for (;idx;idx-= idx & (-idx)) s+=fen[idx];
    return s;
}
void dfshi(ll v,ll p){
    hi[v]=hi[p]-1;
    st[v]=ts;
    for (auto u : g[v]){
        ts++;
        dfshi(u,v);
    }
    fn[v]=ts;
}
ll jav=0;
ll ans;
void ad(ll v){
    pii par=get(1,1,n+1,st[v]);
    upd(1,1,n+1,st[v],fn[v]+1,{hi[v],v});
    add(st[v],1);
    if (getfen(fn[v])-getfen(st[v])>0) return ;
    ans++;
    vis[v]=1;
    if (par.S!=N){
        if (vis[par.S]){
            vis[par.S]=0;
            ans--;
        }
    }
   // cout << v << " par " << par.S << " " << st[v] << " " << fn[v] << " " << ans << endl;
}
void del(ll v){
    hazf(1,1,n+1,st[v],fn[v]+1,{hi[v],v});
    add(st[v],-1);
    pii par=get(1,1,n+1,st[v]);
    if (vis[v]){
        vis[v]=0;
        ans--;
    }
    else return ;
    if (par.S==N) return ;
    ll u=par.S;
    if (getfen(fn[u])-getfen(st[u])==0){
        vis[u]=1;
        ans++;
    }
  //  cout << v << " del " << par.S << " " << ans << endl;
}
void dfs(ll v,ll p){
    ad(v);
    jav=max(jav,ans);
    for (auto u : y[v]){
        dfs(u,v);
    }
    del(v);
}
int Main(){
    cin >> n;
    ans=0;
    jav=0;
    ts=1;
    for (int i=1;i<=n;i++){
        g[i].clear();
        vis[i]=0;
        y[i].clear();
        hi[i]=0;

    }
    for (int i=2;i<=n;i++){
        ll x;
        cin >> x;
        y[x].pb(i);
    }
    for (int i=2;i<=n;i++){
        ll x;
        cin >> x;
        g[x].pb(i);
    }
    dfshi(1,1);
    dfs(1,1);
    kill(jav);
    return 0;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}