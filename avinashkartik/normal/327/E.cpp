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
 
const ll   N     =  24;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], k, x=-1, y=-1, s[1<<N], dp[1<<N];

void calc(ll mask){
    if(s[mask] == x || s[mask] == y) return;
    for(int i = 0; i < n; i++){
        if(mask&(1<<i)) dp[mask] = (dp[mask]+dp[mask-(1<<i)])%mod;
    }
}

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    cin>>k;
    if(k == 1) cin>>x;
    if(k == 2) cin>>x>>y;
    ll p = 1, ind = 0;
    dp[0] = 1;
    for(int i = 1; i < 1<<n; i++){
        if(i == p*2) p *= 2, ind++;
        s[i] = s[i-p] + a[ind];
        calc(i);
    }
    deb1(dp[(1<<n)-1]);
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