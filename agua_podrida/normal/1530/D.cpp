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
const ll INF  = 1e18;
const double eps = 0.00000001;

int n;

void dfs(vvi& g, vi& c, int v, int comp){
    if(c[v] != -1) return;
    c[v] = comp;
    for(auto u : g[v]) dfs(g,c,u,comp);
}

void marcar_ciclo(vi& b, int v, vb& ciclo){
    int u = v;
    do {
        u = b[u];
        v = b[v], v = b[v];
    } while(u != v);
    do {
        ciclo[u] = true;
        u = b[u];
    } while(u != v);
}

void mergear(deque<int>& a, deque<int>& b){
    if(a.size() >= b.size()){
        for(auto x : b) a.pb(x);
        return;
    }
    else {
        reverse(todo(a));
        for(auto x : a) b.push_front(x);
        swap(a,b);
    }
}

deque<int> preorder(vvi& g, int v, vb& ciclo){
    deque<int> res;
    for(auto u : g[v]){
        if(ciclo[u]) continue;
        deque<int> c = preorder(g,u,ciclo);
        mergear(res,c);
    }
    res.pb(v);
    return res;
}

deque<int> coso(vvi& g, vi& b, int v, vb& ciclo){
    while(!ciclo[v]) v = b[v];
    deque<int> res;
    int u = v;
    do{
        u = b[u];
        deque<int> a = preorder(g,u,ciclo);
        for(auto x : a) res.pb(x);
    } while(u != v);
    return res;
}

void d(){
    cin>>n;
    vi b(n);
    F0(i,n) cin>>b[i],b[i]--;
    vvi g(n), inv(n);
    F0(i,n) g[i].pb(b[i]),g[b[i]].pb(i), inv[b[i]].pb(i);

    vi c(n,-1);
    int comp = 0;
    F0(v,n){
        if(c[v] == -1) {
            dfs(g,c,v,comp);
            comp++;
        }
    }
    vi a(n);
    vb listo(comp);
    vb ciclo(n);
    F0(v,n){
        if(listo[c[v]]) continue;
        listo[c[v]] = true;
        marcar_ciclo(b,v,ciclo);
        deque<int> orden = coso(inv,b,v,ciclo);
        a[orden.back()] = orden.front();
        while(orden.size() >= 2){
            int u = orden.front();
            orden.pop_front();
            a[u] = orden.front();
        }
    }
    int k = 0;
    F0(i,n) if(a[i] == b[i]) k++;
    cout<<k<<'\n';
    for(auto x : a) cout<<x+1<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) d();
    return 0;
}