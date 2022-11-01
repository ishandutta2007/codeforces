#include <bits/stdc++.h>
#define pb push_back
#define sz(a) ((int) a.size())
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
const int N=(int)2e5;
int n, m, s, slog=0, nlog=0, dsu_p[N], dsu_r[N], d[N], p[N], r[N], bc[N][20], st[N][20];
struct edge {
    int u,v,w;
};
edge e[N], q[N];
vector<int> g[N], es, x(3*N,0); // LOGARIFMY
pii st1[3*N][20];
ll sum=0;
map<pii,int> mw;

void make_set(int v) {
    dsu_p[v]=v;
    dsu_r[v]=0;
}

int find_set(int v) {
    if(v==dsu_p[v]) return v;
    return dsu_p[v]=find_set(dsu_p[v]);
}

void union_sets(int a, int b) {
    if(dsu_r[a]<dsu_r[b]) swap(a,b);
    dsu_p[b]=a;
    dsu_r[a]+=(dsu_r[a]==dsu_r[b]);
}

void dfs(int v, int prev) {
    p[v]=prev;
    d[v]=d[prev]+1;
    r[v]=sz(es);
    es.pb(v);
    for(int i=0,sz=sz(g[v]); i<sz; i++)
        if(g[v][i]!=prev)
            dfs(g[v][i],v), r[v]=sz(es), es.pb(v);
}

int LCA(int u, int v) {
    if(r[u]>r[v]) swap(u,v);
    int len=x[r[v]-r[u]+1];
    return min(st1[r[u]][len], st1[r[v]-(1<<len)+1][len]).ss;
}

int get_max(int v, int to)
{
    int res=0;
    for(int i=nlog; i>=0; i--)
        if(d[bc[v][i]]>=d[to])
        {
            res=max(res,st[v][i]);
            v=bc[v][i];
        }
    return res;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w), e[i].u--, e[i].v--, q[i]=e[i];
    sort(e,e+m,[](edge fs, edge sc){ return fs.w<sc.w; });
    for(int i=0; i<n; i++) make_set(i);
    for(int i=0; i<m; i++)
        if(find_set(e[i].u)!=find_set(e[i].v))
            union_sets(find_set(e[i].u),find_set(e[i].v)),
            g[e[i].u].pb(e[i].v), g[e[i].v].pb(e[i].u),
            sum+=e[i].w;
    d[0]=-1;
    dfs(0,0);
    s=sz(es);
// LCA
    for(int i=0; i<s; i++) st1[i][0]={d[es[i]], es[i]};
    for(int ppow=1; ppow<s; ppow*=2) x[ppow]=slog, slog++;
    for(int i=2; i<=s; i++) if(!x[i]) x[i]=x[i-1];
    for(int j=1; j<=slog; j++)
        for(int i=0; i<s; i++)
            if(i+(1<<j)<=s)
                st1[i][j]=min(st1[i][j-1], st1[i+(1<<(j-1))][j-1]);
// LCA
// BINARY CLIMB
    for(int ppow=1; ppow<n; ppow*=2) nlog++;
    for(int i=0; i<n; i++) bc[i][0]=p[i];
    for(int j=1; j<=nlog; j++)
        for(int i=0; i<n; i++)
            bc[i][j]=bc[bc[i][j-1]][j-1];
// BINARY CLIMB
//SPARSE TABLE 2
    for(int i=0; i<m; i++) mw[{e[i].u,e[i].v}]=e[i].w, mw[{e[i].v,e[i].u}]=e[i].w;
    for(int i=0; i<n; i++) st[i][0]=mw[{i,p[i]}];
    for(int j=1; j<=nlog; j++)
        for(int i=0; i<n; i++)
            st[i][j]=max(st[i][j-1],st[bc[i][j-1]][j-1]);
//SPARSE TABLE 2


    for(int i=0; i<m; i++)
    {
        int k=LCA(q[i].u,q[i].v);
        printf("%I64d\n",sum-max(get_max(q[i].u,k),get_max(q[i].v,k))+q[i].w);
    }

    return 0;
}