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
const ll mod = 1000000007;
const ll INF  = 1e9;
const double eps = 0.000000001;

void invertirAristas(vvi& listaDeAdyacencias){
    vvi invertido(listaDeAdyacencias.size());
    F0(i,listaDeAdyacencias.size()) F0(j,listaDeAdyacencias[i].size())
            invertido[listaDeAdyacencias[i][j]].eb(i);
    listaDeAdyacencias = invertido;
}

void hacerDfs(vvi& listaDeAdyacencias, int v, vb& visitados, vi& orden){
    if(visitados[v]) return;
    visitados[v] = true;
    F0(i,listaDeAdyacencias[v].size()) {
        hacerDfs(listaDeAdyacencias,listaDeAdyacencias[v][i],visitados,orden);
    }
    orden.eb(v);
}

vi ordenDfs(vvi& listaDeAdyacencias){
    vb visitados(listaDeAdyacencias.size(),false);
    vi orden;
    F0(v,listaDeAdyacencias.size())
        hacerDfs(listaDeAdyacencias,v,visitados,orden);
    return orden;
}

vvi componentesFuertementeConexas(vvi& listaDeAdyacencias){
    vi orden = ordenDfs(listaDeAdyacencias);
    reverse(orden.begin(),orden.end());
    vvi componentes;
    vb visitados(listaDeAdyacencias.size(),false);
    invertirAristas(listaDeAdyacencias);
    F0(v,orden.size()){
        vi componente;
        hacerDfs(listaDeAdyacencias,orden[v],visitados,componente);
        if(!componente.empty()) componentes.eb(componente);
    }
    invertirAristas(listaDeAdyacencias);
    return componentes;
}


void f(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    F0(i,n) cin>>a[i];
    vi caca(m);
    F0(i,m) cin>>caca[i];
    int nodos = 0;

    vector<set<pi>> dp(m);
    F0(i,n) {
        F0(j,m){
            if(a[i][j] == '#'){
                dp[j].insert({i,nodos});
                nodos++;
            }
        }
    }
    vvi g(nodos);

    F0(i,n){
        F0(j,m){
            if(a[i][j] != '#') continue;
            int v = dp[j].lower_bound({i,-1})->second;
            if(j > 0){
                auto it = dp[j-1].lower_bound({i,-1});
                if(it != dp[j-1].end()) {
                    int u = it->second;
                    g[v].pb(u);
                }
            }
            if(j+1 < m){
                auto it = dp[j+1].lower_bound({i,-1});
                if(it != dp[j+1].end()) {
                    int u = it->second;
                    g[v].pb(u);
                }
            }
            auto it = dp[j].lower_bound({i+1,-1});
            if(it != dp[j].end()) {
                int u = it->second;
                g[v].pb(u);
            }
            --it;
            if(it != dp[j].begin()){
                --it;
                if(it->first == i-1){
                    int u = it->second;
                    g[v].pb(u);
                }
            }
        }
    }

    vvi CC = componentesFuertementeConexas(g);
    vi comp(nodos);
    F0(i,CC.size()){
        for(auto v : CC[i]) comp[v] = i;
    }

    vb tienepapi(CC.size(),false);
    F0(v,nodos){
        for(auto w : g[v]) if(comp[v] != comp[w]) tienepapi[comp[w]] = true;
    }


    int res = 0;
    for(auto b : tienepapi) if(!b) res++;

    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    f();
    return 0;
}