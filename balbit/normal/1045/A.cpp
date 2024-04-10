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
const int maxn = 5005;
 
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
 
struct Edge{
    int to, rev; ll cap, flow=0;
    Edge(int to,int rev, ll cap) : to(to), rev(rev), cap(cap) {}
};
 
struct Dinic{
    
 
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
 
int seg[maxn];
int dmax = 5e4+10;
int sgst = 1e4+5;
int S = dmax-1, T = dmax-2;
Dinic dd(dmax, S, T);
 
void BUILD(int o, int l, int r){
    int mid = (l+r)/2;
    if (l>r) return;
    if (l==r){
        dd.add(o/2+sgst,l+5000,inf); return;
    }else if (o!=1){
        dd.add(o/2+sgst, o+sgst, inf);
    }
    BUILD(o*2,l,mid); BUILD(o*2+1,mid+1,r);
}
 
int from = -1;
 
void ADD(int o, int l, int r, int L, int R){
    if (l>R || r<L) return;
    if (l>=L && r<=R) {
        if (l==r){
            dd.add(from,l+5000,1); return;
        }
        dd.add(from, o+sgst, 1); return;
    }
    int mid = (l+r)/2;
    ADD(o*2,l,mid,L,R); ADD(o*2+1,mid+1,r,L,R);
}
 
int TOP[maxn];
bool cancel[maxn*3];

int dofe(int at, int p){
    if (at<=sgst && at>=5000) return at;
    for (Edge &e : dd.g[at]) {
        if (e.flow >= 1 && e.to!=p) {
            int mo = dofe(e.to,at); 
            if (mo!=-1) {
                e.flow --; return mo;
            }
        }
    }
    return -1;
}
 
main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    BUILD(1,0,m-1);
    REP(i,n){
        int TP; cin>>TP; TOP[i] = TP;
        if (TP==0){
            dd.add(S,i,1);
            int K; cin>>K; 
            REP(j,K) {
                int to; cin>>to; dd.add(i,to-1+5000,1);
            }
        }if (TP==1){
            int l, r; cin>>l>>r;
            from = i;
            dd.add(S,i,1);
            ADD(1,0,m-1,l-1,r-1);
        }
        if (TP==2){
            int a, b, c; cin>>a>>b>>c;
            dd.add(S,i,2);
            dd.add(i,a+5000-1,1); dd.add(i,b+5000-1,1); dd.add(i,c+5000-1,1);
        }
    }
    REP(i,m){
        dd.add(i+5000,T,1);
    }
    cout<<dd.mf()<<'\n';
    for (Edge &e : dd.g[S]){
        if (TOP[e.to]==2){
            
            for (Edge &e2 : dd.g[e.to]){
                if (e2.to!=S && e2.flow==1){
                    cout<<e.to+1<<' '<<e2.to+1-5000<<'\n';
                }
                else if (e2.to != S && e.flow==1 && e2.flow!=1){
                    e.flow++; cout<<e.to+1<<' '<<e2.to+1-5000<<'\n'; cancel[e2.to] = 1;
                }
            }
        }
    }
    for (Edge &e : dd.g[S]){
        if (TOP[e.to]==0){
            for (Edge &e2 : dd.g[e.to]){
                if (e2.to!=S && e2.flow==1 && !cancel[e2.to]){
                    cout<<e.to+1<<' '<<e2.to+1-5000<<'\n';
                }
            }
        }else if (TOP[e.to]==1){
            int endp = dofe(e.to, S);
            if (endp!=S && endp!=-1 && !cancel[endp]){
                cout<<e.to+1<<' '<<endp+1-5000<<'\n';
            }
            
        }
    }
}