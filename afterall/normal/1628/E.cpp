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

const int N=3e5+100,M=20;
pii seg[N*4];
ll par[N][M];
ll best[N][M];
vector <pii> g[N];
ll hi[N];
void dfs_begin(ll v,ll p){
    par[v][0]=p;
    hi[v]=hi[p]+1;
    for (auto U : g[v]){
        ll u=U.F;
        if (u==p) continue;
        best[u][0]=U.S;
        dfs_begin(u,v);
    }
}
pii get(ll v,ll h){
    if (h==0){
        return {v,0};
    }
    ll ans=0;
    for (int i=0;i<M;i++){
        if ((h & (1<<i))){
            ans=max(ans,best[v][i]);
            v=par[v][i];
        }
    }
    return {v,ans};
}
pii lca(ll v,ll u){
    if (v==0 || u==0){
        return {max(u,v),0};
    }
    if (hi[v]<hi[u]) swap(u,v);
    pii ans=get(v,hi[v]-hi[u]);
    v=ans.F;
    if (v==u) return ans;
    for (int i=M-1;i>-1;i--){
        if (par[v][i]!=par[u][i]){
            ans.S=max(ans.S,max(best[v][i],best[u][i]));
            v=par[v][i];
            u=par[u][i];
        }
    }
    ans.S=max(ans.S,max(best[v][0],best[u][0]));
    ans.F=par[v][0];
    return ans;
}
ll lazy[N*4];
pii seg_build[N*4];
void build(ll nod,ll l,ll r){
    if (r-l==1){
        seg_build[nod]={l,0};
        return ;
    }
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
    seg_build[nod]=lca(seg_build[nod*2].F,seg_build[nod*2+1].F);
    seg_build[nod].S=max(seg_build[nod].S,max(seg_build[nod*2].S,seg_build[nod*2+1].S));

}
void shift(ll nod){
    if (lazy[nod]==0) return ;
    /// lazy[nod]=-1 0 kon
    lazy[nod*2]=lazy[nod];
    lazy[nod*2+1]=lazy[nod];
    if (lazy[nod]==-1){
        seg[nod*2]={0,0};
        seg[nod*2+1]={0,0};
        lazy[nod]=0;
        return ;
    }
    seg[nod*2+1]=seg_build[nod*2+1];
    seg[nod*2]=seg_build[nod*2];
    lazy[nod]=0;
}
void add(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod]=seg_build[nod];
        lazy[nod]=1;
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    add(nod*2,l,mid,L,R);
    add(nod*2+1,mid,r,L,R);
    seg[nod]=lca(seg[nod*2].F,seg[nod*2+1].F);
    seg[nod].S=max(seg[nod].S,max(seg[nod*2].S,seg[nod*2+1].S));
    //cout << nod << " " << l << " " << r << " " << seg[nod].F << " " << seg[nod].S << endl;
}
void del(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod]={0,0};
        lazy[nod]=-1;
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    del(nod*2,l,mid,L,R);
    del(nod*2+1,mid,r,L,R);
    seg[nod]=lca(seg[nod*2].F,seg[nod*2+1].F);
    seg[nod].S=max(seg[nod].S,max(seg[nod*2].S,seg[nod*2+1].S));
}
bool is(ll nod,ll l,ll r,ll id){
    if (r-l==1){
        return (seg[nod].F!=0);
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id) return is(nod*2,l,mid,id);
    else return is(nod*2+1,mid,r,id);
}
int32_t main(){
    sync;
    ll n,q;
    cin >> n >> q;
    for (int i=0;i<n-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dfs_begin(1,1);
    for (int i=1;i<M;i++){
        for (int j=1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
            best[j][i]=max(best[j][i-1],best[par[j][i-1]][i-1]);
        }
    }
    build(1,1,n+1);
    while(q--){
        ll t;
        cin >> t;
        if (t==1){
            ll l,r;
            cin >> l >> r;
            add(1,1,n+1,l,r+1);
        }
        if (t==2){
            ll l,r;
            cin >> l >> r;
            del(1,1,n+1,l,r+1);
        }
        if (t==3){
            ll x;
            cin >> x;
            ll z=is(1,1,n+1,x);
           // cout << z << " weoif " << endl;
            add(1,1,n+1,x,x+1);
            if (seg[1].S==0) cout << -1 << endl;
            else cout << seg[1].S << endl;
            if (!z) del(1,1,n+1,x,x+1);
        }
    }
   // cout << lca(5,4).F << endl;
}
/*
4 25
1 2 1
1 3 2
1 4 3
3 1
3 2
3 3
3 4
1 1 1
3 1
3 2
3 3
3 4
1 2 2
2 1 1
3 1
3 2
3 3
3 4
1 1 1
3 1
3 2
3 3
3 4
1 3 3
2 1 2
3 1
3 2
3 3




*/