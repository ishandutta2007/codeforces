#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=300100;
struct Edge{int v,ne,len;}e[3*V];
int p[V],K;
void add(int u,int v,int z)
{
    e[K].v=v;e[K].len=z;
    e[K].ne=p[u];p[u]=K++;
}
int set[V],ans[V],mx[V];
int find(int x)
{
    if(set[x]!=x)set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y,int z)
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy)return;
    set[fx]=fy;
    ans[fy]=max(max(ans[fx],ans[fy]),mx[fx]+z+mx[fy]);
    mx[fy]=min(max(mx[fx]+z,mx[fy]),max(mx[fy]+z,mx[fx]));
}
int vis[V],d[V],id,mxx;
void dfs(int u,int fa)
{
    vis[u]=1;
    if(id==-1||mxx<d[u])
    {id=u;mxx=d[u];}
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].v;
        if(v==fa)continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
int n,m,Q,x,y,op;
int main()
{
    while(~scanf("%d%d%D",&n,&m,&Q))
    {
        for(int i=1;i<=n;i++)
        set[i]=i,mx[i]=0,ans[i]=0;
        memset(p,-1,sizeof(p));K=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y,1);
            add(y,x,1);
            U(x,y,1);
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            d[i]=0;
            id=i,mxx=0;
            dfs(i,-1);
            mxx=0;d[id]=0;
            dfs(id,-1);
            int fi=find(i);
            mx[fi]=(mxx+1)/2;
            ans[fi]=mxx;
            //printf("Ans %d %d %d\n",i,ans[fi],mx[fi]);
        }
        while(Q--)
        {
            scanf("%d",&op);
            if(op==2)
            {
                scanf("%d%d",&x,&y);
                U(x,y,1);
            }
            else
            {
                scanf("%d",&x);
                printf("%d\n",ans[find(x)]);
            }
        }
    }
    return 0;
}