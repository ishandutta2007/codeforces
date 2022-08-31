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

ll test = 1, n, k, a[N], f[N], l[N], m[N], last[N], final[N];

void solve(){
    map <ll,ll> ind;
    set <ll> s;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i], s.insert(a[i]);
    int ct = 1;
    for(auto it : s) ind[it] = ct++;
    for(int i = 1; i <= n; i++){
        a[i] = ind[a[i]];
        final[a[i]] = i;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        f[i] = f[last[a[i]]]+1;
        if(last[a[i]] == 0){
            if(last[a[i]-1] == final[a[i]-1]) m[i] = max(f[last[a[i]-1]],m[last[a[i]-1]])+1;
            else m[i] = f[last[a[i]-1]]+1;
        }
        else m[i] = m[last[a[i]]]+1;
        if(last[a[i]-1] == final[a[i]-1]) l[i] = max(l[last[a[i]]],max(m[last[a[i]-1]],f[last[a[i]-1]]))+1;
        else l[i] = max(l[last[a[i]]],f[last[a[i]-1]])+1;
        last[a[i]] = i;
        ans = max(ans,max(f[i],max(m[i],l[i])));
    }
    for(int i = 1; i <= n; i++) f[i] = m[i] = l[i] = last[a[i]] = final[a[i]] = 0;
    deb1(n-ans)
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