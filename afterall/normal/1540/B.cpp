#include <bits/stdc++.h>
/// this time?
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

const int N=250;
ll dp[N][N];
ll mod=1e9+7;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
vector <int> g[N];
ll sz[N];
ll par[N];
ll pp[N];
ll hi[N];
void dfs(ll v,ll p,ll P){
    pp[v]=p;
    hi[v]=hi[p]+1;
    par[v]=P;
    sz[v]=1;
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v,P);
        sz[v]+=sz[u];
    }
}
int Main(){
    ll n;
    cin >> n;
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i=1;i<N;i++){
        dp[0][i]=1;
    }
    ll nim=power(2,mod-2);
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            dp[i][j]=nim*dp[i-1][j]%mod+nim*dp[i][j-1]%mod;
            dp[i][j]%=mod;
        }
    }
    ll ans=0;
    ll inv=power(n,mod-2);
    for (int i=1;i<=n;i++){
        hi[i]=0;
        for (auto u : g[i]){
            dfs(u,i,u);
        }
        sz[i]=n;
        for (int j=i+1;j<=n;j++){
            if (j==i) continue;
            if (j>i){
                ans+=sz[j]*power(n,mod-2)%mod;
                ans%=mod;
            }
            else{
                ans+=(n-sz[par[j]])*power(n,mod-2);
            }
            ll y=j;
            ll v=pp[j];
            while(v!=i){
                ll z=sz[v]-sz[y];
                ll zz=z;
                z=z*inv%mod;
                ll x=hi[v];
                ll yy=hi[j]-hi[v];
                if (i>j){
                    ans+=dp[x][yy]*z%mod;
                    ans%=mod;
                }
                else{
                  //  cout << x << " dp " << y << " " << dp[x][y] << " " << i << " " << j << " " << sz[v] << " " << sz[y] << " " << zz  << endl;
                    ans+=dp[yy][x]*z%mod;
                    ans%=mod;
                }
                y=v;
                v=pp[v];
            }
        }
       // cout << i << " " << ans << endl;
    }
    kill(ans);
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--){
        Main();
    }
}