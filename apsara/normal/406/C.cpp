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
const int V=100100;
struct Edge{int v,ne;}e[2*V];
int p[V],K;
void add(int u,int v)
{
    e[K].v=v;
    e[K].ne=p[u];p[u]=K++;
}
int f[V],d[V];
void dfs(int u,int fa)
{
    vector<int> a;
    vector<int> b;
    a.clear();b.clear();
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].v;
        if(v==fa)continue;
        if(d[v]==-1)
        {
            d[v]=d[u]+1;dfs(v,u);
            if(f[v]==0)a.push_back(v);
        }
        else if(d[v]<d[u])
        {
            b.push_back(v);
        }
    }
    for(int i=0;i<(int)a.size();i++)
    b.push_back(a[i]);
    for(int i=0;i+1<(int)b.size();i+=2)
    {
        printf("%d %d %d\n",b[i],u,b[i+1]);
    }
    if((int)b.size()%2==1)
    {
        f[u]=1;
        printf("%d %d %d\n",b[(int)b.size()-1],u,fa);
    }
}
int n,m,u,v;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(p,-1,sizeof(p));K=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        if(m%2==1)
        {
            puts("No solution");
            continue;
        }
        memset(f,0,sizeof(f));
        memset(d,-1,sizeof(d));
        d[1]=0;dfs(1,-1);
    }
}