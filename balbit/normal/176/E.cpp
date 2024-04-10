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


void GG(){cout<<"0\n"; exit(0);}

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

const int maxn = 1e5+5;

vector<pii> g[maxn];
int par[maxn], abovew[maxn], L[maxn], R[maxn], dep[maxn], wdep[maxn];
int fa[21][maxn];
vector<int> ord;
int IT = 0;

void dfs1(int v, int p) {
    par[v] = p;
    ord.pb(v);
    L[v] = R[v] = IT++;
    for (pii ed : g[v]) {int u = ed.f;
        if (u != p) {
            dep[u] = dep[v] + 1;
            wdep[u] = wdep[v] + ed.s;
            fa[0][u] = v;
            dfs1(u, v);
            R[v] = R[u];
        }
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a,b);
    // jump b
    int need = dep[b] - dep[a];
    REP(j, 21) {
        if (need & (1<<j)) {
            b = fa[j][b];
        }
    }
    RREP(j, 21) {
        if (fa[j][a] != fa[j][b]) {
            a = fa[j][a]; b = fa[j][b];
        }
    }
    if (a != b) a = fa[0][a];
    return a;
}

ll re = 0;

void upd(int pa, int pb, bool add) {

    int a = ord[pa], b = ord[pb];
    int c = lca(a,b);
    ll sm = wdep[a] + wdep[b] - 2*wdep[c];
    bug(a,b,c,sm,add);
    if (add) {
        re += sm;
    }else{
        re -= sm;
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n-1) {
        int u,v,w; cin>>u>>v>>w; --u; --v;
        g[u].pb({v,w}); g[v].pb({u,w});
    }

    dfs1(0, -1);
    for (int j = 1; j<21; ++j) {
        REP(i,n) {
            fa[j][i] = fa[j-1][fa[j-1][i]];
        }
    }

    set<int> here; // stores the indexes of euler order, NOT THE NODES!!!

    int q; cin>>q;
    while (q--) {
        char cc; cin>>cc;
        if (cc == '?') {
            cout<<re/2<<endl;
        }else if (cc == '+'){
            int v; cin>>v; --v;
            int vp = L[v];
            auto it = here.insert(vp).f;
            if (SZ(here) == 0) continue;
            auto prv = (*it)==(*here.begin())?prev(here.end()) : prev(it);
            auto nxt = *it==*prev(here.end())?here.begin() : next(it);
            upd(*prv, *nxt, 0);
            upd(*prv, vp, 1);
            upd(vp, *nxt, 1);
        }else{
            int v; cin>>v; --v;
            int vp = L[v];
            auto it = here.find(vp);
            if (SZ(here) == 0) continue;
            auto prv = it==here.begin()?prev(here.end()) : prev(it);
            auto nxt = it==prev(here.end())?here.begin() : next(it);
            upd(*prv, *nxt, 1);
            upd(*prv, vp, 0);
            upd(vp, *nxt, 0);
            here.erase(vp);
        }
    }


}