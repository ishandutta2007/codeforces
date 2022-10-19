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

using namespace std;

const ll mod = 1e9+7;

void dfs(vvi& g, vi& dist, int v, int d){
    if(dist[v] != -1) return;
    dist[v] = d;
    for(auto u : g[v]) dfs(g,dist,u,d+1);
}

void move_and_swap(){
    int n;
    cin>>n;
    vvi g(n+1);
    vll a(n+1);
    int u;
    REP(v,2,n){
        cin>>u;
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i,2,n) cin>>a[i];

    vi dist(n+1,-1);
    dfs(g,dist,1,0);

    vvi porDis(n);
    F1(v,n) porDis[dist[v]].pb(v);

    vll dp(n+1,-INF),dp1(n,-INF),dp2(n,-INF);

    int d = n-1;
    while(porDis[d].empty()) d--;
    for(auto v : porDis[d]) maxi(dp1[d],a[v]);
    for(auto v : porDis[d]) maxi(dp2[d],-a[v]);
    for(auto v : porDis[d]) dp[v] = max(a[v]+dp2[d],dp1[d]-a[v]);
    d--;
    while(d >= 0){
        for(auto v : porDis[d]){
            for(auto h : g[v]){
                if(dist[h] == d-1) continue;
                maxi(dp1[d],dp[h]+a[v]);
                maxi(dp2[d],dp[h]-a[v]);
            }
        }
        ll lb = INF,ub = -INF;
        for(auto v : porDis[d]) mini(lb,a[v]);
        for(auto v : porDis[d]) maxi(ub,a[v]);
        for(auto v : porDis[d]){
            for(auto h : g[v]){
                if(dist[h] == d-1) continue;
                maxi(dp[v],dp[h] + max(ub-a[v],a[v]-lb));
            }
        }
        for(auto v : porDis[d]){
            maxi(dp[v],dp1[d]-a[v]);
            maxi(dp[v],dp2[d]+a[v]);
        }
        d--;
    }
    cout<<dp[1]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) move_and_swap();
}