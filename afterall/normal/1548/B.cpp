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
const int N=2e5+100;
ll seg[N*4];
ll a[N];
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]=val;
        return ;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,l,mid,id,val);
    else upd(nod*2+1,mid,r,id,val);
    seg[nod]=__gcd(seg[nod*2],seg[nod*2+1]);
}
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++){
        a[i]=abs(a[i+1]-a[i]);
    }
    ll ans=1;
    ll l=0;
    for (int i=1;i<n;i++){
        upd(1,1,n,i,a[i]);
        while(seg[1]==1){
            l++;
            upd(1,1,n,l,0);
        }
        ans=max(ans,i-l+1);
    }


    for (int i=l+1;i<n;i++){
        upd(1,1,n,i,0);
    }
    cout << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}