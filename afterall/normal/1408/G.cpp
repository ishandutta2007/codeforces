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
const int N=1510;
ll g[N][N];
vector <pair <int,pii> > yal;
ll dp[N][N];
ll pd[N];
ll mod=998244353;
ll mi[N][N];
ll mx[N];
ll n;
ll par[N];
ll sz[N];
vector <int> mol[N];
ll last=1;
void merg(ll u,ll v){
    if (par[u]==par[v]) return ;
   // cout << u << " " << v << endl;
    ll d=g[u][v];
    u=par[u],v=par[v];
    last=u;
    for (int i=1;i<=sz[u]+sz[v];i++){
        pd[i]=0;
    }
    for (int i=1;i<=sz[u];i++){
        for (int j=1;j<=sz[v];j++){
            pd[i+j]+=dp[u][i]*dp[v][j]%mod;
            pd[i+j]%=mod;
        }
    }
    sz[u]+=sz[v];
    for (int i=1;i<=sz[u];i++){
        dp[u][i]=pd[i];
    }
    for (auto x : mol[u]){
        for (auto y : mol[v]){
            mx[u]=max(mx[u],g[x][y]);
        }
    }
    for (auto x : mol[v]) mol[u].pb(x);
    for (int i=1;i<=n;i++){
        if (par[i]==v) par[i]=u;
        if (par[i]==u) mi[u][i]=1e9;
    }
    ll mm=1e9;
    for (int i=1;i<=n;i++){
        if (mi[u][i]!=1e9){
            mi[u][i]=min(mi[u][i],mi[v][i]);
        }
        mm=min(mm,mi[u][i]);
    }
    if (mm>mx[u]){
        dp[u][1]=1;
    }
   //     cout << "WHAT " << mx[u] << " " << mm << endl;

}
int Main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> g[i][j];
            mi[i][j]=g[i][j];
            if (i<j){
                yal.pb({g[i][j],{i,j}});
            }
        }
    }
    sort(yal.begin(),yal.end());
    for (int i=1;i<=n;i++){
        dp[i][1]=1;
        par[i]=i;
        sz[i]=1;
        mi[i][i]=1e9;
        mol[i].pb(i);
    }
    for (auto u : yal){
        if (par[u.S.F]!=par[u.S.S]){
            merg(u.S.F,u.S.S);
        }
    }
    for (int i=1;i<=n;i++){
        cout << dp[last][i] << " ";
    }


}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--) Main();
}