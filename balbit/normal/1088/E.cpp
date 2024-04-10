#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 3e5+5;

ll a[maxn], dp[maxn];
vector<ll> vls;
vector<int> g[maxn];
ll goal = -10000000;
ll nof = 0;

void dfs(int v, int p=-1) {
    dp[v] = a[v];
    for (int u : g[v]) {
        if (u!=p) {
            dfs(u,v);
            if (dp[u] > 0) dp[v] += dp[u];
        }
    }
}

void dfs2(int v, int p=-1) {
    dp[v] = a[v];
    for (int u : g[v]) {
        if (u!=p) {
            dfs2(u,v);
            if (dp[u] > 0) dp[v] += dp[u];
        }
    }
    if (dp[v] == goal) ++nof, dp[v]=0;
}

signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n-1) {
        int x,y; cin>>x>>y; x--; y--; g[x].pb(y); g[y].pb(x);
    }
    dfs(0);
    goal=*max_element(dp, dp+n);
    fill(dp,dp+n,0);
#ifdef BALBIT
    REP(i, SZ(vls)) {
        cout<<vls[i]<<' ';
    }
    cout<<endl;
#endif // BALBIT
    dfs2(0);
    cout<<nof*goal<<' '<<nof<<endl;
}