#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e4+100,K=80;
ll mod=998244353;
ll dp[N][K],ans[N][K],par[N][K],rap[N][K],s[N][K];
vector <int> g[N];
ll dfs(ll v,ll p){
    dp[v][0]=1;
    for (auto u : g[v]){
        if (u==p) continue;
      //  cout << v << " " << u << endl;
        dfs(u,v);
    }
    for (int i=0;i<K;i++){
        for (auto u : g[v]){
            if (u==p) continue;
            s[v][i]+=dp[u][i];
            s[v][i]%=mod;
        }
    }
    for (int i=2;i<K;i++){
        for (auto u : g[v]){
            if (u==p) continue;
            for (int j=0;j<=i-2;j++){
                dp[v][i]+=dp[v][i-j-2]*dp[u][j]%mod;
                dp[v][i]%=mod;
            }
        }
    }
}
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll fac[N],fm[N];
ll ent(ll k,ll n){
    if (k==0 || k==n) return 1;
    if (k<0 || k>n) return 0;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
void sik(ll v,ll u){
    memset(dp[v],0,sizeof dp[v]);
    dp[v][0]=1;
    for (int i=0;i<K;i++){
        s[v][i]-=dp[u][i];
        s[v][i]+=mod;
        s[v][i]%=mod;
    }
    for (int i=2;i<K;i++){

            for (int j=0;j<=i-2;j++){
                dp[v][i]+=dp[v][i-j-2]*s[v][j]%mod;
                dp[v][i]%=mod;
            }

    }
    memset(dp[u],0,sizeof dp[u]);
    dp[u][0]=1;
    for (int i=0;i<K;i++){
        s[u][i]+=dp[v][i];
        s[u][i]%=mod;
    }
    for (int i=2;i<K;i++){

            for (int j=0;j<=i-2;j++){
                dp[u][i]+=dp[u][i-j-2]*s[u][j]%mod;
                dp[u][i]%=mod;
            }

    }
}
ll dfst(ll v,ll p){
    for (int i=0;i<K;i++) ans[v][i]=dp[v][i];
    for (auto u : g[v]){
        if (u==p) continue;
        sik(v,u);
        dfst(u,v);
        sik(u,v);
    }
}
int32_t main(){
    fac[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    ll n1,n2,k;
    cin >> n1 >> n2 >> k;
    for (int i=0;i<n1-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i=0;i<n2-1;i++){
        ll u,v;
        cin >> u >> v;
        u+=n1;
        v+=n1;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    dfst(1,1);
    dfs(n1+1,n1+1);
    dfst(n1+1,n1+1);
    for (int i=1;i<=n1;i++){
        for (int j=0;j<K;j++){
            par[i][j]=par[i-1][j]+ans[i][j];
            par[i][j]%=mod;
        }
    }
    for (int i=n1+1;i<=n2+n1;i++){
        for (int j=0;j<K;j++){
            rap[i][j]=rap[i-1][j]+ans[i][j];
            rap[i][j]%=mod;
        }
    }
  //  for (int i=1;i<=n1+n2;i++){
    //    cout << i << " " << ans[i][k] << endl;
   // }
  // cout << ans[1][2] << " " << ans[2][2] << endl;
    ll jav=0;
 //   cout << par[n1][0] << " " << rap[n1+n2][2] << " " << ent(0,k) << endl;
    for (int i=0;i<=k;i++){
        jav+=ent(i,k)*par[n1][i]%mod*rap[n1+n2][k-i]%mod;
   //     cout << i << " " << jav << endl;
    }
    cout << jav%mod << endl;
}