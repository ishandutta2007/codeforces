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
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, l, x, y, a[N];
um m;
vll ans;

void solve(){
    cin>>n>>l>>x>>y;
    for(int i = 1; i <= n; i++) cin>>a[i], m[a[i]] = 1;
    bool fx = 1, fy = 1;
    for(int i = 1; i <= n; i++){
        if(m[a[i]+x] == 1) fx = 0;
        if(m[a[i]+y] == 1) fy = 0;
    }
    if(fx == 1){
        if(fy == 0) ans.pb(x);
        else{
            for(int i = 1; i <= n; i++){
                if(a[i]+x <= l && (m[a[i]+x+y] || m[a[i]+x-y])){
                    ans.pb(a[i]+x);
                    fy = 0;
                    break;
                }
                if(a[i]-x >= 0 && (m[a[i]-x+y] || m[a[i]-x-y])){
                    ans.pb(a[i]-x);
                    fy = 0;
                    break;
                }
            }
            if(fy == 1) ans.pb(x),ans.pb(y);
        }
    }
    else if(fy == 1) ans.pb(y);
    deb1(ans.size());
    for(auto it : ans) cout<<it<<" ";
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