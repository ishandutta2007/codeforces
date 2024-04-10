#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll seg[N*4];
ll st[N],fn[N];
ll a[N];
void upd(ll nod,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod]=max(seg[nod],val);
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
int32_t main(){
    sync;
    ll n;
    cin >> n ;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (st[a[i]]==0) st[a[i]]=i;
        fn[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        if (st[i]!=0){
           // cout << st[i] << " st " << fn[i] << endl;
            upd(1,1,n+1,st[i],fn[i]);
        }
    }
    ll ans=0;

    for (int i=1;i<=n;i++){
        ll z=get(1,1,n+1,1,i+1);
        //cout << i << " " << z << endl;
        if (z==i){
            continue;
        }
        ans+=z-1-i;
        i=z-1;
    }
    cout << ans << endl;
}