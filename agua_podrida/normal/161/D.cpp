#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)

int n,k;
vvi g;
vi malos,d,sz,res,dp;
vb checked;

void dfs(int v, int p){
    for(auto u : g[v]) {
        if(u == p) continue;
        dfs(u,v);
        sz[v] += sz[u];
    }
    sz[v]++;
}

void bfs(){
    d = vi(n,-1);
    queue<pi> q;
    for(auto ki : malos) q.push({ki,0});
    int v,dist;
    while(!q.empty()){
        tie(v,dist) = q.front();
        q.pop();
        if(d[v] != -1) continue;
        d[v] = dist;
        for(auto u : g[v]) q.push({u,dist+1});
    }
}

map<int,int> dp1;
int res1 = 0;

void dfs1(int v, int p, int dist){
    res1 += dp1[k-dist];
    for(auto u : g[v]){
        if(u == p) continue;
        if(checked[u]) continue;
        dfs1(u,v,dist+1);
    }
}

void dfs2(int v, int p, int dist){
    dp1[dist]++;
    for(auto u : g[v]){
        if(u == p) continue;
        if(checked[u]) continue;
        dfs2(u,v,dist+1);
    }
}

int solve(int v){
    dp1.clear();
    dp1[0] = 1;
    for(auto u : g[v]){
        if(checked[u]) continue;
        dfs1(u,v,1);
        dfs2(u,v,1);
    }
    checked[v] = true;
}

int buscarCentroid(int v){
    bool esCentroid = false;
    while(!esCentroid){
        esCentroid = true;
        for(auto u : g[v]) {
            if(checked[u]) continue;
            if(2*sz[u] > sz[v]) {
                sz[v] -= sz[u];
                sz[u] += sz[v];
                v = u;
                esCentroid = false;
                break;
            }
        }
    }
    return v;
}

int centroid(int v){
    v = buscarCentroid(v);
    solve(v);
    for(auto u : g[v]) {
        if(checked[u]) continue;
        centroid(u);
    }
}

void game_on_tree(){
    cin>>n;
    g.resize(n);
    sz.resize(n);
    res.resize(n);
    dp.resize(n);
    checked = vb(n,false);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin>>k;
    malos.resize(k);
    F0(i,k) cin>>malos[i];
    F0(i,k) malos[i]--;
    bfs();
    dfs(0,-1);
    centroid(0);
    F0(i,n) cout<<res[i]<<' ';
    cout<<'\n';
}

void distance_in_tree(){
    cin>>n>>k;
    g.resize(n);
    sz.resize(n);
    checked = vb(n,false);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    centroid(0);
    cout<<res1<<'\n';
}

int main() {
    //freopen("../evolution/evolution-11-common-endings.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    distance_in_tree();
    return 0;
}