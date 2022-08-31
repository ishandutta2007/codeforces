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
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], b[N], c[N], d[N];

int ch(int mid){
    for(int i = 0; i < n; i++) c[i] = a[i];
    for(int i = 0; i < n; i++) d[i] = b[i];
    c[0] -= mid;
    c[0] = max(0ll,c[0]);
    d[n-1] -= mid;
    for(int i = 0; i < n; i++){
        d[i] -= c[i];
        if(d[i] < 0) return (i == n-1)? -1:0;
        c[i+1] -= d[i]; 
        c[i+1] = max(0ll,c[i+1]);
    }
    return 1;
}

bool bs(){
    int l = 0, r = b[n-1];
    while(l <= r){
        int mid = (l+r)/2;
        int x = ch(mid);
        //deb2(mid,x)
        if(x == 1) return 1;
        if(x == 0) l = mid+1;
        else r = mid-1;
    }
    return 0;
}

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    if(bs()) deb1("YES")
    else deb1("NO")
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}