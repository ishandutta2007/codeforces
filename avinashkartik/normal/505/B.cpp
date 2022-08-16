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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  105;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1, p[N][N], sz[N][N], n, m, q;

void make(ll n, ll m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            p[i][j] = i;
            sz[i][j] = 1;
        }
    }
}

int find(ll x, ll c){
    return (p[x][c] == x)? x: p[x][c] = find(p[x][c],c);
}

void merge(ll x, ll y, ll c){
    ll a = find(x,c);
    ll b = find(y,c);
    if(a != b){
        if(sz[a][c] >= sz[b][c]) swap(a,b);
        p[a][c] = b;
        sz[b][c] += sz[a][c];
    }
}

void solve(){
    cin>>n>>m;
    make(n,m);
    for(int i = 1; i <= m; i++){
        int u,v,c;
        cin>>u>>v>>c;
        merge(u,v,c);
    }
    cin>>q;
    while(q--){
        int u,v,ct = 0;
        cin>>u>>v;
        for(int i = 1; i <= m; i++)
            if(find(u,i) == find(v,i)) ct++;
        deb1(ct)
    }
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