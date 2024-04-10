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
const int N=5e5+100;
ll a[N];
ll seg[N*4];
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]=val;
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    seg[nod]=max(seg[nod*2],seg[nod*2+1]);
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return 0;
    if (l>=L && r<=R) return seg[nod];
    ll mid=(r+l)/2;
    return max(get(nod*2,l,mid,L,R),get(nod*2+1,mid,r,L,R));
}
map <int,int> mp;
vector <int> com;
ll vis[N];
int Main(){
    ll n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        a[i]-=i;
        a[i]+=N;
        com.pb(a[i]);
    }
    sort(com.begin(),com.end());
    for (int i=0;i<com.size();i++){
        mp[com[i]]=i+1;
    }
    for (int i=1;i<=n;i++) a[i]=mp[a[i]];
    vector <int> b;
    for (int i=0;i<k;i++){
        ll x;
        cin >> x;
        vis[x]=1;
        b.pb(x);
        if (i && a[b[i-1]]>a[b[i]]) kill(-1);
    }
    ll cnt=1;
    ll mx=0;
    ll po=0;
    ll id=0;
    if (b.size()==0) po=1;
    for (int i=1;i<=n;i++){
        if (a[i]<cnt) continue;
        if (b.size()>id && a[i]>a[b[id]]) continue;
        ll ans=get(1,1,N,cnt,a[i]+1);
        ans++;
        upd(1,1,N,a[i],ans);
        if (vis[i]){
            id++;
            cnt=a[i];
            if (b.size() && b.back()==i) po=1;
        }
        if (po) mx=max(mx,ans);
    }
    cout << n-mx << endl;
}
int32_t main(){
    sync;
    ll t;
    //cin >> t;
        t=1;
    while(t--){
        Main();
    }

}