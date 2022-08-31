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
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<pll,ll>  um;
typedef  vector<pll>           vpll;
 
const int   N    =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test=1, n, x, p[N], m;
vector <int> fact[N];
string t;

void sieve(){
    for(int i = 2; i*i < N; i++){
        if(p[i] == 0)
            for(int j = i*i; j < N; j += i) p[j] = 1;
    }
}

void pf(int x){
    for(int i = 2; i*i <= x; i++){
        if(p[i] == 0){
            int ct = 0;
            while(x%i == 0){
                x /= i;
                ct++;
            }
            fact[i].pb(ct);
        }
    }
    if(x > 1) fact[x].pb(1);
}

void solve(){
    sieve();
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        pf(x);
        m = max(m,x);
    }
    ll ans = 1;
    for(int i = 2; i <= m; i++){
        if(p[i] == 0){
            sort(fact[i].begin(), fact[i].end());
            int sz = fact[i].size();
            if(sz <= n-2) continue;
            auto it = fact[i].begin();
            if(sz == n)
                it++;
            ans *= pow(i,(*it));
        }
    }
    deb1(ans)
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