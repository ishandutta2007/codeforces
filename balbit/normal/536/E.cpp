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

struct P{
    int l, r; // values of l and r are not counted
    bool dis; // are l and r disconnected
    ll sum;
    void flip(){
        swap(l,r);
    }
};

ll getF[maxn];

P mrg(P a, P b) {
    P re;
    re.sum = a.sum + b.sum;
    if (a.dis && b.dis) {
        re.sum += getF[a.r + b.l];
    }
    re.l = a.l + (a.dis? 0 : b.l);
    re.r = b.r + (b.dis? 0 : a.r);
    re.dis = a.dis || b.dis;
    return re;
}

P noth = {0, 0, 0, 0};
array<P, 2> oneP = {{{0,0,1,0}, {1,1,0,0}}};

P seg[maxn*4];

void build(int o=1, int l=0, int r=maxn-1) {
    if (l == r) {
        seg[o] = oneP[0];
        return;
    }
    int mid = (l+r)/2;
    build(o*2,l,mid); build(o*2+1,mid+1,r);
    seg[o] = mrg(seg[o*2], seg[o*2+1]);
}


P QU(int L, int R, int o=1, int l=0, int r=maxn-1) {
    if (l > R || r < L) return noth;
    if (l >= L && r <= R) {
        return seg[o];
    }
    int mid = (l+r)/2;
    return mrg(QU(L,R,o*2,l,mid), QU(L,R,o*2+1,mid+1,r));
}

void MO(int p, int o=1, int l=0, int r=maxn-1) {
    if (l > p || r < p) return;
    if (l == r) {
        seg[o] = oneP[1];
        return;
    }
    int mid = (l+r)/2;
    MO(p,o*2,l,mid); MO(p,o*2+1,mid+1,r);
    seg[o] = mrg(seg[o*2], seg[o*2+1]);
}


// hld time
int par[maxn], dep[maxn], sz[maxn];
int head[maxn], segpos[maxn], chainsz[maxn], chainpos[maxn]; // chainsz and segpos stored at head
int whobel[maxn]; // who's underneath this edge id?

vector<pii> g[maxn]; // {to, id}

void dfs1(int v, int p) {
    par[v] = p;
    sz[v] = 1;
    for (pii ed : g[v]) {
        int u = ed.f;
        if (u != p) {
            dep[u] = dep[v] + 1;
            whobel[ed.s] = u;
            dfs1(u,v);
            sz[v] += sz[u];
        }
    }
}

void dfs2(int v, int p) {
    chainsz[head[v]]++;
    int bg = -1, bgsz = -1;
    for (pii ed : g[v]) { int u = ed.f;
        if (u != p) {
            if (sz[u] > bgsz) {
                bgsz = sz[u]; bg = u;
            }
        }
    }
    for (pii ed : g[v]) { int u = ed.f;
        if (u != p) {
            if (u == bg) {
                head[u] = head[v];
                chainpos[u] = chainpos[v] + 1;
            }else{
                head[u] = u;
                chainpos[u] = 0;
            }
            dfs2(u,v);
        }
    }
}

struct query{
    int t; // time
    int id;
    int v,u;
};

ll get(int u, int v) {
    bug(u,v);
    P up = noth, vp = noth; // left-> right = top to bottom
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) {
            swap(u,v); swap(up, vp); // want to jump u
        }
        P yoi = QU(segpos[head[u]], segpos[head[u]] + chainpos[u]);
        bug(u, head[u], yoi.l, yoi.r, yoi.sum);
        up = mrg(yoi, up);
        u = par[head[u]];
    }
    if (dep[u] < dep[v]) {
        swap(u,v); swap(up, vp); // u is still lower
    }
    P btw = QU(segpos[head[v]] + chainpos[v] + 1, segpos[head[u]] + chainpos[u]); // v -> u
    vp.flip();
    // vp is now orig_v -> v
    // up is u -> orig_u
    P ya = mrg(vp, mrg(btw, up));
    ll ans = ya.sum;
    bug(ya.sum, ya.l, ya.r, ya.dis);
    if (ya.dis) {
        ans += getF[ya.l] + getF[ya.r];
    }else{
        ans += getF[ya.l];
    }
    return ans;
}

ll finans[maxn];

signed main(){
    IOS();

    int n,q; cin>>n>>q;
    REP(i,n-1) cin>>getF[i+1];

    vector<query> upd;

    REP(i,n-1) {
        int u,v,w; cin>>u>>v>>w; --u; --v;
        g[u].pb({v, i}); g[v].pb({u,i});
        upd.pb({w, i, -1, -1});
    }

    dfs1(0, -1);
    dfs2(0, -1);

    int IT = 0;
    REP(i,n) {
        bug(i, head[i], chainpos[i]);
        if (head[i] == i) {
            segpos[i] = IT;
            IT += chainsz[i];
            bug(segpos[i], chainsz[i]);
        }
    }


    REP(i, q) {
        int u,v,w; cin>>u>>v>>w;
        upd.pb({w, i, u-1, v-1});
    }

    sort(ALL(upd), [&](query a, query b) {
         if (a.t != b.t) return a.t > b.t;
         return a.u < b.u; // do the negative (edges) first
         });

    build();

    for (auto Q : upd) {
        if (Q.u == -1) {
            int bot = whobel[Q.id];
            bug("edge", bot);
            MO(segpos[head[bot]] + chainpos[bot]);
        }else{
            finans[Q.id] = get(Q.u, Q.v);
        }
    }

    REP(i, q) {
        cout<<finans[i]<<endl;
    }
}