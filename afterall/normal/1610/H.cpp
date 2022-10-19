#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <string>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <limits.h>
#include <tuple>
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
const int N=3e5+100,M=20;
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
        if ((h & (1<<i))) v=par[v][i];
    }
    return v;
}
ll lca(ll v,ll u){
    if (hi[u]>hi[v]) swap(u,v);
    v=getpar(v,hi[v]-hi[u]);
    if (v==u) return v;
    for (int i=M-1;i>-1;i--){
        if (par[v][i]!=par[u][i]){
            v=par[v][i];
            u=par[u][i];
        }
    }
    return par[v][0];
}
vector <int> seg[N*4];
ll mark[N];
void add(ll nod,ll l,ll r,ll L,ll R,ll val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].pb(val);
        return ;
    }
    ll mid=(r+l)/2;
    add(nod*2,l,mid,L,R,val);
    add(nod*2+1,mid,r,L,R,val);
}

void get(ll nod,ll l,ll r,ll id){
    for (auto u : seg[nod]) mark[u]=1;
    seg[nod].clear();
    if (r-l==1) return ;
    ll mid=(r+l)/2;
    if (mid>id) get(nod*2,l,mid,id);
    else get(nod*2+1,mid,r,id);
}
ll fen[N];
void addfen(ll idx,ll val){
    for (;idx<N;idx+=idx & (-idx)){
        fen[idx]+=val;
    }
}
ll getfen(ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)){
        s+=fen[idx];
    }
    return s;
}
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    for (int i=2;i<=n;i++){
        ll x;
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }
    par[1][0]=1;
    dfspar(1,1);
    vector <pair <int,pii> > b;
    vector <pii> q;
    for (int i=1;i<=m;i++){
        ll x,y;
        cin >> x >> y;
        ll f=lca(x,y);
        if (f!=x && f!=y) {
            q.pb({x,y});
            continue;
        }
        if (f==y) swap(x,y);
    
        ll z=getpar(y,hi[y]-hi[x]-1);
     //   cout << x << " " << y << "  lkerfj " << f << " " << hi[y] << " " << hi[x] << " " << par[y][0] << endl;
        if (z==y){
            cout << -1 << endl;
            return 0;
        }
        b.pb({-hi[z],{z,i}});
        add(1,1,n+1,st[z],st[y],i);
        add(1,1,n+1,fn[y]+1,fn[z]+1,i);
    }
    sort(b.begin(),b.end());
    if (b.size()==0){
        cout << 1 << endl;
        return 0;
    }
    vector <int> ans;
    for (int i=0;i<b.size();i++){
        if (mark[b[i].S.S]) continue;
        ans.pb(b[i].S.F);
        addfen(st[b[i].S.F],1);
        get(1,1,n+1,st[b[i].S.F]);
    }
    ll p1=0;
    for (auto U : q){
        ll x=U.F,y=U.S;
        if (getfen(fn[x])-getfen(st[x]-1)+getfen(fn[y])-getfen(st[y]-1)>=ans.size()) p1=1;
    }
    ll jav=ans.size()+p1;
    cout << jav << endl;
}
/*
5 5
1 1 1 4
2 4
4 3
1 5
3 5
5 1

 */