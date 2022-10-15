#include <bits/stdc++.h>

#define ll long long 
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
 
 
using namespace std;
 
const int maxn = 5002;
const int inf = 1<<29;
 
 
const long long INF = 1LL<<60;
struct Dinic {  //O(VVE), with minimum cut 
    static const int MAXN = 100005;
    struct Edge{
        int u, v;
        long long cap, rest;
    };
 
    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];
 
    void init(){
        edges.clear();
        for ( int i = 0 ; i < MAXN ; i++ ) G[i].clear();
    }
 
    // min cut start
    bool side[MAXN];
    void cut(int u) {
        side[u] = 1;
        for ( int i : G[u] ) {
            if ( !side[ edges[i].v ] && edges[i].rest ) cut(edges[i].v);
        } 
    }
    // min cut end
 
    void add_edge(int u, int v, long long cap){
        edges.push_back( {u, v, cap, cap} );
        edges.push_back( {v, u, 0, 0LL} );
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }
    
    bool bfs(){
        memset(d, -1, sizeof(d));
        queue<int> que;
        que.push(s); d[s]=0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (int ei : G[u]){
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0){
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }
 
    long long dfs(int u, long long a){
        if ( u == t || a == 0 ) return a;
        long long flow = 0, f;
        for ( int &i=cur[u]; i < (int)G[u].size() ; i++ ) {
            Edge &e = edges[ G[u][i] ];
            if ( d[u] + 1 != d[e.v] ) continue;
            f = dfs(e.v, min(a, e.rest) );
            if ( f > 0 ) {
                e.rest -= f;
                edges[ G[u][i]^1 ].rest += f;
                flow += f;
                a -= f;
                if ( a == 0 )break;
            }
        }
        return flow;
    }
    long long fo = 0;
    long long maxflow(int s, int t){
        this->s = s, this->t = t;
        ll mf = 0;
        while ( bfs() ){
            memset(cur, 0, sizeof(cur));
            while  (mf = dfs(s, INF) )  fo += mf;
        }
        return fo;
    }
};
 
int pt[maxn], c[maxn]; // Potential, club
bool seen[maxn];
 
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    REP(i,n) cin>>pt[i]; REP(i,n) cin>>c[i], c[i]--;
    int ns; cin>>ns;
    vector<int> order(ns);
    REP(i,ns){
        cin>>order[i]; order[i]--; seen[order[i]]=1;
    }
    REP(i,n) {
        if (!seen[i]) order.pb(i);
    }
    reverse(ALL(order));
    assert(order.size()==n);
    Dinic dd;
    int mex = 0;
    int st = n+m+1, en = n+m+2;
    REP(i,m) dd.add_edge(st,i, 1);
    dd.add_edge(m+mex, en, 1);
    vector<int> ans;
    if (n==ns){
        ans.pb(0);
    }
    REP(j,n-1){
        dd.add_edge(c[order[j]],pt[order[j]]+m,1);
        //cout<<"Edge from "<<c[order[j]]<<" to "<<pt[order[j]]<<endl;
        while(mex<n&&dd.maxflow(st,en)==mex+1){
            mex++; if (mex<n) dd.add_edge(m+mex, en, 1);
        }
        if (j>=n-ns-1){
            ans.pb(mex);
        }
    }
    RREP(i,SZ(ans)) cout<<ans[i]<<'\n';
 
}