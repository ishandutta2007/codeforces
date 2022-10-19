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
const int N=1e5+100,inf=(ll)1e15;
set <int> s;
vector <int> bad;
ll nxt(ll x){
    ll y=lower_bound(bad.begin(),bad.end(),x)-bad.begin();
    return bad[y];
}
pii seg[N*4];
ll lazy[N*4];
    ll n;
void shift(ll nod){
    lazy[nod*2]+=lazy[nod];
    lazy[nod*2+1]+=lazy[nod];
    seg[nod*2].F+=lazy[nod];
    seg[nod*2+1].F+=lazy[nod];
    lazy[nod]=0;
}
void build(ll nod,ll l,ll r){
    seg[nod]={0,l};
    if (r-l==1) return ;
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
}
void put(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]={val,l};
        return;
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id) put(nod*2,l,mid,id,val);
    else put(nod*2+1,mid,r,id,val);
    seg[nod]=seg[nod*2];
    if (seg[nod].F>seg[nod*2+1].F) seg[nod]=seg[nod*2+1];
}
void upd(ll nod,ll l,ll r,ll L,ll R,ll val){
   // cout << nod << " " << l << " " << r << " " << val << endl;
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R){
        seg[nod].F+=val;
        lazy[nod]+=val;
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
    seg[nod]=seg[nod*2];
    if (seg[nod].F>seg[nod*2+1].F) seg[nod]=seg[nod*2+1];
}
pii getmax(ll nod,ll l,ll r,ll L,ll R){
   // cout << nod << " " << l << " " << r << endl;
    if (l>=R || L>=r){
        return {inf,0};
    }
    if (l>=L && r<=R){
        return seg[nod];
    }
    ll mid=(r+l)/2;
    shift(nod);
    pii a=getmax(nod*2,l,mid,L,R);
    pii b=getmax(nod*2+1,mid,r,L,R);
    if (a.F<=b.F) return a;
    else return b;
}
ll a[N];
void solve(ll l,ll r,ll val){
    while(true){
       //     cout << "KIR" << endl;
        pii b=getmax(1,1,n+1,l,r);
        if (b.F>0) break;
        ll p1=0;
        if (b.F==0) p1=1;
        ll i=b.S;
        a[i]=a[i]-b.F;
        if (nxt(a[i])==a[i]) p1=1;
        ll z=nxt(a[i]+1);
        put(1,1,n+1,i,z-a[i]);
      //  cout << i << " " << b.F << " " << a[i] << " " << z-a[i] << endl;
        a[i]=z;
        if (p1){
            upd(1,1,n+1,l,r,-val);
        }
    }
}
ll what(ll x){
    ll y=*s.lower_bound(x);
    pii e=getmax(1,1,n+1,y,y+1);
    return a[y]-e.F;
}
int32_t main(){
    sync;
    bad.pb(1);
    while((ll)bad.back()*(ll)42<inf){
        bad.pb((ll)bad.back()*(ll)42);
    }
    cin >> n;
    build(1,1,n+1);
    ll q;
    cin >> q;
    for (int i=1;i<=n;i++){
        s.insert(i);
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
        ll x=nxt(a[i]);
        put(1,1,n+1,i,x-a[i]);
        //cout << x-a[i] << endl;
        a[i]=x;
    }
    while(q--){
        ll t;
        cin >> t;
        if (t==1){
            ll x;
            cin >> x;
            cout << what(x) << endl;
        }
        if (t==2){
            ll l,r,val;
            cin >> l >> r >> val;
            if (l!=1){
                ll z=what(l-1);
                a[l-1]=nxt(z);
                put(1,1,n+1,l-1,a[l-1]-z);
                s.insert(l-1);
            }
            while(*s.lower_bound(l)<r){
                ll x=*s.lower_bound(l);
                s.erase(x);
                put(1,1,n+1,x,inf);
            }
            a[r]=nxt(val);
            put(1,1,n+1,r,a[r]-val);
            s.insert(r);
        }
        if (t==3){
            ll l,r,val;
            cin >> l >> r >> val;
            if (l!=1){
                ll z=what(l-1);
                a[l-1]=nxt(z);
                put(1,1,n+1,l-1,a[l-1]-z);
                s.insert(l-1);
            }
            ll z=what(r);
            a[r]=nxt(z);
            put(1,1,n+1,r,a[r]-z);
            s.insert(r);
            upd(1,1,n+1,l,r+1,-val);
            solve(l,r+1,val);
         //   cout << "ikki" << endl;
        }
    }
}