#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], k, x;
um ind;

ll check(ll l, ll r){
    return r/x - (l-1)/x;
}

ll bsmax(ll x){
    ll l = 0;
    ll r = x;
    ll ans = n;
    while(l <= r){
        ll mid = (l+r)/2;
        //deb3(a[mid],a[x],check(a[mid],a[x]))
        if(check(a[mid],a[x]) < k){
            r = mid-1;
        }
        else{
            if(check(a[mid],a[x]) == k) ans = mid;
            l = mid+1;
        }
    }
    return ans;
}

ll bsmin(ll x){
    ll l = 0;
    ll r = x;
    ll ans = n+1;
    while(l <= r){
        ll mid = (l+r)/2;
        //deb3(a[mid],a[x],check(a[mid],a[x]))
        if(check(a[mid],a[x]) > k){
            l = mid+1;
        }
        else{
            if(check(a[mid],a[x]) == k) ans = mid;
            r = mid-1;
        }
    }
    return ans;
}   

void solve(){
    cin>>n>>x>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
    for(int i = 0; i < n; i++) ind[a[i]] = i;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll x = bsmax(ind[a[i]]);
        ll y = bsmin(ind[a[i]]);
        ans += x-y+1;
        //deb3(x,y,ans)
    }
    deb1(ans);
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}