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
typedef  map<pair<pll,pll>,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,w;
vll a;

ll calc(vll b){
    ll d = b[1]-b[0], ct = 0;
    for(int i = 2; i < n; i++){
        ll x = b[i-1]+d;
        if(abs(x-b[i]) <= 1) ct += abs(x-b[i]);
        else return INF;
        b[i] = x;
    }
    return ct;
}

void solve(){
    cin>>n;
    a = vll(n,0);
    for(int i = 0; i < n; i++) cin>>a[i];
    ll res = INF;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            a[0] += i, a[1] += j;
            res = min(res,calc(a)+abs(i)+abs(j));
            a[0] -= i, a[1] -= j;
        }
    }
    if(res > n) deb1(-1)
    else deb1(res)
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