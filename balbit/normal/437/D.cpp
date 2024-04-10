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

ll inv (ll b){
    return b==1?1:(mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

int par[maxn];
int sz[maxn];
void setup(int n) {
    REP(i,n) par[i]=i, sz[i]=1;
}
int find(int x){
    return x==par[x]?x:par[x] = find(par[x]);
}
void merge(int a, int b) {
    a = find(a); b = find(b);
    sz[a] += sz[b];
    par[b] = a;
}

int a[maxn];
bool done[maxn];
vector<int> g[maxn];

signed main(){
    IOS();
    int n, m; cin>>n>>m;
    setup(n);
    vector<pii> tmp;
    REP(i,n) cin>>a[i], tmp.pb({a[i],i});
    sort(ALL(tmp), greater<pii>());
    REP(i,m) {
        int x, y; cin>>x>>y; --x; --y;
        g[x].pb(y); g[y].pb(x);
    }
    double re = 0;
    REP(it,n) {
        int v = tmp[it].s;
        bug(v);
        vector<ll> szs;
        ll sig = 1;
        ll tmpre = 0;
        for (int u : g[v]) {
            if (done[u] && find(u)!=find(v)) {
                szs .pb( sz[find(u)] );
                bug(v, u, szs.back());
                tmpre += (ll)szs.back() * sig;
                sig += szs.back();
                merge(u,v);
            }
        }
        re += tmpre / (double) (n*(ll)(n-1)) * a[v];
        done[v] = 1;
    }
    re *= 2;
    cout<<fixed<<setprecision(6)<<re<<endl;
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}