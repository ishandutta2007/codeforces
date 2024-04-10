#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define y1 zck_is_king
#define pii pair<int, int>
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

struct edge{
    int u, w, i;
};

vector<edge> g[maxn];
int par[maxn], head[maxn], hv[maxn], sz[maxn], dep[maxn], wdep[maxn], last[maxn], which[maxn];
int stp[maxn], enp[maxn], nof[maxn]; // [,)
bool hasch[maxn];
//auto cmp = [](int a, int b) {
//    return dep[a] < dep[b];
//};
priority_queue<pii, vector<pii>, greater<pii> > pq[maxn];
int lastedge[maxn], lasttime[maxn]; // -1 lastedge is heavy child


void dfs1(int v, int p) {
    sz[v] = 1; par[v] = p;
    int bigsz = 0;
    for (edge e : g[v]) {
        if (e.u != p) {
            hasch[v]=1;
            which[e.u] = e.i;
            //dfs1(e.u, v);
            par[e.u] = v; dep[e.u] = dep[v] + 1; wdep[e.u] = wdep[v] + e.w;
            lastedge[v] = e.i;
            dfs1(e.u, v);
            sz[v] += sz[e.u];
            if (sz[e.u] > bigsz) {
                hv[v] = e.u; bigsz = sz[e.u];
            }
        }
    }
    if (lastedge[v] == which[hv[v]]) {
        lastedge[v] = -1;
    }
    if (!hasch[v]) {
        lastedge[v] = -2;
    }
}

void dfs2(int v, int p) {
    nof[head[v]]++;
    if (lastedge[v] >= 0) {
        pq[head[v]].push({dep[v], v});
        bug(head[v], v);
    }
    for (edge e : g[v]) {
        if (e.u == p) continue;
        if (hv[v] == e.u) {
            head[e.u] = head[v];
        }else{
            head[e.u] = e.u;
        }
        dfs2(e.u,v);
    }
}

vector<pii> flist;
//int ncnt [maxn];
//int nowneed = 0;

void add(int v, int t, int pt) {

    flist.pb({pt==0?0:pt + wdep[v], t+wdep[v]});
//    ncnt[v] ++; if (ncnt[v] == 1) nowneed++;
}

int s[maxn*2];

void MO(int p, int v) {
    for (s[p += maxn]=v; p>1; p>>=1) {
        s[p>>1] = max(s[p], s[p^1]);
    }
}

ll QU(int l, int r) {
    ll re = 0;
    for (l+=maxn, r+=maxn; l<r; l>>=1,r>>=1) {
        if (l&1) MX(re, s[l++]);
        if (r&1) MX(re, s[--r]);
    }
    return re;
}

void go(int v, int t) {
    while (1) {
        bug(v, head[v]);
        int H = head[v];
        // delete nodes on top of me
        while (!pq[H].empty() && pq[H].top().f < dep[v]) {
            int u = pq[H].top().s;
            assert(lastedge[u] != -1);
            add(u,t, lasttime[u]);
            lastedge[u] = -1;
            pq[H].pop();
        }
        if (v != H ) {
            MO(stp[H] + (dep[par[v]] - dep[H]), t);
            bug(v, H, stp[H] + dep[par[v]] - dep[H]);
        }
        v = H;
        if(v == 0) break;
        if (lastedge[par[v]] != which[v]){

            int pt = -1;
            if (lastedge[par[v]] == -1){
                pq[head[par[v]]].push({dep[par[v]], par[v]});
                pt = QU(stp[head[par[v]]]+(dep[par[v]]-dep[head[par[v]]]), enp[head[par[v]]]);
                bug(pt);
            }else{
                pt = lasttime[par[v]];
            }
            lastedge[par[v]] = which[v];
            add(par[v], t, pt);
            bug(par[v], t, pt);
        }
            lasttime[par[v]] = t;
        v = par[v];
    }
}

struct EE{
    int t, to;
    bool qu;
    bool operator < (const EE &b) const {
        return t!=b.t?t<b.t:qu>b.qu;
    }
};

signed main(){
    IOS();
//    bug(string(decltype(cmp)));
    int n,m; cin>>n>>m;
    REP(i,n-1) {
        int a,b,w; cin>>a>>b>>w; --a; --b;
        g[a].pb({b,w,i});
    }
    dfs1(0,-1);
    dfs2(0,-1);
    int NOW = 0;
    REP(i,n) {
        if (head[i] == i) {
            stp[i] = NOW; enp[i] = NOW + nof[i]; NOW += nof[i];
            bug(i, stp[i], enp[i]);
        }
    }
    REP(i,n) bug(i, head[i]);
    REP(j,m) {
        int v,t; cin>>v>>t; --v;
        go(v,t);
    }
//    sort(ALL(flist));
    int prv = 0;
//    int re2 = 0;
//    bool done = 0;
    vector<EE> ev;
    for (pii & p : flist) {
        ev.pb({p.f, p.s, 0});
        ev.pb({p.s, -1, 1});
    }
    vector<int> tyd; // try to do
    priority_queue<int, vector<int>, greater<int> > fr;
    sort(ALL(ev));
    ll ret = inf;
    for (EE e: ev){
        REP(j, e.t-prv) {
            if (!fr.empty()) {
                tyd.pb(fr.top()); fr.pop();
            }else break;
        }
        if (e.qu) {
            if (!fr.empty() && fr.top() <= e.t) {
                assert(fr.top()==e.t);
                ret = e.t; break;
            }
        }else{
            fr.push(e.to);
        }
        prv = e.t;
//        int dst = p.f - prv;
//        int tk = min(nowneed, dst);
//        nowneed-=tk; re2+=tk;
//        if (nowneed > 0) {
//            cout<<p.f<<' ';done=1; break;
//        }
//        if (--ncnt[p.s]) ++nowneed;
    }
    int nofsmol = 0;
    for (int x : tyd) nofsmol += (x < ret);
    bug(SZ(tyd));
    if (ret == inf) ret = -1;
    cout<<ret<<' '<<nofsmol<<endl;
//    if (!done) cout<<-1<<' ';
//    cout<<re2<<endl;
}