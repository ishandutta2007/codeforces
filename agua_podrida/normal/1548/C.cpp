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
const int mod = 1e9+7;
const int INF  = 1e9;
const double eps = 0.00000001;


/*
//El ejemplo calcula para cada vertice la suma de las distancias a todos los vertices (problema del CSES)

struct nodo{
    //caso base para las hojas
    nodo(){
        l = h1 = h2 = 0;
    }

    nodo(int _l, int _h1, int _h2){
        l = _l;
        h1 = _h1;
        h2 = _h2;
    }

    //funcion para combinar dos subarboles (que tienen la misma raiz)
    void combinar(nodo b){
        maxi(l,b.l);
        maxi(l,h1+b.h1);
        maxi(h2,b.h2);
        maxi(h2,min(h1,b.h1));
        maxi(h1,b.h1);
    }

    int l,h1,h2;
};

//Dado un subarbol A doy el valor para el subarbol que es un vertice v que tiene A como unico hijo
nodo colgar(nodo a, int d){
    return nodo(max(a.l,d+a.h1),max(0,a.h1+d),0);
}

int t = 0;
int n;
vi peso_parent,in,out;
vector<nodo> a,padre;
vector<vector<nodo>> pref;
vvi g,peso,parent;


//Saca de g[v] al padre de v. Lo deja en parent[v]
void dfs(int v = 0, int p = 0){
    in[v] = t++;
    parent[v][0] = p;
    F0(i,g[v].size()){
        int& u = g[v][i];
        if(u == p) {
            peso_parent[v] = peso[v][i];
            swap(u,g[v].back());
            swap(peso[v][i],peso[v].back());
            peso[v].pop_back();
            g[v].pop_back();
            break;
        }
    }
    for(auto u : g[v]) dfs(u,v);
    out[v] = t;
}

void dfs1(int v = 0){
    pref[v].pb(a[v]);
    for(auto u : g[v]){
        dfs1(u);
        a[v].combinar(colgar(a[u],peso_parent[u]));
        pref[v].pb(a[v]);
    }
}

void dfs2(int v = 0){
    nodo suf;
    if(v != 0) suf = colgar(padre[v],peso_parent[v]);
    F0R(i,g[v].size()){
        int u = g[v][i];
        padre[u].combinar(pref[v][i]);
        padre[u].combinar(suf);
        dfs2(u);
        suf.combinar(colgar(a[u],peso_parent[u]));
    }
}

void binary_lift(){
    F0(v,n) F0(j,21) parent[v][j+1] = parent[parent[v][j]][j];
}

bool es_ancestro(int u, int v){
    return in[u] <= in[v] and out[u] >= in[v];
}

int hijo_lca(int u, int v){
    F0R(j,22){
        if(!es_ancestro(parent[u][j],v)) u = parent[u][j];
    }
    return u;
}

int lca(int u, int v){
    if(es_ancestro(u,v)) return u;
    return parent[hijo_lca(u,v)][0];
}

int caso_lca(int w, int u, int v){
    u = hijo_lca(u,w);
    v = hijo_lca(v,w);
    return abs(a[u].l - a[v].l);
}

int camino(int u, int w){
    if(u == w or parent[u][0] == w) return INF;
    if(a[u].l >= padre[parent[u][0]].l)
        return a[u].l - padre[parent[u][0]].l;
    //busco el u mas alto tal que: a[u].l < padre[parent[u][0]].l
    F0R(j,22){
        int v = parent[u][j];
        if(!es_ancestro(parent[v][0],w) and a[v].l < padre[parent[v][0]].l) u = v;
    }
    int res = abs(a[u].l - padre[parent[u][0]].l);
    u = parent[u][0];
    if(parent[u][0] != w) mini(res,abs(a[u].l - padre[parent[u][0]].l));
    return res;
}

void teleferico(){
    cin>>n;
    g = peso = vvi(n);
    in = out = peso_parent = vi(n);
    pref = vector<vector<nodo>>(n);
    a = padre = vector<nodo>(n);
    parent = vvi(n,vi(22));
    int u,v,w;
    F0(i,n-1){
        cin>>u>>v>>w;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
        peso[u].pb(w);
        peso[v].pb(w);
    }
    dfs();
    dfs1();
    dfs2();
    binary_lift();
    int q;
    cin>>q;
    while(q--){
        cin>>u>>v;
        u--, v--;
        if(in[u] > in[v]) swap(u,v);
        if(parent[v][0] == u) {
            cout<<"-1\n";
            continue;
        }
        int res = INF;
        w = lca(u,v);
        if(w != u) res = caso_lca(w,u,v);
        mini(res,camino(u,w));
        mini(res,camino(v,w));
        cout<<res<<'\n';
    }
}
*/

//tiras una lista de operaciones y querys
//las operaciones son agregar o quitar arista (PRE: solo agregas aristas que no estaban y sacas aristas que si)
//las querys son sobre el DSU, en este ejemplo pregunta sobre el tamano de la componente conexa de un vertice, pero se puede cambiar en solve()
//hay que darle un vector de "coso". Las operaciones/querys se indican con '+','-' y '?'.
//n es la cantidad de nodos y m la cantidad de eventos.

ll powmod(ll a, int exp){
    if(exp == 0) return 1;
    ll b = powmod(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2) b *= a;
    b %= mod;
    return b;
}

ll calcinv(ll a){
    return powmod(a,mod-2);
}

const int N = 3e6;

ll fact[N+1],invfact[N+1],inv[N+1];

void precalc(){
    inv[1] = 1;
    for(int i = 2; i <= N; ++i)
        inv[i] = mod - (mod/i) * inv[mod%i] % mod;

    fact[0] = 1;
    F1(i,N) fact[i] = (fact[i-1]*i) % mod;

    invfact[0] = 1;
    F1(i,N) invfact[i] = (invfact[i-1] * inv[i]) % mod;
}

ll comb(int n, int k){
    ll res = fact[n];
    res *= invfact[k];
    res %= mod;
    res *= invfact[n-k];
    res %= mod;
    return res;
}

void c(){
    int n,q;
    cin>>n>>q;
    vll dp(3),dpp(3);
    vll res(q,1);
    vpi query(q);
    F0(i,q){
        cin>>query[i].first;
        query[i].second = i;
    }
    sort(todo(query));
    int i = 0;
    F0(m,3) dp[m] = n;
    F1(x,3*n-1){
        dpp[0] = comb(3*n,x+1) - 2*dp[0] - dp[1];
        dpp[0] %= mod;
        dpp[0] *= inv[3];
        dpp[0] %= mod;
        if(dpp[0] < 0) dpp[0] += mod;
        dpp[1] = (dpp[0] + dp[0]) % mod;
        dpp[2] = (dpp[1] + dp[1]) % mod;
        swap(dp,dpp);
        while(i < q and query[i].first == x){
            ll resi = dp[0];
            resi += comb(3*n,x);
            resi %= mod;
            res[query[i].second] = resi;
            i++;
        }
    }
    for(auto x : res) cout<<x<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    c();
    return 0;
}