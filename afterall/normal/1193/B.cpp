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
const int N=1e5+100;
ll seg[N*4],lazy[N*4],last[N*4];
ll point=0;
void apply(ll nod,ll k){
    if (last[nod]<point){
        seg[nod]=0;
        lazy[nod]=0;
        last[nod]=point;
    }
    seg[nod]+=k;
    lazy[nod]+=k;
    return ;
}
void shift(ll nod){
    apply(nod,0);
    apply(nod*2,lazy[nod]);
    apply(nod*2+1,lazy[nod]);
    lazy[nod]=0;
}
void put(ll nod,ll l,ll r,ll id,ll val){
    apply(nod,0);
    if (r-l==1){
        seg[nod]=max(seg[nod],val);
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id) put(nod*2,l,mid,id,val);
    else put(nod*2+1,mid,r,id,val);
    seg[nod]=max(seg[nod*2],seg[nod*2+1]);
}
void upd(ll nod,ll l,ll r,ll L,ll R,ll val){
    apply(nod,0);
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod]+=val;
        lazy[nod]+=val;
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
    seg[nod]=max(seg[nod*2],seg[nod*2+1]);
    return ;
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    apply(nod,0);
    if (l>=R || L>=r) return 0;
    if (l>=L && r<=R) return seg[nod];
    shift(nod);
    ll mid=(r+l)/2;
    return max(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}
ll sz[N];
vector <int> g[N];
void dfssz(ll v,ll p){
    sz[v]=1;
    for (auto u : g[v]){
        if (u==p) continue;
        dfssz(u,v);
        sz[v]+=sz[u];
    }
}
ll W[N],a[N];
vector <pii> c;
ll sdf(ll v,ll p){
    ll z=get(1,1,N,1,a[v]+1);
    c.pb({a[v],z});
    for (auto u : g[v]){
        sdf(u,v);
    }
}
ll dfs(ll v,ll p){
    ll big=-1;
    for (auto u : g[v]){
        if (big==-1 || sz[big]<sz[u]) big=u;
    }
    vector <vector <pii> > b;
    for (auto u : g[v]){
        if (u!=big){
            dfs(u,v);
            c.clear();
            sdf(u,v);
            sort(c.begin(),c.end());
            c.pb({N,0});
            b.pb(c);
            point++;
        }
    }
    if (big==-1){
        if (W[v])
        upd(1,1,N,a[v],N,W[v]);
    }
    else{
        dfs(big,v);
        for (auto u : b){
            for (int i=u.size()-1;i>-1;i--){
                if (u[i].S){
            //        if (v==1){
              //          cout << u[i].F << " " << u[i+1].F << " " << u[i].S << " " << get(1,1,N,1,a[5]+1) << endl;
                //    }
                    upd(1,1,N,u[i].F,u[i+1].F,u[i].S);
                    ll z=get(1,1,N,1,u[i].F);
                  //  if (v==1){
                    //    cout << u[i].F << " jnfr " << z << endl;
                    //}
                    put(1,1,N,u[i].F,z+u[i].S);
                }
            }
        }
        if (W[v]){
        ll z=get(1,1,N,1,a[v]+1);
        put(1,1,N,a[v],z+W[v]);
        }
    }
   // cout << v << " " << get(1,1,N,1,a[v]+1) << endl;
}
int32_t main(){
    ll n,m,k;
    cin >> n >> m >> k;
    for (int i=2;i<=n;i++){
        ll p;
        cin >> p;
        g[p].pb(i);
    }
    for (int i=1;i<=m;i++){
        ll v,d,w;
        cin >> v >> d >> w;
        a[v]=d;
        W[v]=w;

    }
    dfssz(1,1);
    dfs(1,1);
    cout << seg[1] << endl;
}
/*
8 8 10
1
2
2
1
5
5
6
1 10 1
2 9 1
3 8 1
4 7 1
5 6 1
6 5 1
7 5 1
8 4 1
*/