//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI >    VVI;
typedef long long int   LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(2e5)+10;
const int LOGN = 20;
const LL INF = LL(2e18);
VI g[N];
int U[N],V[N];LL W[N];
int DP[LOGN][N],chainParent[N],chainHead[N],blen,chainNo[N],pos[N],sub[N],nchain,level[N];
LL baseArray[N],ST[4*N];
int adj(int u,int e)
{
    return U[e]==u?V[e]:U[e];
}
void HLD(int u,int ee)
{
    baseArray[blen]=W[ee];
    pos[u]=blen;blen++;
    chainNo[u]=nchain;
    int sc=-1,mx=0;
    for(int i=0;i<SZ(g[u]);i++)
    {
        int e = g[u][i];
        if(e==ee)continue;
        int w = adj(u,e);
        if(sub[w]>mx)
            sc = e,mx = sub[w];
    }
    if(sc==-1)return;
    HLD(adj(u,sc),sc);
    for(int i=0;i<SZ(g[u]);i++)
    {
        int e = g[u][i];
        if(e==ee || e==sc)continue;
        int w = adj(u,e);
        nchain++;chainParent[nchain]=u;chainHead[nchain]=w;
        HLD(w,e);
    }
}
void dfs(int u,int ee)
{
    sub[u]=1;
    for(int i=0;i<SZ(g[u]);i++)
        if(g[u][i]!=ee)
        {
            int w = adj(u,g[u][i]);
            level[w]=level[u]+1;
            DP[0][w]=u;
            dfs(w,g[u][i]);
            sub[u]+=sub[w];
        }
}
bool fucked(LL a,LL b)
{
    return a >= INF/b;
}
int n;
#define lc x<<1
#define rc x<<1 | 1
void build(int l=0,int r=blen,int x=1)
{
    if(l==r-1)return void (ST[x]=baseArray[l]);
    int m = (l+r)/2;
    build(l,m,lc);
    build(m,r,rc);
    if(fucked(ST[lc],ST[rc]))ST[x]=INF;
    else ST[x]=ST[lc]*ST[rc];
}
void point_update(int pos,LL val,int l=0,int r=blen,int x=1)
{
    if(l>pos || r<=pos)return;
    if(l==r-1 && l==pos)return void(ST[x]=val);
    int m = (l+r)/2;
    point_update(pos,val,l,m,lc);
    point_update(pos,val,m,r,rc);
    if(fucked(ST[lc],ST[rc]))ST[x]=INF;
    else ST[x]=ST[lc]*ST[rc];
}
LL range_query(int L,int R,int l=0,int r=blen,int x=1)
{
    if(l>=R || r<=L)return 1;
    if(l>=L && r<=R)return ST[x];
    int m = (l+r)/2;
    LL la = range_query(L,R,l,m,lc);
    LL ra = range_query(L,R,m,r,rc);
    if(fucked(la,ra))return INF;
    else return la*ra;
}
int lca(int a,int b)
{
    if(level[a]>level[b])swap(a,b);
    int d = level[b]-level[a];
    for(int i=0;i<LOGN;i++)
        if((1<<i)&d)
            b=DP[i][b];
    if(a==b)return a;
    for(int i=LOGN-1;i>=0;i--)
        if(DP[i][a]!=DP[i][b])
            a=DP[i][a],b=DP[i][b];
    return DP[0][a];
}
void preprocess()
{
    //hang the tree
    DP[0][1]=1;
    dfs(1,0);
    //HLD
    chainHead[nchain]=chainParent[nchain]=1;
    HLD(1,0);
    //LCA
    for(int i=1;i<LOGN;i++)
        for(int j=1;j<=n;j++)
            DP[i][j]=DP[i-1][DP[i-1][j]];
    //segtree
    build();
}
LL query_up(int u,int p,LL y)
{
    while(chainNo[u]!=chainNo[p])
    {
        LL d = range_query(pos[chainHead[chainNo[u]]],pos[u]+1);
        y = y / d;
        u = chainParent[chainNo[u]];
    }
    if(u==p)return y;
    LL d = range_query(pos[p]+1,pos[u]+1);
    y = y/d;
    return y;
}
int main()
{
    si(n);
    int m;si(m);
    for(int i=1;i<n;i++)
    {
        scanf("%d %d %lld\n",U+i,V+i,W+i);
        g[U[i]].PB(i);
        g[V[i]].PB(i);
    }
    preprocess();
    while(m--)
    {
        int t;si(t);
        if(t==1)
        {
            int a,b;si(a);si(b);
            LL y;sll(y);
            int LCA = lca(a,b);
            y = query_up(a,LCA,y);
            y = query_up(b,LCA,y);
            lldout(y);
        }
        else 
        {
            int e;si(e);
            LL c;sll(c);
            int x = level[U[e]]>level[V[e]]?U[e]:V[e];
            point_update(pos[x],c);
        }
    }
    return 0;
}