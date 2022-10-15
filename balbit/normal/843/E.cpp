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

const int maxn = 1000+5;


struct Dinic{
    struct Edge{
        int to, rev, id; ll cap, flow=0;
        Edge(int to,int rev, ll cap, int id) : to(to), rev(rev), cap(cap), id(id) {}
    };
    vector<vector<Edge> > g;
    int n, s, t;
    vector<int> level, ptr;
    Dinic(int n, int s, int t):n(n),s(s),t(t){
        level.resize(n,-1); ptr.resize(n); g.resize(n);
    }
    void add(int v, int u, ll cap, int id){
        g[v].pb({u,SZ(g[u]),cap,id});
        g[u].pb({v,SZ(g[v])-1,0,-1});
    }
    bool bfs(){
        queue<int> q({s});
        level[s] = 0;
        while (!q.empty()){
            int v = q.front(); q.pop();
            for (auto &e : g[v]){
                if (e.cap - e.flow ==0) continue;
                int u = e.to;
                if (level[u]==-1){
                    level[u] = level[v]+1; q.push(u);
                }
            }
        } return level[t]!=-1;
    }
    vector<int> cut(){
        fill(ALL(level), -1);
        bfs();
        vector<int> re;
        REP(v,n) {
            for (Edge e : g[v]) {
                if (level[v] != -1 && level[e.to] == -1 && e.id != -1) {
                    re.pb(e.id);
                }
            }
        }
        bug(SZ(re));
        return re;
    }
    ll dfs(int v, ll amt){
        if (amt == 0 || v==t) return amt;
        for (; ptr[v] <SZ(g[v]); ptr[v]++){
            Edge &e = g[v][ptr[v]];
            int u = e.to;
            if (level[u] == level[v]+1){
                ll tt = dfs(u,min(amt, e.cap - e.flow));
                if (tt==0) continue;
                e.flow+=tt; g[e.to][e.rev].flow-=tt; return tt;
            }
        } return 0;
    }
    ll mf(){
        ll re = 0;
        while (bfs()){
            while (ll amt = dfs(s,inf)) re += amt;
            fill(ALL(level), -1); fill(ALL(ptr), 0);
        } return re;
    }
};

vector<pii> g[maxn];
vector<int> g2[maxn];
int nom[maxn];
int ts[maxn];
bool seen[105];

int IT = 0;

bool dfs(int v, int targ, bool noadd = 0) {
    seen[v] = 1; ts[v] = IT++;
    if (v == targ) {
        return 1;
    }
    for (pii p : g[v]) {
        if (!seen[p.f]) {
            if (dfs(p.f, targ,noadd)) {
                if (!noadd)
                    ++nom[p.s];
                return 1;
            }
        }else{
//            if (ts[p.f] < ts[v]) assert(0);
        }
    }
    return 0;
}

bool dfs2(int v, int targ) {
    seen[v] = 1;
    if (v == targ) {
        return 1;
    }
    for (int u : g2[v]) {
        if (!seen[u]) {
            if (dfs2(u, targ)) {
                return 1;
            }
        }
    }
    return 0;
}

vector<pii> one;

bool reach(int a, int b) {
    memset(seen, 0, sizeof seen);
    return dfs(a,b,1);
}

//bool safe(int a, int b) {
//    for (pii p : one) {
//        if (p.f == a && p.s == b) continue;
//        if (reach(b,p.f) && reach(p.s, a)) return 0;
//    }
//    return 1;
//}

bool incut[maxn];



signed main(){
    IOS();

    int n,m,s,t; cin>>n>>m>>s>>t; --s; --t;
    Dinic dd(n,s,t);

    vector<pair<pii, int> > ho;

    REP(i,m) {
        int a,b,x; cin>>a>>b>>x; --a; --b;
        g2[a].pb(b);
        if (!x){
            ho.pb({{a,b},i});
            nom[i] = -1;
        }
        if (x){
            one.pb({a,b});
            g[a].pb({b,i});
        }
    }

    for (auto p : ho) {
        int a = p.f.f, b = p.f.s, id = p.s;
//        if (safe(a,b)) {
//            dd.add(a,b,inf,id);
//        }else{
            dd.add(a,b,inf,id);
//        }
    }

    REP(a,n) {
        for (pii P : g[a]) {
            int b = P.f; int id = P.s;
            memset(seen, 0, sizeof seen);
            dd.add(a,b,1,id);
            if (a != s && b != t)
                dd.add(b,a,inf,-1);
//            if (!dfs(b,a,1)) {
//                dd.add(a,b,1,id);
//            }else{
//                dd.add(a,b,inf,id);
//            }

            if (nom[id]) continue;

            if (reach(s,a) && reach(b,t)) {
                dfs(s,a); dfs(b,t); ++nom[id];
            }else{
                assert(reach(b,a));
                dfs(b,a);
                ++nom[id];
            }
//
//            memset(seen, 0, sizeof seen);
//            assert(dfs(s, a));
//            ++ nom[id];
//            memset(seen, 0, sizeof seen);
//            assert(dfs(b, t));

        }
    }


    int flo = dd.mf();
    vector<int> cut = dd.cut();
    bug(flo, SZ(cut));
    if (SZ(cut) != flo) {
        cout<<SZ(cut)<<' '<<flo<<endl;
        exit(0);
        assert(SZ(cut) == flo); // min cut max flow

    }
    for (int x : cut) bug(x);
    for (int x : cut) incut[x]=1;

    REP(a,n) {
        for (pii P : g[a]) {
            int b = P.f; int id = P.s;
            if (dd.level[a]==-1) {
                if (dd.level[b] != -1) {
                    bug(b,a);
                    cout<<flo<<' '<<a<<' '<<b<<endl;
//                    assert(0);
//
                    exit(0);
                }
            }
        }
    }

    cout<<flo<<endl;

    REP(i,m) {
        if (incut[i] ) {
            if (nom[i] == -1) nom[i] = 0;
            cout<<nom[i]<<' '<<nom[i]<<endl;
        }else{
            if (nom[i] == -1) nom[i] = 0;
            cout<<nom[i]<<' '<<nom[i]+1<<endl;
        }
    }

}

/*
5 7 1 5
1 2 1
1 2 1
1 2 1
2 4 4
4 3 1
3 2 1
4 5 3


4 12 1 4
1 2 0
1 2 0
1 2 0
1 2 0
3 4 0
3 4 0
3 4 0
3 4 0

2 3 0
3 2 1
1 3 1
2 4 1


2 1 1 2
1 2 1
*/