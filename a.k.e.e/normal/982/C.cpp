#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN=100005,INF=1<<29;

int n;
struct Node
{
    int v;
    Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
void addEdge(int u,int v)
{
    Node *p=&pool[++etot];
    p->v=v;p->next=h[u];h[u]=p;
}

int size[MAXN],d[MAXN];
void dfs(int u,int pa)
{
    size[u]=1;
    for(Node *p=h[u];p;p=p->next)
    {
        if(p->v==pa)continue;
        dfs(p->v,u);
        size[u]+=size[p->v];
    }
}

bool flag=true;
void dp(int u,int pa)
{
    int c2=0;
    for(Node *p=h[u];p;p=p->next)
    {
        if(p->v==pa)continue;
        dp(p->v,u);
        if(!(size[p->v]&1))c2++;
        d[u]+=d[p->v];
    }
    d[u]+=c2;
}

int main()
{
    int u,v;
    scanf("%d",&n);
    if(n&1)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,-1);
    dp(1,-1);
    cout<<d[1]<<endl;
    return 0;
}