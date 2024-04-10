#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

#define int ll

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

const int maxn = 1e5+5;

bool QTYPE=0;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { 
        if (QTYPE) return p<o.p;
        return k < o.k; 
    }
};

struct LineContainer : multiset<Line > {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        QTYPE=1; auto l = *lower_bound({0,0,x}); QTYPE = 0;
        return l.k * x + l.m;
    }
};

LineContainer * hull[maxn];
int a[maxn], b[maxn];

vector<int> g[maxn];
int sz[maxn];
int dp[maxn];

void dfs(int v, int p=-1){ 
    int bg = 0, id = -1;
    sz[v] = 1;
    hull[v] = new LineContainer();
    for (int u : g[v]){
        if (u!=p){
            dfs(u,v);
            MX(bg, sz[u]); if (bg==sz[u]) id = u, hull[v]=hull[u];
            sz[v]+=sz[u];
        }
    }

    for (int u : g[v]){
        if (u!=p && u!=id){
            for (Line x : *hull[u]) {
                hull[v]->add(x.k, x.m);
            }
        }
    }
    if (sz[v] == 1){
        dp[v] = 0;
    }else{
        dp[v] = hull[v]->query(a[v]);
    }
    
    hull[v]->add(b[v], dp[v]);
    // bug(v);
    // for (Line x : *hull[v]){
    //     bug(x.k, x.m);
    // }
}

main(){
    IOS();
    int n; cin>>n;
    REP(i,n) cin>>a[i], a[i] = -a[i]; REP(i,n) cin>>b[i];
    REP(i,n-1){
        int x,y; cin>>x>>y; g[x-1].pb(y-1); g[y-1].pb(x-1);
    }
    dfs(0);
    REP(i,n){
        cout<<-dp[i]<<' ';
    }
}