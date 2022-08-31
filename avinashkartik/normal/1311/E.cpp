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
 
const ll   N     =  5e3+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, d;

void solve(){
    cin>>n>>d;
    ll mx = n*(n-1)/2, mn = 0;
    for(int i = 2; i <= n; i++) mn += (ll) log2(i);
    if(d < mn or d > mx){
        deb1("NO")
        return;
    }
    vector<int> par(n);
    iota(par.begin(), par.end(), -1);
    
    vector<int> cnt(n, 1);
    cnt[n - 1] = 0;
    
    vector<int> bad(n);
    
    vector<int> dep(n);
    iota(dep.begin(), dep.end(), 0);
    
    int cur = n * (n - 1) / 2;
    while (cur > d) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (!bad[i] && cnt[i] == 0 && (v == -1 || dep[v] > dep[i])) {
                v = i;
            }
        }
        assert(v != -1);
        int p = -1;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] < 2 && dep[i] < dep[v] - 1 && (p == -1 || dep[p] < dep[i])) {
                p = i;
            }
        }
        if (p == -1) {
            bad[v] = 1;
            continue;
        }
        assert(dep[v] - dep[p] == 2);
        --cnt[par[v]];
        --dep[v];
        ++cnt[p];
        par[v] = p;
        --cur;
    }

    cout << "YES" << endl;
    for (int i = 1; i < n; ++i) cout << par[i] + 1 << " ";
    cout << endl;
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