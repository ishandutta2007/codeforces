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

const int N=5e5+100,inf=(ll)1e9;
ll seg[N*4];
ll lazy[N*4];
ll dp[N];
ll a[N];
ll par[N];
map <int,int> mp;
void shift(ll nod){
    seg[nod*2]+=lazy[nod];
    seg[nod*2+1]+=lazy[nod];
    lazy[nod*2]+=lazy[nod];
    lazy[nod*2+1]+=lazy[nod];
    lazy[nod]=0;
}
void add(){
    seg[1]++;
    lazy[1]++;
}
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        //cout << nod << " erfn " << l << " " << r << " " << id << " " << val << endl;
        seg[nod]=max(seg[nod],val);
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    seg[nod]=max(seg[nod*2],seg[nod*2+1]);
   // cout << nod << " erfn " << l << " " << r << " " << id << " " << val << endl;
        
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return -inf;
    if (l>=L && r<=R) {
     //   cout << nod << " wleifjkerf " << l << " " << r << " " << seg[nod] << endl;;
        return seg[nod];
    }
    shift(nod);
    ll mid=(r+l)/2;
    return max(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}
void Main(){
    mp.clear();
    ll n;
    cin >> n ;
    for (int i=0;i<=(n+2)*4;i++){
        seg[i]=-inf;
        lazy[i]=0;
    }
    vector <int> b;
    b.pb(0);
    for (int i=1;i<=n;i++){
        dp[i]=0;
        cin >> a[i];
        par[i]=par[i-1]+a[i];
        b.pb(par[i]);
    }
    sort(b.begin(),b.end());
    for (int i=0;i<b.size();i++){
        mp[b[i]]=i+1;
    }
    for (int i=1;i<=n;i++) par[i]=mp[par[i]];
    upd(1,1,n+2,mp[0],0);
    ll ans=-inf;
    for (int i=1;i<=n;i++){
        add();
        if (a[i]>0) dp[i]=dp[i-1]+1;
        if (a[i]==0) dp[i]=dp[i-1];
        if (a[i]<0) dp[i]=dp[i-1]-1;
      //  cout << get(1,1,n+2,1,par[i]) << " efeirjf " << par[i] << " " << mp[0] << endl;
        dp[i]=max(dp[i],get(1,1,n+2,1,par[i]));
        upd(1,1,n+2,par[i],dp[i]);
        ans=max(ans,dp[i]);
       // cout << i << " lerf " << dp[i] << endl;
    }
    cout << dp[n] << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}