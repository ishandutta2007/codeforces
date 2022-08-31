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
 
const ll   N     =  1e5+5;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, num[MAXN] = {}, den[MAXN], m, p[MAXN] = {}, a[N], b[N];

void sieve(){
    for(ll i = 2; i*i < MAXN; i++){
        if(p[i] == 0){
            for(int j = i*i; j < MAXN; j += i) p[j] = 1;
        }
    }
}

void fact(ll x, int f){
    for(ll i = 2; i*i <= x; i++){
        if(p[x] == 0) break;
        while(x%i == 0){
            if(f == 1) num[i]++;
            else den[i]++;
            x /= i;
        }
    }
    if(x > 1){
        if(f == 1) num[x]++;
        else den[x]++;
    }
}

ll compress(ll x, int f){
    ll res = 1;
    for(ll i = 2; i*i <= x; i++){
        if(p[x] == 0) break;
        while(x%i == 0){
            if(f == 1 and num[i] > 0) num[i]--, res *= i;
            else if(f == 0 and den[i] > 0) den[i]--, res *= i;
            x /= i;
        }
    }
    if(x > 1){
        if(f == 1 and num[x] > 0) num[x]--, res *= x;
        else if(f == 0 and den[x] > 0) den[x]--, res *= x;
    }
    return res;
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i], fact(a[i],1);
    for(int i = 0; i < m; i++) cin>>b[i], fact(b[i],0);
    for(ll i = 2; i < MAXN; i++){
        ll x = min(num[i],den[i]);
        num[i] = den[i] = x;
    }
    for(int i = 0; i < n; i++) a[i] /= compress(a[i],1);
    for(int i = 0; i < m; i++) b[i] /= compress(b[i],0);
    deb2(n,m)
    for(int i = 0; i < n; i++) cout<<a[i]<<" "; cout<<endl;
    for(int i = 0; i < m; i++) cout<<b[i]<<" "; cout<<endl;
}

int main(){
    sieve();
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
        string txt;
        cin>>txt;
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}