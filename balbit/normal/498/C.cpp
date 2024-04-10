#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
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

ll inv (ll b){
    return b==1?1:(mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

struct Dinic{
    int n, s, t;
    struct Edge{
        int to, rev; int flow=0, cap;
        Edge(int to, int rev, int cap): to(to),rev(rev),cap(cap) {

        }
    };
    vector<int> level,ptr;
    vector<vector<Edge> > g;
    Dinic(int n, int s, int t) : n(n),s(s),t(t){
        level.resize(n);
        ptr.resize(n);
        g.resize(n);
    }
    void add(int v, int u, int cap) {
        g[v].pb({u,SZ(g[u]),cap});
        g[u].pb({v,SZ(g[v])-1,0});
    }
    bool bfs() {
        fill(ALL(level),-1);
        level[s] = 0;
        queue<int> q({s});
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto &e : g[v]) {
                if (e.cap - e.flow > 0) {
                    if (level[e.to]==-1) {
                        level[e.to] = level[v]+1;
                        q.push(e.to);
                    }
                }
            }
        }
        return level[t]!=-1;
    }
    int dfs(int v, int amt=iinf) {
        if (v==t || amt == 0) return amt;

        for (;ptr[v]<SZ(g[v]); ptr[v]++) {
            Edge &e = g[v][ptr[v]];
            if (level[e.to] == level[v]+1 && e.cap!=e.flow) {
                int hmm = dfs(e.to, min(amt, e.cap-e.flow));
                if (hmm !=0){
                    e.flow += hmm;
                    g[e.to][e.rev].flow -= hmm;
                    return hmm;
                }
            }
        }
        return 0;
    }
    int mf(){
        int re = 0;
        while (bfs()){
            fill(ALL(ptr),0);
            while (int amt = dfs(s)){
                re += amt;
            }
        } return re;
    }

};

int a[maxn];
vector<int> to[maxn]; // odd-based
map<int, int> nof[maxn];

signed main(){
    IOS();
    int n, m; cin>>n>>m;
    set<int> prm;
    REP(i,n) {
        cin>>a[i];
        int tmp = a[i];
        FOR(j,2,sqrt(a[i])+1) {
            if (tmp % j ==0) {
                prm.insert(j);
                while (tmp%j==0)tmp/=j, nof[i][j]++;
            }
        }
        if (tmp != 1) prm.insert(tmp), nof[i][tmp]++;
    }
    REP(i,m) {
        int x,y; cin>>x>>y; --x; --y; // 0-based
        if (x%2==1) swap(x,y); // even on the left
        to[x].pb(y);
    }
    bug(prm.size());
    int re = 0;
    for (int p : prm) {
        bug(p);
        int N = 0;
        map<int, int> mp; int ID = 0;
        REP(i,n) {
            if (a[i]%p == 0){
                N++;
                mp[i] = ID++;
            }
        }
        N += 5;
        int S = N-1, T = N-2;
        Dinic dd (N,S,T);
        REP(i,n) {
            if (a[i]%p == 0){
                if (i%2==0){
                    dd.add(S,mp[i],nof[i][p]);
                }else{
                    dd.add(mp[i],T,nof[i][p]);
                }
            }
        }
        for (int i = 0; i<n; i+=2) {
            if (a[i]%p==0) {
                for (int u : to[i]) {
                    if (a[u]%p == 0){
                        dd.add(mp[i],mp[u],iinf);
                    }
                }
            }
        }
        re += dd.mf();
    }
    cout<<re<<endl;
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}