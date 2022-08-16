#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
 
const ll   N     =  4e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, t1,t2,x1,x2,t0;
ld ans = INFi;
pll val;

ld check(ll y1, ll y2){
    if(y1+y2 == 0) return 0;
    return (ld)(t1*y1+t2*y2)/(y1+y2);
}

void bs(ll y1){
    int l = 0;
    int r = x2;
    while(l <= r){
        int mid = (l+r)/2;
        ld t = check(y1,mid);
        if(t >= t0){
            if(ans >= t){
                ans = t;
                val = {y1,mid};
            }
            if(t != t0) r = mid-1;
            else l = mid+1;
        }
        else l = mid+1;
    }
}

void solve(){
    cin>>t1>>t2>>x1>>x2>>t0;
    for(int i = 0; i <= x2; i++){
        ld t = check(0,i);
        if(t >= t0){
            if(ans >= t){
                ans = t;
                val = {0,i};
            }
        }
    }
    for(int i = 1; i <= x1; i++){
        bs(i);
    }
    deb2(val.f,val.s);
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