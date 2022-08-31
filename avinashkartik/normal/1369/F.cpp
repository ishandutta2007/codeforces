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
 
const ll   N     =  1e6+8;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, st[N][2];

bool lose(ll s, ll e){
    if(s > e) return 0;
    int f = 1;
    while(e){
        if(f == -1) return (e-s)%2;
        if(e/2 < s and s <= e){
            if(f == 1) return 1;
            return (e-s)%2; 
        }
        e /= 2;
        if(f != -1) f ^= 1;
        if(e&1 and f == 0) f = -1;
    }
}

bool win(ll s, ll e){
    if(s > e) return 1;
    int f = 0;
    if(e&1) f = -1;
    while(e){
        if(f == -1) return (e-s)%2;
        if(e/2 < s and s <= e){
            if(f == 1) return 1;
            return (e-s)%2; 
        }
        e /= 2;
        if(f != -1) f ^= 1;
        if(e&1 and f == 0) f = -1;
    }
}

void solve(){
    cin>>n;
    st[1][0] = 1; 
    for(int i = 1; i <= n; i++){
        ll s,e;
        cin>>s>>e;
        if(st[i][0] == 1){
            st[i+1][0] = lose(s,e);
            st[i+1][1] = win(s,e);
        }
        if(st[i][1] == 1){
            st[i+1][0] |= lose(s+1,e)&lose(2*s,e);
            st[i+1][1] |= win(s+1,e)&win(2*s,e);
        }
    }
    deb2(st[n+1][1],st[n+1][0])
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