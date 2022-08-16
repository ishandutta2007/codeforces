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
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, k, m, f[100];

ll NCR(ll n, ll r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r);
    ll res = 1;
    for(ll k = 1; k <= r; ++k){
        res = (res*(n-k+1)/k);
    }
    return res;
}

ll check(ll mid){
    ll res1 = 0, res2 = 0, ub = 2*mid, lb = mid, k1 = k, k2 = k;
    for(ll i = log2(ub); i >= 0; i--){
        ll x = pow(2,i);
        if(ub&x) res1 += NCR(i,k1), k1--;
    }
    for(ll i = log2(lb); i >= 0; i--){
        ll x = pow(2,i);
        if(lb&x) res2 += NCR(i,k2), k2--;
    }
    return res1-res2;
}

void solve(){
    cin>>m>>k;
    ll l = 1;
    ll r = 1e18;
    while(l <= r){
        ll mid = (l+r)/2;
        ll x = check(mid);
        if(x == m){
            deb1(mid);
            break;
        }
        else if(x < m) l = mid+1;
        else r = mid-1;
    }
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