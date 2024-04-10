#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+10;
ll val[N];
ll ans[N];
vector <pii> g[N];
vector <pii> ind[N];
map <pii,int> mp;
vector <pii> f;
ll visit[N];
ll vis[N];
ll p1=0;
void dfs(ll v){
    visit[v]=1;
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i].F;
        if (visit[u]==0){
            dfs(u);
        }
    }
    p1++;
    f.pb({p1,v});
}
vector <int> mol[N];
vector <int> rass;
void sdf(ll v,ll k,ll vv){
    mol[k].pb(v);
    vis[v]=k;
    val[v]=vv;
    rass.pb(v);
    for (int i=0;i<ind[v].size();i++){
        ll u=ind[v][i].F;
        if (vis[u]==0 && visit[u]==1){
            sdf(u,k,vv-ind[v][i].S);
        }
    }
}

int32_t main(){
    sync;
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    for (int i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        ind[v].pb({u,w});
    }
    ll p2=1;
    for (int i=1;i<=n;i++){
        if (visit[i]==0){
            f.clear();
            p1=0;
            dfs(i);
            sort(f.begin(),f.end());
            reverse(f.begin(),f.end());
            for (int j=0;j<f.size();j++){
                ll v=f[j].S;
                if (vis[v]==0){
                    rass.clear();
                    sdf(v,p2,0);
                    for (auto x : rass){
                        for (auto y : g[x]){
                            if (vis[y.F]==vis[x]){
                                ll zz=__gcd(ans[p2],abs(val[x]-val[y.F]+y.S));
                                ans[p2]=zz;
                            }
                        }
                    }
                    p2++;
                }
            }
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll v,s,l;
        cin >> v >> s >> l;
        ll W=__gcd(s,l);

        v=vis[v];
      //  cout << v << " " << l << " " << ans[v] << endl;
        if (s%__gcd(l,ans[v])!=0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

}