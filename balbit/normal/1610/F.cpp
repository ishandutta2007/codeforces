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


int ori[maxn];

struct ED{
    int u, i;
    bool org; // original direction or not
};

int n,m;
pii edges[maxn];
int wei[maxn];

struct chain{
    int v, u; // starting and ending
    vector<int> ed;
    void setdir(bool b) {
        if (b) {
            for (int x : ed) ori[x] ^= 1;
        }
    }
};

struct graph{
    vector<ED> g[maxn]; // {to, index}
    int ptr[maxn]; // dfs position
    int deg[maxn];
    bool used[maxn];
    void add(int u, int v, int id) {
        g[u].pb({v,id,1});
        g[v].pb({u,id,0});
        edges[id] = (pii{u,v});

        deg[u]++; deg[v]++;
    }
    chain build;
    void dfs(int v) {
        for (int &i = ptr[v]; i < SZ(g[v]); ++i) {
            if (used[g[v][i].i]) continue;
            used[g[v][i].i] = 1;
            --deg[v]; --deg[g[v][i].u];
            build.ed.pb(g[v][i].i);
            ori[g[v][i].i] ^= g[v][i].org;
            dfs(g[v][i].u);
            return;
        }
        build.u = v;
    }
    vector<chain> getchains(){
        vector<chain> re;
        REP(i,n) {
            while (ptr[i] != SZ(g[i]) && deg[i] % 2 == 1) {
                build = {i, i, {}};
                dfs(i);
                if (build.v != build.u) {
                    re.pb(build);
                }
            }
        }
        REP(i,n) {
            while (ptr[i] != SZ(g[i])) {
                build = {i, i, {}};
                dfs(i);
                if (build.v != build.u) {
                    assert(0);
                }
            }
        }
        return re;
    }
    graph(){
        memset(used, 0, sizeof used);
        memset(ptr, 0, sizeof ptr);
        memset(deg, 0, sizeof deg);
    }
};

pii who[maxn]; // {chain id, 0:is v; 1: is u}

vector<pii> rel[maxn];
int flp[maxn];

void df2(int v, bool b) {
    flp[v] = b;
    for (pii p : rel[v]) {
        if (flp[p.f] == -1) {
            df2(p.f, b ^ p.s);
        }
    }
}

int dd[maxn];
int dar[maxn];

signed main(){
    IOS();

    cin>>n>>m;

    graph g1, g2;

    REP(i,m) {
        int a,b,c; cin>>a>>b>>c; --a; --b;
        (c==1?g1:g2).add(a,b,i);
        wei[i] = c;
    }

    vector<chain> c1 = g1.getchains(), c2 = g2.getchains();
    fill(who, who+n+1, pii{-1, 0} );
    REP(i, SZ(c1)) {
        auto &c = c1[i];
        who[c.v] = {i, 0};
        who[c.u] = {i, 1};
    }

    for (auto &c : c2) {
        if (who[c.v].f != -1 && who[c.u].f != -1) {
            rel[who[c.v].f].pb({who[c.u].f, who[c.v].s ^ who[c.u].s ^ 1});
            rel[who[c.u].f].pb({who[c.v].f, who[c.v].s ^ who[c.u].s ^ 1});
        }
    }

    memset(flp, -1, sizeof flp);

    REP(i, SZ(c1)) {
        if (flp[i] == -1) {
            df2(i, 0);
        }
        auto &c = c1[i];
        c.setdir(flp[i]);
        bug(c.v, c.u, flp[i]);
        if (!flp[i]) {
            dd[c.v] = 1; dd[c.u] = -1;
        }else{
            dd[c.v] = -1; dd[c.u] = 1;
        }
    }

    for (auto &c : c2) {
        if (who[c.v].f != -1 && who[c.u].f != -1) {
            if (dd[c.v] == -1) {
                assert(dd[c.u] == 1);
                dd[c.v] += 2; dd[c.u] += -2;
            }else{
                assert(dd[c.u] == -1);
                dd[c.v] += -2; dd[c.u] += 2;
                c.setdir(1);
            }
        }
    }

    for (auto &c : c2) {
        if (who[c.v].f != -1 && who[c.u].f != -1) {
        }else{
            dd[c.v] += 2; dd[c.u] += -2;
            if ((dd[c.v]&1) || (dd[c.u]&1)) {
                if (abs(dd[c.v]) != 1 && abs(dd[c.u]) != 1) {
                    dd[c.v] += -4; dd[c.u] += 4;
                    c.setdir(1);
                }
            }
        }
    }
    int re= 0 ;
    REP(i,n) {
        bug(i, dd[i]);
        re += abs(dd[i]) == 1;
    }
    cout<<re<<endl;
    REP(i,m) {
        cout<<(ori[i]?1:2);
        if (!ori[i]) {
            dar[edges[i].s] += wei[i];
            dar[edges[i].f] -= wei[i];
        }else{
            dar[edges[i].f] += wei[i];
            dar[edges[i].s] -= wei[i];
        }
    }
    REP(i,n) {
        bug(i, dar[i]);
    }
}