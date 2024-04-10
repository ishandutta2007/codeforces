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

const int iinf = 1<<29;
const int inf = iinf;
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

struct Dinic{
    struct Edge{
        int to, rev; int cap, flow=0;
        Edge(int to,int rev, int cap) : to(to), rev(rev), cap(cap) {}
    };

    vector<vector<Edge> > g; 
    int n;
    int s, t;
    vector<int> level, ptr;
    Dinic(int n, int s, int t):n(n),s(s),t(t){
        level.resize(n,-1); ptr.resize(n); g.resize(n);
    }
    void add(int v, int u, int cap){
        g[v].pb({u,SZ(g[u]),cap}); 
        g[u].pb({v,SZ(g[v])-1,0});
    }
    bool bfs(){ // Build layers with edges on the residual graph that aren't fuint
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
    int dfs(int v, int amt){ // Returns flow amount of any flow on bfs graph
        if (amt == 0 || v==t) return amt;
        for (; ptr[v] <SZ(g[v]); ptr[v]++){
            Edge &e = g[v][ptr[v]]; 
            int u = e.to;
            if (level[u] == level[v]+1){
                int tt = dfs(u,min(amt, e.cap - e.flow));
                if (tt==0) continue;
                e.flow+=tt; g[e.to][e.rev].flow-=tt; return tt;
            }
        } return 0;
    }
    int mf(){
        int re = 0;
        while (bfs()){
            while (int amt = dfs(s,inf)) re += amt; // Basically ford fulkerson, but on layered graph
            fill(ALL(level), -1); fill(ALL(ptr), 0);
        } return re;
    }
};

int msk[maxn];
int touch[64];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s; cin>>s; 
    int n = s.length();
    int Q; cin>>Q;
    vector<int> nof(6);
    vector<int> nmsk(64);
    while (Q--){
        int at; cin>>at; 
        string t; cin>>t;
        REP(i, SZ(t)){
            msk[at-1]|=1<<(t[i]-'a');
        }
        nmsk[msk[at-1]] ++;

    }
    REP(i,n) if (msk[i]==0) msk[i]=63, nmsk[63]++;
    REP(i,64) REP(j,64) if (j&i) touch[j]+=nmsk[i];
    REP(i, n) nof[s[i]-'a']++;
    REP(i,n){
        REP(j,64) if (j&msk[i]) touch[j]--;
        bool done = 0;
        REP(j, 6){

            if (nof[j] && msk[i] & (1<<j)){
                bool can = 1;
                nof[j]--;
                FOR(mk,1, 64){
                    int nf = 0;
                    REP(k,6) {
                        if (mk & (1<<k)) nf += nof[k];
                    }
                    if (nf > touch[mk]) {
                        can = 0;
                        break;
                    }
                }
                if (can){
                    s[i] = ('a'+j); done = 1; break;
                }
                nof[j]++;
            }
        }
        if (!done ) {
            cout<<"Impossible\n"; return 0;
        }
    }
    cout<<s<<endl;
    
}