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
const int N=2e5+100;
ll seg[N*4][3];
void del(ll nod,ll l,ll r){
    for (int j=0;j<3;j++) seg[nod][j]=0;
    if (r-l==1) return ;
    ll mid=(r+l)/2;
    del(nod*2,l,mid);
    del(nod*2+1,mid,r);
}
void upd(ll nod,ll l,ll r,ll id,ll val,ll K){
    if (r-l==1){
        seg[nod][K]=val;
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val,K);
    else upd(nod*2+1,mid,r,id,val,K);
    seg[nod][K]=seg[nod*2][K]+seg[nod*2+1][K];
}
ll get(ll nod,ll l,ll r,ll L,ll R,ll K){
    if (R<=L) return 0;
    if (l>=R || L>=r) return 0;
    if (l>=L && r<=R) return seg[nod][K];
    ll mid=(r+l)/2;
    return get(nod*2,l,mid,L,R,K)+get(nod*2+1,mid,r,L,R,K);
}
ll a[N];
vector <int> b[N];
ll sig[N];
ll T[N];
bool cmp(pair <pii,int> x,pair <pii,int> y){
    return x.F.S*y.S<x.S*y.F.S;
}
string ans[N];
int Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    n=m;
    reverse(a+1,a+n+1);
    del(1,1,n+1);
    vector < pair <pii,int> > v;
    for (int i=1;i<=n;i++){
        ans[i]="";
        cin >> T[i];
        sig[i]=0;
        b[i].clear();
        for (int j=0;j<T[i];j++){
            ll x;
            cin >> x;
            b[i].pb(x);
            sig[i]+=x;
        }
        v.pb({{i,sig[i]},T[i]});

    }
    sort(v.begin(),v.end(),cmp);
    reverse(v.begin(),v.end());
    v.pb({{0,0},0});
    reverse(v.begin(),v.end());

    for (int i=1;i<=n;i++){
        if (i>1 && a[i-1]*v[i].S>=v[i].F.S) upd(1,1,n+1,i,1,0);
        if (a[i]*v[i].S>=v[i].F.S) upd(1,1,n+1,i,1,1);
        if (i<n && a[i+1]*v[i].S>=v[i].F.S) upd(1,1,n+1,i,1,2);
    }
  //  cout << " get " << get(1,1,n+1,1,n+1,1) << endl;
    //for (int i=1;i<=n;i++){
      //  cout << a[i] << " erf " << v[i].F.F << endl;
    //}
    for (int i=1;i<=n;i++){
        ll id=v[i].F.F;
        for (auto u : b[id]){
            sig[id]-=u;
            T[id]--;
            ll l=0,r=n+1;
            while(r-l>1){
                ll mid=(r+l)/2;
                if (sig[id]*v[mid].S>=T[id]*v[mid].F.S) l=mid;
                else r=mid;
            }
           // cout << id << " efn " << u << " ief " << l << endl;
            ll jav=0;
            if (l>i){
                if (a[l]*T[id]>=sig[id]) jav++;
                jav+=get(1,1,n+1,i+1,l+1,0);
                jav+=get(1,1,n+1,l+1,n+1,1);
                jav+=get(1,1,n+1,1,i,1);
            }
            else if (l<i){
                l++;
                if (a[l]*T[id]>=sig[id]) jav++;
                jav+=get(1,1,n+1,l,i,2);
                jav+=get(1,1,n+1,i+1,n+1,1);
                jav+=get(1,1,n+1,1,l,1);
            }
            else if (l==i){
                if (a[l]*T[id]>=sig[id]) jav++;
                jav+=get(1,1,n+1,1,l,1);
                jav+=get(1,1,n+1,l+1,n+1,1);
            }
            if (jav==n) ans[id]+='1';
            else ans[id]+='0';
            sig[id]+=u;
            T[id]++;
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] ;
    }
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}
/*
1
4 2
9 12 12 6
2
4 5
3
111 11 11
*/