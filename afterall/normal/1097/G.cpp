#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+100,K=210;
ll n,k;
ll mod=1e9+7;
ll p2[N];
vector <int> g[N];
ll dp[N][K];
int sz[N];
ll oo=0;
ll po=0;
int dfssz(ll v,ll p){
    sz[v]=1;
    for (auto u : g[v]){
        if (u==p) continue;
        dfssz(u,v);
        sz[v]+=sz[u];
    }
}
void dfs(ll v,ll p){
    dp[v][0]=1;
    ll z=0;
    ll y=0;
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v);
        ll o=z;
        z+=sz[u];
        y++;
        for (int i=min(k,z);i>-1;i--){
            for (int j=max((ll)0,i-o-1);j<=min(i,sz[u]);j++){
                if (j!=0)
                    dp[v][i]+=dp[u][j]*2*dp[v][i-j];
                else{
                    dp[v][i]=dp[u][j]*2*dp[v][i-j];
                }
                if (j<i && j!=0){
                    dp[v][i]+=dp[u][j]*2*dp[v][i-j-1];
                }
                if (j<i && j==0){
                    dp[v][i]+=dp[v][i-1]*(p2[sz[u]]-1);
                }
                dp[v][i]%=mod;
                oo+=2;
            }
        }
    }
}
ll ans[N];
ll dfsk(ll v,ll p){
    ll tt=0;
    for (int i=1;i<=k;i++){
        for (auto u : g[v]){
            tt++;
            if (u==p) continue;
            dp[v][i]-=dp[u][i]*p2[sz[v]-1-sz[u]+1];
           // dp[v][i]%=mod;
            if (i!=1){
                ll z=dp[u][i-1];
                dp[v][i]-=z*p2[sz[v]-sz[u]];
               // dp[v][i]+=mod;
                //dp[v][i]%=mod;
                ans[i]+=2*z*(p2[n-sz[u]]-1)%mod;
              //  if (tt&2) ans[i]%=mod;
                //ans[i]%=mod;
         //       cout << z << " jd " << 2*z*(p2[n-sz[u]]-1) << endl;
            }
            if (i==1){
                ll z=p2[sz[u]]-1;
                dp[v][i]-=z*p2[sz[v]-sz[u]-1];
               // dp[v][i]+=mod;
                //dp[v][i]%=mod;
                ans[1]+=(p2[sz[u]]-1)*(p2[n-sz[u]]-1)%mod;
               // ans[1]%=mod;
            }
            if (tt&2){
            dp[v][i]%=mod;
            dp[v][i]+=mod;
         //   dp[v][i]%=mod;
            }
        }
    }
    for (int i=1;i<=k;i++){
        dp[v][i]+=mod;
        dp[v][i]%=mod;
    }
    for (auto u : g[v]){
        if (u==p) continue;
        dfsk(u,v);
    }
}
ll pd[K][K];
ll fac[N],fm[N];
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll ent(ll k,ll n){
    if (k==0 || k==n) return 1;
    if (k<0 || k>n) return 0;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
int32_t main(){
    sync;
    p2[0]=1;
    fac[0]=1;
    for (int i=1;i<N;i++){
        p2[i]=p2[i-1]*2%mod;
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    cin >> n >> k;
    for (int i=0;i<n-1;i++){

        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfssz(1,1);
    dfs(1,1);
    dfsk(1,1);
   // for (int i=1;i<=k;i++) ans[i]+=mod,ans[i]%=mod;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            ans[j]+=dp[i][j]*(p2[n-sz[i]+1]);
            if (i&4)
            ans[j]%=mod;
        }
    }
    ll jav=0;
    pd[0][0]=1;
    for (int i=1;i<K;i++){
        for (int j=1;j<=i;j++){
            for (int p=1;p<=i;p++){
                pd[i][j]+=pd[i-p][j-1]*ent(p,i)%mod;
                pd[i][j]%=mod;
            }
        }
    }
    for (int i=1;i<=k;i++){
        ans[i]%=mod;
        jav+=pd[k][i]*ans[i]%mod;
     //   cout << ans[i] << endl;
    }
    if (po) kill(oo);
    jav+=mod;
    cout << jav%mod << endl;


}