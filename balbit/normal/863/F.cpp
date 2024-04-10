#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
const ll INF = inf;


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

const int maxn = 28;


struct MCMF{
    int n, s, t;
    struct Edge{
        int to;
        ll cost;
        int rev; // rev id
        ll cap, flow=0; // Can have negative flow!!!!!
        Edge(int to, int rev, ll cost, ll cap): to(to), rev(rev), cost(cost), cap(cap) {}
    };
    vector<int> par, id;
    vector<ll> dist;
    vector<vector<Edge> > g;
    MCMF(int n,int s,int t): n(n), s(s), t(t){
        par.resize(n); id.resize(n); dist.resize(n,inf);
        g.resize(n);
    }
    void add(int v, int u, ll f, ll c){
        g[v].pb({u,SZ(g[u]),c,f});
        g[u].pb({v,SZ(g[v])-1,-c,0});
    }
    bool spfa(){ // SPFA
        queue<int> q ({s});
        vector<int> vis(n,0);
        fill(ALL(dist), inf); dist[s] = 0;
        while (!q.empty()){
            int v = q.front(); q.pop();
            vis[v] = 0;
            for (int i = 0; i<SZ(g[v]); i++){
                Edge &e = g[v][i];
                if (e.cap - e.flow==0) continue;
                if (dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    par[e.to] = v; id[e.to] = i;
                    if (!vis[e.to]){
                        q.push(e.to); vis[e.to] = 1; 
                    }
                }
            }
        }
        return dist[t] != inf;
    }

    pair<ll, ll> mf(){
        pair<ll, ll> re = {0,0};
        while (spfa()){
            ll famt = inf;
            for (int v = t; v!=s; v = par[v]){
                Edge &e = g[par[v]][id[v]];
                MN(famt, e.cap - e.flow);
            }
            for (int v = t; v!=s; v = par[v]){
                Edge &e = g[par[v]][id[v]];
                e.flow += famt;
                g[e.to][e.rev].flow -= famt;
            }
            re.f += famt; 
            re.s += dist[t] * famt;
        }
        return re;
    }
};

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    vector<int> mn(n,0), mx(n,n-1);
    REP(i,q){
        int t, l, r, v; cin>>t>>l>>r>>v; v--;
        if (t==1) FOR(i,l-1,r) MX(mn[i],v);
        else FOR(i,l-1,r) MN(mx[i],v);
    }
    int s = n+n+4, t = n+n+3;
    MCMF g(n+n+5, s,t);
    REP(i,n){
        g.add(s,i,1,0);
        if (mn[i]>mx[i]) GG();
        FOR(j,mn[i], mx[i]+1) {
            g.add(i,j+n,1,0);
        }
    }
    REP(i,n){
        REP(j,n){
            g.add(i+n, t, 1, j*2+1);
        }
    }
    cout<<g.mf().s<<endl;

}