#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  2e5+8;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const ll  INFi  =  0x7f7f7f7f;

ll p[N],sz[N],vis[N];
ll n,u,v1,w,ans[N];
vector<pair<ll,pll>> v;

void make(){
    for(int i = 1; i < N; i++){
        p[i] = i;
        sz[i] = 1;
    }
}

int find(ll x){
    return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y, ll w){
    ll a = find(x);
    ll b = find(y);
    if(a != b){
        if(sz[a] >= sz[b]) swap(a,b);
        p[a] = b;
        ans[w] += sz[a]*sz[b];
        sz[b] += sz[a];
    }
}


int main(){
    fastio;
    make();
    ll q;
    cin>>n>>q;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v1>>w;
        v.push_back({w,{u,v1}});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n-1; i++)
        merge(v[i].y.x,v[i].y.y,v[i].x);
    for(int i = 1; i < N; i++)
        ans[i] += ans[i-1];
    while(q--){
        cin>>u;
        cout<<ans[u]<<" ";
    }
    cout<<endl;
}