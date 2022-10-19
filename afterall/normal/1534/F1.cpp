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
const int N=4e5+100;
vector <int> g[N];
vector <int> id[N],b[N];
vector <int> ind[N];
vector <pii> f;
ll good[N];
ll visit[N];
ll vis[N];
vector <int> y[N];
ll in[N];
ll p1=0;
void dfs(ll v){
    visit[v]=1;
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i];
        if (visit[u]==0){
            dfs(u);

        }
    }
    p1++;
   // cout << v << " hjklm " << p1 << endl;
    f.pb({p1,v});
}
vector <int> mol[N];
void sdf(ll v,ll k){
    //cout << v << " jk ";
    vis[v]=k;
    mol[k].pb(v);
    for (int i=0;i<ind[v].size();i++){
        ll u=ind[v][i];
        if (vis[u]==0 && visit[u]==1){
            sdf(u,k);
        }
    }
}
void dfsv(ll v){
    vis[v]=1;
    for (auto u : y[v]){
        if (vis[u]==0) dfsv(u);
    }
}
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    ll cnt=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            id[i].pb(cnt++);
            char c;
            cin >> c;
            b[i].pb((c=='#'));
            good[cnt-1]=(c=='#');
        }
    }
    for (int i=1;i<=n;i++) {
        ll x;
        cin >> x;

    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ll v=id[i][j-1];
            bool p = b[i][j-1];
            if (p){
                if (i>1){
                    g[v].pb(id[i-1][j-1]);
                }
                if (i<n){
                    g[v].pb(id[i+1][j-1]);
                }
                if (j>1){
                    g[v].pb(id[i][j-2]);
                }
                if (j<m){
                    g[v].pb(id[i][j]);
                }
            }
            else{
                if (i<n){
                    g[v].pb(id[i+1][j-1]);
                }
            }
        }
    }
    for (int i=0;i<=cnt;i++){
        for (auto u : g[i]){
            ind[u].pb(i);
        }
    }
    ll p2=0;
    for (int i=0;i<=cnt;i++){
        if (visit[i]==0){
            f.clear();
           // cout << i << endl;
            p1=0;
            dfs(i);
            sort(f.begin(),f.end());
            reverse(f.begin(),f.end());
            for (int j=0;j<f.size();j++){
                ll v=f[j].S;

                if (vis[v]==0){
                    sdf(v,p2);

                    p2++;
                }
            }
        }
    }
    for (int i=0;i<=cnt;i++){
        visit[i]=vis[i];
        for (auto u : g[i]){
            if (vis[i]!=vis[u]){
                y[vis[i]].pb(vis[u]);

                in[vis[u]]++;
            }
        }
    }
    queue <int> q;
    vector <int> ras;
    for (int i=1;i<=p2;i++){
        if (in[i]==0) q.push(i);
    }
    while(q.size()){
        ll v=q.front();
        ras.pb(v);
        q.pop();
        for (auto u : y[v]){
            in[u]--;
            if (in[u]==0){
                q.push(u);
            }
        }
    }
    memset(vis,0,sizeof vis);
    ll ans=0;
   // cout << visit[11] << endl;
    for (auto u : ras){
        ll pp=0;
        if (vis[u]) continue;
        for (auto v : mol[u]) if (good[v]) pp=v;
      //  cout << pp << " " << visit[pp] << endl;
        if (pp==0) continue;
        ans++;
        dfsv(u);
    }
    kill(ans);
}