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

int n,u,v,t;
vvi g;
vi padre, altura, diam, xpord;
vi tin,tout;
vpi coso;

void dfs(int v, int p, int d){
    tin[v] = t;
    coso.pb({d,v});
    padre[v] = p;
    altura[v] = 0;
    diam[v] = 0;
    int h1 = 0, h2 = 0;
    for(auto u : g[v]){
        if(u == p) continue;
        dfs(u,v,d+1);
        maxi(altura[v],altura[u]+1);
        maxi(h2,altura[u]+1);
        if(h1 < h2) swap(h1,h2);
        maxi(diam[v],diam[u]);
    }
    maxi(diam[v],h1+h2);
    tout[v] = ++t;
}

bool ancestor(int v, int u){
    return tin[v] <= tin[u] and tout[v] >= tout[u];
}

void a(){
    t = 0;
    cin>>n;
    g = vvi(n);
    padre = altura = xpord = diam = tin = tout = vi(n);
    coso.clear();
    F0(i,n-1){
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0,0);
    sort(todo(coso));
    v = coso[n-1].second;
    int i = n-1;
    F0R(d,n){
        while(i >= 0 and coso[i].first == d+1){
            while(!ancestor(v,coso[i].second)) v = padre[v];
            i--;
        }
        xpord[d] = d-(diam[v]+1)/2;
        if(i == n-1) xpord[d] = n;
    }
    vi dporx(n+1);
    int d = 1;
    F1(x,n-1){
        while(xpord[d] < x) d++;
        dporx[x] = d;
    }
    dporx[n] = altura[0];
    F1(x,n) cout<<dporx[x]<<' ';
    cout<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) a();
}