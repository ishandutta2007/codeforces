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
const int mod = 1e9+7;
const int INF  = 1e18;
const double eps = 0.00000001;

struct nodo {

    void push(nodo& izq, nodo& der, int x, int y){
        if(x+1 != y)
            izq.z += z, der.z += z;
        v += z;
        z = 0;
    }

    void upd(ll val, int x, int y){
        z += val;
    }

    nodo comb(nodo& izq, nodo& der){
        if(izq.v > der.v) i = izq.i;
        else i = der.i;
        v = max(izq.v,der.v);
        return *this;
    }

    int i;
    ll v;
    ll z;
};

struct segmentTreeLazy {
    segmentTreeLazy (int _n){
        n = _n;
        tree = vector<nodo>(4*n);
    }

    void build(){
        build(1,0,n);
    }

    void build(int v, int l, int r){
        if(l+1 == r) tree[v] = {l,0,0};
        else {
            int m = (l+r)/2;
            build(2*v,l,m);
            build(2*v+1,m,r);
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

vvi g;
int t = 0;
vi in,out,padre,revin;


void dfs(int v, int p){
    padre[v] = p;
    in[v] = t++;
    for(auto u : g[v]){
        if(u == p) continue;
        dfs(u,v);
    }
    out[v] = t;
}

void e(){
    int n,k;
    cin>>n>>k;
    int u,v;
    g = vvi(n);
    in = out = padre = revin = vi(n);
    F0(i,n-1){
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    segmentTreeLazy st(n);
    st.build();
    dfs(0,0);
    F0(v,n) revin[in[v]] = v;

    F0(v,n) st.upd(in[v],out[v],1);

    vb proh(n,false);
    int prohibidos = 0;
    ll r = 0;
    ll b = min(n-prohibidos,n/2);
    ll w = n-b-r;
    ll res = (r-b) * w;

    F1(r,k){
        v = st.get(0,n).i;
        v = revin[v];
        while(!proh[v]){
            st.upd(in[v],out[v],-1);
            proh[v] = true;
            prohibidos++;
            v = padre[v];
        }
        b = min(n-prohibidos,n/2);
        w = n-b-r;
        maxi(res,(r-b)*w);
    }

    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    e();
}