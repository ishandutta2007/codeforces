#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
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
 
const ll   N     =  2e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll t=1,n,m,k,ct[N],sp[N],a[N];
vll adj[N],rev[N];

void bfs(ll s){
    queue <ll> q;
    q.push(s);
    sp[s] = 0;
    while(q.size()){
        ll x = q.front();
        q.pop();
        for(auto it : rev[x]){
            if(sp[it] == -1){
                sp[it] = sp[x]+1;
                ct[it] = 1;
                q.push(it);
            }
            else if(sp[x] < sp[it]) ct[it]++;
        }
    }
}
int main(){
    fastio;
    //cin>>t;
    while(t--){
        cin>>n>>m;
        memset(sp,-1,sizeof(sp));
        for(int i = 0; i < m; i++){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            rev[v].push_back(u);
        }
        cin>>k;
        for(int i = 0; i < k; i++) cin>>a[i];
        bfs(a[k-1]);
        ll m1=0,m2=0;
        for(int i = 0; i < k-1; i++){
            if(sp[a[i]] == sp[a[i+1]]+1){
                if(ct[a[i]] > 1) m2++;
            }
            else m1++,m2++;
        }
        cout<<m1<<" "<<m2<<endl;
    }
}