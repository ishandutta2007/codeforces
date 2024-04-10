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
#define INF 2e18
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
ll mod = 998244353;


int n,m;
ll x;

struct DSU{

    DSU(int _n, vll& _a){
        n = _n;
        p = vi(n);
        F0(i,n) p[i] = i;
        V = vvi(n);
        F0(i,n) V[i].pb(i);
        a = _a;
        F0(i,n) if(a[i] >= x) alcanza.insert(i);
        vec = vector<map<int,int>>(n);
    }

    int find(int v){
        return p[v];
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(V[u].size() < V[v].size()) swap(u,v);

        for(auto w : V[v]) vec[u].erase(w);
        for(auto w : V[v]) V[u].pb(w), p[w] = u;
        alcanza.erase(v);
        a[u] += a[v] - x;
        if(a[u] < x) alcanza.erase(u);

        for(auto w : vec[v]) if(p[w.first] != u) vec[u][w.first] = w.second;
    }


    int n;
    vi p;
    vvi V;
    vll a;
    vector<map<int,int>> vec;
    set<int> alcanza;
};

map<pi,int> id;

void f(){
    cin>>n>>m>>x;
    vll a(n);
    F0(i,n) cin>>a[i];


    int u,v;
    DSU uf(n,a);
    F0(i,m){
        cin>>u>>v;
        u--, v--;
        id[{min(u,v),max(u,v)}] = i+1;
        uf.vec[u][v] = u;
        uf.vec[v][u] = v;
    }

    ll suma = 0;
    for(auto x : a) suma += x;
    if(suma < x * (ll) (n-1)) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vi res;
    while(res.size() < n-1 and !uf.alcanza.empty()){
        u = *uf.alcanza.begin();
        v = uf.vec[u].begin()->first;
        int w = uf.vec[u][v];
        res.pb(id[{min(v,w),max(v,w)}]);
        uf.unite(w,v);
    }

    for(auto it : id){
        tie(u,v) = it.first;
        if(uf.find(u) != uf.find(v)){
            uf.unite(u,v);
            res.pb(it.second);
        }
    }

    for(auto x : res) cout<<x<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f();
}