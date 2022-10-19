#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

struct scc{
    int n;
    vector<vi> edg, redg;
    vector<bool> vis;
    stack<int> S;
    vi comp, rep;
    void init(int _n){n=_n;edg.rsz(n); redg.rsz(n);vis.rsz(n);comp.resize(n, -1);}
    void ae(int v, int u){
        edg[v].pb(u);
        redg[u].pb(v);
    }
    void dfs(int v){
        vis[v]=1;
        for(int u:edg[v])if(!vis[u])dfs(u);
        S.push(v);
    }
    void dfs2(int v, int c){
        vis[v]=0;
        comp[v]=c;
        for(int u:redg[v])if(vis[u])dfs2(u, c);
    }
    void solve(){
        for(int i=0; i<n; i++)if(!vis[i])dfs(i);
        while(sz(S)){
            if(vis[S.top()])dfs2(S.top(), S.top()), rep.pb(S.top());
            S.pop();
        }
    }
};
struct sat2{
    int n;
    vi val;
    scc g;
    sat2(int _n): n(_n){g.init(2*n);val.resize(n, -1);}
    void any(int v, int u){
        g.ae((v+n)%(n+n), u);
        g.ae((u+n)%(n+n), v);
    }
    void both(int v, int u){
        g.ae((v+n)%(n+n), v);
        g.ae((u+n)%(n+n), u);
    }
    void imply(int v, int u){
        g.ae(v, u);
    }
    void either(int v, int u){
        g.ae(v, (u+n)%(n+n));
        g.ae(u, (v+n)%(n+n));
        g.ae((v+n)%(n+n), u);
        g.ae((u+n)%(n+n), v);
    }
    bool solve(){
        g.solve();
        for(int i=0; i<n; i++)if(g.comp[i]==g.comp[i+n])return 0;
        vi lab(n+n);
        for(int i=0; i<g.rep.size(); i++)lab[g.rep[i]]=i+1;
        for(int i=0; i<n; i++)val[i]=(lab[g.comp[i]]<lab[g.comp[i+n]]);
        return 1;
    }
};
const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    sat2 g(n);
    for(int i=0; i<m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        u--;
        v--;
        g.either(u, v+n*c);
    }
    if(!g.solve()){
        cout<<"Impossible";
        return 0;
    }
    vi V;
    for(int i=0; i<n; i++)if(g.val[i])V.pb(i+1);
        cout<<sz(V)<<"\n";
        for(int i:V)cout<<i<<" ";
}