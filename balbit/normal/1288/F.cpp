#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 404+5;

string L, R;
vector<pii> G[maxn];

struct Edge{
    int to, cap, flow, cost, id;
};

vector<Edge> E;
vector<int> g[maxn];
int N,S,T;

void add(int v, int u, int cap, int cost, int id = -1) {
    if (cap < 0) GG();
    g[v].pb(SZ(E));
    E.pb({u,cap,0,cost,id});
    g[u].pb(SZ(E));
    E.pb({v,0,0,-cost,id});
}

int par[maxn];
bool inq[maxn];
ll dst[maxn];

int mc(){
    memset(par, -1, sizeof par);
    memset(dst, 0x3f, sizeof dst);
    memset(inq, 0, sizeof inq);
    dst[S] = 0; inq[S] = 1;
    queue<int> q({S});
    while (!q.empty()) {
        int v = q.front(); q.pop();
        bug(v, dst[v]);
        inq[v] = 0;
        for (int i : g[v]) {
            Edge & e = E[i];
            if (e.cap-e.flow>0) {
                if (dst[e.to] > dst[v] + e.cost) {
                    dst[e.to] = dst[v] + e.cost;
                    par[e.to] = i;
                    if (!inq[e.to]) {
                        inq[e.to] = 1;
                        q.push(e.to);
                    }
                }
            }
        }
    }
    if (dst[T] > 0) return 1;
    if (par[T] != -1) {
        for (int at = T; at != S; ) {
            E[par[at]].flow ++;
            E[par[at]^1].flow --;
            at = E[par[at]^1].to;
        }
    }
    bug(dst[T]);
    return dst[T];
}

//map<pii, int> id;
int edgeans[maxn];

signed main(){
    IOS();

    int n1, n2, m, r, b; cin>>n1>>n2>>m>>r>>b;
    cin>>L>>R;
    REP(i,m) {
        int a,b; cin>>a>>b; --a; --b;
        G[a].pb({b+n1,i});
        G[b+n1].pb({a,i});
//        id[{a,b+n1}] = i;
    }
    N = n1+n2+4;
    S = N-1, T=N-2;
    ll req = r * m;
    REP(i,n1) {
        if (L[i] == 'R') {
            add(S,i,SZ(G[i])-1,0);
        }
        if (L[i] == 'U') {
            add(S,i,SZ(G[i]) * 2, 0);
        }
        if (L[i] == 'B') {
            add(S,i,SZ(G[i])+1,-1000000);
            req += 1000000 * (SZ(G[i]) + 1);
            add(S,i,SZ(G[i])-1,0);
        }
        for (pii j : G[i]) {
            add(i,j.f,1,-r,j.s);
            add(i,j.f,1,b,j.s);
        }
    }
    REP(i,n2) {
        int me = i + n1;
        if (R[i] == 'R') {
            add(me,T,SZ(G[me])-1,0);
        }
        if (R[i] == 'B') {
            add(me,T,SZ(G[me])+1,-1000000);
            req += 1000000 * (SZ(G[me])+1);
            add(me,T,SZ(G[me])-1,0);
        }
        if (R[i] == 'U') {
            add(me,T,SZ(G[me])*2,0);
        }
    }
    bug(req);

    while (1) {
        ll hi = mc(); if (hi > 0) break;
        bug(hi); req += hi;
    }
    bug(req);
    if (req >= 40000) GG();
    cout<<req<<endl;
    REP(v,n1) {
        for (int i: g[v]) {
            if (i % 2 == 0) {
                Edge & e = E[i];
                assert(e.to >=n1 && e.to < n1+n2);
//                bug(v, e.to, id[{v,e.to}]);
                if (e.flow == e.cap)
                    edgeans[e.id]++;
            }
        }
    }
    REP(i,m) {
        cout<<"RUB"[edgeans[i]];
    }
}