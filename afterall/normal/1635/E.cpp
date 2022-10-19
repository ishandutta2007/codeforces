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
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll vis[N];
/// vis[1]=L : vis[2]=R
vector <pii> g[N];
vector <int> y[N];
ll in[N];
ll jav[N];
void dfs(ll v,ll k){
    vis[v]=k;
    for (auto U : g[v]){
        if (vis[U.F]==vis[v]){
            cout << "NO" << endl;
            exit(0);
        }
        if (!vis[U.F]) dfs(U.F,3-k);
    }
}
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll t,u,v;
        cin >> t >> u >> v;
        g[u].pb({v,t});
        g[v].pb({u,t});
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]) dfs(i,1);
    }
    for (int i=1;i<=n;i++){
        for (auto U : g[i]){
            if (vis[i]==1){
                /// L
                if (U.S==1){
                    in[U.F]++;
                    y[i].pb(U.F);
                }
                else{
                    in[i]++;
                    y[U.F].pb(i);
                }
            }
            else{
                if (U.S==2){
                    in[U.F]++;
                    y[i].pb(U.F);
                }
                else{
                    in[i]++;
                    y[U.F].pb(i);
                }
            }
        }
    }
    vector <int> ans;
    queue <int> q;
    for (int i=1;i<=n;i++){
        if (in[i]==0) q.push(i);
    }
    while(q.size()){
        ll v=q.front();
        q.pop();
        ans.pb(v);
        for (auto u : y[v]){
            in[u]--;
            if (in[u]==0) q.push(u);
        }
    }
    if (ans.size()!=n){
        cout << "NO" << endl;
        return 0;
    }
    for (int i=0;i<n;i++){
        jav[ans[i]]=i+1;
    }
    cout << "YES" << endl;
    for (int i=1;i<=n;i++){
        if (vis[i]==1) cout << "L ";
        else cout << "R ";
        cout << jav[i]  << endl;
    }
}