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

const int maxn = 2e5+5;

int part[maxn], pars[maxn];
ll dt[maxn], ds[maxn];

int yos[maxn], yot[maxn]; // the first person on the royal road they touch

struct edge{
    int v, u, i, w;
    int G(int x) {
        return v^u^x;
    }
};

void ass(bool x){
    if (!x) {
        cout<<"Dead"<<endl; exit(0);
    }
}

vector<edge>g[maxn];
vector<edge> E; // edges
int n,m,q;
bool royal[maxn]; // are you on the path from S -> T
int royalpos[maxn]; // position on royal path

int build(int v, int *par, int *yo) {
    if (yo[v] != -1) return yo[v];
    if (royal[v]) {
        return yo[v] = royalpos[v];
    }
    return yo[v] = build(E[par[v]].G(v), par, yo);
}

vector<int> pth; // S -> T
vector<int> pthedges;
bool royalid[maxn]; // is this edge id royal

void dij(int S, int T, ll *d, int *par, int *yo, bool first=0){ // returns list of ids of nodes
    memset(d, 0x3f, sizeof dt);
    memset(par, -1, sizeof part);
    priority_queue<pii, vector<pii>, greater<pii> > pq; pq.push({0, S});
    if (!first) {
        for (int i = SZ(pth)-2; i>=0; --i) {
            d[pth[i]] = ds[S] - ds[pth[i]];
            par[pth[i]] = pthedges[i];
            bug(pth[i], pthedges[i]);
            pq.push({d[pth[i]], pth[i]});
        }
    }
    d[S] = 0;
    while (!pq.empty()) {
        int v = pq.top().s; ll w = pq.top().f; pq.pop();
//        bug(v,w);
        if (w != d[v]) continue;
        for (edge &e : g[v]) {
            if (d[e.u] > d[v] + e.w) {
                d[e.u] = d[v] + e.w;
                pq.push({d[e.u], e.u});
                par[e.u] = e.i;
            }
        }
    }
//    REP(i,n) {
//        if (i != S) ass(d[i] < 0x3f3f3f3f3f3f3f3f);
//    }
    if (first) {
        vector<int> ret;
        vector<int> retedges;
        for (int at = T; at != S; at = E[par[at]].G(at)) {
    //        bug(at);
            ret.pb(at);
            royalid[par[at]] = 1;
            retedges.pb(par[at]);
        }
        ret.pb(S);
        reverse(ALL(ret));
        reverse(ALL(retedges));
        pth = ret;
        pthedges = retedges;
        int IT = 0;
        for (int x : ret) {
            royal[x] = 1;
            royalpos[x] = IT++;
        }
    }
    memset(yo, -1, sizeof yos);
    REP(i,n) {
        if (yo[i] == -1 && d[i] != 0x3f3f3f3f3f3f3f3f) {
            build(i, par, yo);
        }
    }
}

vector<int> in[maxn], out[maxn];

ll cuthere[maxn];

signed main(){
    IOS();
    cin>>n>>m>>q;
    REP(i,m) {
        int u,v,w; cin>>u>>v>>w; --u; --v;
        g[u].pb({u,v,i,w});
        g[v].pb({v,u,i,w});
        E.pb({v,u,i,w});
    }
    dij(0,n-1,ds,pars,yos,1);
    dij(n-1,0,dt,part,yot,0);
    for (int x : pth) bug(x);



    REP(i,m) {
        if (royalid[i]) continue;
        int u = E[i].u, v = E[i].v;
//        ass(yos[u] >= 0 && yot[v] >= 0);
        if (yos[u] < yot[v]) {
            bug(yos[u], yot[v], ds[u] + dt[v] + E[i].w);
            in[yos[u]].pb(ds[u] + dt[v] + E[i].w);
            out[yot[v]].pb(ds[u] + dt[v] + E[i].w);
        }
        swap(u,v);
        if (yos[u] < yot[v]) {
            bug(yos[u], yot[v], ds[u] + dt[v] + E[i].w);
            in[yos[u]].pb(ds[u] + dt[v] + E[i].w);
            out[yot[v]].pb(ds[u] + dt[v] + E[i].w);
        }
    }

    multiset<ll> fren;

    REP(i, n) {
        for (ll x : in[i]) {
            fren.insert(x);
        }
        for (ll x : out[i]) {
            fren.erase(fren.find(x));
        }
        cuthere[i] = fren.empty()?inf:*fren.begin();
    }

    REP(qqq, q) {
        int tid, w; cin>>tid>>w;
        --tid;
        int u = E[tid].u, v = E[tid].v;
        ll forcewalk = min(ds[v] + dt[u], ds[u] + dt[v]) + w;
        ll avoid;
        if (royalid[tid]) {
            avoid = cuthere[min(royalpos[u], royalpos[v])];
        }else{
            avoid = ds[n-1];
        }
        bug(forcewalk, avoid);
        cout<<min(forcewalk, avoid)<<endl;
    }
}


/*


6 7 10
1 2 2
2 3 3
3 6 4
1 4 10
4 2 15
4 5 13
5 6 13



*/