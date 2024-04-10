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
const int INF  = 1e9;
const double eps = 0.00000001;

/*
struct DSU{

    DSU(int _n){
        n = _n;
        color = vi(n);
        tam = vi(n,1);
        donde = vi(n);
        F0(i,n) donde[i] = i;
        comp = vvi(n);
        F0(i,n) comp[i].pb(i);
    }

    int find(int v){
        return donde[v];
    }

    bool unite(int u, int v){
        if(donde[u] == donde[v]){
            return color[u] != color[v];
        }
        int cu = donde[u], cv = donde[v];
        if(tam[cu] < tam[cv]) swap(cu,cv);
        for(auto w : comp[cv]){
            comp[cu].pb(w);
            donde[w] = cu;
            if(color[u] == color[v]) color[w] = (color[w]+1)%2;
        }
        tam[cu] += tam[cv];
        comp[cv].clear();
        return true;
    }

    int n;
    vi color,donde,tam;
    vvi comp;
};

bool algunanotoca(vpi& aux, int x){
    int u,v;
    for(auto e : aux){
        tie(u,v) = e;
        if(u != x and v != x) return true;
    }
    return false;
}

bool messirve2(vpi& aux){
    if(aux.size() <= 1) return false;
    set<int> loop;
    int u,v;
    for(auto e : aux){
        tie(u,v) = e;
        if(u == v) loop.insert(u);
    }
    if(loop.size() >= 2) return true;
    if(loop.size() == 1){
        int x = *loop.begin();
        for(auto e : aux){
            tie(u,v) = e;
            if(u != x and v != x) return true;
        }
    }

    set<int> incidentes;
    for(auto e : aux){
        tie(u,v) = e;
        incidentes.insert(u), incidentes.insert(v);
    }
    if(incidentes.size() < 4)
        return false;
    return (algunanotoca(aux,aux[0].first) and algunanotoca(aux,aux[0].second));
}

bool messirve(vpi& aux){
    if(aux.size() <= 1) return false;
    set<int> loop;
    int u,v;
    for(auto e : aux){
        tie(u,v) = e;
        if(u == v) loop.insert(u);
    }
    if(loop.size() >= 2) return true;
    if(loop.size() == 1){
        int x = *loop.begin();
        for(auto e : aux){
            tie(u,v) = e;
            if(u != x and v != x) return true;
        }
    }

    set<int> incidentes;
    for(auto e : aux){
        tie(u,v) = e;
        incidentes.insert(u), incidentes.insert(v);
    }
    if(incidentes.size() < 4)
        return false;
    if(algunanotoca(aux,aux[0].first) and algunanotoca(aux,aux[0].second)) return true;

    vpi aux2;
    for(auto e : aux) if(e != aux[0]) aux2.pb(e);
    return messirve2(aux2);

}

void d(){
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> E(m);
    int b,u,v;
    F0(i,m){
        cin>>u>>v>>b;
        u--,v--;
        E[i] = {b,u,v};
    }
    sort(E.begin(),E.end());
    reverse(E.begin(),E.end());


    DSU uf(n);
    bool esbipartito = true;
    vi res;
    int i = 0;
    vpi aux;
    while(i < m and get<0>(E[i]) == get<0>(E[0])) {
        tie(b,u,v) = E[i];
        esbipartito &= uf.unite(u,v);
        aux.pb({min(u,v),max(u,v)});
        i++;
    }
    if(messirve(aux)) res.pb(b);

    while(i < m){
        if(!esbipartito) break;
        int j = i;

        vpi aux;
        while(i < m and get<0>(E[j]) == get<0>(E[i])) {
            tie(b,u,v) = E[j];
            j++;
            if(uf.donde[u] == uf.donde[v] and uf.color[u] != uf.color[v]) continue;
            int cu = uf.find(u), cv = uf.find(v);
            int x1 = cu*2+uf.color[u], x2 = cv*2+uf.color[v];
            aux.pb({min(x1,x2),max(x1,x2)});
        }

        if(messirve(aux)) res.pb(b);

        while(i < j) {
            tie(b,u,v) = E[i];
            esbipartito &= uf.unite(u,v);
            i++;
        }
    }


    reverse(res.begin(),res.end());
    if(esbipartito) res.pb(0);
    if(res.empty()){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(auto x : res) cout<<x<<'\n';
}*/

int n,q;
vvi g;
vll res;
vvpi querys;
vvpll dp;

void restar_id(vpll& v){
    F0(i,v.size()) v[i].second -= v[i].first;
}

ll calcpto(vpll& v, int i, ll x){
    ll l = v[i-1].first, r = v[i].first;
    ll m = (v[i].second - v[i-1].second) / (r-l);
    return (x-l) * m + v[i-1].second;
}

void max1(vpll& v){
    if(v[0].second <= 1){
        v = {{0,1},{INF,1}};
        return;
    }
    int i = 0;
    while(v[i+1].second > 1) i++;
    ll l = v[i].first, r = v[i+1].first;
    while(l+1 != r){
        ll mid = (l+r)/2;
        ll y = calcpto(v,i+1,mid);
        if(y > 1) l = mid;
        else r = mid;
    }
    while(v.size() > i+1) v.pop_back();
    if(l != v[i].first)
        v.pb({l,calcpto(v,i+1,l)});
    v.pb({r,1});
    v.pb({INF,1});
}

void transformar(vpll& v){
    restar_id(v);
    max1(v);
}

bool cmp(vpll& a, vpll& b){
    return a.size() < b.size();
}

void mergear(vpll& a, vpll& b){
    vpll res = {{0,a[0].second + b[0].second}};
    int i = 1, j = 1;
    while(i+1 < a.size() or j+1 < b.size()){
        if(a[i].first < b[j].first){
            ll y = calcpto(b,j,a[i].first);
            y += a[i].second;
            res.pb({a[i].first,y});
            i++;
        }
        else if(b[j].first < a[i].first){
            ll y = calcpto(a,i,b[j].first);
            y += b[j].second;
            res.pb({b[j].first,y});
            j++;
        }
        else {
            res.pb({a[i].first,a[i].second + b[j].second});
            i++, j++;
        }
    }
    res.pb({INF,a.back().second + b.back().second});
    a = res;
}

void dfs(int v, int p){
    dp[v] = {{0,0},{INF,0}};
    vvpll hijos;
    for(auto u : g[v]){
        if(u == p) continue;
        dfs(u,v);
        transformar(dp[u]);
        hijos.pb(dp[u]);
    }
    //sort(hijos.begin(),hijos.end(),cmp);
    for(auto h : hijos) mergear(dp[v],h);
    sort(todo(querys[v]));
    int i = 0;
    for(auto quer : querys[v]){
        while(dp[v][i].first <= quer.first) i++;
        res[quer.second] = calcpto(dp[v],i,quer.first);
    }
}

void f(){
    cin>>n;
    g = vvi(n);
    querys = vvpi(n);
    dp = vvpll(n);
    int u,v,k;
    F0(i,n-1){
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin>>q;
    res = vll(q);
    F0(i,q){
        cin>>v>>k;
        v--;
        querys[v].pb({k,i});
    }
    dfs(0,0);
    for(auto x : res) cout<<x<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f();
}