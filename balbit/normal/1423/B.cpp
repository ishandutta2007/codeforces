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

const int maxn = 1e6+5;

struct Dinic{
    struct Edge{
        int to, rev; ll cap, flow=0;
        Edge(int to,int rev, ll cap) : to(to), rev(rev), cap(cap) {}
    };
    vector<vector<Edge> > g;
    int n, s, t;
    vector<int> level, ptr;
    Dinic(int n, int s, int t):n(n),s(s),t(t){
        level.resize(n,-1); ptr.resize(n); g.resize(n);
    }
    void add(int v, int u, ll cap){
        g[v].pb({u,SZ(g[u]),cap});
        g[u].pb({v,SZ(g[v])-1,0});
    }
    bool bfs(){ // Build layers with edges on the residual graph that aren't full
        queue<int> q({s});
        level[s] = 0;
        while (!q.empty() && level[t] == -1){
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
    ll dfs(int v, ll amt){ // Returns flow amount of any flow on bfs graph
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
            while (ll amt = dfs(s,inf)) re += amt; // Basically ford fulkerson, but on layered graph
            fill(ALL(level), -1); fill(ALL(ptr), 0);
        } return re;
    }
};

signed main(){

    IOS();
    int n,m; cin>>n>>m;
    vector<pair<int, pii> > v;
    for (int i = 0; i<m; ++i) {
        int a,b,w; cin>>a>>b>>w;
        --a; --b;
        v.pb({w,{a,b}});
    }
    sort(ALL(v));
    int l = 0, r = 1000000002;
    while (l != r) {
        int mid = (l+r)/2;
        int N = n*2+5, S = N-1, T = N-2;
        Dinic dd (N,S,T);
        for (int i = 0; i<n; ++i) {
            dd.add(S,i,1);
            dd.add(i+n,T,1);
        }
        for (auto & e : v) {
            if (e.f > mid) break;
            dd.add(e.s.f , e.s.s+n,1);
        }
        int f = dd.mf();
        bug(mid, f);
        if (f == n) {
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if (l > 1000000000) {
        cout<<-1<<endl; return 0;
    }
    cout<<l<<endl;
}