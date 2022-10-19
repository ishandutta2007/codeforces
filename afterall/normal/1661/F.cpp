#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;

ll cost_function(int n,int k){
    int z=n/k;
    int a=k,b=0;
    a-=n-z*k;
    b+=n-z*k;
    return 1ll * a*z*z+1ll* b*(z+1)*(z+1);
}
ll value(int n,int k){
    if (n==k) return 0;
    return cost_function(n,k)-cost_function(n,k+1);
}
ll get(ll n,ll k){
    int l=0,r=n;
    while(r-l>1){
        ll mid=(r+l)/2;
        if (value(n,mid)>k) l=mid;
        else r=mid;
    }
    return r;
}
int a[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    ll m;
    ll last=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        ll z=a[i];
        a[i]=a[i]-last;
        last=z;
    }
    cin >> m;
    ll l=0,r=(ll)1e18;
    ll jav=last-n;
    ll o=2;
    while(r-l>1){
        ll mid=(r+l)/2;
        ll cnt=0;
        ll ans=0;
        ll e=0;
        for (int i=1;i<=n;i++){
            ll x=get(a[i],mid);
            ans+=cost_function(a[i],x);
            cnt+=max((ll)0,get(a[i],mid-1)-x);
            e+=x-1;
        }
        if (ans-cnt*mid<=m) {
            if (ans>m) e+=(ans-m+mid-1)/mid;
            jav=min(jav,e);
            l=mid;
        }
        else r=mid;
    }
    cout << jav << endl;
}