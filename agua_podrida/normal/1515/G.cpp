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
#define INF 1e9
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)

const ll mod = 1000000007;

const int N = 2e5;
int n,m;
vpll g[N];
vi gr[N],color,toposort;
ll dist[N],dp[N];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

void dfs(int v){
    if(color[v] != -1) return;
    color[v] = 0;
    for(auto u : gr[v]) dfs(u);
    toposort.pb(v);
}

void dfs2(int v, int c, ll d){
    if(color[v] != -1) return;
    color[v] = c;
    dist[v] = d;
    int u;
    ll l;
    for(auto e : g[v]){
        tie(u,l) = e;
        if(color[u] == c) dp[c] = gcd(dp[c],abs(d+l-dist[u]));
        else dfs2(u,c,d+l);
    }
}

void f(){
    cin>>n>>m;
    int u,v;
    ll l;
    F0(i,m){
        cin>>u>>v>>l;
        u--, v--;
        g[u].pb({v,l});
        gr[v].pb(u);
    }
    color = vi(n,-1);
    F0(v,n) dfs(v);
    color = vi(n,-1);
    int c = 0;
    F0R(i,n){
        v = toposort[i];
        if(color[v] != -1) continue;
        dp[c] = 0;
        dfs2(v,c,0);
        c++;
    }

    int q;
    cin>>q;
    ll s,t;
    while(q--){
        cin>>v>>s>>t;
        v--;
        c = color[v];
        if(s % gcd(dp[c],t) == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    f();
}