#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll L[N];
ll R[N];
ll dp[N][2];
vector <int> g[N];
void dfs(ll v,ll p){
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v);
        dp[v][1]+=max(dp[u][1]+abs(R[v]-R[u]),dp[u][0]+abs(R[v]-L[u]));
        dp[v][0]+=max(dp[u][1]+abs(L[v]-R[u]),dp[u][0]+abs(L[v]-L[u]));
    }
}
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> L[i] >> R[i];
    for (int i=0;i<n+10;i++){
        dp[i][0]=0;
        dp[i][1]=0;
        g[i].clear();
    }
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    kill(max(dp[1][1],dp[1][0]));
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}