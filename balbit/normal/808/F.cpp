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

const int maxn = 2e5+5;

struct Dinic{
    struct Edge{
        int to, rev; ll cap, flow=0;
        Edge(int to,int rev, ll cap) : to(to), rev(rev), cap(cap) {}
    };

    vector<vector<Edge> > g; 
    int n;
    int s, t;
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

bool np[maxn];
void build(){
    FOR(i,2,maxn){
        if (!np[i]) for (int j = i+i; j<maxn; j+=i){
            np[j]=1;
        }
    }
}
vector<pair<pii, int> > v;


ll mx(int moe){
    vector<pii> go;
    ll S = 0;
    map<int, int> mp;
    for (auto &x : v){
        if (x.s<=moe) {
            if (x.f.s!=1) mp[x.f.s] += x.f.f;
            else MX(mp[x.f.s],x.f.f);
        }
    }
    vector<int> have;
    map<int, int> id;
    int idat = 0;
    for (pii x : mp){
        id[x.f] = idat++; go.pb(x); S += x.s;
    }
    int n = SZ(go) + 5;
    int s = n-1, t = n-2;
    Dinic dd(n,s,t);
    REP(i, SZ(go)){
        if (go[i].f & 1){
            dd.add(id[go[i].f], t, go[i].s);
        }else{
            dd.add(s, id[go[i].f], go[i].s);
        }
    }
    REP(i, SZ(go)) REP(j, SZ(go)){
        int a = go[i].f, b = go[j].f;
        if (a%2==0 && b%2==1){
            if (np[a+b]==0){
                dd.add(id[a], id[b], inf);
            }
        }
    }
    return S-dd.mf();
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    build();
    int n, k;
    cin>>n>>k;
    // ll S = 0;
    REP(i,n){
        int a, b, c; cin>>a>>b>>c; v.pb({{a,b},c});
    }
    int l = 0, r = n+2;
    while (l!=r){
        int mid = (l+r)/2;
        if (mx(mid)>=k){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if (l>n){
        GG();
    }
    cout<<l<<endl;
    
}