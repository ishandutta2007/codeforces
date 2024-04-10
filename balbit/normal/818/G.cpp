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


void GG(){cout<<"No\n"; exit(0);}

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

const int maxn = 1e5+5;

struct MCMF{
    int n, s, t;
    struct Edge{
        int to, rev;
        ll cost, cap, flow=0; // Can have negative flow!!!!!
        Edge(int to, int rev, ll cost, ll cap): to(to), rev(rev), cost(cost), cap(cap) {}
    };
    vector<int> par, id;
    vector<ll> dist;
    vector<vector<Edge> > g;
    MCMF(int n,int s,int t): n(n), s(s), t(t){
        par.resize(n); id.resize(n); dist.resize(n,inf);
        g.resize(n);
    }
    void add(int v, int u, ll c, ll f){
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
    int n; cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int N = n*2 + 10;
    int s = N-1, t = N-2, S = N-3;
    MCMF F (N, s, t);
    F.add(s,S,0,4);
    REP(i,n){
        int p1=20,m1=20,mo=20;
        F.add(S,i*2,0,1);
        F.add(i*2, i*2+1,-1,1);
        F.add(i*2+1,t,0,1);
        FOR(j,i+1,n){
            if (mo && a[j]%7 == a[i]%7) {
                mo--; F.add(i*2+1,j*2,0,1); 
            }
            if (p1 && a[j] == a[i]+1){
                p1--; F.add(i*2+1,j*2,0,1);
            }
            if (m1 && a[j] == a[i]-1){
                m1--; F.add(i*2+1,j*2,0,1);     
            }
        }
    }
    cout<<-F.mf().s<<endl;
}