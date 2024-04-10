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
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

int n,m;
vvi g;
vi path_res;
vvi tengo;
vpi pairing_res;
vb visited;

void dfs1(vvi& g, vi& path, int v){
    visited[v] = true;
    if(!path_res.empty()) return;
    path.pb(v);
    if(path.size()*2 >= n) path_res = path;
    for(auto u : g[v]){
        if(visited[u]) continue;
        dfs1(g,path,u);
    }
    path.pop_back();
}

void dfs2(vvi& g, int v){
    visited[v] = true;
    priority_queue<pi> q;
    vi hijos;
    for(auto u : g[v]){
        if(visited[u]) continue;
        dfs2(g,u);
        hijos.pb(u);
        q.push({tengo[u].size(),u});
    }
    while(q.size() >= 2){
        int a = q.top().second;
        q.pop();
        int b = q.top().second;
        q.pop();
        pairing_res.pb({tengo[a].back(),tengo[b].back()});
        tengo[a].pop_back();
        tengo[b].pop_back();
        if(!tengo[a].empty()) q.push({tengo[a].size(),a});
        if(!tengo[b].empty()) q.push({tengo[b].size(),b});
    }
    tengo[v].pb(v);
    for(auto u : hijos){
        if(tengo[u].size() > tengo[v].size()) swap(tengo[u],tengo[v]);
        while(!tengo[u].empty()) tengo[v].pb((int) tengo[u].back()), tengo[u].pop_back();
    }
}

void pairs_of_pairs(){
    cin>>n>>m;
    g = vvi(n);
    visited = vb(n,false);
    tengo = vvi(n);
    path_res.clear();
    pairing_res.clear();
    int u,v;
    F0(i,m){
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi path;
    dfs1(g,path,0);
    if(!path_res.empty()){
        cout<<"PATH\n";
        cout<<path_res.size()<<'\n';
        for(auto v : path_res) cout<<v+1<<' ';
        cout<<'\n';
        return;
    }

    visited = vb(n,false);
    dfs2(g,0);

    cout<<"PAIRING\n";
    cout<<pairing_res.size()<<'\n';
    for(auto w : pairing_res) cout<<w.first+1<<' '<<w.second+1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) pairs_of_pairs();
}