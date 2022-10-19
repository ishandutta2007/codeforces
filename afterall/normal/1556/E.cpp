#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100,inf=(ll)1e18;
ll a[N];
pii seg[N*4];
void build(ll nod,ll l,ll r){
    if (r-l==1){
        seg[nod]={a[l],a[l]};
        return ;
    }
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
    seg[nod].F=min(seg[nod*2].F,seg[nod*2+1].F);
    seg[nod].S=max(seg[nod*2].S,seg[nod*2+1].S);
}
ll getmin(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return inf;
    if (l>=L && r<=R) return seg[nod].F;
    ll mid=(r+l)/2;
    return min( getmin(nod*2,l,mid,L,R),getmin(nod*2+1,mid,r,L,R) );
}
ll getmax(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return -inf;
    if (l>=L && r<=R) return seg[nod].S;
    ll mid=(r+l)/2;
    return max( getmax(nod*2,l,mid,L,R),getmax(nod*2+1,mid,r,L,R) );
}
int Main(){
    ll n,q;
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a[i]=-a[i]+x;
    }
    for (int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    build(1,1,n+1);
    while(q--){
        ll l,r;
        cin >> l >> r;
        if (a[r]-a[l-1]!=0){
            cout << -1 << endl;
            continue;
        }
        ll z=getmin(1,1,n+1,l,r+1);
        if (z<a[l-1]){
            cout << -1 << endl;
            continue;
        }
        ll x=getmax(1,1,n+1,l,r+1);
        cout << x-a[l-1] << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}