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
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
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
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

vi ciclos;

void dfs(vector<multiset<int>>& g, int v, int d){
    if(v == 1 and d > 0) {
        ciclos[d]++;
        return;
    }
    int u = *g[v].begin();
    g[v].erase(g[v].find(u));
    g[u].erase(g[u].find(v));
    dfs(g,u,d+1);
}

ll DP[4001],DPP[4001],AUX[4001];

ll& dp(int i){
    return DP[i+2000];
}

ll& dpp(int i){
    return DPP[i+2000];
}

int n,m;

void actualizar(int len){
    REP(i,-n,n) dpp(i) = dp(i);
    REP(i,-n,n) {
        if(i - len >= -n) dpp(i) += dp(i-len);
        if(i + len <= n) dpp(i) += dp(i+len);
        dpp(i) %= mod;
    }
    REP(i,-n,n) dp(i) = dpp(i);
}

void actualizar2(int len){
    REP(i,-n,n) dpp(i) = 0;
    REP(i,-n,n) {
        if(i - len >= -n) dpp(i) += dp(i-len);
        if(i + len <= n) dpp(i) += dp(i+len);
        dpp(i) %= mod;
    }
    REP(i,-n,n) dp(i) = dpp(i);
}

void a(){
    cin>>n>>m;
    vector<multiset<int>> g(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    ciclos = vi(n+1);
    while(!g[1].empty()) dfs(g,1,0);

    REP(i,-n,n) dp(i) = 0;
    dp(0) = 1;
    F1(i,n){
        if(ciclos[i] <= 1) continue;
        F0(j,ciclos[i]-1) actualizar(i);
    }

    ll res = 0;

    F1(i,n){
        if(ciclos[i] == 0) continue;
        F0(k,4001) AUX[k] = DP[k];
        F1(j,n){
            if(i == j) continue;
            if(ciclos[j] == 0) continue;
            actualizar(j);
        }
        ll resi = 0;
        REP(k,-i+2,i-2) resi += dp(k);
        resi %= mod;
        resi *= 2;
        resi *= ciclos[i];
        resi %= mod;
        res += resi;
        res %= mod;
        F0(k,4001) DP[k] = AUX[k];
    }

    F0(k,4001) DP[k] = 0;
    dp(0) = 1;
    F1(i,n){
        if(ciclos[i] <= 1) continue;
        F0(j,ciclos[i]-1) actualizar2(i);
    }

    F1(i,n){
        if(ciclos[i] == 0) continue;
        F0(k,4001) AUX[k] = DP[k];
        F1(j,n){
            if(i == j) continue;
            if(ciclos[j] == 0) continue;
            actualizar2(j);
        }
        ll resi = 0;
        resi += dp(-i+1);
        resi += dp(i-1);
        resi %= mod;
        resi *= 2;
        resi *= ciclos[i];
        resi %= mod;
        res += resi;
        res %= mod;
        F0(k,4001) DP[k] = AUX[k];
    }

    F0(k,4001) DP[k] = 0;
    dp(0) = 1;
    F1(i,n){
        F0(j,ciclos[i]) actualizar2(i);
    }
    res += dp(0);
    res %= mod;
    if(res < 0) res += mod;
    cout<<res<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a();
}