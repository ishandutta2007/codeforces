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

ll test = 1, n, k, a[N];
multiset <ll> s10, s11, s01;

void solve(){
    s10.clear();
    s11.clear();
    s01.clear();
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        ll ti,ai,bi;
        cin>>ti>>ai>>bi;
        if(ai == 1 and bi == 1){
            s11.insert(ti);
        }
        if(ai == 1 and bi == 0){
            s10.insert(ti);
        }
        if(ai == 0 and bi == 1){
            s01.insert(ti);
        }
    }
    while(s10.size() and s01.size()){
        auto it0 = s10.begin();
        auto it1 = s01.begin();
        s11.insert(*it0+*it1);
        s10.erase(it0);
        s01.erase(it1);
    }
    if(s11.size() < k){
        deb1(-1)
        return;
    }
    ll ans = 0, ct = 0;
    for(auto it : s11){
        ans += it;
        ct++;
        if(ct == k) break;
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