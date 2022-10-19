#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const ll N=3e5+100,inf=(ll)4e18+10;
ll seg[N*4];
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]=min(seg[nod],val);
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    seg[nod]=min(seg[nod*2],seg[nod*2+1]);
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (L>=r || l>=R){
        return inf;
    }
    if (l>=L && r<=R){
        return seg[nod];
    }
    ll mid=(r+l)/2;
    return min(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}
vector <pii> q;
ll x[N];
ll w[N];
ll best[N];
vector <pii> of[N];
ll ans[N];
ll n,tq;
void Main(){
    memset(seg,63,sizeof seg);
    for (int i=0;i<=n;i++) of[i].clear();
    for (int i=0;i<tq;i++){
        of[q[i].S].pb({q[i].F,i+1});
    }
    vector <int> agh;
    w[0]=-inf;
    agh.pb(0);
    for (int i=1;i<=n;i++){
        while(agh.size() && w[agh.back()]>w[i]) agh.pop_back();
        best[i]=agh.back();
        agh.pb(i);
    }
    upd(1,1,n+1,n,inf);
    for (int i=2;i<=n;i++){
        upd(1,1,n+1,i-1,(x[i]-x[i-1])*(w[i]+w[i-1]));
    }
    for (int i=2;i<=n;i++){
        if (best[i]!=0){
            ll z=(x[i]-x[best[i]])*(w[i]+w[best[i]]);
        //if (z<(x[i]-x[i-1])*(w[i]+w[i-1])){
          //  cout << i << " mamad " << best[i] << " " << z << endl;
            upd(1,1,n+1,best[i],z);
        }
        for (auto U : of[i]){
            ll id=U.S;
            ll l=U.F;
            ll z=get(1,1,n+1,l,i);
            ans[id]=min(ans[id],z);
        }
    }
}
int32_t main(){
    sync;
    cin >> n >> tq;
    for (int i=0;i<=tq;i++) ans[i]=inf;
    for (int i=1;i<=n;i++){
        cin >> x[i] >> w[i];
    }
    for (int i=0;i<tq;i++){
        ll l,r;
        cin >> l >> r;
        q.pb({l,r});
    }
    Main();
    
    reverse(x+1,x+n+1);
    for (int i=1;i<=n;i++) x[i]*=-1;
    reverse(w+1,w+n+1);
    for (int i=0;i<tq;i++){
        q[i].F=n-q[i].F+1;
        q[i].S=n-q[i].S+1;
        swap(q[i].F,q[i].S);
    }
    Main();
    for (int i=1;i<=tq;i++){
        cout << ans[i] << endl;
    }
}