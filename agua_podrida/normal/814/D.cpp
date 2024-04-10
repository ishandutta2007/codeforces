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
#define todo(v) v.begin(),v.end()
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
double PI = acos(-1.0);
#define fora(e,v) for(auto e : v)
const int mod = 1e9+7;
const ll INF  = 1e18;
const double eps = 0.00000001;

void dfs(vvi& g, vi& prof, int v, int d){
    prof[v] = d;
    for(auto u : g[v]) dfs(g,prof,u,d+1);
}

void disco(){
    int n;
    cin>>n;
    vvi g(n);
    vi parent(n,-1);
    vll x(n),y(n),r(n);
    F0(i,n) cin>>x[i]>>y[i]>>r[i];
    F0(i,n){
        int padre = -1;
        F0(j,n){
            if(i == j) continue;
            ll dist2 = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if(r[j] > r[i] and dist2 <= r[j]*r[j] and (padre == -1 or r[j] < r[padre])) padre = j;
        }
        parent[i] = padre;
        if(padre != -1){
            g[padre].pb(i);
        }
    }

    vi prof(n);

    F0(i,n){
        if(parent[i] == -1){
            dfs(g,prof,i,0);
        }
    }

    ll res = 0;
    F0(i,n){
        if(prof[i] <= 1) res += r[i]*r[i];
        else if(prof[i] % 2) res += r[i]*r[i];
        else res -= r[i]*r[i];
    }

    cout<<setprecision(9)<<fixed<<PI*res<<'\n';
}

int main(){
    disco();
    return 0;
}