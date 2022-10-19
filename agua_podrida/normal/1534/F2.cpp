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

vi orden;
vb visitado;

void dfs1(vvi& g, int v){
    if(visitado[v]) return;;
    visitado[v] = true;
    for(auto u : g[v]) dfs1(g,u);
    orden.pb(v);
}

void dfs2(vvi& g, vi& comp, int v, int c){
    if(comp[v] != -1) return;
    comp[v] = c;
    for(auto u : g[v]) dfs2(g,comp,u,c);
}

vi componentesFuertementeConexas(vvi& g, vvi& gr){
    orden.clear();
    visitado = vb(g.size(),false);
    F0(v,g.size()) dfs1(g,v);
    vi comp(g.size(),-1);
    int c = 0;
    F0R(i,orden.size()){
        int v = orden[i];
        if(comp[v] != -1) continue;
        dfs2(gr,comp,v,c);
        c++;
    }
    return comp;
}

void dfs(vector<set<int>>& g, vb& marca, vb& visite, int v){
    if(visite[v]) return;
    visite[v] = true;
    for(auto u : g[v]){
        marca[u] = true;
        dfs(g,marca,visite,u);
    }
}

vpi inter;

void dfs2(vector<set<int>>& g, vvi& dp, vb& visite, vb marca, int v) {
    if(visite[v]) return;
    visite[v] = true;
    if(marca[v]) return;
    for(auto u : g[v]){
        if(marca[u]) continue;
        dfs2(g,dp,visite,marca,u);
        mini(dp[v][0],dp[u][0]);
        maxi(dp[v][1],dp[u][1]);
    }
    if(dp[v][1] != -1) inter.pb({dp[v][0],dp[v][1]});
}

void comprimir(vpi& inter){
    vi claves;
    for(auto p : inter) claves.pb(p.first), claves.pb(p.second);
    sort(todo(claves));
    unordered_map<int,int> id;
    int j = 0;
    F0(i,claves.size()){
        if(i == 0 or claves[i] != claves[i-1]) id[claves[i]] = j, j++;
    }
    F0(i,inter.size()){
        inter[i].first = id[inter[i].first];
        inter[i].second = id[inter[i].second];
    }
}

void f(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    F0(i,n) cin>>a[i];
    vi caca(m);
    F0(i,m) cin>>caca[i];
    if(m == 1){
        cout<<min(caca[0],1)<<'\n';
        return;
    }
    vvi id(n,vi(m,-1));
    vi ult(m,-1);
    int nodos = 0;
    vvi g,gr;

    F0R(i,n){
        F0(j,m){
            if(a[i][j] != '#') continue;
            g.pb({});
            if(gr.size() < g.size()) gr.pb({});
            id[i][j] = nodos;
            if(j > 0 and ult[j-1] != -1){
                g[nodos].pb(id[ult[j-1]][j-1]);
                gr[id[ult[j-1]][j-1]].pb(nodos);
            }
            if(j+1 < m and a[i][j+1] == '#'){
                g[nodos].pb(nodos+1);
                gr.pb({nodos});
            }
            else if(j+1 < m and ult[j+1] != -1){
                g[nodos].pb(id[ult[j+1]][j+1]);
                gr[id[ult[j+1]][j+1]].pb(nodos);
            }

            if(ult[j] != -1){
                g[nodos].pb(id[ult[j]][j]);
                gr[id[ult[j]][j]].pb(nodos);
                if(ult[j] == i+1) {
                    g[id[ult[j]][j]].pb(nodos);
                    gr[nodos].pb(id[ult[j]][j]);
                }
            }
            ult[j] = i;
            nodos++;
        }
    }
    a.clear();

    vi comp = componentesFuertementeConexas(g,gr);
    int c = 0;
    for(auto ci : comp) maxi(c,ci+1);
    vvi dp(c,{nodos,-1});
    vector<set<int>> dag(c);
    F0(v,nodos){
        for(auto w : g[v]) if(comp[w] != comp[v]) dag[comp[v]].insert(comp[w]);
    }
    F0(j,m){
        if(caca[j] == 0) continue;
        int veo = 0;
        F0R(i,n){
            if(id[i][j] != -1) veo++;
            if(veo == caca[j]) {
                maxi(dp[comp[id[i][j]]][1],j);
                mini(dp[comp[id[i][j]]][0],j);
                break;
            }
        }
    }

    vb visite(c,false);
    vb marca(c,false);
    F0(i,c) if(dp[i][1] != -1) dfs(dag,marca,visite,i);

    dp = vvi(c,{nodos,-1});

    int pongo = 0;
    F0(j,m){
        if(caca[j] == 0) continue;
        int veo = 0;
        F0R(i,n){
            if(id[i][j] != -1) veo++;
            if(veo == caca[j]) {
                if(dp[comp[id[i][j]]][1] == -1) {
                    dp[comp[id[i][j]]] = {pongo,pongo};
                    pongo++;
                }
                break;
            }
        }
    }
    id.clear();

    visite = vb(c,false);
    F0(i,c) dfs2(dag,dp,visite,marca,i);

    marca.clear();
    visite.clear();
    dp.clear();

    sort(todo(inter));
    comprimir(inter);
    if(inter.empty()) {
        cout<<"0\n";
        return;
    }
    int l = inter[0].first;
    int res = 0;
    int i = 0;
    while(i < inter.size()){
        int r = -1;
        while(i < inter.size() and inter[i].first <= l){
            maxi(r,inter[i].second);
            i++;
        }
        if(r+1 > l) res++;
        l = r+1;
    }
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    f();
    return 0;
}