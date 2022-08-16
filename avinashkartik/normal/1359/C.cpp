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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1, c, h, t;

ld calc(int x){
    return abs(t - (ld) (x*h + (x-1)*c)/(2*x-1));
}
 
int check(int mid){
    if(calc(mid) < calc(mid+1) && calc(mid) < calc(mid-1))
        return 1;
    return 0;
}
 
int bs(){
    ll l = 1;
    ll r = 1e6, mid;
    while(l <= r){
        mid = (l+r)/2;
        //deb2(mid,(ld) (mid*h + (mid-1)*c)/(2*mid-1))
        if(check(mid) == 1) return mid;
        if((ld) (mid*h + (mid-1)*c)/(2*mid-1) > t) l = mid+1;
        else r = mid-1;
    }
    return mid;
}

void solve(){
    cin>>h>>c>>t;
    if(2*t <= (h+c)){
        deb1(2)
        return;
    }
    ll x = bs(), y = x;
    ld m = h;
    for(int i = max(x-1,1ll); i <= x+1; i++){
        if(calc(i) < m){
            m = calc(i);
            y = i;
        }
    }
    deb1(2*y-1)
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