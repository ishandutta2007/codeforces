#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const int mod = 998244353;
const ll INF  = 1e18;
const double eps = 0.00000001;

/*
struct nodo {
    nodo();
    void combinar(nodo b);
};

nodo colgar(nodo a);

vi parent;
vvi g;
vector<nodo> a,padre;
vector<vector<nodo>> pref;

//Saca de g[v] al padre de v. Lo deja en parent[v]
void dfs(int v = 0, int p = 0){
    parent[v] = p;
    for(auto& u : g[v]){
        if(u == p) {
            swap(u,g[v].back());
            g[v].pop_back();
            break;
        }
    }
    for(auto u : g[v]) dfs(u,v);
}

void dfs1(int v = 0){
    for(auto u : g[v]) {
        dfs1(u);
        if(u == g[v][0]) a[v] = colgar(a[u]);
        else a[v].combinar(colgar(a[u]));
        pref[v].pb(a[v]);
    }
}

void dfs2(int v = 0){
    nodo suf;
    F0R(i,g[v].size()){
        int u = g[v][i];
        padre[u] = colgar(a[v]);
        if(i > 0) padre[u].combinar(pref[v][i-1]);
        if(i+1 < g[v].size()) padre[u].combinar(suf);

        if(i+1 < g[v].size()) suf.combinar(colgar(a[u]));
        else suf = colgar(a[u]);

        dfs2(u);
    }
}
*/

struct nodo{

    nodo(){
        n = 0;
        s = 0;
    }

    nodo(ll d){
        n = d;
        s = 0;
    }

    nodo(ll _n, ll _s){
        n = _n;
        s = _s;
    }

    void combinar(nodo b, ll d){
        n += b.n-d;
        s += b.s;
    }

    ll n;
    ll s;
};

nodo colgar(nodo a, ll d){
    return nodo(a.n+d,a.s+a.n);
}

int n;
vi parent;
vll a;
vector<nodo> dp,padre,res;
vector<vector<nodo>> pref;
vvi g;

//Saca de g[v] al padre de v. Lo deja en parent[v]
void dfs(int v = 0, int p = 0){
    parent[v] = p;
    for(auto& u : g[v]){
        if(u == p) {
            swap(u,g[v].back());
            g[v].pop_back();
            break;
        }
    }
    for(auto u : g[v]) dfs(u,v);
}

void dfs1(int v = 0){
    dp[v].n = a[v];
    pref[v].pb(dp[v]);
    for(auto u : g[v]){
        dfs1(u);
        dp[v].combinar(colgar(dp[u],a[v]),a[v]);
        pref[v].pb(dp[v]);
    }
}

void dfs2(int v = 0){
    res[v] = pref[v].back();
    if(v != 0) res[v].combinar(colgar(padre[v],a[v]),a[v]);
    nodo suf(a[v]);
    if(v != 0) suf = colgar(padre[v],a[v]);
    F0R(i,g[v].size()){
        int u = g[v][i];
        padre[u].n = a[v];
        padre[u].combinar(pref[v][i],a[v]);
        padre[u].combinar(suf,a[v]);
        dfs2(u);
        suf.combinar(colgar(dp[u],a[v]),a[v]);
    }
}

void tree_distances(){
    cin>>n;
    g = vvi(n);
    pref = vector<vector<nodo>>(n);
    dp = res = padre = vector<nodo>(n);
    parent = vi(n);
    a = vll(n);
    F0(i,n) cin>>a[i];
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs();
    dfs1();
    dfs2();

    ll mx = 0;
    F0(i,n) maxi(mx,res[i].s);
    cout<<mx<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    tree_distances();
    return 0;
}