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
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=5e5+100;
const ll inf=(ll)1e16,INF=1e9;

pair <ll,ll> seg[N*4];
int kam[N*4];
void shift(ll nod){
    seg[nod*2].F=max(seg[nod*2].F,seg[nod].F);
    seg[nod*2+1].F=max(seg[nod*2+1].F,seg[nod].F);
    seg[nod*2].S=max(seg[nod*2].S,kam[nod*2]+seg[nod*2].F);
    seg[nod*2+1].S=max(seg[nod*2+1].S,kam[nod*2+1]+seg[nod*2+1].F);
    seg[nod].F=-inf;
}
void putkam(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod].S=max(seg[nod].S,kam[nod]+seg[nod].F);
        seg[nod].F=-inf;
        kam[nod]=max((ll)kam[nod],val);
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id) putkam(nod*2,l,mid,id,val);
    else putkam(nod*2+1,mid,r,id,val);
    kam[nod]=max(kam[nod*2],kam[nod*2+1]);
    seg[nod].S=max(seg[nod*2].S,seg[nod*2+1].S);
}
void upd(ll nod,ll l,ll r,ll L,ll R,ll val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].F=max(seg[nod].F,val);
        seg[nod].S=max(seg[nod].S,seg[nod].F+kam[nod]);
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
    seg[nod].S=max(seg[nod*2].S,seg[nod*2+1].S);
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return -inf;
    if (l>=L && r<=R) return seg[nod].S;
    shift(nod);
    ll mid=(r+l)/2;
    return max(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}  
ll a[N];
ll c[N];
ll d[N];
int b[3][N];
vector <pii> q[N];
void Main(){
    ll n,tq;
    cin >> n >> tq;
    for (int i=0;i<3;i++){
        for (int j=1;j<=n;j++){
            cin >> b[i][j];
            if (i==1) c[j]=c[j-1]+b[i][j];
        }
    }
    a[1]=b[0][1];
    for (int i=2;i<=n;i++){
        a[i]=a[i-1]+b[0][i]-b[1][i-1];
    }
    for (int i=n;i;i--) d[i]=d[i+1]+b[2][i];
    for (int i=1;i<=n;i++) d[i]+=c[i];
    ll ans=-inf;
    for (int i=0;i<tq;i++){
        ll l,r,val;
        cin >> l >> r >> val;
        q[l].pb({r,val});
    }
    memset(kam,-63,sizeof kam);
    for (int i=0;i<N*4;i++) seg[i]={-inf,-inf};
    for (int i=1;i<=n;i++){
        
       // cout << a[i] << " ejirfn " << d[i] << endl;
        ll z=max(a[i],get(1,1,n+1,i,n+1));
        if (i>1) z=max(z,get(1,1,n+1,i-1,n+1));
        for (auto U : q[i]){
            ll r=U.F,w=U.S;
            putkam(1,1,n+1,r,-w);
        }
        upd(1,1,n+1,i,n+1,z);
        z=get(1,1,n+1,i,n+1);
        ans=max(ans,z+d[i]);
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}