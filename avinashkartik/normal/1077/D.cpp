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
 
const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, k, a[N];
ll ct[N], m[N];
vll ans;
set <ll> s;

int ch(ll mid){
    int val = 0;
    for(auto it : s){
        val += ct[it]/mid;
    }
    return val >= k;
}

void solve(){
    mset(ct,0);
    mset(m,0);
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i], ct[a[i]]++, s.insert(a[i]);
    ll l = 1, r = n, res = 1;
    while(l <= r){
        ll mid = (l+r)/2;
        if(ch(mid)){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    for(auto it : s){
        while(ct[it]/(m[it]+1) >= res) ans.pb(it), m[it]++;
    }
    for(int i = 0; i < k; i++){
        cout<<ans[i]<<" ";
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