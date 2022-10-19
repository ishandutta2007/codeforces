#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100;
vector <int> g[N];
ll st[N],fn[N],ts=1;
ll val[N];
ll ans[N];
ll vis[N];
ll par[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
vector <int> qq[N];
ll dfs(ll v){
    st[v]=ts;
    for (auto u : g[v]){
        ts++;
        dfs(u);
    }
    fn[v]=ts;
}
pii seg[N*4];
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]={val,l};
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    seg[nod].F=max(seg[nod*2].F,seg[nod*2+1].F);
    if (seg[nod].F==seg[nod*2].F) seg[nod]=seg[nod*2];
    else seg[nod]=seg[nod*2+1];
}
pii get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return {0,N};
    if (l>=L && r<=R){
        return seg[nod];
    }
    ll mid=(r+l)/2;
    pii a=get(nod*2,l,mid,L,R);
    pii b=get(nod*2+1,mid,r,L,R);
    if (a.F>=b.F) return a;
    else return b;
}
ll tn;
ll df(ll v){
    reverse(qq[v].begin(),qq[v].end());
    for (int i=0;i<qq[v].size();i++){
        pii a=get(1,1,tn+1,st[v],fn[v]+1);
        ans[qq[v][i]]=a.F;
        if (a.F!=0){
            upd(1,1,tn+1,a.S,0);
        }
    }
    for (auto u : g[v]){
        df(u);
    }
}
int Main(){
    memset(ans,-1,sizeof ans);
    ll n,m,tq;
    cin >> n >> m >> tq;
    for (int i=1;i<=n;i++){
        cin >> val[i];
    }
    vector <pii> yal;
    for (int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        yal.pb({u,v});
    }
    vector <pii> q;
    for (int i=0;i<tq;i++){
        ll t,v;
        cin >> t >> v;
        if (t==2){
            vis[v-1]=1;
            v--;
        }
        q.pb({t,v});
    }
    for (int i=0;i<m;i++){
        if (!vis[i]){
            q.pb({2,i});
        }
    }
    reverse(q.begin(),q.end());
    for (int i=1;i<N;i++){
        par[i]=i;
    }
 //   cout << par[1] << endl;
 //   cout << getpar(1) << endl;
  //  cout << " EjNE " << endl;
    tn=n+1;
    for (int i=0;i<q.size();i++){
     //   cout << i  << " " << q[i].F<< endl;
        if (q[i].F==1){
            ll v=q[i].S;

            v=getpar(v);
            qq[v].pb(i);
        }
        else{
            ll v=yal[q[i].S].F,u=yal[q[i].S].S;
          //  cout << u << " " << v << " " << tn << endl;
            v=getpar(v);
            u=getpar(u);
            if (u==v) continue;
            g[tn].pb(u);
            g[tn].pb(v);
            par[u]=tn;
            par[v]=tn;
            tn++;
        }
    }
    memset(vis,0,sizeof vis);
    for (int i=1;i<=n;i++){
        ll v=getpar(i);
        if (!vis[v]){
            g[tn].pb(v);
            vis[v]=1;
        }
    }
    dfs(tn);
    for (int i=1;i<=tn;i++){
        upd(1,1,tn+1,st[i],val[i]);
    }
    df(tn);
    for (int i=N-1;i>-1;i--){
        if (ans[i]!=-1){
            cout << ans[i] << endl;
        }
    }

}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--) Main();
}