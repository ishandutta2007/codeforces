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

int test=1, n, k, p[N], s, a[N];

void sieve(){
    for(int i = 2; i*i < N; i++){
        if(p[i] == 0)
            for(int j = i*i; j < N; j += i) 
                if(p[j] == 0) p[j] = i;
    }
}

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i], s += a[i];
    if(s == 1){ deb1(-1); return; }
    ll ans = 0, ct = 0, res = INF;
    vll v;
    for(int k = 2; k <= s; k++){
        if(p[k] != 0 or s%k != 0) continue;
        ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 1) v.pb(i);
            ct += a[i];
            if(ct == k){
                int mid = v[k/2];
                for(auto it : v)
                    ans += abs(it-mid);
                ct = 0;
                v.clear();
            }
        }
        res = min(res,ans);
    }
    deb1(res)
}

int main(){
    fastio;
    sieve();
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}