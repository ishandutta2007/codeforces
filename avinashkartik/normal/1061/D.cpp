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
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, x, y, st[N] = {}, f[N] = {};
multiset <pll> s, tv;

void solve(){
    cin>>n>>x>>y;
    for(int i = 0; i < n; i++){
        ll l,r;
        cin>>l>>r;
        s.insert({l,r});
        tv.insert({f[i],i});
    }
    ll ans = 0;
    for(auto it : s){
        auto i = tv.lower_bound({it.f,0});
        i--;
        if(y*(it.f-(*i).f) > x) i = tv.begin();
        if((*i).f == 0) st[(*i).s] = it.f;
        f[(*i).s] = it.s;
        tv.erase(i);
        tv.insert({f[(*i).s],(*i).s});
    }
    for(int i = 0; i < n; i++){
        if(f[i] == 0) continue;
        ans += x+(f[i]-st[i])*y;
        ans %= mod;
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