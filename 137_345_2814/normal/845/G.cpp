#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long p[64];
void ins(long long a)
{
    for(int i=63;i>=0;i--)
    {
        if(!((a>>i)&1))
        continue;
        if(!p[i])
        {
            p[i]=a;
            break;
        }
        a^=p[i];
    }
}
long long sol(long long ans)
{
    for(int i=63;i>=0;i--)
    if((ans^p[i])<ans)
    ans^=p[i];
    return ans;
}
int cnt,head[100001],n,m,a,b;
long long dis[100001],c;
struct ed{
    int t,next;
    long long v;
}e[200001];
void adde(int f,int t,long long v)
{
    e[++cnt].t=t;
    e[cnt].v=v;
    e[cnt].next=head[f];
    head[f]=cnt;
    e[++cnt].t=f;
    e[cnt].v=v;
    e[cnt].next=head[t];
    head[t]=cnt;
}
void dfs(int v,int fa)
{
    for(int i=head[v];i;i=e[i].next)
    {
        if(dis[e[i].t]!=-1)
        ins(dis[v]^e[i].v^dis[e[i].t]);
        else
        {
            dis[e[i].t]=dis[v]^e[i].v;
            dfs(e[i].t,v);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=m;i++)
    scanf("%d%d%lld",&a,&b,&c),adde(a,b,c);
    dis[1]=0;dfs(1,0);
    printf("%lld\n",sol(dis[n]));
}