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
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 998244353;

const int N = 600;
ll res[N][N];
ll dp[N];

int n,m;
vvpi g;

void actualizar(int v, ll t){
    int i = 0;
    F0(j,g[v].size()) if(g[v][j].second < g[v][i].second) i = j;
    int u = (int) (g[v][i].first + t)%n;
    ll c = g[v][i].second;
    int j = (i+1) % g[v].size();
    u %= n;
    do {
        if((g[v][j].first+t)%n == u) {
            mini(c,(ll) g[v][j].second);
            j++;
            j %= g[v].size();
        }
        mini(dp[u],t+c);
        u++,c++;
        u %= n;
    } while(u != (int) (g[v][i].first + t)%n);
}

void dijkstra(int src){
    F0(i,n) dp[i] = (ll) INF;
    dp[src] = 0;
    F0(i,n){
        int v = 0;
        while(res[src][v] != -1) v++;
        F0(u,n) if(res[src][u] == -1 and dp[u] < dp[v]) v = u;

        res[src][v] = dp[v];
        actualizar(v,dp[v]);
    }
}

void d(){
    cin>>n>>m;
    F0(i,n) F0(j,n) res[i][j] = -1;
    g = vvpi(n);
    int u,v,c;
    F0(i,m) {
        cin>>u>>v>>c;
        g[u].pb({v,c});
    }
    F0(i,n) sort(todo(g[i]));
    F0(i,n) dijkstra(i);

    F0(i,n) {
        F0(j,n) cout<<res[i][j]<<' ';
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    d();
    return 0;
}