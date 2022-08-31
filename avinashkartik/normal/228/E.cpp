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
 
const ll   N     =  105;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, a[N][N], vis[N], on[N], flag = 0;
vll ans;

void dfs(ll ind, ll x){
    if(flag == -1) return;
    if(vis[ind] == x) return;
    else if(vis[ind] != -1){ flag = -1; return; }
    vis[ind] = x;
    for(int i = 1; i <= n; i++){
        if(a[ind][i] == -1) continue;
        dfs(i,a[ind][i]^x^1);
    }
}

void solve(){
    mset(on,-1);
    mset(a,-1);
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v,f;
        cin>>u>>v>>f;
        a[u][v] = a[v][u] = f;
    }
    for(int i = 1; i <= n; i++){
        if(on[i] != -1) continue;
        mset(vis,-1);
        flag = 0;
        dfs(i,0);
        if(flag == -1){
            mset(vis,-1);   
            flag = 0;
            dfs(i,1);
            if(flag == -1){
                deb1("Impossible")
                return;
            }
        }
        for(int i = 1; i <= n; i++)
            if(vis[i] != -1) on[i] = vis[i];

    }
    for(int i = 1; i <= n; i++){
        if(on[i] == 1) ans.pb(i);
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