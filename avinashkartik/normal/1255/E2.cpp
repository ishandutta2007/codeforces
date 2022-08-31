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
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<pll,ll>  um;
typedef  vector<pll>           vpll;
 
const int   N    =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, k, s, a[N], tmp[N];
vll fact;

void pf(ll x){
    for(ll i = 2; i*i <= x; i++){
        if(x%i == 0){
            while(x%i == 0){
                x /= i;
            }
            fact.pb(i);
        }
    }
    if(x > 1) fact.pb(x);
}

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i], s += a[i];
    if(s == 1){ deb1(-1); return; }
    pf(s);
    ll ans = 0, res = INF;
    vll v;
    for(auto k : fact){
        ans = 0;
        for(int i = 1; i <= n; i++) tmp[i] = a[i];
        for(int i = 1; i <= n; i++){
            if(tmp[i] < 0){
                ans -= tmp[i];
                tmp[i+1] += tmp[i];
                continue;
            }
            ll x = tmp[i]%k, y = k-x;
            if(x < y){
                ans += x;
                tmp[i+1] += x;
            }
            else{
                ans += y;
                tmp[i+1] -= y;
            }
        }
        res = min(res,ans);
    }
    deb1(res)
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