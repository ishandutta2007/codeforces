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
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,a[N],vis[N] = {},vis1[N] = {};

void clr(){
    for(int i = 1; i <= n; i++) vis[a[i]] = 0;
}

ll solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i],vis[a[i]] = 1;
    for(int i = 1; i < 1024*2; i++){
        for(int j = 1; j <= n; j++){
            vis1[i^a[j]] = 1;
        }
        int key = 1;
        for(int k = 1; k <= n; k++){
            if(vis[a[k]] != vis1[a[k]]) key = 0;
        }
        for(int j = 1; j <= n; j++){
            vis1[i^a[j]] = 0;
        }
        if(key == 1){
            clr();
            return i;
        }
    }
    clr();
    return -1;
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        deb1(solve());
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}