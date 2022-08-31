#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], dpleft[N][65], dpright[N][65];

ll memleft(ll ind, ll m){
    if(ind == -1 || a[ind] > m) return 0;
    if(dpleft[ind][m] != -1) return dpleft[ind][m];
    return dpleft[ind][m] = max(0ll,memleft(ind-1,m)+a[ind]);
}

ll memright(ll ind, ll m){
    if(ind == n || a[ind] > m) return 0;
    if(dpright[ind][m] != -1) return dpright[ind][m];
    return dpright[ind][m] = max(0ll,memright(ind+1,m)+a[ind]);
}

void solve(){
    mset(dpleft,-1);
    mset(dpright,-1);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans,memleft(i-1,a[i])+memright(i+1,a[i]));
    }
    deb1(ans)
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