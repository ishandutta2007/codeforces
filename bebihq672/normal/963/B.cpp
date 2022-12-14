#include<iostream>
#include<cstdio>
using namespace std;
struct Edge{
    int to,next;
}e[404040];
int cnt=0,head[202020];
void add(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int d[202020],d2[202020];
int size[202020];
void dfs(int x,int fa)
{
    size[x]=1;
    for(int i=head[x];i!=0;i=e[i].next)
    {
        int to=e[i].to;
        if(to!=fa)
        {
            dfs(to,x);
            size[x]+=size[to];
            if(size[to]%2==0)
                printf("%d\n",to);
        }
    }
}
void dfs2(int x,int fa)
{
    if(size[x]%2==1)
        printf("%d\n",x);
    for(int i=head[x];i!=0;i=e[i].next)
    {
        int to=e[i].to;
        if(to!=fa)
            dfs2(to,x);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int pi;
        scanf("%d",&pi);
        if(pi!=0)
        {
            d[i]++;
            d[pi]++;
            add(pi,i);
            add(i,pi);
        }
    }
    if(n%2==0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    dfs(1,0);
    dfs2(1,0);
    return 0;
}