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
const ll INF  = 1e18;
const double eps = 0.00000001;

const int N = 2e5;
ll inv[N+1],criba[N+1];

void eratos(){
    F1(i,N) criba[i] = i;
    for(int x = 2; x*x <= N; x++){
        if(criba[x] != x) continue;
        for(int y = 2*x; y <= N; y += x) criba[y] = x;
    }
    inv[1] = 1;
    for(int i = 2; i <= N; i++) inv[i] = mod - (mod/i) * inv[mod%i] % mod;
}

int n;
vector<map<int,pi>> g;
vi mcm,actual;
ll valmcm,res;

void sumar(int x){
    while(x != 1){
        int p = criba[x];
        actual[p]++;
        valmcm *= p;
        valmcm %= mod;
        maxi(mcm[p],actual[p]);
        x /= p;
    }
}

void restar(int x){
    while(x != 1){
        int p = criba[x];
        valmcm *= inv[p];
        valmcm %= mod;
        actual[p]--;
        x /= p;
    }
}

void dfs(int v, int p){
    int x,y;
    for(auto uv : g[v]){
        int u = uv.first;
        if(u == p) continue;
        tie(x,y) = uv.second;
        restar(y);
        sumar(x);
        dfs(u,v);
        restar(x);
        sumar(y);
    }
}

void dfs2(int v, int p){
    res += valmcm;
    int x,y;
    for(auto uv : g[v]){
        int u = uv.first;
        if(u == p) continue;
        tie(x,y) = uv.second;
        restar(x);
        sumar(y);
        dfs2(u,v);
        restar(y);
        sumar(x);
    }
}

void D(){
    res = 0;
    cin>>n;
    g = vector<map<int,pi>>(n);
    mcm = actual = vi(n+1);
    int u,v;
    ll x,y;
    F0(i,n-1){
        cin>>u>>v>>x>>y;
        u--, v--;
        g[u][v] = {x,y};
        g[v][u] = {y,x};
    }

    dfs(0,0);
    valmcm = 1;
    for(int p = 2; p <= n; p++){
        F0(it,mcm[p]) {
            valmcm *= (ll) p;
            valmcm %= mod;
        }
    }
    actual = mcm;
    dfs2(0,0);

    cout<<res%mod<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    eratos();
    int t;
    cin>>t;
    while(t--) D();
}