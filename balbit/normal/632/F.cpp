#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"NOT MAGIC\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 2500+5;

int a[maxn][maxn];
int lca[maxn][maxn];
int mn[maxn][maxn]; // min on path (u,v)
int dep[maxn];

vector<pii> g[maxn];

void dfs(int v, int p) {
    for (pii u : g[v]) {
        if (u.f != p) {
            dep[u.f] = dep[v] + 1;
            dfs(u.f, v);
        }
    }
}
//namespace DSU{
    int par[maxn];
    vector<int> here[maxn];
    int find(int x) {return x == par[x]?x:par[x] = find(par[x]);}
    void mrg(int a, int b) {
        a = find(a); b = find(b);
        for (int y : here[a]) {
            here[b].pb(y);
        }
        vector<int>().swap(here[a]);
        par[a] = b;
    }
//};

signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n) par[i] = i, here[i].pb(i);
    vector<pair<int, pii> > v;
    REP(i,n) REP(j,n) {
        cin>>a[i][j];
        if (i < j)
            v.pb({a[i][j], {i,j}});
//        if (i != j) {
//            g[i].pb({j, a[i][j]});
//        }
    }
    REP(i,n) REP(j,n) {
        if (a[i][j] != a[j][i] || (i==j && a[i][j] != 0)) {
            GG();
        }
    }
    sort(ALL(v));
    for (auto e : v) {
        int A = e.s.f, B = e.s.s;
        if (find(A) != find(B)) {
            int g1 = find(A), g2 = find(B);
            for (int x : here[g1]) for( int y : here[g2]) {
                if (a[x][y] != e.f) {
                    GG();
                }
            }
            mrg(g1,g2);
//            g[A].pb({B, e.f}); g[B].pb({A, e.f});
//            bug(A,B);
        }
    }

    cout<<"MAGIC"<<endl;



}