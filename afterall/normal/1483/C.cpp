#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=3e5+100;
ll seg[N*4];
ll lazy[N*4];
void shift(ll nod){
    lazy[nod*2]+=lazy[nod];
    lazy[nod*2+1]+=lazy[nod];
    seg[nod*2]+=lazy[nod];
    seg[nod*2+1]+=lazy[nod];
    lazy[nod]=0;
    return ;
}
void put(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]=val;
        return;
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id) put(nod*2,l,mid,id,val);
    else put(nod*2+1,mid,r,id,val);
    seg[nod]=max(seg[nod*2],seg[nod*2+1]);
}
void upd(ll nod,ll l,ll r,ll L,ll R,ll val){
    if (l>=R || L>=r) return ;
    if (l>=L && r<=R) {
        seg[nod]+=val;
        lazy[nod]+=val;
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R,val);
    upd(nod*2+1,mid,r,L,R,val);
    seg[nod]=max(seg[nod*2],seg[nod*2+1]);
}
ll a[N];
ll b[N];
ll dp[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=0;i<N*4;i++) seg[i]=-(ll)1e15;
    a[0]=0;
    vector <pii> agh;
    agh.pb({0,0});
    for (int i=1;i<=n;i++){
        put(1,0,n+1,i-1,dp[i-1]);
        upd(1,0,n+1,i-1,i,b[i]);
        ll last=i;
        while(agh.size() && a[agh.back().F]>a[i]){
            upd(1,0,n+1,agh.back().S-1,last-1,-b[agh.back().F]);
        //    cout << agh.back()-1 << " " << last-1 << " " << -b[agh.back()] << " " << b[i] << endl;
            upd(1,0,n+1,agh.back().S-1,last-1,b[i]);
            last=agh.back().S;
            agh.pop_back();
        }
        if (last!=agh.back().F+1) cout << 1/0 << endl;
        agh.pb({i,last});
        dp[i]=seg[1];
      //  cout << i << " " << dp[i]  << endl;
    }
    cout << dp[n] << endl;
}