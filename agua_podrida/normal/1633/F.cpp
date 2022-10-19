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
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 998244353;
const int INF  = 1e9;
const double eps = 0.00000001;

//El intervalo que corresponde al subarbol de v es [in[v],out[v])
//El intervalo que corresponde al heavypath desde el mas alto hasta v es [in[nxt[v]],in[v]]
//Si u y v pertenecen al mismo heavypath (y v es menos profundo que u) el intervalo [in[v],in[u]] corresponde al camino entre u y v.

int t = 0,n,q;
vi sz,in,out,nxt,prof,parent;
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


vll costopadre;

void dfs_sz(int v = 0, int d = 0) {
    sz[v] = 1;
    prof[v] = d;
    for(auto &u: g[v]) {
        dfs_sz(u,d+1);
        costopadre[v] -= costopadre[u];
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]]) {
            swap(u, g[v][0]);
        }
    }
}

//nxt[v] es el nodo ms alto del heavy-path que pasa por v.
void dfs_hld(int v = 0) {
    in[v] = t++;
    for(auto u: g[v]) {
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
    out[v] = t;
}

struct nodo {

    void push(nodo& izq, nodo& der, int x, int y){
        if(!pendiente) return;
        if(x+1 != y)
            izq.pendiente = !izq.pendiente, der.pendiente = !der.pendiente;
        swap(pares,impares);
        swap(sumapares,sumaimpares);
        pendiente = false;
    }

    void upd(ll val, int x, int y){
        pendiente = !pendiente;
    }

    nodo comb(nodo& izq, nodo& der){
        pares = izq.pares + der.pares;
        impares = izq.impares + der.impares;
        sumaimpares = izq.sumaimpares + der.sumaimpares;
        sumapares = izq.sumapares + der.sumapares;
        return *this;
    }

    ll pares,impares;
    ll sumaimpares,sumapares;
    bool pendiente = false;
};


struct segmentTreeLazy {
    segmentTreeLazy (int _n){
        n = _n;
        tree = vector<nodo>(4*n);
    }

    void build(vll& a){
        build(a,1,0,n);
    }

    void build(vll& a, int v, int l, int r){
        if(l+1 == r) {
            if(l == 0) tree[v] = {0,1,0,0,false};
            else tree[v] = {1,0,0,a[l],false};
        }
        else {
            int m = (l+r)/2;
            build(a,2*v,l,m);
            build(a,2*v+1,m,r);
            tree[v].comb(tree[2*v],tree[2*v+1]);
        }
    }

    void upd(int l, int r, ll val){
        upd(l, r, val, 1, 0, n);
    }

    void upd(int l, int r, ll val, int v, int x, int y){
        push(v,x,y);
        if(r <= x or l >= y) return;
        if(l <= x and r >= y) {
            tree[v].upd(val, x, y);
            push(v,x,y);
            return;
        }
        int m = (x+y)/2;
        upd(l, r, val, 2 * v, x, m);
        upd(l, r, val, 2 * v + 1, m, y);
        tree[v].comb(tree[2*v],tree[2*v+1]);
    }

    nodo get(int l, int r){
        return get(l,r,1,0,n);
    }

    nodo get(int l, int r, int v, int x, int y){
        push(v,x,y);
        if(r <= x or l >= y) return nodo();
        if(l <= x and r >= y) return tree[v];
        int m = (x+y)/2;
        nodo izq = get(l,r,2*v,x,m);
        nodo der = get(l,r,2*v+1,m,y);
        return nodo().comb(izq,der);
    }

    void push(int v, int x, int y){
        if(x+1 != y) tree[v].push(tree[2*v],tree[2*v+1],x,y);
        else tree[v].push(tree[0],tree[0],x,y);
    }

    vector<nodo> tree;
    int n;
};

int main(){
    cin>>n;
    sz = in = out = nxt = prof = parent = vi(n);
    g = vvi(n);
    costopadre = vll(n);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        costopadre[u] += i+1;
        costopadre[v] += i+1;
    }
    dfs();
    dfs_sz();
    dfs_hld();
    segmentTreeLazy st(n);
    vll costopadre2(n);
    F0(v,n) costopadre2[in[v]] = costopadre[v];
    st.build(costopadre2);

    int t;
    cin>>t;
    int activados = 1;
    while(t != 3){
        if(t == 1){
            activados++;
            cin>>v;
            v--;
            while(true){
                int w = nxt[v];
                st.upd(in[w],in[v]+1,0);
                if(w == 0) break;
                v = parent[w];
            }
            ll res;
            if(activados != st.get(0,n).impares*2) res = 0;
            else res = st.get(0,n).sumaimpares;
            cout<<res<<'\n';
        }
        else {
            if(activados != st.get(0,n).impares*2)
                cout<<"0\n";
            else {
                vll res;
                F0(v,n){
                    if(st.get(in[v],in[v]+1).impares == 1){
                        res.pb(costopadre[v]);
                    }
                }
                sort(todo(res));
                cout<<res.size()<<' ';
                for(auto x : res) cout<<x<<' ';
                cout<<'\n';
            }
        }
        cin>>t;
    }
}