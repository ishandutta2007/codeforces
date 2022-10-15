#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int maxn = 3e5+5;

struct Dinic{
    struct Edge{
        int to, rev;
        ll cap, flow;
    };
    int n, s, t;
    vector<vector<Edge> > g;
    vector<int> ptr;
    vector<int> dst;
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        g.resize(n); ptr.resize(n); dst.resize(n);
    }
    void add(int v, int u, ll fo) {
        g[v].pb({u,SZ(g[u]),fo,0});
        g[u].pb({v,SZ(g[v])-1,0,0});
    }
    bool bfs() {
        fill(ALL(dst),-1);
        queue<int> q({s});
        dst[s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (Edge & e : g[v]) {
            if (e.cap != e.flow  && dst[e.to] == -1) {
                    dst[e.to] = dst[v] + 1;
                    q.push(e.to);
                }
            }
        }
        bug(t, dst[t]);
        return dst[t] != -1;
    }
    ll dfs(int v, ll amt) {
        if (amt == 0 || v == t) return amt;
        for (; ptr[v] < SZ(g[v]); ++ptr[v]) {
            Edge & e = g[v][ptr[v]];
            if (dst[e.to] == dst[v] + 1 && e.cap != e.flow) {
                ll mo = dfs(e.to, min(amt, e.cap-e.flow));
                if (mo != 0) {
                    e.flow += mo;
                    g[e.to][e.rev].flow -= mo;
                    return mo;
                }
            }
        }
        return 0;
    }
    ll mf() {
        ll re = 0;
        while (bfs()) {
            fill(ALL(ptr), 0);
            while (ll amt = dfs(s, 0x3f3f3f3f3f3f3f3f)) {
                re += amt;
            }
        }
        return re;
    }
};

signed main(){
    IOS();
    int n,h,m; cin>>n>>h>>m;
    int N = n*(h+1) + m + 5, S = N-1, T = N-2;
    Dinic dd(N,S,T);
    for (int i = 0; i<n; i++) {
        dd.add(S,i*(h+1),h*h);
        dd.add(i*(h+1)+h, T, inf);
        for (int j = 1; j<=h; j++) {
            dd.add(i*(h+1)+j-1,i*(h+1)+j,h*h - (j) * (j) );
        }
    }
    for (int i = 0; i<m;i++) {
        int l,r,x,c;cin>>l>>r>>x>>c; --l; --r;
        int at = n*(h+1);
        for (int j = l; j<=r; j++) {
            dd.add(j*(h+1)+x,at+i,inf);
        }
        dd.add(at+i,T,c);
    }
    cout<<n * h * h - dd.mf()<<endl;
}