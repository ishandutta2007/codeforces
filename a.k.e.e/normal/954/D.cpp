#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN=1005,INF=0x3f3f3f3f;

int n,m;

struct Node
{
    int v;
    Node *next;
}pool[MAXN<<2|1],*h[MAXN];
int tot=0;
void addEdge(int u,int v)
{
    Node *p=&pool[++tot];
    p->v=v;p->next=h[u];h[u]=p;
}

int dis1[MAXN],dis2[MAXN];
queue<int> q;
void getdis(int src,int *dis)
{
    memset(dis,0,sizeof(dis));
    dis[src]=1;
    while(!q.empty())q.pop();
    q.push(src);
    register int u;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(Node *p=h[u];p;p=p->next)
            if(!dis[p->v])
            {
                dis[p->v]=dis[u]+1;
                q.push(p->v);
            }
    }
}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u,v,src,sink;
    scanf("%d%d%d%d",&n,&m,&src,&sink);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v);
    	addEdge(v,u);
    }
    getdis(src,dis1);
    getdis(sink,dis2);
    /*for(int i=1;i<=n;i++)
    	printf("%d %d\n",dis1[i],dis2[i]);
    cout<<endl;*/
    int ans=0;
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    		if(min(dis1[i]+dis2[j],dis1[j]+dis2[i])>=dis1[sink])
            {
                ans++;
                //cout<<i<<" "<<j<<endl;
            }
    printf("%d\n",ans-m);
    return 0;
}