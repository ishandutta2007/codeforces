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
const int N=5e5+100;
pair <pii,int> seg[N*4];
ll n;
ll a[N];
ll lazy[N*4];
void shift(ll nod,ll l,ll r){
    if (lazy[nod]==0) return ;
    ll mid=(r+l)/2;
    lazy[nod*2]=lazy[nod];
    lazy[nod*2+1]=lazy[nod];
    seg[nod*2].F={lazy[nod],lazy[nod]};
    seg[nod*2+1].F={lazy[nod],lazy[nod]};
    seg[nod*2].S=(mid-l)*lazy[nod];
    seg[nod*2+1].S=(r-mid)*lazy[nod];
    lazy[nod]=0;
}
void build(ll nod,ll l,ll r){
    if (r-l==1){
        seg[nod]={{a[l],a[l]},a[l]};
        return ;
    }
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
    seg[nod].S=seg[nod*2].S+seg[nod*2+1].S;
    seg[nod].F.F=min(seg[nod*2].F.F,seg[nod*2+1].F.F);
    seg[nod].F.S=max(seg[nod*2].F.S,seg[nod*2+1].F.S);
}
void upd(ll nod,ll l,ll r,ll L,ll R,ll val){
    if (l>=R || L>=r) return ;
    if (seg[nod].F.S<=val) return ;
    if (l>=L && r<=R && seg[nod].F.F>=val){
        lazy[nod]=val;
        seg[nod].F={val,val};
        seg[nod].S=(r-l)*val;
        return ;
    }
    shift(nod,l,r);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
    seg[nod].S=seg[nod*2].S+seg[nod*2+1].S;
    seg[nod].F.F=min(seg[nod*2].F.F,seg[nod*2+1].F.F);
    seg[nod].F.S=max(seg[nod*2].F.S,seg[nod*2+1].F.S);
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return 0;
    if (l>=L && r<=R) return seg[nod].S;
    shift(nod,l,r);
    ll mid=(r+l)/2;
    return get(nod*2,l,mid,L,R)+get(nod*2+1,mid,r,L,R);
}
ll ans[N];
int32_t main(){
    sync;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n+1);
    for (int i=1;i<=n;i++){
        upd(1,1,n+1,1,i,a[i]);
        ans[i]=get(1,1,n+1,1,i+1);
    }
    build(1,1,n+1);
    memset(lazy,0,sizeof lazy);
    for (int i=n;i;i--){
        upd(1,1,n+1,i,n+1,a[i]);
        ans[i]+=get(1,1,n+1,i,n+1);
    }
    ll mx=0;
    ll id=0;
    for (int i=1;i<=n;i++){
        mx=max(mx,ans[i]-a[i]);
        if (mx==ans[i]-a[i]) id=i;
    }
    for (int i=id+1;i<=n;i++){
        a[i]=min(a[i],a[i-1]);
    }
    for (int i=id-1;i;i--) a[i]=min(a[i],a[i+1]);
    for (int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
}