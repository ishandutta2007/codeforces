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
ll par[N];
ll lf[N],rt[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
set <int> seg[N*4];
void add(ll nod,ll l,ll r,ll L,ll R,ll val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].insert(val);
        return ;
    }
    ll mid=(r+l)/2;
    add(nod*2,l,mid,L,R,val);
    add(nod*2+1,mid,r,L,R,val);
}
void del(ll nod,ll l,ll r,ll L,ll R,ll val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].erase(val);
        return ;
    }
    ll mid=(r+l)/2;
    del(nod*2,l,mid,L,R,val);
    del(nod*2+1,mid,r,L,R,val);
}
void merg(ll x,ll y){
    x=getpar(x);
    y=getpar(y);
    del(1,1,N,lf[y]+1,rt[y],y);
    del(1,1,N,lf[x]+1,rt[x],x);
    par[x]=y;
    lf[y]=min(lf[y],lf[x]);
    rt[y]=max(rt[y],rt[x]);
    add(1,1,N,lf[y]+1,rt[y],y);
}
vector <pii> a;
void get(ll nod,ll l,ll r,ll id,ll x){

    for (auto u : seg[nod]){
        ll z=u;
        a.pb({x,z});
    }
    if (r-l==1) return ;
    ll mid=(r+l)/2;
    if (mid>id) get(nod*2,l,mid,id,x);
    else get(nod*2+1,mid,r,id,x);
}
map <int,int> mp;
vector <int> com;
pii W[N];
int32_t main(){
    ll n;
    cin >> n;
    vector <pair <int,pii> > q;
    ll cnt=0;
    for (int i=0;i<n;i++){
        ll t,l,r;
        cin >> t >> l >> r;
        q.pb({t,{l,r}});
        if (t==1){
            com.pb(l);
            com.pb(r);
        }
    }
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end())-com.begin());
    for (int i=0;i<com.size();i++){
        mp[com[i]]=i+1;
    }
    for (int i=0;i<q.size();i++){
        if (q[i].F==1){
            cnt++;
            par[cnt]=cnt;
            q[i].S.F=mp[q[i].S.F];
            q[i].S.S=mp[q[i].S.S];
            ll l=q[i].S.F;
            ll r=q[i].S.S;
            W[cnt]={l,r};
            lf[cnt]=l;
            rt[cnt]=r;
            a.clear();
            get(1,1,N,l,cnt);
            get(1,1,N,r,cnt);
            add(1,1,N,lf[cnt]+1,rt[cnt],cnt);
            for (auto u : a){
                merg(u.F,u.S);
            }
        }
        else{
            ll u=q[i].S.F,v=q[i].S.S;
            u=getpar(u);
            v=getpar(v);
            if (u==v || (lf[v]<W[u].F && rt[v]>W[u].S) || (lf[v]<W[u].S && rt[v]>W[u].S)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}