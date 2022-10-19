#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;
ll val[N];
vector <int> g[N];
ll sz[N];
void dfs(ll v,ll p,ll h){
    ll p1=0;
    sz[v]=0;
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v,h+1);
        sz[v]+=sz[u];
    }
    if (v==1){
        val[v]=-sz[v];
        sz[v]=0;
        return;
    }
    if (h%2==0){
        val[v]=-sz[v]-1;
        sz[v]=-1;
    }
    else {
        val[v]=-sz[v]+1;
        sz[v]=1;
    }
    
}
void Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1,0);
    for (int i=1;i<=n;i++) cout << val[i] << " ";
        cout << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}