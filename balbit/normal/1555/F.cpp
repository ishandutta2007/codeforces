#include <bits/stdc++.h>
using namespace std;

#define int ll

#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i = n-1; i>=0; --i)

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<"- "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T && x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y){cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT

const int maxn = 5e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

// 1. Find a spanning tree
// 2. For every edge, it is legal iff it covers no edge that was already covered
// 3. If you determine that an edge is legal (ie it covers no done node and xor of its path is 1),
//    mark all the stuff on its path as done
// 4. To determine if a path has done nodes, use euler tour order differences

vector<pii> g[maxn]; // to, value
bool ans[maxn];
int dep[maxn];
int xps[maxn]; // prefix xor of values from the root

namespace DSU{
    int par[maxn];
    int find(int x) {return x == par[x]? x : par[x] = find(par[x]);}
    void mrg(int a, int b) {
        a = find(a); b = find(b);
        par[a] = b;
    }
    void init(){
        REP(i, maxn) par[i] = i;
    }
}

struct BIT{
    int s[maxn];
    void MO(int e, int v) {
        for (++e; e<maxn; e+=e&-e) {
            s[e] += v;
        }
    }
    int QU(int e) {
        int re= 0;
        for (++e; e>0; e-=e&-e) {
            re += s[e];
        }
        return re;
    }
    BIT(){memset(s, 0, sizeof s);}
};

struct edge{
    int a,b,i,x;
};

vector<int> ord, delord;
int pa[maxn];
bool seen[maxn];
int whereord[maxn], wheredelord[maxn]; // where in the order am i, where in the delorder am i
int takedel[maxn]; // up to which point do i take the deletion order?
int fa[20][maxn];

void dfs(int v, int p) {
    seen[v] = 1;
    whereord[v] = SZ(ord); ord.pb(v);
    takedel[v] = SZ(delord)-1;
    pa[v] = p;
    for (pii e : g[v]) {
        int u = e.f;
        if (u != p) {
            dep[u] = dep[v] + 1;
            fa[0][u] = v;
            xps[u] = xps[v] ^ e.s;
            dfs(u,v);
        }
    }
    wheredelord[v] = SZ(delord); delord.pb(v);
}

BIT pos, neg;

int gt(int a) {
    return pos.QU(whereord[a]) - neg.QU(takedel[a]);
}

void rem(int a) {
    bug(a);
    pos.MO(whereord[a], 1);
    neg.MO(wheredelord[a], 1);
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) {
        swap(a,b);
    }
    int k = dep[a] - dep[b];
    REP(i, 18) {
        if (k & (1<<i)) {
            a = fa[i][a];
        }
    }
    assert(dep[a] == dep[b]);
    for (int j=17; j>=0; --j) {
        if (fa[j][a] != fa[j][b]) {
            a = fa[j][a]; b = fa[j][b];
        }
    }
    if (a!=b) a = fa[0][a];
    return a;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    bug(1,2);

    DSU::init();

    int n,m; cin>>n>>m;
    vector<edge> Es;

    REP(i,m) {
        int a,b,x; cin>>a>>b>>x; --a; --b;

        int A = DSU::find(a), B = DSU::find(b);
        if (A!=B) {
            // tree edge!
            g[a].pb({b,x}); g[b].pb({a,x});
            DSU::mrg(a,b);
            ans[i] = 1;
        }else{
            Es.pb({a,b,i,x});
        }
    }


    REP(i,n) {
        if (!seen[i]) {
            bug(i);
            dfs(i, -1);
        }
    }

    REP1(j, 19) {
        REP(i,n) {
            fa[j][i] = fa[j-1][fa[j-1][i]];
        }
    }



    for (edge e : Es) {
        int a = e.a, b = e.b;
        if (dep[a] > dep[b]) swap(a,b);
        if ((xps[a] ^ xps[b]^e.x) == 0) {
            continue;
        }
        int c = lca(a,b);
        int btw = gt(b) + gt(a) - 2*gt(c);
        bug(a,b,c,btw);
        if (btw == 0) {
            // yay!

            while (b != c) {
                bug(b, pa[b]);
                rem(b);
                b = pa[b];
            }
            while(a!=c) {
                bug(a, pa[a]);
                rem(a);
                a = pa[a];
            }

            ans[e.i] = 1;
            bug(e.i);
        }
    }

    REP(i, m) {
        cout<<(ans[i]?"YES":"NO")<<endl;

    }
}