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
typedef  map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, p, a[N];
vll s1;
um ct;

ll fastmod(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res;
}

void solve(){
    ct.clear();
    s1.clear();
    cin>>n>>p;
    for(int i = 0; i < n; i++) cin>>a[i];
    if(p == 1){
        deb1(n%2)
        return;
    }
    sort(a,a+n);
    int f = 0, m;
    for(int i = n-1; i >= 0; i--){
        if(f == 0){
            s1.pb(a[i]);
            m = a[i];
            f = 1;
            continue;
        }
        ll j = a[i];
        ct[j]++;
        while(ct[j] == p){ ct[j] = 0, ct[j+1]++, j++; }
        if(j == m) f = 0, ct[j] = 0;
    }
    ll ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        ans1 = (ans1+fastmod(p,a[i]))%mod;
    }
    for(auto it : s1) ans2 = (ans2+fastmod(p,it))%mod;
    deb1((2*ans2-ans1+2*mod)%mod)
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