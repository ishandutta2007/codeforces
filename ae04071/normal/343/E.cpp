#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;


struct edge{
    int t,c,f,r;
    edge() {}
    edge(int t,int c):t(t), c(c), f(0) {}
    int rem() {return c-f; }
};
struct MaxFlow {
    vector<vector<edge>> adj;
    vector<int> pre, idx;
    
    void init(int n) {
        adj.resize(n);
        pre.resize(n);
        idx.resize(n);
    }
    void clean() {
        for(auto &arr:adj) for(auto &e:arr) e.f = 0;
    }
    void addEdge(int u,int v,int c) {
        adj[u].push_back(edge(v,c));
        adj[v].push_back(edge(u,c));
        adj[u].back().r = adj[v].size() - 1;
        adj[v].back().r = adj[u].size() - 1;
    }
    int flow(int src,int sik) {
        int tf = 0;
        while(true) {
            fill(pre.begin(),pre.end(),0);
            fill(idx.begin(),idx.end(),-1);
            
            queue<int> que;
            que.push(src);
            while(!que.empty()) {
                int cur = que.front();que.pop();
                for(auto &it:adj[cur]) if(!pre[it.t] && it.rem()) {
                    pre[it.t] = cur;
                    idx[it.t] = it.r;
                    que.push(it.t);
                }
            }

            if(!pre[sik]) break;
            const int INF = 1e9;
            int f=INF;
            for(int cur = sik; cur != src; cur = pre[cur]) {
                int pi = pre[cur], pj = adj[cur][idx[cur]].r;
                f = min(f, adj[pi][pj].rem());
            }
            for(int cur = sik; cur != src; cur = pre[cur]) {
                int pi = pre[cur], pj = adj[cur][idx[cur]].r;
                adj[pi][pj].f += f;
                adj[cur][idx[cur]].f -= f;
            }
            tf += f;
        }
        return tf;
    }
}mf;

const int MAXN=201;
int n,m,vis[MAXN];
vector<pii> ret;
void dfs(int cur) {
    if(vis[cur]) return;
    vis[cur] = 1;
    for(auto &it:mf.adj[cur]) if(it.rem()) dfs(it.t);
}
void GomoryHu() {
    ret.resize(n+1);
    fill(ret.begin(), ret.end(), pii(0,1));
    ret[1] = {0,0};
    for(int i=2;i<=n;i++) {
        mf.clean();
        ret[i].fi = mf.flow(i, ret[i].se);
        fill(vis,vis+n+1,0);
        dfs(i);
        for(int j=i+1;j<=n;j++) if(ret[j].se == ret[i].se && vis[j]) ret[j].se = i;
    }
}

int ac;
vector<int> ans,adj[201];
pii dfs2(int cur,int p,int f=1) {
    pii r(100001, 0);
    if(f) r = min(r, pii(ret[cur].fi, cur));
    for(auto &it:adj[cur]) if(!vis[it]) {
        r = min(r, dfs2(it, cur));
    }
    return r;
}
void find_ans(int cur,int p) {
    pii val = dfs2(cur, p, 0);
    if(val.se == 0) {
        ans.push_back(cur);
    } else {
        ac += val.fi;
        find_ans(val.se, ret[val.se].se);
        vis[val.se] = 1;
        find_ans(cur, ret[cur].se);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    mf.init(n+1);
    for(int i=0,u,v,w;i<m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        mf.addEdge(u,v,w);
    }   
    GomoryHu();
    fill(vis,vis+n+1,0);
    for(int i=1;i<=n;i++) if(ret[i].se) adj[ret[i].se].push_back(i);
    find_ans(1, 0);
    printf("%d\n",ac);
    for(auto &it:ans) printf("%d ",it);
    
    return 0;
}