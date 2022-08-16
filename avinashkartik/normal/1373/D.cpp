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
 
const ll   N     =  2e5+5;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], preo[N], pree[N];

void solve(){
    ll ans = 0, mx1 = 0, mx2 = 0, m1 = 0, m2 = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i%2 == 0) ans += a[i];
    }
    preo[0] = 0, pree[0] = 0;
    for(int i = 1; i < n; i++){
        pree[i] = pree[i-1];
        preo[i] = preo[i-1];
        if(i%2 == 0){
            preo[i] += a[i] - a[i-1];
            mx1 = min(mx1,preo[i]-m1);
            m1 = max(m1,preo[i]);
        }
        else{
            pree[i] += a[i] - a[i-1];
            mx2 = max(mx2,pree[i]-m2);
            m2 = min(m2,pree[i]);
        }
    }
    deb1(max(ans-mx1,ans+mx2))
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