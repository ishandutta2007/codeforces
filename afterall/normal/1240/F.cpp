#include <bits/stdc++.h>
typedef int ll;
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
const int N=1e2+100,K=1e3+100;
vector <int> g[N];
map <pii,int> rng,vis;
ll t[N][K];
void make0(){
    for (int i=1;i<N;i++){
        for (auto u : g[i]){
            vis[{i,u}]=0,vis[{u,i}]=0,t[i][rng[{u,i}]]=0;
        }
    }
}
void upd(){
    for (int v=1;v<N;v++){
        for (auto u : g[v]){
            t[u][rng[{u,v}]]++;
        }
    }
}
void dfs(ll v,ll r1,ll r2){
    for (auto u : g[v]){
        if (vis[{u,v}] || rng[{u,v}]!=r1) continue;
        rng[{v,u}]=r2;
        rng[{u,v}]=r2;
        vis[{v,u}]=1;
        vis[{u,v}]=1;
        dfs(u,r2,r1);
        break;
    }
}
int32_t main(){
    ll n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
    }
    vector <pii> yal;
    for (int i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        yal.pb({u,v});
    }
    for (int ya=0;ya<m;ya++){
        ll u=yal[ya].F,v=yal[ya].S;
        ll mnu=N,mnv=N;
        for (int i=1;i<=k;i++){
            mnu=min(mnu,t[u][i]);
            mnv=min(mnv,t[v][i]);
        }
        ll pll=0;

        for (int i=1;i<=k;i++){
            if (t[u][i]-1<=mnu && t[v][i]-1<=mnv){
                pll=1;
                rng[{u,v}]=i;
                rng[{v,u}]=i;
                t[u][i]++;
                t[v][i]++;
                break;
            }
        }
        if (pll){
            continue;
        }
        ll rv,ru;
        for (int i=1;i<=k;i++){
            if (t[v][i]==mnv) rv=i;
            if (t[u][i]==mnu) ru=i;
        }
        dfs(u,rv,ru);
        rng[{u,v}]=rv;
        rng[{v,u}]=rv;
        make0();
        for (int i=1;i<=n;i++){
            t[i][ru]=0;
            t[i][rv]=0;
        }
        upd();
    }
    for (auto u : yal){
        cout << rng[{u.F,u.S}] << endl;
    }
}