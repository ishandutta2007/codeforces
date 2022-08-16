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
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, p, a[N], y[N];
multiset <ll> s;

void solve(){
    cin>>n>>p;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
    vll ans;
    ll st = 0, val = 0, ct = 0;
    for(int i = 0; i < n; i++){
        st = max(st,a[i]-i);
    }
    for(int j = 0,i = 0,x = st; j < n; j++,x++){
        while(i < n and a[i] <= x) i++,ct++;
        y[j] = ct%p;
        s.insert(ct%p);
        ct--;
    }
    for(int j = 0; j < n; j++){
        if(s.find(val) == s.end()) ans.pb(st+j);
        auto it = s.lower_bound(y[j]);
        s.erase(it);
        s.insert(val);
        val = (val-1+p)%p;
    }
    deb1(ans.size())
    debv(ans)
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