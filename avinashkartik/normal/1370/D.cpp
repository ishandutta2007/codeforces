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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, a[N];

int ch(ll mid){
    int ct = 0, p = -2;
    for(int i = 0; i < n-!(k&1); i++){
        if(i == p+1) continue;
        if(a[i] <= mid){
            ct++, p = i;
        }
    }
    if(ct >= (k+1)/2) return 1;
    ct = 0, p = -1;
    for(int i = 1; i < n-(k&1); i++){
        if(i == p+1) continue;
        if(a[i] <= mid){
            ct++, p = i;
        }
    }
    return ct >= k/2;
}

ll bs(){
    ll l = 1, r = 1e9, ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(ch(mid)){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    return ans;
}

void solve(){
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    deb1(bs());
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