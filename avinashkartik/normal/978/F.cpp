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
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  map<pair<pll,pll>,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,ans[N],vis[N];
vll v[N];
vpll a;

void solve(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.pb({x,i});
    }
    for(int i = 0; i < m; i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    sort(a.begin(), a.end());
    int j = 0;
    for(int i = 0; i < n; i++){
        if(i != 0 and a[i].f > a[i-1].f){
            for(int k = j; k < i; k++) vis[a[k].s] = 1;
            j = i;
        }
        int res = j;
        for(auto it : v[a[i].s])
            if(vis[it] == 1) res--;
        ans[a[i].s] = res;
    }
    for(int i = 0; i < n; i++) cout<<ans[i]<<" "; cout<<endl;
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