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
#define INF 1e9
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
const ll mod = 998244353;

struct Edge {
    int u, v;
    ll weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

class unionFindPC {
public:
    unionFindPC(int n);
    int find(int i); // pre, el nodo est
    void unite(int s, int t);
private:
    vector<int> set; //en la posicin de cada elemento est su padre
    vector<int> peso; //peso
};

unionFindPC::unionFindPC(int n) {
    set = vector<int> (n);
    peso = vector<int> (n, 1);
    for(int i = 0; i< n; i++){
        set[i] = i; // al principio cada uno es su propio padre
    }
}

int unionFindPC::find(int i) {
    if(set[i] != i)
        set[i] = find(set[i]);
    return set[i];
}

void unionFindPC::unite(int s, int t) {
    int i = find(s);
    int j = find(t);
    if (i == j) return;
    if (peso[i] <= peso[j]) swap(i, j);
    set[j] = i;
    peso[i] += peso[j];
    peso[j] = 1;// tcnicamente no hace falta ponerlo, por invariante el peso me importa solamente en las races
}

int n,m;
vector<Edge> edges;
vi comp;
set<int> no_marcados;

void dfs(vector<set<int>>& g, int c, unionFindPC& uf, int v){
    if(!no_marcados.count(v)) return;
    no_marcados.erase(v);
    int u = -1;
    while(no_marcados.upper_bound(u) != no_marcados.end()){
        u = *no_marcados.upper_bound(u);
        if(g[v].count(u) or u == v) continue;
        uf.unite(u,v);
        dfs(g,c,uf,u);
    }
}

void c() {
    edges.clear();
    cin>>n>>m;
    F0(i,n) no_marcados.insert(i);
    ll min_sobra = 1e18;
    comp = vi(n,-1);
    vector<set<int>> g(n);
    int u,v;
    ll w;
    F0(i,m){
        cin>>u>>v>>w;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
        edges.pb({u,v,w});
    }

    int c = 0;
    unionFindPC uf(n), uf2(n);
    F0(i,n){
        if(no_marcados.count(i)) dfs(g,c,uf,i), c++;
    }

    sort(todo(edges));

    ll res = 0;
    for(auto e : edges){
        if(uf.find(e.u) != uf.find(e.v)) res += e.weight, uf.unite(e.u,e.v), uf2.unite(e.u,e.v);
        else if(uf2.find(e.u) != uf2.find(e.v)) mini(min_sobra,e.weight);
    }

    ll aristas = (ll) n * (ll) (n-1) / 2;
    aristas -= m;

    if(aristas < n) {
        ll x = 0;
        for(auto e : edges) x = x ^ e.weight;

        res = min(res+x,res+min_sobra);
    }

    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    c();
}