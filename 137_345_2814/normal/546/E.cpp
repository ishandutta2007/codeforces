#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct edge{
    int v,m,next;
}ed[2001];
int head[501],cur[501],dep[501],m,n,cnt,k[101][101];
void adde(int f,int t,int m)
{
    ed[cnt].v=t;
    ed[cnt].m=m;
    ed[cnt].next=head[f];
    head[f]=cnt++;
    ed[cnt].v=f;
    ed[cnt].m=0;
    ed[cnt].next=head[t];
    head[t]=cnt++;
}
bool bfs(int s,int t)
{
    memcpy(cur,head,sizeof(cur));
    memset(dep,-1,sizeof(dep));
    queue<int> p;
    p.push(s);
    dep[s]=0;
    while(!p.empty())
    {
        int q=p.front();
        p.pop();
        for(int i=head[q];i!=-1;i=ed[i].next)
        {
            int v=ed[i].v;
            if(ed[i].m&&dep[v]==-1)
            {
                dep[v]=dep[q]+1;
                p.push(v);
                if(v==t)
                return 1;
            }
        }
    }
    return 0;
}
int dfs(int u,int f,int t)
{
    if(u==t)
    return f;
    int ret=0,tmp;
    for(int& i=cur[u];i!=-1;i=ed[i].next)
    if(ed[i].m&&dep[ed[i].v]==dep[u]+1&&(tmp=dfs(ed[i].v,min(ed[i].m,f),t)))
    {
        ed[i].m-=tmp;
        ed[i^1].m+=tmp;
        ret+=tmp;
        f-=tmp;
        if(!f)
        return ret;
    }
    return ret;
}
int dinic(int s,int t)
{
    int ans=0;
    while(bfs(s,t))
    ans+=dfs(s,0x3f3f3f3f,t);
    return ans;
}
int main()
{
    int a,b,c=0,d=0;
    scanf("%d%d",&m,&n);
    cnt=c=0;
    memset(head,-1,sizeof(head));
    memset(k,0,sizeof(k));
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        adde(0,i,a);
        d+=a;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        adde(i,m+i,0x3f3f3f3f);
        adde(m+i,m*2+1,a);
        c+=a;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        adde(a,b+m,0x3f3f3f3f);
        adde(b,a+m,0x3f3f3f3f);
    }
    if(c!=d)
    {
        printf("NO\n");
        return 0;//
    }
    if(dinic(0,2*m+1)==c)
    {
    printf("YES\n");
    for(int i=1+m;i<=m*2;i++)
    for(int j=head[i];j!=-1;j=ed[j].next)
    {
        if(ed[j].m<=1000000&&ed[j].v&&ed[j].v<=m)
        k[ed[j].v][i-m]+=ed[j].m;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        printf("%d ",k[i][j]);
        printf("\n");
    }
    }
    else
    printf("NO\n");
}