#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
ll seg[N*4];
ll lazy[N*4];
ll n;
void shift(ll nod,ll l,ll r){
    if (lazy[nod]==1){
        lazy[nod*2] ^= 1;
        lazy[nod*2+1] ^= 1;
        ll mid=(r+l)/2;
        seg[nod*2]=mid-l-seg[nod*2];
        seg[nod*2+1]=r-mid-seg[nod*2+1];
    }
    lazy[nod]=0;
}
void upd(ll nod,ll l,ll r,ll L,ll R){
   // cout << nod << " nod " << l << " " << r << endl;
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R) {
        seg[nod]=r-l-seg[nod];
        lazy[nod] ^= 1;
        return ;
    }
    shift(nod,l,r);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R);
    upd(nod*2+1,mid,r,L,R);
    seg[nod]=seg[nod*2]+seg[nod*2+1];
}
ll get (ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return 0;
    if (l>=L && r<=R) return seg[nod];
    ll mid=(r+l)/2;
    shift(nod,l,r);
    return get(nod*2,l,mid,L,R)+get(nod*2+1,mid,r,L,R);
}
ll getfirst0(ll nod,ll l,ll r,ll x){
    if (r<=x) return N;
    if (seg[nod]==r-l) return N;
    ll mid=(r+l)/2;
    if (l<x){
        shift(nod,l,r);
        return min(getfirst0(nod*2,l,mid,x),getfirst0(nod*2+1,mid,r,x));
    }
    if (r-l==1) return l;
    shift(nod,l,r);
    if (seg[nod*2]!=mid-l) return getfirst0(nod*2,l,mid,x);
    else return getfirst0(nod*2+1,mid,r,x);

}
ll getfirst1(ll nod,ll l,ll r,ll x){
    if (r<=x) return N;
    if (seg[nod]==0) return N;
    ll mid=(r+l)/2;
    if (l<x){
        shift(nod,l,r);
        return min(getfirst1(nod*2,l,mid,x),getfirst1(nod*2+1,mid,r,x));
    }
    if (r-l==1) return l;
    shift(nod,l,r);
    if (seg[nod*2]!=0) return getfirst1(nod*2,l,mid,x);
    else return getfirst1(nod*2+1,mid,r,x);
}
void add(ll x){
    ll z=getfirst0(1,1,N,x);
   // cout << x << " " << z << endl;
    upd(1,1,N,x,z+1);
}
void del(ll x){
    ll z=getfirst1(1,1,N,x);
    upd(1,1,N,x,z+1);
  
}
ll getanswer(){
    ll l=1,r=N;
    while(r-l>1){
        ll mid=(r+l)/2;
        if (get(1,1,N,mid,N)>0) l=mid;
        else r=mid;
    }
    return l;
}
ll a[N];
int32_t main(){
    sync;
    ll t=1;
    ll q;
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        add(a[i]);
    }
   
    for (int i=0;i<q;i++){
        ll x,val;
        cin >> x >> val;
        del(a[x]);
        a[x]=val;
        add(a[x]);
        cout << getanswer() << endl;
     
    }
}